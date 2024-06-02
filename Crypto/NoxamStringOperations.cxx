


#include "../Headers/Crypto/NoxamStringOprations.hxx"


using namespace std;



/*
|===========================================================
|    NoxamSplitString()
|===========================================================
|
|
|===========================================================
*/
char** NoxamSplitString(char* NxmString, char* NxmDelimiter, int* NxmNumElements, bool NxmIgnoreEmpty)
{
    int NxmDelimeterLen = strlen(NxmDelimiter);
    int NxmStringLen = strlen(NxmString);
    int NxmDelimatch = 0;
    *NxmNumElements = 0;

    if (NxmDelimeterLen == 0 || NxmDelimeterLen >= NxmStringLen)
    {
        return (char**)NULL;
    }
    char* NxmInitial = NxmString;
    char** NxmBuffer = (char**)malloc(((NxmStringLen / NxmDelimeterLen) + 1) * sizeof(char*));
    ZeroMemory(NxmBuffer, ((NxmStringLen / NxmDelimeterLen) + 1) * sizeof(char*));

    for (int I = 0; I < NxmStringLen; I++)
    {
        if (NxmString[I] == NxmDelimiter[NxmDelimatch])
        {
            NxmDelimatch++;
        } else {

            NxmDelimatch = 0;

            if (NxmString[I] == NxmDelimiter[NxmDelimatch])
            {
                NxmDelimatch++;
            }
        }

        if (NxmDelimatch == NxmDelimeterLen)
        {
            NxmDelimatch = 0;
            char* NxmData = NxmInitial;
            int NxmDataLen = NxmString + I - NxmInitial + 1 - NxmDelimeterLen;
            NxmInitial = NxmString + I + 1;

            if (NxmDataLen == 0 && NxmIgnoreEmpty)
            {
                continue;
            }
            NxmBuffer[*NxmNumElements] = (char*)malloc(NxmDataLen + 1);

            if (NxmDataLen)
            {
                memcpy_s(NxmBuffer[*NxmNumElements], NxmDataLen, NxmData, NxmDataLen);
            }
            NxmBuffer[*NxmNumElements][NxmDataLen] = '\0';
            *NxmNumElements = *NxmNumElements + 1;
        }

        if (I == NxmStringLen - 1)
        {
            char* NxmData = NxmInitial;
            int NxmDataLen = NxmString + I - NxmInitial + 1;

            if (NxmDataLen == 0 && NxmIgnoreEmpty)
            {
                continue;
            }
            NxmBuffer[*NxmNumElements] = (char*)malloc(NxmDataLen + 1);

            if (NxmDataLen)
            {
                memcpy_s(NxmBuffer[*NxmNumElements], NxmDataLen, NxmData, NxmDataLen);
            }
            NxmBuffer[*NxmNumElements][NxmDataLen] = '/0';
            *NxmNumElements = *NxmNumElements + 1;
        }
    }
    return NxmBuffer;
}

/*
|===========================================================
|    NoxamFreeSplitStringBuffer()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeSplitStringBuffer(char** NxmBuffer, int NxmNumElements)
{
    for (int C = 0; C < NxmNumElements; C++)
    {
        free(NxmBuffer[C]);
    }
    free(NxmBuffer);
}

/*
|===========================================================
|    NoxamJoinSplitString()
|===========================================================
|
|
|===========================================================
*/
char *NoxamJoinSplitString(char** NxmStrings, int NxmNumelements, int *NxmOutputLength)
{
    int NxmSize = 0;

    for (int Q = 0; Q < NxmNumelements; Q++)
    {
        NxmSize += strlen(NxmStrings[Q]);
    }
    char* NxmFinalBuffer = (char*)malloc(NxmSize);
    NxmFinalBuffer[NxmSize] = 0;

    for (int W = 0, NxmIndex = 0; W < NxmNumelements; W++)
    {
        memcpy_s(NxmFinalBuffer + NxmIndex, NxmSize - NxmIndex, NxmStrings[W], strlen(NxmStrings[W]));
    }
    *NxmOutputLength = NxmSize;

    return NxmFinalBuffer;
}

/*
|===========================================================
|    NoxamFreeJoinStringBuffer()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeJoinStringBuffer(char* NxmBuffer)
{
    free(NxmBuffer);
}