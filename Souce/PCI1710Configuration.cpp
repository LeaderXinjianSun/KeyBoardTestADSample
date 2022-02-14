#include "KeyBoardTestADSample.h"

#define PCI1710_BUS 5
#define PCI1710_DEVICE 15
#define PCI1710_FUNCTION 0
using namespace std;
int PCI1710BaseAddress = -1;
int PCI1710ID = 0xC080;
PPCI_COMMON_CONFIG PCI1710Data;
UCHAR buffer[PCI_COMMON_HDR_LENGTH];

void PCI1710Configuration_Initialize() {
	PCI_SLOT_NUMBER SlotNumber;
	PPCI_COMMON_CONFIG Pci1710Data;
	ULONG bytesWritten = 0;

	Pci1710Data = (PPCI_COMMON_CONFIG)buffer;
	SlotNumber.u.bits.Reserved = 0;
	SlotNumber.u.bits.DeviceNumber = PCI1710_DEVICE;
	SlotNumber.u.bits.FunctionNumber = PCI1710_FUNCTION;
	bytesWritten = RtGetBusDataByOffset(PCIConfiguration, PCI1710_BUS, SlotNumber.u.AsULONG, Pci1710Data, 0, PCI_COMMON_HDR_LENGTH);
	if (bytesWritten != 0) {
		if (Pci1710Data->VendorID != 0xffff) {
			int i;
			ULONG base;

			PCI1710Data = Pci1710Data;
			for (i = 0; i < 6; i++) {
				base = Pci1710Data->u.type0.BaseAddresses[i];
				if (base & 0x1) {
					base &= 0xfffffffc;
					PCI1710BaseAddress = (unsigned short)base;
					break;
				}
			}
		}
	}
}

int PCI1710Configuration_IOAddress() {
	return PCI1710BaseAddress;
}

PPCI_COMMON_CONFIG PCI1710Configuration_PciData() {
	return PCI1710Data;
}

void WritePci1710Register(unsigned int address, unsigned char value) {
	RtWritePortUchar((PUCHAR)(PCI1710ID + address), value);
	LARGE_INTEGER sleep = { 3 };
	RtSleepFt(&sleep);
}
unsigned char ReadPci1710Register(unsigned int address) {
	return RtReadPortUchar((PUCHAR)(PCI1710ID + address));
}

void AD_Sampling()	// AD sampling
{
	extern PRTCONSUMERCSB pSharedMemory;
	WritePci1710Register(9, 0x01);	//clear FIFO
	WritePci1710Register(0, 0x01);	//trig an ad sample
	unsigned char empty = ReadPci1710Register(7);	// read PCI1710 FIFO(empty or not)
	unsigned short short1 = RtReadPortUshort((PUSHORT)PCI1710ID);
	for (size_t i = 0; i < DataLimit - 1; i++)
	{
		pSharedMemory->Channel0[i] = pSharedMemory->Channel0[i + 1];
	}
	pSharedMemory->Channel0[DataLimit - 1] = short1 & 0xFFF;
													//AD_SampleData[0] = (AD_SampleData[0] - 2048) / 2048 * 10;	// AD sample data -> voltage value
	WritePci1710Register(9, 0x01);
	WritePci1710Register(0, 0x01);
	empty = ReadPci1710Register(7);
	short1 = RtReadPortUshort((PUSHORT)PCI1710ID);
	for (size_t i = 0; i < DataLimit - 1; i++)
	{
		pSharedMemory->Channel1[i] = pSharedMemory->Channel1[i + 1];
	}
	pSharedMemory->Channel1[DataLimit - 1] = short1 & 0xFFF;
													//AD_SampleData[1] = (AD_SampleData[1] - 2048) / 2048 * 10;	// AD sample data -> voltage value
	WritePci1710Register(9, 0x01);
	WritePci1710Register(0, 0x01);
	empty = ReadPci1710Register(7);
	short1 = RtReadPortUshort((PUSHORT)PCI1710ID);
	for (size_t i = 0; i < DataLimit - 1; i++)
	{
		pSharedMemory->Channel2[i] = pSharedMemory->Channel2[i + 1];
	}
	pSharedMemory->Channel2[DataLimit - 1] = short1 & 0xFFF;
													//AD_SampleData[2] = (AD_SampleData[2] - 2048) / 2048 * 10;	// AD sample data -> voltage value
	WritePci1710Register(9, 0x01);
	WritePci1710Register(0, 0x01);
	empty = ReadPci1710Register(7);
	short1 = RtReadPortUshort((PUSHORT)PCI1710ID);
	for (size_t i = 0; i < DataLimit - 1; i++)
	{
		pSharedMemory->Channel3[i] = pSharedMemory->Channel3[i + 1];
	}
	pSharedMemory->Channel3[DataLimit - 1] = short1 & 0xFFF;
													//AD_SampleData[3] = (AD_SampleData[3] - 2048) / 2048 * 10;	// AD sample data -> voltage value
}