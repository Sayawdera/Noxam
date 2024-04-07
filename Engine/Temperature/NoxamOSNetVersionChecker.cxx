#include <sstream>
#include <string>

#include <windows.h>

#include "../../Headers/SystemX/NoxamOSNetVersionChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamQUeryKey()
|===========================================================
|
|
|===========================================================
*/
bool NoxamQUeryKey(HKEY HKeY, char *NetVer)
{
    TCHAR AchKey[NOXAM_KEY_LENGTH];
    DWORD CbName;
    TCHAR AchClass[MAX_PATH] = TEXT("");
    DWORD CchClassName = MAX_PATH;
    DWORD CSubKeys = 0;
    DWORD CbMaxSubKeys;
    DWORD CchMaxClass;
    DWORD CValues;
    DWORD CchMaxValue;
    DWORD CbMaxValueData;
    DWORD CbSecurityDescriptor;
    FILETIME FTLastWriteTime;
    DWORD I, RetCode;
    TCHAR AchValue[NOXAM_KEY_LENGTH];
    DWORD CchValue = NOXAM_KEY_LENGTH;

    RetCode = RegQueryInfoKey(HKeY, AchClass, &CchClassName, NULL, &CSubKeys, &CbMaxSubKeys, &CchMaxClass, &CValues, &CchMaxValue, &CbMaxValueData, &CbSecurityDescriptor, &FTLastWriteTime);

    if (CSubKeys)
    {
        CbName = NOXAM_KEY_LENGTH;
        RetCode = RegEnumKeyEx(HKeY, CSubKeys - 1, AchKey, &CbName, NULL, NULL, NULL, &FTLastWriteTime);

        if (RetCode == ERROR_SUCCESS)
        {
            std::wstring WArchKey = AchKey;
            int size_needed = WideCharToMultiByte(CP_UTF8, 0, &WArchKey[0], (int)WArchKey.size(), NULL, 0, NULL, NULL);
            std::string strTo(size_needed, 0);
            WideCharToMultiByte(CP_UTF8, 0, &WArchKey[0], (int)WArchKey.size(), &strTo[0], size_needed, NULL, NULL);
            strcpy(NetVer, strTo.c_str());

            return TRUE;
        }
    }

    return FALSE;
}

/*
|===========================================================
|    NoxamGetLastestNetInstalled()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetLastestNetInstalled(char *NxmStr, int NxmBufferLength)
{
    HKEY HTestKey;
    char *NetVer = (char *)malloc(NxmBufferLength);

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\NET Framework Setup\\NDP"), 0, KEY_READ, &HTestKey) == ERROR_SUCCESS)
    {
        NoxamQUeryKey(HTestKey, NetVer);
        strcpy(NxmStr, NetVer);
    }
    RegCloseKey(HTestKey);
    free(NetVer);

    return TRUE;
}