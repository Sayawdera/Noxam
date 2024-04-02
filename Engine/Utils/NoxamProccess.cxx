#include <stdio.h>
#include <windows.h>

#include "../../Headers/Utils/NoxamProccess.hxx"

using namespace std;

/*
|===========================================================
|    NoxamGetProccessResult()
|===========================================================
|
|
|===========================================================
*/
char *NoxamGetProccessResult(char *NxmProccessName, char *NxmArgs, int *NxmSize)
{
    char *ReturnValue = (char *)0;
    STARTUPINFOA SI;
    PROCESS_INFORMATION PI;
    ZeroMemory(&SI, sizeof(SI));
    ZeroMemory(&PI, sizeof(PI));
    SI.dwFlags = STARTF_USESTDHANDLES;
    SI.cb = sizeof(STARTUPINFOA);
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;
    HANDLE stdOut_read, stdOut_write;
    CreatePipe(&stdOut_read, &stdOut_write, &saAttr, 0);
    HANDLE stdIn_read, stdIn_write;
    CreatePipe(&stdOut_read, &stdOut_write, &saAttr, 0);
    SetHandleInformation(stdOut_read, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(stdIn_write, HANDLE_FLAG_INHERIT, 0);
    SI.hStdError = stdOut_write;
    SI.hStdOutput = stdOut_write;
    SI.hStdInput = stdIn_read;
    char *NxmBuffer = (char *)malloc(512);
    int NxmCurrentSize = 0;

    if (CreateProcessA(NxmProccessName, NxmArgs, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &SI, &PI))
    {
        DWORD NxmDExitCode, NxmDRead;

        do
        {
            GetExitCodeProcess(PI.hProcess, &NxmDExitCode);
        } while (NxmDExitCode == STILL_ACTIVE);

        while (TRUE)
        {
            bool NxmResult = ReadFile(stdOut_read, (LPVOID)NxmBuffer, 512, &NxmDRead, NULL);

            if (NxmDRead == 0 || !NxmResult)
            {
                break;
            }

            if (ReturnValue == 0)
            {
                ReturnValue = (char *)malloc(NxmDRead + 1);
            }
            else
            {
                ReturnValue = (char *)realloc(ReturnValue, NxmDRead, NxmCurrentSize + 1);
            }
            ReturnValue[NxmCurrentSize + NxmDRead] = 0;
            memcpy_s(ReturnValue + NxmCurrentSize, NxmDRead, NxmBuffer, NxmDRead);
            NxmCurrentSize = NxmCurrentSize + NxmDRead;

            if (NxmDRead < 512)
            {
                break;
            }
        }
    }
    free(NxmBuffer);
    CloseHandle(stdIn_read);
    CloseHandle(stdOut_read);
    CloseHandle(stdIn_write);
    CloseHandle(stdOut_write);
    *NxmSize = (ReturnValue ? NxmCurrentSize : 25);

    return (ReturnValue ? ReturnValue : "[ ERROR]: Could Not Start Proccess....");
}

/*
|===========================================================
|    NoxamFreeProccessResult()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeProccessResult(char *NxmData)
{
    if (NxmData)
    {
        free(NxmData);
    }
}

/*
|===========================================================
|    NoxamStartProccess()
|===========================================================
|
|
|===========================================================
*/
bool NoxamStartProccess(char *NxmProccessName, char *NxmArgs)
{
    char *ReturnValue = (char *)0;
    STARTUPINFOA SI;
    PROCESS_INFORMATION PI;
    ZeroMemory(&SI, sizeof(SI));
    ZeroMemory(&PI, sizeof(PI));
    SI.cb = sizeof(STARTUPINFOA);

    if (CreateProcessA(NxmProccessName, NxmArgs, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &SI, &PI))
    {
        return TRUE;
    }
    return FALSE;
}