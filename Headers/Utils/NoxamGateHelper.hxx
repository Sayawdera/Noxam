#ifndef NOXAM_NOXAMGATEHELPER_HXX
#define NOXAM_NOXAMGATEHELPER_HXX

#include <string>



char* NoxamGetBotID();
char* NoxamSendCommandWithDecodeResponse(char* NxmCommand);

void NoxamSetBoldID(char* NxmNewID);
void NoxamFreeDecodeResponse(char* NxmResponse);




#endif NOXAM_NOXAMGATEHELPER_HXX
