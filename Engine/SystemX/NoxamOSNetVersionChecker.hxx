#ifndef NOXAM_NOXAMOSNETVERSIONCHECKER_HXX
#define NOXAM_NOXAMOSNETVERSIONCHECKER_HXX

#define NOXAM_KEY_LENGTH 255
#define NOXAM_VALUE_NAME 16383

#pragma comment(lib, "Advapi32.lib");

bool NoxamQUeryKey(HKEY HKeY, char *NetVer);

bool NoxamGetLastestNetInstalled(char *NxmStr, int NxmBufferLength);

#endif NOXAM_NOXAMOSNETVERSIONCHECKER_HXX
