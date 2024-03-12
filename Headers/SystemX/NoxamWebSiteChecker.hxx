#ifndef NOXAM_NOXAMWEBSITECHECKER_HXX
#define NOXAM_NOXAMWEBSITECHECKER_HXX


bool NoxamCheckIfWebSiteIsUp(char* NxmURL);
bool NoxamCheckIfWebSiteIsUp(char* NxmURL, char* NxmPath);
bool NoxamURLToHostPath(char* NxmURL, char** NxmHost, char** NxmPath);
void NoxamFreeHostPathResult(char* NxmHost, char* NxmPath);



#endif NOXAM_NOXAMWEBSITECHECKER_HXX
