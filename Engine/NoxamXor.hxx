#ifndef NOXAM_NOXAMXOR_HXX
#define NOXAM_NOXAMXOR_HXX

char* NoxamXorInputKey(char* NxmInput, char* NxmKey, int NxmInputLength, int NxmKeyLength);
void NoxamFreeXorResult(char* NxmInput);
char* NoxamXorGenerateKey(int NxmLength);
void NoxamXorFreeKey(char* NxmKey);


#endif NOXAM_NOXAMXOR_HXX
