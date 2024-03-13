#include <windows.h>
#include "../../Headers/Crypto/NoxamWebSafeEncryption.hxx"
#include "../../Headers/Crypto/NoxamURLEncoding.hxx"

using namespace std;


/*
|===========================================================
|    NoxamGetEncodedXorResult()
|===========================================================
|
|
|===========================================================
*/
char* NoxamGetEncodedXorResult(char* NxmInput, char* NxmKey, int NxmInputLength, int NxmKeyLength, char** NxmOutputKey)
{
    char* NxmXoredInput = NoxamXorInputKey(NxmInput, NxmKey, NxmInputLength, NxmKeyLength);
    char* NxmEncoded = NoxamURLEncode(NxmXoredInput, NxmInputLength);
    *NxmOutputKey = NoxamURLEncode(NxmKey, NxmKeyLength);
    NoxamFreeXorResult(NxmXoredInput);

    return NxmEncoded;
}

/*
|===========================================================
|    NoxamGetDecodedXorResult()
|===========================================================
|
|
|===========================================================
*/
char* NoxamGetDecodedXorResult(char* NxmInput, char* NxmKey, int* NxmOutputLength)
{
    int NxmInputLen, NxmKeyLength;
    char* NxmDecodeKey = NoxamURLDecode(NxmKey, &NxmKeyLength);
    char* NxmDecodeInput = NoxamURLDecode(NxmInput, &NxmInputLen);
    char* NxmOutput = NoxamXorInputKey(NxmDecodeInput, NxmDecodeKey, NxmInputLen, NxmKeyLength);
    NoxamFreeURLDecodeResult(NxmDecodeInput);
    NoxamFreeURLDecodeResult(NxmDecodeKey);
    *NxmOutputLength = NxmInputLen;

    return NxmOutput;
}


/*
|===========================================================
|    NoxamFreeEncodedXorResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeEncodedXorResult(char* NxmInput, char* NxmKey)
{
    NoxamFreeURLEncodeResult(NxmInput);
    NoxamFreeURLEncodeResult(NxmKey);
}

/*
|===========================================================
|    NoxamFreeDecodedXorResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeDecodedXorResult(char* NxmInput)
{
    NoxamFreeXorResult(NxmInput);
}