//////////////////////////////////////////////////////////////////
//
// KeyBoardTestADSampleRtTimerThread.cpp - cpp file
//
// This file was generated using the RTX64 Application Template for Visual Studio.
//
// Created: 2022/2/14 17:12:10 
// User: Robot01
//
//////////////////////////////////////////////////////////////////

#include "KeyBoardTestADSample.h"

// RTX64 periodic timer handler function.  Refer to the RTX64 Samples directory for examples of
// periodic timers.
//
void
RTFCNDCL
TimerHandler(PVOID context)
{
	//double time = 0;
	//double counts = 0;
	//LARGE_INTEGER nFreq;
	//LARGE_INTEGER nBeginTime;
	//LARGE_INTEGER nEndTime;
	//QueryPerformanceFrequency(&nFreq);
	//QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  

	// TO DO:
	// Your timer handler code here.
	AD_Sampling();
	//RtWprintf(L"Timer proc...\n");

	//QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	//�����ʱ��Ϊ0.7ms
}

