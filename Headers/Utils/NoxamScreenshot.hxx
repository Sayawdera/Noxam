#ifndef NOXAM_NOXAMSCREENSHOT_HXX
#define NOXAM_NOXAMSCREENSHOT_HXX



char* NoxamCaptureScreenShot(int* NxmLength);
bool NoxamSendScreenShot(char* NxmDestination, unsigned short NxmPORT, char* NxmData, int NxmDataLength, char* NxmBotID);
void NoxamFreeScreenShot(char*)



#endif NOXAM_NOXAMSCREENSHOT_HXX
