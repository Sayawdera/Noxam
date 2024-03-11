#include <stdio.h
#include <string>
#include <windows.h>

#include "../../Headers/Net/NoxamSocket.hxx"
#include "../../Headers/Net/NoxamHTTP.hxx"
#include "../../Headers/Crypto/NoxamStringOprations.hxx"

using namespace std;

/*
|===========================================================
|    NoxamToHex()
|===========================================================
|
|
|===========================================================
*/
char NoxamToHex(char NxmCode)
{

}

/*
|===========================================================
|    NoxamUrlEncode()
|===========================================================
|
|
|===========================================================
*/
char* NoxamUrlEncode(char *NxmStr)
{

}

/*
|===========================================================
|    NoxamHttQuery()
|===========================================================
|
|
|===========================================================
*/
int NoxamHttQuery(char* NxmHost, char* NxmPath, NxmNameValuePair** NxmHeaders, NxmNameValuePair*** NxmResponseHeaders, char** NxmResponseData, int* NxmDataLength, bool NxmIsString, char* NxmProtocol, NxmNameValuePair** NxmPostData)
{

}


/*
|===========================================================
|    NoxamFreeHTTPResponse()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeHTTPResponse(NxmNameValuePair** NxmHeaders, char* NxmData)
{

}


/*
|===========================================================
|    NoxamGetSocket()
|===========================================================
|
|
|===========================================================
*/
bool NoxamGetSocket(char* NxmHost, NxmSocetAddressIn* Address)
{

}