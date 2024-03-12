#ifndef NOXAM_NOXAMURLENCODING_HXX
#define NOXAM_NOXAMURLENCODING_HXX

#include <windows.h>

static char* NoxamHexTable = "0123456789ABCDEF";

char* NoxamURLEncode(char* NxmInput, int NxmLength);
char* NoxamURLDecode(char* NxmInput, int NxmOutputLength);

void NoxamFreeURLEncodeResult(char* NxmInput);
void NoxamFreeURLDecodeResult(char* NxmInput);

#endif NOXAM_NOXAMURLENCODING_HXX
