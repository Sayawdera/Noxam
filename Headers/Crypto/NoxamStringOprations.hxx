#ifndef NOXAM_NOXAMSTRINGOPRATIONS_HXX
#define NOXAM_NOXAMSTRINGOPRATIONS_HXX

#include <stdio.h>
#include <windows.h>

char** NoxamSplitString(char* NxmString, char* NxmDelimiter, int NxmNumElements, bool NxmIgnoreEmpty);
void NoxamFreeSplitStringBuffer(char** NxmBuffer, int NxmNumElements);
char *NoxamJoinSplitString(char** NxmStrings, int NxmNumelements, int *NxmOutputLength);
void NoxamFreeJoinStringBuffer(char* NxmBuffer);


#endif NOXAM_NOXAMSTRINGOPRATIONS_HXX
