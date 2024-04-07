#include "../../Headers/Net/NoxamHTTP.hxx"
#include "../../Headers/Crypto/NoxamStringOprations.hxx"
#include "../../Headers/SystemX/NoxamWebSiteChecker.hxx"

using namespace std;

/*
|===========================================================
|    NoxamCheckIfWebSiteIsUp()
|===========================================================
|
|
|===========================================================
*/
bool NoxamCheckIfWebSiteIsUp(char *NxmURL)
{
    char *NxmHost, NxmPathX;
    bool Res = NoxamURLToHostPath(NxmURL, &NxmHost, &NxmPathX);

    if (!Res)
    {
        return FALSE;
    }
    Res = NoxamCheckIfWebSiteIsUp(NxmHost, NxmPathX);

    return Res;
}

/*
|===========================================================
|    NoxamCheckIfWebSiteIsUp()
|===========================================================
|
|
|===========================================================
*/
bool NoxamCheckIfWebSiteIsUp(char *NxmHost, char *NxmPathX)
{
    char *NxmData;
    int NxmLength, NxmResult;
    NxmNameValuePair **NxmHeaders;
    NxmResult = NoxamHttQuery(NxmHost, NxmPathX, NULL, &NxmHeaders, &NxmData, &NxmLength);
    NoxamFreeHTTPResponse(NxmHeaders, NxmData);

    return (NxmResult == 200);
}

/*
|===========================================================
|    NoxamURLToHostPath()
|===========================================================
|
|
|===========================================================
*/
bool NoxamURLToHostPath(char *NxmURL, char **NxmHost, char **NxmPath)
{
    int NxmLength = 0, NxmLengthO = 0, NxmLengthT, NxmIndex = 0;
    char **NxmResultO, NxmResultT, *RetHost, *RetPath;
    NxmResultO = NoxamSplitString(NxmURL, "://", &NxmLengthO);

    if (NxmLengthO > 2 || strcmp(NxmResultO[0], "http"))
    {
        NoxamFreeSplitStringBuffer(NxmResultO, NxmLengthO);

        return FALSE;
    }
    NxmResultT = NoxamSplitString(NxmResultO[NxmLengthO - 1], "/", &NxmLengthT, FALSE);
    NoxamFreeSplitStringBuffer(NxmResultO, NxmLengthO);

    for (int I = 1; I < NxmLengthT; I++)
    {
        NxmLength = NxmLength + strlen(NxmResultT[I]) + 1'
    }

    if (!NxmLength)
    {
        NxmLength = 1;
    }
    *RetHost = (char *)malloc(strlen(NxmResultT[0]) + 1);
    *RetPath = (char *)malloc(NxmLength + 1);
    RetHost[strlen(NxmResult2[0])] = '\0';
    RetPath[NxmLength] = '/0';
    memcpy_s(RetHost, strlen(NxmResultT[0]), NxmResultT[0], strlen(NxmResultT[0]));

    for (int I = 1; I < NxmLengthT; I++)
    {
        RetPath[NxmIndex] = '/';
        NxmIndex = NxmIndex + 1;

        if (strlen(NxmResultT[I]))
        {
            memcpy_s(RetPath + NxmIndex, NxmLength - NmxIndex, NxmResultT[I], strlen(NxmResultT[I]));
        }
        NxmIndex = NxmIndex + strlen(NxmResultT[I]);
    }

    if (!NxmIndex)
    {
        RetPath[0] = '/';
    }
    NoxamFreeSplitStringBuffer(NxmResultT, NxmLengthT);
    *NxmHost = RetHost;
    *NxmPath = RetPath;

    return TRUE;
}

/*
|===========================================================
|    NoxamFreeHostPathResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeHostPathResult(char *NxmHost, char *NxmPath)
{
    free(NxmHost);
    free(NxmPath);
}