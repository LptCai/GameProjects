#ifndef ___BITMAP_H___
#define ___BITMAP_H___

#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

#define BITMAP_ID   0x4D42    // the universal bitmap ID
/*****************************************************************************
LoadBitmapFile()

Returns a pointer to the bitmap image of the bitmap specified by filename.
Also returns the bitmap header information. No support for 8-bit bitmaps.
*****************************************************************************/
unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);

/*****************************************************************************
LoadBitmapFileWithAlpha

Loads a bitmap file normally, and then adds an alpha component to use for
blending
*****************************************************************************/
unsigned char *LoadBitmapFileWithAlpha(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);


#endif