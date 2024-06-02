#include <sstream>
#include <string>

#include <windows.h>

#include "../Headers/SystemX/NoxamOSCPUChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetCPUName()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetCPUName(char *NxmStr, int NxmBufferLenght)
{
    int NxmCPUInfo[4] = {-1};
    __cpuid(NxmCPUInfo, 0x80000000);
    unsigned int NExidS = NxmCPUInfo[0];
    char CPUBrandString[0x45] = {0};

    for (unsigned int X = 0x80000000; X <= NExidS; ++X)
    {
        __cpuid(NxmCPUInfo, X);

        if (X == 0x80000002)
        {
            memcpy(CPUBrandString, NxmCPUInfo, sizeof(NxmCPUInfo));
        }
        else if (X == 0x80000003)
        {
            memcpy(CPUBrandString + 16, NxmCPUInfo, sizeof(NxmCPUInfo));
        }
        else if (X == 0x80000004)
        {
            memcpy(CPUBrandString + 32, NxmCPUInfo, sizeof(NxmCPUInfo));
        }
    }
    strcpy(NxmStr, CPUBrandString);

    return true;
}