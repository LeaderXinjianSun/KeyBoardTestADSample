#pragma once
#include <Windows.h>
#include <Rtapi.h>
#include "common.h" 

namespace ADSampleDataTrans
{
	public ref class DataTrans
	{
	public:
		static PRTCONSUMERCSB mPSharedMemory = NULL;
		static void openMemory(void);
		static cli::array<unsigned short>^ getChannel0();
		static unsigned short getChannel0LastValue();
		static cli::array<unsigned short>^ getChannel1();
		static unsigned short getChannel1LastValue();
		static cli::array<unsigned short>^ getChannel2();
		static unsigned short getChannel2LastValue();
		static cli::array<unsigned short>^ getChannel3();
		static unsigned short getChannel3LastValue();
	private:

	};
}


