#ifndef NOXAM_NOXAMSOCKET_HXX
#define NOXAM_NOXAMSOCKET_HXX

#include <ws2tcpip.h>
#include <winsock2.h>


#pragma comment(lib, "ws2_32.lib")


bool NoxamGetSocketAddress(char* NxmHost, sockaddr_in* NxmAddress);


#endif NOXAM_NOXAMSOCKET_HXX
