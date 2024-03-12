#ifndef NOXAM_NOXAMPROCCESS_HXX
#define NOXAM_NOXAMPROCCESS_HXX


char* NoxamGetProccessResult(char* NxmProccessName, char* NxmArgs, int* NxmSize);
void NoxamFreeProccessResult(char* NxmData);
bool NoxamStartProccess(char* NxmProccessName, char* NxmArgs);

#endif NOXAM_NOXAMPROCCESS_HXX
