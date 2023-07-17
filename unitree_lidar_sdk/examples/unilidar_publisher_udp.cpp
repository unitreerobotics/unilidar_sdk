/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/
#include <cstring>
#include "unitree_lidar_sdk.h"
#include "udp_handler.h"
using namespace unitree_lidar_sdk;

int main(int argc, char *argv[])
{
  // Config from terminal
  std::string serial_port;
  std::string destination_ip;
  unsigned short destination_port;

  if (argc == 2)
  {
    serial_port = argv[1];
    destination_ip = "127.0.0.1";
    destination_port = 12345;
  }
  else if (argc == 4)
  {
    serial_port = argv[1];
    destination_ip = argv[2];
    destination_port = std::atoi(argv[3]);
  }
  else
  {

    std::cout << "usage 1: this_executable <serial_port> <destination_ip> <destination_port>" << std::endl;
    std::cout << "usage 2: this_executable <serial_port> " << std::endl;
    std::cout << "   where the default sever_ip = 127.0.0.1, <destination_port> = 12345" << std::endl;

    std::cout << "Input Serial Port: ";
    std::cin >> serial_port;

    std::cout << "Input Destination IP: ";
    std::cin >> destination_ip;

    std::cout << "Input Destination Port: ";
    std::cin >> destination_port;
  }

  std::cout << "Unilidar Configuration: "
            << "\n\tserial_port = " << serial_port
            << "\n\tdestination_ip = " << destination_ip
            << "\n\tdestination_port = " << destination_port
            << std::endl;

  // Initialize Lidar Object
  UnitreeLidarReader *lreader = createUnitreeLidarReader();
  int cloud_scan_num = 1;
  if (lreader->initialize(cloud_scan_num, serial_port))
  {
    printf("Unilidar initialization failed! Exit here!\n");
    exit(-1);
  }
  else
  {
    printf("Unilidar initialization succeed!\n");
  }

  // Set Lidar Working Mode
  printf("Set Lidar working mode to: NORMAL ... \n");
  lreader->setLidarWorkingMode(NORMAL);

  // Print Lidar Version
  while (true)
  {
    if (lreader->runParse() == VERSION)
    {
      printf("lidar firmware version = %s\n", lreader->getVersionOfFirmware().c_str());
      break;
    }
    usleep(500);
  }
  printf("lidar sdk version = %s\n", lreader->getVersionOfSDK().c_str());

  // UDP
  UDPHandler client;
  client.CreateSocket();

  // Parse PointCloud and IMU data
  MessageType result;
  std::string version;
  PointCloudUnitree cloudMsg;
  ScanUnitree scanMsg;
  char buffer[10000];
  uint32_t length = 0;
  bool imuMsgSent = false;
  bool scanMsgSent = false;
  uint32_t imuMsgType = 101;
  uint32_t scanMsgType = 102;

  printf("Data type size: \n");
  printf("\tsizeof(PointUnitree) = %ld\n", sizeof(PointUnitree));
  printf("\tsizeof(ScanUnitree) = %ld\n", sizeof(ScanUnitree));
  printf("\tsizeof(IMUUnitree) = %ld\n", sizeof(IMUUnitree));
  
  while (true)
  {
    result = lreader->runParse(); // You need to call this function at least 1500Hz

    switch (result)
    {
    case NONE:
      break;

    case IMU:
      length = dataStructToUDPBuffer<IMUUnitree>(lreader->getIMU(), imuMsgType, buffer);
      client.Send(buffer, length, (char *)destination_ip.c_str(), destination_port); // 发送数据

      if (imuMsgSent == false)
      {
        imuMsgSent = true;
        printf("IMU message is sending!\n");
        printf("\tData format: | uint32_t msgType | uint32_t dataSize | IMUUnitree data |\n");
        printf("\tMsgType = %d, SentSize=%d, DataSize = %ld\n", imuMsgType, length, sizeof(IMUUnitree));
      }

      break;

    case POINTCLOUD:
      cloudMsg = lreader->getCloud();
      scanMsg.id = cloudMsg.id;
      scanMsg.stamp = cloudMsg.stamp;
      scanMsg.validPointsNum = cloudMsg.points.size();
      memcpy(scanMsg.points, cloudMsg.points.data(), cloudMsg.points.size() * sizeof(PointUnitree));

      length = dataStructToUDPBuffer<ScanUnitree>(scanMsg, scanMsgType, buffer);
      client.Send(buffer, length, (char *)destination_ip.c_str(), destination_port); // 发送数据

      if (scanMsgSent == false)
      {
        scanMsgSent = true;
        printf("Scan message is sending!\n");
        printf("\tData format: | uint32_t msgType| uint32_t dataSize | ScanUnitree data |\n");
        printf("\tMsgType = %d, SentSize=%d, DataSize = %ld\n", scanMsgType, length, sizeof(ScanUnitree));
      }
      break;

    default:
      break;
    }

    usleep(500);
  }

  return 0;
}
