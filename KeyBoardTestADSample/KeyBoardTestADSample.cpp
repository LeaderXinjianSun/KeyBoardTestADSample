//////////////////////////////////////////////////////////////////
//
// KeyBoardTestADSample.cpp - cpp file
//
// This file was generated using the RTX64 Application Template for Visual Studio.
//
// Created: 2022/2/14 17:12:10 
// User: Robot01
//
//////////////////////////////////////////////////////////////////

#include "KeyBoardTestADSample.h"
   

int _tmain(int argc, _TCHAR * argv[])
{
 
    // for periodic timer code
    LARGE_INTEGER  liPeriod;     // timer period
    HANDLE         hTimer;       // timer handle
   
    //  RTX64 periodic timer code:
    //  TO DO: Set default timer period to your desired time.
    //         The period needs to be an even multiple of the HAL
    //         period found in the control panel.
    //         This example uses a period of 500 micro seconds.

    liPeriod.QuadPart = 5000;

    // Create a periodic timer
    if (!(hTimer = RtCreateTimer(NULL,            // Ignored
                                 0,               // Stack size (0 means use default size)
                                 TimerHandler,    // Timer handler
                                 NULL,            // Context argument to pass to handler
                                 RT_PRIORITY_MAX, // Timer thread priority
                                 CLOCK_2)))       // RTX64 HAL timer
    {
        //
        // TO DO:  exception code here
        // RtWprintf(_T("RtCreateTimer error = %d\n"),GetLastError());
        // NOTE: If this is changed to ExitProcess(), C++ static destructors in the main
        // module and all atexit-registered callbacks will not be called.
        exit(1);
    }

    if (!RtSetTimerRelative(hTimer,
                            &liPeriod,
                            &liPeriod))
    {
        //
        // TO DO: exception code here
        // RtWprintf(_T("RtSetTimerRelative error = %d\n"),GetLastError());
        // NOTE: If this is changed to ExitProcess(), C++ static destructors in the main
        // module and all atexit-registered callbacks will not be called.
        exit(1);
    }
 
    //
    // TO DO:  your program code here
    //
 
    // for periodic timer code
    if (!RtDeleteTimer(hTimer))
    {
        // RtWprintf(_T("RtDeleteTimer error = %d\n"),GetLastError());
        // TO DO:  your exception code here
        // NOTE: If this is changed to ExitProcess(), C++ static destructors in the main
        // module and all atexit-registered callbacks will not be called.
        exit(1);
    }
 
    return 0;
}
