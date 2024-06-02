#ifndef NOXAM_NOXAMWEBSAFEENCRYPTION_HXX
#define NOXAM_NOXAMWEBSAFEENCRYPTION_HXX


#include "../NoxamXor.hxx"


char* NoxamGetEncodedXorResult(char* NxmInput, char* NxmKey, int NxmInputLength, int NxmKeyLength, char** NxmOutputKey);
char* NoxamGetDecodedXorResult(char* NxmInput, char* NxmKey, int* NxmOutputLength);

void NoxamFreeEncodedXorResult(char* NxmInput, char* NxmKey);
void NoxamFreeDecodedXorResult(char* NxmInput);

#endif NOXAM_NOXAMWEBSAFEENCRYPTION_HXX
