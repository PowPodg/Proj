//---------------------------------------------------------------------------

#ifndef UWrite_FileH
#define UWrite_FileH
//-------------------------------------------------------------------------
#include "setupapi.h"
#include "devguid.h"


#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#include <Winbase.h>
#include <windows.h>
#include "hidusage.h"
#include "hidpi.h"
#include <pshpack4.h>
//#include <fstream.h>

#include "Compile.h"

//#include "HID_M.h"


 #include "Main_Form.h"
//#include "UProc_Dev.h"
//#include "USB_PROC.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>

#define DATA_TYPE_SERVICE         0x01

#define DATA_TYPE_DATA_DT         0x02
//---------------------------------------------------------------------------
class Write_File : public TThread
{
private:

protected:
	   int size_buf_for_write;
	   DWORD DWsize_buf_for_write;
 int length, res, i_hread;
 bool res_write;
 unsigned int Time_Sec_test;
	void __fastcall Execute();
	bool Flag_Event_Buf;

public:
	__fastcall Write_File(bool CreateSuspended);
				void __fastcall Access_Ext_Form();
  // void __fastcall	BufferForWriteToFile_Filling(BYTE);
   void __fastcall ClearArrForWriteToFile ();
   DWORD SizeBytes_for_Hread_Write_to_File;
   S32 Temp_Count_Depth;
	   bool Flag_Buf; //флаг для записи в один буфер
	   bool Flag_Buf_1;  //флаг для записи в другой буфер
	   DWORD SizeArrForWriteToFile;

//-----------------------------------------------------------
#pragma pack (1)
 struct head  {
  unsigned Size_Name_Well;
  char *Name_Well;
  };
head Head_Data;
 
  #pragma pack (8)
 
  #pragma pack (1)
  typedef struct   {
  BYTE Id;
  int Count_Depth;      //для счтетчика меток глуб. в короб.
  int Depth;            // глубина с учетом забиваемой оператором
  unsigned int Time_betw_Depth;
  unsigned int Time_Sec;
  unsigned int Time_Milsec;
  S16 Label_Depth;
  U16 ADC1;
  U16 ADC2;
 void ServiceData_File ()
 {
		Id=0x77;    
 }                 
   } ServiceData_File;           

   #pragma pack (8)
   
   ServiceData_File *Temp_StructForService;  

   ServiceData_File For_Size_Struct;

 //ServiceData_File Data_ForWriteToFile[1000];
 //ServiceData_File Data_ForWriteToFile_1[1000]; //для двойной буферизации

 BYTE New_ForWriteToFile[100*(1000+sizeof(ServiceData_File))]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 BYTE New_ForWriteToFile_1[100*(1000+sizeof(ServiceData_File))]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 //----------------------------------------------------------------------------------------------------------

   #pragma pack (1)
  typedef struct   {
  BYTE Id;
  bool DataCurrent;
  bool DataVolt;
  bool DataMain;
  bool DataSensMagn;
  bool ReqDataAccelGyr;
  bool AutoCalibSensMagn;

 void DT_FlagsHeader_File ()
 {
		Id=0x55;     
 }               
   } DT_FlagsHeader_File;              

	#pragma pack (8)
	
   DT_FlagsHeader_File *Temp_DT_FlagsHeader_File;  
 //----------------------------------------------------------------------------------------------------------
 
   #pragma pack (1)
  typedef struct   {
  BYTE Id;
  BYTE NumDataCurrent;
  BYTE NumDataVolt;
  BYTE NumDataMain;
	struct MagSen
		  {
		   BYTE NumPointsTimeSlice;
		   BYTE StepOffsetFirstSensor;
		   BYTE NumSensDisBetwGroup;
		   BYTE NumPolingCycleBefRes;
		   BYTE NumSensInGroup;
		  } MagnSens;
  BYTE NumAccelGyr;
  bool AutoCalibSensMagn;

 void DT_Header_File ()
 {
		Id=0x55;    
  }                 
   } DT_Header_File;              

	#pragma pack (8)
   DT_Header_File *Temp_DT_Header_File;   

 };

extern Write_File *Thread_Write_to_File;
//---------------------------------------------------------------------------
#endif
