import socket
import struct

# IP and Port
UDP_IP = "0.0.0.0"
UDP_PORT = 12345

# Point Type
class PointUnitree:
    def __init__(self, x, y, z, intensity, time, ring):
        self.x = x
        self.y = y
        self.z = z
        self.intensity = intensity
        self.time = time
        self.ring = ring

# Scan Type
class ScanUnitree:
    def __init__(self, stamp, id, validPointsNum, points):
        self.stamp = stamp
        self.id = id
        self.validPointsNum = validPointsNum
        self.points = points

# IMU Type
class IMUUnitree:
    def __init__(self, stamp, id, quaternion, angular_velocity, linear_acceleration):
        self.stamp = stamp
        self.id = id
        self.quaternion = quaternion
        self.angular_velocity = angular_velocity
        self.linear_acceleration = linear_acceleration

# Create UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

# Calculate Struct Sizes
imuDataStr = "=dI4f3f3f"
imuDataSize = struct.calcsize(imuDataStr)

pointDataStr = "=fffffI"
pointSize = struct.calcsize(pointDataStr)

scanDataStr = "=dII" + 120 * "fffffI"
scanDataSize = struct.calcsize(scanDataStr)

print("pointSize = " +str(pointSize) + ", scanDataSize = " + str(scanDataSize) + ", imuDataSize = " + str(imuDataSize))

while True:
    # Recv data
    data, addr = sock.recvfrom(10000)
    print(f"Received data from {addr[0]}:{addr[1]}")

    msgType = struct.unpack("=I", data[:4])[0]
    print("msgType =", msgType)

    if msgType == 101:  # IMU Message
        length = struct.unpack("=I", data[4:8])[0]
        imuData = struct.unpack(imuDataStr, data[8:8+imuDataSize])
        imuMsg = IMUUnitree(imuData[0], imuData[1], imuData[2:6], imuData[6:9], imuData[9:12])

        print("An IMU msg is parsed!")
        print("\tstamp =", imuMsg.stamp, "id =", imuMsg.id)
        print("\tquaternion (x, y, z, w) =", imuMsg.quaternion)
        print("\tangular velocity =", imuMsg.angular_velocity)
        print("\tlinear acceleration =", imuMsg.linear_acceleration)
        print("\n")

    elif msgType == 102:  # Scan Message
        length = struct.unpack("=I", data[4:8])[0]
        stamp = struct.unpack("=d", data[8:16])[0]
        id = struct.unpack("=I", data[16:20])[0]
        validPointsNum = struct.unpack("=I", data[20:24])[0]
        scanPoints = []
        pointStartAddr = 24
        for i in range(validPointsNum):
            pointData = struct.unpack(pointDataStr, data[pointStartAddr: pointStartAddr+pointSize])
            pointStartAddr = pointStartAddr + pointSize
            point = PointUnitree(*pointData)
            scanPoints.append(point)
        scanMsg = ScanUnitree(stamp, id, validPointsNum, scanPoints)

        print("A Scan msg is parsed!")
        print("\tstamp =", scanMsg.stamp, "id =", scanMsg.id)
        print("\tScan size =", scanMsg.validPointsNum)
        print("\tfirst 10 points (x, y, z, intensity, time, ring) =")
        for i in range(min(10, scanMsg.validPointsNum)):
            point = scanMsg.points[i]
            print("\t", point.x, point.y, point.z, point.intensity, point.time, point.ring)
        print("\n")

sock.close()
