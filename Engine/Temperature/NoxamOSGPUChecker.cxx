#include <iostream>
#include <string>

#include <windows.h>
#include <comdef.h>
#include <wbemidl.h>

#include "../../Headers/SystemX/NoxamOSGPUChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetGPUName()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetGPUName(char *NxmStr, int NxmBufferLength)
{
    ZeroMemory(NxmStr, NxmBufferLength);
    HRESULT HReS;
    HReS = CoInitializeEx(0, COINIT_MULTITHREADED);

    if (FAILED(HReS))
    {
        return 0;
    }
    HReS = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EDAC_NONE, NULL);

    if (FAILED(HReS))
    {
        CoUninitialize();
        return 0;
    }
    IWbemLocator *PLoC = NULL;
    HReS = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&PLoC);

    if (FAILED(HReS))
    {
        CoUninitialize();
        return 0;
    }
    IWbemServices *PSvC = NULL;
    HReS = PLoC->ConnectServer(_bstr_t(L"root\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &PSvC);

    if (FAILED(HReS))
    {
        PLoC->Release();
        CoUninitialize();
        return 0;
    }
    HReS = CoSetProxyBlanket(PSvC, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EDAC_NONE);

    if (FAILED(HReS))
    {
        PSvC->Release();
        PLoC->Release();
        CoUninitialize();
        return 0;
    }
    IEnumWbemClassObject *PEnumErator = NULL;
    HReS = PSvC->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_VideoController"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &PEnumErator);

    if (FAILED(HReS))
    {
        PSvC->Release();
        PLoC->Release();
        CoUninitialize();
        return 0;
    }
    IWbemClassObject *PCiSObJ = (IWbemClassObject *)malloc(sizeof(IWbemClassObject));
    ULONG URtRn;
    bool PSD = false;

    while (PEnumErator)
    {
        HRESULT HR = PEnumErator->Next(WBEM_INFINITE, 1, &PCiSObJ, &URtRn);

        if (0 == URtRn)
        {
            break;
        }
        VARIANT VtProp;
        HR = PCiSObJ->Get(L"Caption", 0, &VtProp, 0, 0);
        std::wstring wGpuName = VtProp.bstrVal;
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wGpuName[0], (int)wGpuName.size(), NULL, 0, NULL, NULL);
        std::string strTo(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &wGpuName[0], (int)wGpuName.size(), &strTo[0], size_needed, NULL, NULL);

        if (!PSD)
        {
            strcpy(NxmStr, strTo.c_str());
        }
        else
        {
            strcpy(NxmStr + size_needed, strTo.c_str());
        }
        PSD = TRUE;
        VariantClear(&VtProp);
    }
    PSvC->Release();
    PLoC->Release();
    PEnumErator->Release();
    PCiSObJ->Release();
    CoUninitialize();

    // free(PCiSObJ);

    return 0;
}
