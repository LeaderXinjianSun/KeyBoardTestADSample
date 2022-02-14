//////////////////////////////////////////////////////////////////
//
// KeyBoardTestADSample.h - header file
//
// This file was generated using the RTX64 Application Template for Visual Studio.
//
// Created: 2022/2/14 17:12:10 
// User: Robot01
//
//////////////////////////////////////////////////////////////////

#pragma once
//This define will deprecate all unsupported Microsoft C-runtime functions when compiled under RTSS.
//If using this define, #include <rtapi.h> should remain below all windows headers
//#define UNDER_RTSS_UNSUPPORTED_CRT_APIS
#ifndef KEYBOARDTESTADSAMPLE_H_
#define KEYBOARDTESTADSAMPLE_H_
#include <SDKDDKVer.h>

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <errno.h>
#include <windows.h>
#include <tchar.h>
#include <rtapi.h>    // RTX64 APIs that can be used in real-time and Windows applications.

#ifdef UNDER_RTSS
#include <rtssapi.h>  // RTX64 APIs that can only be used in real-time applications.
#endif // UNDER_RTSS
#include "common.h" 
 
// function prototype for periodic timer function
void
RTFCNDCL
TimerHandler(void * nContext);
void PCI1710Configuration_Initialize();
int PCI1710Configuration_IOAddress();
PPCI_COMMON_CONFIG PCI1710Configuration_PciData();
void WritePci1710Register(unsigned int address, unsigned char value);
unsigned char ReadPci1710Register(unsigned int address);
void AD_Sampling();
#endif