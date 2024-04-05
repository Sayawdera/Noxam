#include <sstream>
#include <string>

#include <windows.h>

#include "../../Headers/SystemX/NoxamOSGetRAM.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetRam()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetRam(char *NxmStr, int NxmBufferLength)
{
    unsigned long long NxmRam;
    GetPhysicallyInstalledSystemMemory(&NxmRam);
    __itoa(NxmRam, NxmStr, 10);

    return true;
}
