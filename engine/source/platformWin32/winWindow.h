//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef _PLATFORM_WIN32_WINWINDOW_H
#define _PLATFORM_WIN32_WINWINDOW_H

// Creates the menu bar for the window
extern void CreateWin32MenuBar( void );
extern void DestroyWin32MenuBar( void );
extern bool HasWin32MenuBar( void );

extern "C"
{
   DLL_PUBLIC int winmain(int argc, const char **argv);

   // Only Needed 
   DLL_PUBLIC int winInit(int argc, const char **argv, HWND windowHwnd);
   DLL_PUBLIC void winDestroy();

   DLL_PUBLIC void winMainLoop();
   DLL_PUBLIC void winResize(int width, int height);
   DLL_PUBLIC void winMouseMove(int x, int y);
   DLL_PUBLIC void winMouseButton(bool down, bool left);
};

#endif _PLATFORM_WIN32_WINWINDOW_H
