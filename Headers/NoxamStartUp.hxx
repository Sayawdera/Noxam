#ifndef NOXAM_NOXAMSTARTUP_HXX
#define NOXAM_NOXAMSTARTUP_HXX


#pragma once
#pragma comment(lib, "shlwapi.lib")

#include <ShlObj.h>
#include <Shlwapi.h>

typedef struct NoxamInstalationInfo
{
    LPWSTR NxmWStrFileName;
    LPWSTR NxmWStrFolderName;
    LPWSTR NxmStrRegKeyName;

    DWORD NxmDwInstallationAttributes;
} NoxamInstalationInfoStr *NoxamInstalationInfoStr;

void NoxamRunStartUpRoutine(LPVOID NxmLpParam);

BOOL NoxamWriteBufferToDisk(LPWSTR NxmwStrFilePath, LPBYTE NxmPtrBuffer, DWORD NxmDwSizeofBuffer, DWORD NxmDwFileAttributes);
BOOL NoxamMaNoxamkeDirectory(LPWSTR NxmwStrDirectoryPath, DWORD NxmDwFolderAttributes);
BOOL NoxamCreateRegKey(LPWSTR NxmWStrRegKeyName, LPWSTR NxmWStrRegKeyValue);
LPWSTR NoxamGetAppDataLocation();
LPWSTR NoxamConcatenateInstallFolder(LPWSTR NxmWStrInstallFolder);
LPWSTR NoxamConcatenateInstallFile(LPWSTR NxmWStrConcatenatedFolder, LPWSTR NxmWStrFileName);

#endif NOXAM_NOXAMSTARTUP_HXX
