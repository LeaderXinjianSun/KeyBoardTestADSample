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

int PCI1710BaseAddress1 = -1;

void AD_ChannelRangeConfig(void)
{
	for (unsigned char i = 0x00; i < 0x08; i++)
	{
		WritePci1710Register(4, i);	//MUX control
		WritePci1710Register(5, i);	//MUX control
		WritePci1710Register(2, 0x04);	// AD channel range setting
	}
}
PRTCONSUMERCSB pSharedMemory;
void AD_SampleInitialize(void)	//	AD sample initialize
{
	AD_ChannelRangeConfig();
	WritePci1710Register(4, 0x00);	//MUX control
	WritePci1710Register(5, 0x03);	//MUX control
	WritePci1710Register(6, 0x01);	//control register setting
}

int _tmain(int argc, _TCHAR * argv[])
{

	HANDLE hShCSB = NULL;
	extern PRTCONSUMERCSB pSharedMemory;
	pSharedMemory = NULL;
    // for periodic timer code
    LARGE_INTEGER  liPeriod;     // timer period
    HANDLE         hTimer;       // timer handle
   
    //  RTX64 periodic timer code:
    //  TO DO: Set default timer period to your desired time.
    //         The period needs to be an even multiple of the HAL
    //         period found in the control panel.
    //         This example uses a period of 500 micro seconds.

    liPeriod.QuadPart = 10000;
	PCI1710Configuration_Initialize();
	PCI1710BaseAddress1 = PCI1710Configuration_IOAddress();
	RtPrintf("PCI1710BaseAddress: %d\n\n", PCI1710BaseAddress1);
	AD_SampleInitialize();
	

	// Create the shared memory region used to communicate with the user-space producer.
	hShCSB = RtCreateSharedMemory(PAGE_READWRITE, 0, sizeof(RTCONSUMERCSB), SharedMemoryName, (void**)&pSharedMemory);

	if (hShCSB == NULL)
	{
		DWORD error = GetLastError();
		RtPrintf("RtConsumer: Failed to create shared memory region: error = %d\n", error);
		return 1;
	}


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
	//RtWprintf(L"*** test Start\n");

	do
	{
		//RtPrintf("Channel0: %d\n", pSharedMemory->Channel0[DataLimit - 1]);
		//RtPrintf("Channel1: %d\n", pSharedMemory->Channel1[DataLimit - 1]);
		//RtPrintf("Channel2: %d\n", pSharedMemory->Channel2[DataLimit - 1]);
		//RtPrintf("Channel3: %d\n", pSharedMemory->Channel3[DataLimit - 1]);
		Sleep(1000);
	} while (true);
 
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
