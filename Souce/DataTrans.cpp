#include "DataTrans.h"

void ADSampleDataTrans::DataTrans::openMemory(void)
{
	PRTCONSUMERCSB pSharedMemory = NULL;
	RtOpenSharedMemory(PAGE_READWRITE, FALSE, SharedMemoryName, (void**)&pSharedMemory);
	mPSharedMemory = pSharedMemory;
}
cli::array<unsigned short>^ ADSampleDataTrans::DataTrans::getChannel0()
{
	cli::array<unsigned short>^ receivedData = gcnew cli::array<unsigned short>(DataLimit);
	for (size_t i = 0; i < DataLimit; i++)
	{
		receivedData[i] = ADSampleDataTrans::DataTrans::mPSharedMemory->Channel0[i];
	}
	return receivedData;
}
unsigned short ADSampleDataTrans::DataTrans::getChannel0LastValue()
{
	return ADSampleDataTrans::DataTrans::mPSharedMemory->Channel0[DataLimit - 1];
}

cli::array<unsigned short>^ ADSampleDataTrans::DataTrans::getChannel1()
{
	cli::array<unsigned short>^ receivedData = gcnew cli::array<unsigned short>(DataLimit);
	for (size_t i = 0; i < DataLimit; i++)
	{
		receivedData[i] = ADSampleDataTrans::DataTrans::mPSharedMemory->Channel1[i];
	}
	return receivedData;
}
unsigned short ADSampleDataTrans::DataTrans::getChannel1LastValue()
{
	return ADSampleDataTrans::DataTrans::mPSharedMemory->Channel1[DataLimit - 1];
}

cli::array<unsigned short>^ ADSampleDataTrans::DataTrans::getChannel2()
{
	cli::array<unsigned short>^ receivedData = gcnew cli::array<unsigned short>(DataLimit);
	for (size_t i = 0; i < DataLimit; i++)
	{
		receivedData[i] = ADSampleDataTrans::DataTrans::mPSharedMemory->Channel2[i];
	}
	return receivedData;
}
unsigned short ADSampleDataTrans::DataTrans::getChannel2LastValue()
{
	return ADSampleDataTrans::DataTrans::mPSharedMemory->Channel2[DataLimit - 1];
}

cli::array<unsigned short>^ ADSampleDataTrans::DataTrans::getChannel3()
{
	cli::array<unsigned short>^ receivedData = gcnew cli::array<unsigned short>(DataLimit);
	for (size_t i = 0; i < DataLimit; i++)
	{
		receivedData[i] = ADSampleDataTrans::DataTrans::mPSharedMemory->Channel3[i];
	}
	return receivedData;
}
unsigned short ADSampleDataTrans::DataTrans::getChannel3LastValue()
{
	return ADSampleDataTrans::DataTrans::mPSharedMemory->Channel3[DataLimit - 1];
}