#include <sstream>
#include <string>

#include <windows.h>

#include "../Headers/SystemX/NoxamOSHWidChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetHWid()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetHWid(char *NxmStr, int NxmBufferLength)
{
    HW_PROFILE_INFOA HpI;
    ZeroMemory(&HpI, sizeof(HW_PROFILE_INFOA));
    GetCurrentHwProfileA(&HpI);
    strcpy(NxmStr, HpI.szHwProfileGuid);
    return TRUE;
}