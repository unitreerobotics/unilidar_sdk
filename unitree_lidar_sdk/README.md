# Unitree Lidar SDK

## Introduction
This package is a cmake package, which is specially used for running `Unitree LiDAR L1`.

The functions that this package can provide includes:
- Parse the raw data transmitted from the lidar hardware, and convert it into pointcloud and IMU data
- Get the pointcloud data
- Get the IMU data

The output pointcloud defaultly uses a self-defined data type so that this SDK doesn't rely too much on external dependencies. In other case,
- if you are used to use [Point Cloud Library](https://pointclouds.org/), you can use the header `unitree_lidar_sdk_pcl.h` to transform our pointcloud to PCL format;
- if you wish to directly use a [ROS](https://www.ros.org/) package, you are also able to utilize our ROS pacakge for this lidar.

## Dependency
We have verified that this package can successfully run under this environment:
- `Ubuntu 20.04` 

This SDK hardly depends on any external dependencies.
But if you want to use PCL cloud format, you need to install one. 

## Configure

Connect your lidar to your computer with a USB cable, then confirm your serial port name for lidar:
```
$ ls /dev/ttyUSB*
/dev/ttyUSB0
```

The default serial port name is `/dev/ttyUSB0`.
If it is not the default one, you need to modify the configuration parameter in `example_lidar.cpp`.

## Build

You can build this program as a cmake project:
```
cd unitree_lidar_sdk

mkdir build

cd build

cmake .. && make -j2
```

## Run
Directly run the example:
```
../bin/example_lidar
```

The output is like this:
```
$ ../bin/example_lidar 
lidar firmware version = 0.3.2+230511
lidar sdk version = 1.0.3

Dirty Percentage = 5.145833 %
Dirty Percentage = 4.166667 %
Dirty Percentage = 4.166667 %

Turn on all the LED lights ...
Turn off all the LED lights ...
Set LED mode to: FORWARD_SLOW ...
Set LED mode to: REVERSE_SLOW ...
Set LED mode to: SIXSTAGE_BREATHING ...

Set Lidar working mode to: NORMAL_MODE ... 

An IMU msg is parsed!
	stamp = 1683874160.559222, id = 729
	quaternion (x, y, z, w) = [0.0131, -0.0091, 0.6888, -0.7225]

An IMU msg is parsed!
	stamp = 1683874160.564979, id = 121
	quaternion (x, y, z, w) = [0.0102, -0.0093, 0.7099, -0.7018]

An IMU msg is parsed!
	stamp = 1683874160.568425, id = 122
	quaternion (x, y, z, w) = [0.0118, -0.0096, 0.7099, -0.7018]

An IMU msg is parsed!
	stamp = 1683874160.573472, id = 123
	quaternion (x, y, z, w) = [0.0126, -0.0093, 0.7098, -0.7018]

An IMU msg is parsed!
	stamp = 1683874160.577348, id = 124
	quaternion (x, y, z, w) = [0.0128, -0.0093, 0.7099, -0.7018]

A Cloud msg is parsed! 
	stamp = 1683874145.535888, id = 1
	cloud size  = 278
	first 10 points (x,y,z,intensity,time,ring) = 
	  (-0.029885, -0.136897, 0.000448, 88.000000, 0.000000, 0)
	  (-0.035384, -0.171399, 0.005140, 91.000000, 0.000023, 0)
	  (-0.043000, -0.219542, 0.012437, 127.000000, 0.000046, 0)
	  (-0.054879, -0.294965, 0.024572, 132.000000, 0.000069, 0)
	  (-0.055288, -0.301204, 0.033170, 106.000000, 0.000093, 0)
	  (-0.054542, -0.300348, 0.041173, 101.000000, 0.000116, 0)
	  (-0.053764, -0.299285, 0.049148, 99.000000, 0.000139, 0)
	  (-0.056123, -0.318406, 0.060981, 92.000000, 0.000162, 0)
	  (-0.055230, -0.316827, 0.069422, 91.000000, 0.000185, 0)
	  (-0.051257, -0.294854, 0.072849, 128.000000, 0.000208, 0)
	  ...
```

Here, we print the first 10 points of the pointcloud message and the quaternion of the IMU message.

**Notice**:
- In Ubuntu, accessing a serial port device requires the appropriate permissions. If your C++ program does not have sufficient permissions to access the serial port device, you will get a **"Permission denied"** error.
- To solve this error, you can use the following command to add the current user to the dialout group:
```
sudo usermod -a -G dialout $USER
```
- After adding the user to the dialout group, you need to log out and log back in for the changes to take effect.


## How To Parse Point Cloud From MavLink Messages

If you want to parse point cloud from MavLink Messages which are acquired from serial directly, you can refer to this document.
- [HowToParsePointCloudAndIMUDataFromMavLinkMessages.md](./doc/HowToParsePointCloudAndIMUDataFromMavLinkMessages.md)

## Version History

### v1.0.0 (2023.05.04)
- Support firmware version: 0.3.1

### v1.0.1 (2023.05.05)
- Support firmware version: 0.3.1
- Add support of setting lidar working mode, e.g. `NORMAL_MODE` and `STANDBY_MODE`
- Add support of LED lights

### v1.0.2 (2023.05.11)
- Support firmware version: 0.3.2

### v1.0.3 (2023.05.12)
- Support firmware version: 0.3.2
- Add support of getting the percentage of removed dirty points

### v1.0.4 (2023.05.30)
- Support firmware version: 1.0.1

### v1.0.5 (2023.06.05)
- Support firmware version: 1.0.1
- Update default `rotate_yaw_bias` to calibrated value `-38.5` degree.
- Update `README.md` with notice to solve the "Permission denied" error while opening serial port.

### v1.0.6 (2023.06.19)
- Support firmware version: 1.0.1
- Modify the `initialize()` function to check whether the specified serial port exist. If the serial port name does not exist, initialization fails and `return -1` rather than throw out an error unexpectedly。
- Add z bias to lidar basis plane

### v1.0.7 (2023.06.21)
- Support firmware version: 1.0.1
- Add coordinate system definition in readme
- Modified readme of `unitree_lidar_ros` and `unitree_lidar_ros2`

### v1.0.8 (2023.06.28)
- Support firmware version: 1.0.1
- Solve the dependency problem --- `cannot find -llz4`
- Add mavlink headers for optional use

### v1.0.9 (2023.06.30)
- Support firmware version: 1.0.1
- Delete the date postfix of firmware version
- Improve support of setting lidar working mode, which can switch between `NORMAL_MODE` and `STANDBY_MODE`

### v1.0.10 (2023.07.17)
- Support firmware version: 1.0.1
- Add a UDP publisher written in C++, which can publish lidar data to a specified IP address and port
- Add a UDP subscriber example written in C++, which is able to subscibe scan and imu data mentioned above
- Add a UDP subscriber example written in Python, which is able to subscibe scan and imu data mentioned above
- Add a compiled install package for Windows user, though which you can acquire lidar data in windows.

### v1.0.11 (2023.07.27)
- Add a instruction document for how to parse point cloud and imu data from mavlink messages directly.
- The document is `HowToParsePointCloudAndIMUDataFromMavLinkMessages.md`

### v1.0.12 (2023.09.20)
- Add support of UDP interface, which can parse original bytes from a specified UDP port and send commands to lidar ip and port.
- Update `unitree_lidar_ros`

### v1.0.13 (2023.10.09)
- Modify the serial port reading method in `unitree_lidar_sdk`. It will block when you call `runParse()` function, waiting for the serial port to have bytes and then reading the data once.
- Support Serial-to-UDP adapter board

### v1.0.14 (2023.10.30)
- Repair occasional segmentation fault when using serial-to-udp board.

### v1.0.15 (2024.01.04)
- Modify default lidar and local ip address in `example_lidar_udp.cpp`

### v1.0.16 (2024.02.18)
- Add a function to close UDP connection
- Set the timeout to 1 second for `initializeUDP()`