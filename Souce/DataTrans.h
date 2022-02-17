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
		static cli::array<double>^ getChannel0(int length);
		static double getChannel0LastValue();
		static cli::array<double>^ getChannel1(int length);
		static double getChannel1LastValue();
		static cli::array<double>^ getChannel2(int length);
		static double getChannel2LastValue();
		static cli::array<double>^ getChannel3(int length);
		static double getChannel3LastValue();
	private:

	};
}


