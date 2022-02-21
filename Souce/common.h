// common.h
// This head defines some commonly-used macros and structs.

#ifndef COMMON_H_
#define COMMON_H_

#include <windows.h>
#include <array>
using namespace std;
// SharedMemoryName
// This is the name of the shared memory region that the user-space and
// real-time code will use to communcate.
#define SharedMemoryName L"WindowsRealtimeSharedMemory"

#define DataLimit 1000

typedef struct RtConsumerCSB
{
	array<unsigned short, DataLimit> Channel0{};
	array<unsigned short, DataLimit> Channel1{};
	array<unsigned short, DataLimit> Channel2{};
	array<unsigned short, DataLimit> Channel3{};
} RTCONSUMERCSB, *PRTCONSUMERCSB;


#endif