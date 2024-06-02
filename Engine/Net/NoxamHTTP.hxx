#ifndef NOXAM_NOXAMHTTP_HXX
#define NOXAM_NOXAMHTTP_HXX


#include "NoxamSocket.hxx"

#define NOXAM_POST_BUFFER_LEN (1024 * 1024 * (7))
static char* NoxamResponseCodeName = "Noxam HTTP Response Code";

typedef struct NxmNameValuePair
{
    const char* NxmName;
    const char* NxmValue;

    NxmNameValuePair(char* NxmName, char* NxmValue)
    {
        NxmName = NxmName;
        NxmValue = NxmValue;
    }
} NxmNameValuePair;

char NoxamToHex(char NxmCode);
char* NoxamUrlEncode(char *NxmStr);
int NoxamHttQuery(char* NxmHost, char* NxmPath, NxmNameValuePair** NxmHeaders, NxmNameValuePair*** NxmResponseHeaders, char** NxmResponseData, int* NxmDataLength, bool NxmIsString, char* NxmProtocol, NxmNameValuePair** NxmPostData);
void NoxamFreeHTTPResponse(NxmNameValuePair** NxmHeaders, char* NxmData);
bool NoxamGetSocket(char* NxmHost, NxmSocetAddressIn* Address);
#endif NOXAM_NOXAMHTTP_HXX
