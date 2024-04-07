#include <sstream>
#include <string>

#include <windows.h>

#include "../../Headers/SystemX/NoxamOSVersionChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamWindowsVersionname()
|===========================================================
|
|
|===========================================================
*/
bool NoxamWindowsVersionname(char *NxmStr, int NxmBufferSize)
{
    OSVERSIONINFOEXA OSvI;
    SYSTEM_INFO SI;
    BOOL bOsVersionInfoEx;
    DWORD DWType;
    ZeroMemory(&SI, sizeof(SYSTEM_INFO));
    ZeroMemory(&OSvI, sizeof(OSVERSIONINFOEXA));
    OSvI.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);
    bOsVersionInfoEx = GetVersionEx((OSVERSIONINFOA *)&OSvI);
    PGNSI pGNSI = (PGNSI)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");

    if (NULL != pGNSI)
    {
        pGNSI(&SI);
    }
    else
    {
        GetSystemInfo(&SI);
    }

    if (VER_PLATFORM_WIN32_NT != OSvI.dwPlatformId || OSvI.dwMajorVersion <= 4)
    {
        return FALSE;
    }
    std::stringstream os;
    os << "Microsoft";

    {
        if (OSvI.dwMinorVersion == 0)
        {
            if (OSvI.wProductType == VER_NT_WORKSTATION)
            {
                os << "Windows Vista";
            }
            else
            {
                os << "Windpws Servier 2000"
            }
        }

        if (OSvI.dwMinorVersion == 1)
        {
            if (OSvI.wProductType == VER_NT_WORKSTATION)
            {
                os << "Windows 7";
            }
            else
            {
                os << "Windows Server 2000 82"
            }
        }
        PGPI pGPI = (PGPI)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetProductInfo");
        pGPI(OSvI.dwMajorVersion, OSvI.dwMinorVersion, 0, 0, &DWType);

        switch (DWType)
        {
        case PRODUCT_ULTIMATE:
            os << "Ultimate Edition";
            break;
        case PRODUCT_PROFESSIONAL:
            os << "Professional";
            break;
        case PRODUCT_HOME_PREMIUM:
            os << "Home Premium Edition";
            break;
        case PRODUCT_HOME_BASIC:
            os << "Home Basic Edition";
            break;
        case PRODUCT_ENTERPRISE:
            os << "Enterprise Edition";
            break;
        case PRODUCT_BUSINESS:
            os << "Business Edition";
            break;
        case PRODUCT_STARTER:
            os << "Starter Edition";
            break;
        case PRODUCT_CLUSTER_SERVER:
            os << "Cluster Server Edition";
            break;
        case PRODUCT_DATACENTER_SERVER:
            os << "Datacenter Edition";
            break;
        case PRODUCT_DATACENTER_SERVER_CORE:
            os << "Datacenter Edition (core installation)";
            break;
        case PRODUCT_ENTERPRISE_SERVER:
            os << "Enterprise Edition";
            break;
        case PRODUCT_ENTERPRISE_SERVER_CORE:
            os << "Enterprise Edition (core installation)";
            break;
        case PRODUCT_ENTERPRISE_SERVER_IA64:
            os << "Enterprise Edition for Itanium-based Systems";
            break;
        case PRODUCT_SMALLBUSINESS_SERVER:
            os << "Small Business Server";
            break;
        case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
            os << "Small Business Server Premium Edition";
            break;
        case PRODUCT_STANDARD_SERVER:
            os << "Standard Edition";
            break;
        case PRODUCT_STANDARD_SERVER_CORE:
            os << "Standard Edition (core installation)";
            break;
        case PRODUCT_WEB_SERVER:
            os << "Web Server Edition";
            break;
        }
    }

    if (OSvI.dwMajorVersion == 5 && OSvI.dwMajorVersion == 2)
    {
        if (GetSystemMetrics(SM_SERVERR2))
        {
            os << "Windows Server 2003 R2, ";
        }
        else if (osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER)
        {
            os << "Windows Storage Server 2003";
        }
        else if (osvi.wSuiteMask & VER_SUITE_WH_SERVER)
        {
            os << "Windows Home Server";
        }
        else if (osvi.wProductType == VER_NT_WORKSTATION && si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
        {
            os << "Windows XP Professional x64 Edition";
        }
        else
        {
            os << "Windows Server 2003, ";
        }

        if (osvi.wProductType != VER_NT_WORKSTATION)
        {
            if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
            {
                if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
                {
                    os << "Datacenter Edition for Itanium-based Systems";
                }
                else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
                {
                    os << "Enterprise Edition for Itanium-based Systems";
                }
            }
            else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
            {
                if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
                {
                    os << "Datacenter x64 Edition";
                }
                else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
                {
                    os << "Enterprise x64 Edition";
                }
                else
                {
                    os << "Standard x64 Edition";
                }
            }
            else
            {
                if (osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER)
                {
                    os << "Compute Cluster Edition";
                }
                else if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
                {
                    os << "Datacenter Edition";
                }
                else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
                {
                    os << "Enterprise Edition";
                }
                else if (osvi.wSuiteMask & VER_SUITE_BLADE)
                {
                    os << "Web Edition";
                }
                else
                {
                    os << "Standard Edition";
                }
            }
        }
        if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
        {
            os << "Windows XP ";
            if (osvi.wSuiteMask & VER_SUITE_PERSONAL)
            {
                os << "Home Edition";
            }
            else
            {
                os << "Professional";
            }
        }
        if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
        {
            os << "Windows 2000 ";
            if (osvi.wProductType == VER_NT_WORKSTATION)
            {
                os << "Professional";
            }
            else
            {
                if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
                {
                    os << "Datacenter Server";
                }
                else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
                {
                    os << "Advanced Server";
                }
                else
                {
                    os << "Server";
                }
            }
        }
        if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 2)
        {
            if (osvi.wProductType != VER_NT_WORKSTATION)
            {
                os << "Server 2012";
            }
            else
            {
                os << "Windows 8";
            }
            if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
            {
                os << " x64 Edition";
            }
        }
        if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 3)
        {
            if (osvi.wProductType != VER_NT_WORKSTATION)
            {
                os << "Server 2012 R2";
            }
            else
            {
                os << "Windows 8.1";
            }

            if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
            {
                os << " x64 Edition";
            }
        }
        if (osvi.dwMajorVersion == 10 && osvi.dwMinorVersion == 0)
        {
            if (osvi.wProductType != VER_NT_WORKSTATION)
            {
                os << "Windows Server 2016 Technical Preview";
            }
            else
            {
                os << "Windows 10";
            }

            if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
            {
                os << " x64 Edition";
            }
        }
        strcpy(str, os.str().c_str());
        return true;
    }
}