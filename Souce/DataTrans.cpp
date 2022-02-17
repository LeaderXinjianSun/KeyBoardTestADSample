#include "DataTrans.h"

void ADSampleDataTrans::DataTrans::openMemory(void)
{
	PRTCONSUMERCSB pSharedMemory = NULL;
	RtOpenSharedMemory(PAGE_READWRITE, FALSE, SharedMemoryName, (void**)&pSharedMemory);
	mPSharedMemory = pSharedMemory;
}
cli::array<double>^ ADSampleDataTrans::DataTrans::getChannel0(int length)
{
	if (length > DataLimit)
	{
		length = DataLimit;
	}
	cli::array<double>^ receivedData = gcnew cli::array<double>(length);
	for (size_t i = 0; i < length; i++)
	{
		receivedData[i] = (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel0[DataLimit - length + i] - 2048) / 2048 * 10;
	}
	return receivedData;
}
double ADSampleDataTrans::DataTrans::getChannel0LastValue()
{
	return (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel0[DataLimit - 1] - 2048) / 2048 * 10;
}

cli::array<double>^ ADSampleDataTrans::DataTrans::getChannel1(int length)
{
	if (length > DataLimit)
	{
		length = DataLimit;
	}
	cli::array<double>^ receivedData = gcnew cli::array<double>(length);
	for (size_t i = 0; i < length; i++)
	{
		receivedData[i] = (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel1[DataLimit - length + i] - 2048) / 2048 * 10;
	}
	return receivedData;
}
double ADSampleDataTrans::DataTrans::getChannel1LastValue()
{
	return (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel1[DataLimit - 1] - 2048) / 2048 * 10;
}

cli::array<double>^ ADSampleDataTrans::DataTrans::getChannel2(int length)
{
	if (length > DataLimit)
	{
		length = DataLimit;
	}
	cli::array<double>^ receivedData = gcnew cli::array<double>(length);
	for (size_t i = 0; i < length; i++)
	{
		receivedData[i] = (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel2[DataLimit - length + i] - 2048) / 2048 * 10;
	}
	return receivedData;
}
double ADSampleDataTrans::DataTrans::getChannel2LastValue()
{
	return (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel2[DataLimit - 1] - 2048) / 2048 * 10;
}

cli::array<double>^ ADSampleDataTrans::DataTrans::getChannel3(int length)
{
	if (length > DataLimit)
	{
		length = DataLimit;
	}
	cli::array<double>^ receivedData = gcnew cli::array<double>(length);
	for (size_t i = 0; i < length; i++)
	{
		receivedData[i] = (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel3[DataLimit - length + i] - 2048) / 2048 * 10;
	}
	return receivedData;
}
double ADSampleDataTrans::DataTrans::getChannel3LastValue()
{
	return (double)(ADSampleDataTrans::DataTrans::mPSharedMemory->Channel3[DataLimit - 1] - 2048) / 2048 * 10;
}