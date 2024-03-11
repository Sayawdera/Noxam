#ifndef NOXAM_NOXAMOSVERSIONCHECKER_HXX
#define NOXAM_NOXAMOSVERSIONCHECKER_HXX

#define NOXAM_PRODUCT_PROFESSIONAL 0x00000030
#define NOXAM_VER_SUITE_WH_SERVER 0x00008000

typedef void (WINAPI *NXMPGSNSI)(NXMLPSYSTEMINFO);
typedef BOOL(WINAPI *NXMPGPI)(NXMDWORD, NXMDWORD, NXMDWORD, NXMDWORD, PNXMDWORD);


bool NoxamWindowsVersionname(char* NxmStr, int NxmBufferSize);

#endif NOXAM_NOXAMOSVERSIONCHECKER_HXX
