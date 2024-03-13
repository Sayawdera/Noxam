


#include "../../Headers/Crypto/NoxamURLEncoding.hxx"

using namespace std;


/*
|===========================================================
|    NoxamURLEncode()
|===========================================================
|
|
|===========================================================
*/
char* NoxamURLEncode(char* NxmInput, int NxmLength)
{
    int NxmInputLen = NxmLength;
    int NxmOutputLen = NxmInputLen * 3;
    char* NxmOutput = (char*)malloc(NxmOutputLen + 1);
    char* NxmRetOutput = NxmOutput;
    NxmOutput[NxmOutputLen] = '/0';

    for (int R = 0; R < NxmInputLen; R++)
    {
        *NxmOutput++ = '%';
        *NxmOutput++ = NoxamHexTable[(NxmInput[R] & 0xF0) >> 4];
        *NxmOutput++ = NoxamHexTable[(NxmInput[R] & 0xF0)];
    }

    return NxmRetOutput;
}

/*
|===========================================================
|    NoxamURLDecode()
|===========================================================
|
|
|===========================================================
*/
char* NoxamURLDecode(char* NxmInput, int* NxmOutputLength)
{
    int NxmInputLen = strlen(NxmInput);

    if ((NxmInputLen % 3) != 0)
    {
        return NULL;
    }
    int NxmOutputLen = NxmInputLen / 3;
    *NxmOutputLength = NxmOutputLen;
    char* NxmOutput = (char*)malloc(NxmOutputLen + 1);
    NxmOutput[NxmOutputLen] = '/0';
    char* NxmWorkingInput = NxmInput;
    char* NxmRetOutput = NxmOutput;

    for (int I = 0; I < NxmOutputLen; I++)
    {
        NxmWorkingInput++;
        char NxmCharValue = 0;
        char NxmWorking = *NxmWorkingInput++;
        char NxmActual;

        for (NxmActual = 0; NxmActual < 16; NxmActual++)
        {
            if (NoxamHexTable[NxmActual] == NxmWorking)
            {
                break;
            }
        }
        NxmCharValue += (NxmActual << 4);
        NxmWorking = *NxmWorkingInput++;

        for (NxmActual = 0; NxmActual < 16; NxmActual++)
        {
            if (NoxamHexTable[NxmActual] == NxmWorking)
            {
                break;
            }
        }
        NxmCharValue += NxmActual;
        *NxmOutput++ = NxmCharValue;
    }
    return NxmRetOutput;
}

/*
|===========================================================
|    NoxamFreeURLEncodeResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeURLEncodeResult(char* NxmInput)
{
    free(NxmInput);
}

/*
|===========================================================
|    NoxamFreeURLDecodeResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeURLDecodeResult(char* NxmInput)
{
    free(NxmInput);
}