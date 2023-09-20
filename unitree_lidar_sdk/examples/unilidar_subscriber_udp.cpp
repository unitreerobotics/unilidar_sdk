/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#include "unitree_lidar_sdk.h"

#include "udp_handler.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace unitree_lidar_sdk;
using namespace std;

int main(int argc, char *argv[])
{
  // Config from terminal
  unsigned short port;

  if (argc == 1){
    std::cout << "Usage: this_executable <udp_port>" << std::endl;
    port = 12345;
    sleep(1);
  }
  else if (argc == 2)
  {
    port = std::atoi(argv[1]);
  }
  else
  {
    std::cout << "Usage: this_executable <udp_port>" << std::endl;
    std::cout << "Input UDP Port: ";
    std::cin >> port;
  }

  std::cout << "Unilidar Configuration: "
            << "\n\tport = " << port
            << std::endl;

  UDPHandler server(port);
  server.CreateSocket();
  server.Bind();

  char recv_buf[10000];
  sockaddr_in client_addr;
  memset(&client_addr, 0, sizeof(client_addr));

  ScanUnitree scanMsg;
  IMUUnitree imuMsg;
  uint32_t msgType;
  uint32_t length;
  while (true)
  {
    int len = server.Recv(recv_buf, sizeof(recv_buf), &client_addr);
    if (len <= 0)
    {
      cout << "recv error" << endl;
      break;
    }
    cout << "received data from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;

    memcpy(&msgType, recv_buf, 4);

    cout << "msgType = " << msgType << endl;

    if (msgType == 101)
    {
      memcpy(&length, recv_buf + 4, 4);
      memcpy(&imuMsg, recv_buf + 8, sizeof(IMUUnitree));

      printf("An IMU msg is parsed!\n");
      printf("\tstamp = %f, id = %d\n", imuMsg.stamp, imuMsg.id);
      printf("\tquaternion (x, y, z, w) = [%.4f, %.4f, %.4f, %.4f]\n",
             imuMsg.quaternion[0], imuMsg.quaternion[1],
             imuMsg.quaternion[2], imuMsg.quaternion[3]);
      printf("\n");
    }
    else if (msgType == 102)  // 4+4+2896 bytes, which stands for [msgType, dataSize, data of ScanUnitree]
    {
      memcpy(&length, recv_buf + 4, 4);
      memcpy(&scanMsg, recv_buf + 8, sizeof(ScanUnitree));

      printf("A Scan msg is parsed! \n");
      printf("\tstamp = %f, id = %d\n", scanMsg.stamp, scanMsg.id);
      printf("\tScan size  = %d \n", scanMsg.validPointsNum);
      printf("\tfirst 10 points (x,y,z,intensity,time,ring) = \n");
      for (int i = 0; i < 10; i++)
      { // print the first 10 points
        printf("\t  (%f, %f, %f, %f, %f, %d)\n",
               scanMsg.points[i].x,
               scanMsg.points[i].y,
               scanMsg.points[i].z,
               scanMsg.points[i].intensity,
               scanMsg.points[i].time,
               scanMsg.points[i].ring);
      }
      printf("\n");
    }
  }

  server.Close();
  return 0;
}