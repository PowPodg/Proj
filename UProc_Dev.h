//---------------------------------------------------------------------------

#ifndef UProc_DevH
#define UProc_DevH
//--------------------------------------------------------------------------
#include "Compile.h"
 #include "UHID_MY.h"

 #include "aclapi.h"
#include "setupapi.h"
#include "devguid.h"
#include "hidusage.h"
#include <io.h>
 #include <fcntl.h>
 #include <sys\stat.h>
 #include <process.h>
 #include <share.h>
 #include <stdio.h>
 #include <stdlib.h>
#include <Winbase.h>
#include <windows.h>
#include "hidusage.h"
//#include "hidpi.h"
#include <pshpack4.h>
//#include <fstream.h>
#include "Mmsystem.h"
#include <Classes.hpp>


 #include "Main_Form.h"
//---------------------------------------------------------------------------


//$$---- Form CPP ----
//---------------------------------------------------------------------------
#define OBJ_INHERIT             0x00000002L
#define OBJ_PERMANENT           0x00000010L
#define OBJ_EXCLUSIVE           0x00000020L
#define OBJ_CASE_INSENSITIVE    0x00000040L
#define OBJ_OPENIF              0x00000080L
#define OBJ_OPENLINK            0x00000100L
#define OBJ_KERNEL_HANDLE       0x00000200L
#define OBJ_FORCE_ACCESS_CHECK  0x00000400L
#define OBJ_VALID_ATTRIBUTES    0x000007F2L

#define FILE_SUPERSEDE                  0x00000000
#define FILE_OPEN                       0x00000001
#define FILE_CREATE                     0x00000002
#define FILE_OPEN_IF                    0x00000003
#define FILE_OVERWRITE                  0x00000004
#define FILE_OVERWRITE_IF               0x00000005
#define FILE_MAXIMUM_DISPOSITION        0x00000005

#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020




#define SEMD         0x01
#define EMDS_I       0x02
#define DES8         0x03
#define AutoDES8     0x04  

#define RECEIVING_DATA   0x77
#define INIT_DEVICE      0x01
#define RESET_DEVICE     0x02
#define RESET_M_Depth_Magnet_Mark      0x03  

#define PC_READ_PROCESS     0x01
#define PC_READ_END         0x02


#define INIT_AT64_ATUSB_READY         0x01

#define NEW_DATA_READY                0x01

#define ALARM_DATA_PREV_NOT_READ         0x02 
#define ALARM_TIME_OUT                   0x01 

#define  SzeBlockDataIn                  62  
#define  SIZE_BLOCK_DATA_WORDS_IN             31  

#define NOT_VALID                       0xFF

#define TIME_PERIOD_MANCH_50us                 47//47// 24// 47 //  39     //для ATMega 128 - 16 MHz
#define TIME_PERIOD_MANCH_25us                  12//  19

 //IndexT *IndexM;

//---------------------------------------------------------------------------

//TMY_HID1 *TMY_HID_Proc;

class TDev_Proc : public  TObject
{

protected:

 int Width_Target_Window;
 int OutWidth_Target_Window() {return Width_Target_Window;};

  //TMY_HID *TMY_HID_Proc;

 BYTE __fastcall TypeDevice_read();
 void __fastcall TypeDevice_write(BYTE type_dev);

  BYTE __fastcall TypeCommand_read();
 void __fastcall TypeCommand_write(BYTE type_com);

   BYTE __fastcall IndexBeginBloc_read();
 void __fastcall   IndexBeginBloc_write(BYTE IndBeg);

	BYTE __fastcall IndexEndBloc_read();
 void __fastcall   IndexEndBloc_write(BYTE IndEnd);

   BYTE __fastcall TimeCurrentPause_read();
 void __fastcall   TimeCurrentPause_write(BYTE Value);

   BYTE __fastcall TimeOutReceivData_read();
 void __fastcall   TimeOutReceivData_write(BYTE Value);

  USHORT __fastcall NumberWordsFromDownholeTool_read();
 void __fastcall   NumberWordsFromDownholeTool_write(USHORT Value);

 BYTE __fastcall TimePeriodForManch_read();
 void __fastcall TimePeriodForManch_write(BYTE Value);

 BYTE __fastcall NumberBytesInCommandForDownholeTool_read();
 void __fastcall NumberBytesInCommandForDownholeTool_write(BYTE Value);

  BYTE __fastcall TypeCommandForDownholeTool_read();
 void __fastcall TypeCommandForDownholeTool_write(BYTE Value);
 //-----------------------------------
   BYTE __fastcall CodeAlarmDevUSB_read();
   void __fastcall CodeAlarmDevUSB_write(BYTE Value);
   BYTE __fastcall ReadyInitDevUSB_read();
   BYTE __fastcall NewDataReadyFromDownhTool_read();

 USHORT NumCommandDT_Intern;
  USHORT __fastcall NumCommandDT_read(){return NumCommandDT_Intern;}
 void __fastcall NumCommandDT_write(USHORT Value){NumCommandDT_Intern=Value;}

 USHORT ErrorCommandDT_Intern;
  USHORT __fastcall ErrorCommandDT_read(){ return ErrorCommandDT_Intern;}
 void __fastcall ErrorCommandDT_write(USHORT Value){ErrorCommandDT_Intern=Value;}

 //bool EventDepthСhangedFlagVar;
 //bool __fastcall EventDepthСhangedFlag_read(){return EventDepthСhangedFlagVar;}
 //void __fastcall EventDepthСhangedFlag_write(bool Value){EventDepthСhangedFlagVar=Value;}

 bool EventTimeOutFlagVar;
 bool __fastcall EventTimeOutFlag_read(){return EventTimeOutFlagVar;}
 void __fastcall EventTimeOutFlag_write(bool Value){EventTimeOutFlagVar=Value;}
 bool EventInitReadyFlagVar;
 bool __fastcall EventInitReadyFlag_read(){return EventInitReadyFlagVar;}
 void __fastcall EventInitReadyFlag_write(bool Value){EventInitReadyFlagVar=Value;}
 bool EventNewDataFromDTFlagVar;
 bool __fastcall EventNewDataFromDTFlag_read(){return EventNewDataFromDTFlagVar;}
 void __fastcall EventNewDataFromDTFlag_write(bool Value){EventNewDataFromDTFlagVar=Value;}
 bool EventCodeAlarmFromDTFlagVar;
 bool __fastcall EventCodeAlarmFromDTFlag_read(){return EventCodeAlarmFromDTFlagVar;}
 void __fastcall EventCodeAlarmFromDTFlag_write(bool Value){EventCodeAlarmFromDTFlagVar=Value;}

 bool EventNumBlockHIDFlagVar;
 bool __fastcall EventNumBlockHID_EventFlag_read(){return EventNumBlockHIDFlagVar;}
 void __fastcall EventNumBlockHID_EventFlag_write(bool Value){EventNumBlockHIDFlagVar=Value;}

USHORT NumBlockForDataDT_Var;
 USHORT __fastcall NumBlockForDataDT_read(){ return NumBlockForDataDT_Var;}
 void __fastcall NumBlockForDataDT_write(USHORT Value){NumBlockForDataDT_Var=Value;}

 USHORT __fastcall NumBlockFromUSBDev_read();


  #pragma pack ()
private:
 TNotifyEvent NfyDepthСhangedEvent;
 TNotifyEvent NfyTimeOutEvent;
 TNotifyEvent NfyInitReadyEvent;
 TNotifyEvent NfyNewDataFromDT_Event;
 TNotifyEvent NfyCodeAlarmFromDT_Event;
  TNotifyEvent NfyNumBlockHID_Event;


//-------------------------------------
public:

//-----------------out report---------------------
  __property   BYTE TypeDevice = { read = TypeDevice_read, write = TypeDevice_write};
  __property   BYTE TypeCommand = { read = TypeCommand_read, write = TypeCommand_write};
  __property   BYTE IndexBeginBloc = { read = IndexBeginBloc_read, write = IndexBeginBloc_write};
  __property   BYTE IndexEndBloc = { read = IndexEndBloc_read, write = IndexEndBloc_write};
  __property   BYTE TimeCurrentPause = { read = TimeCurrentPause_read, write = TimeCurrentPause_write};
  __property   BYTE TimeOutReceivData = { read = TimeOutReceivData_read, write = TimeOutReceivData_write};
  __property   USHORT NumberWordsFromDownholeTool = { read = NumberWordsFromDownholeTool_read, write = NumberWordsFromDownholeTool_write};
  __property   BYTE TimePeriodForManch = { read = TimePeriodForManch_read, write = TimePeriodForManch_write};
  __property   BYTE NumberBytesInCommandForDownholeTool = {read = NumberBytesInCommandForDownholeTool_read, write = NumberBytesInCommandForDownholeTool_write};
  __property   BYTE TypeCommandForDownholeTool = {read = TypeCommandForDownholeTool_read, write= TypeCommandForDownholeTool_write};



  __property   TNotifyEvent EventDepthСhanged = { read = NfyDepthСhangedEvent, write = NfyDepthСhangedEvent };

  __property   TNotifyEvent EventTimeOut = { read = NfyTimeOutEvent, write = NfyTimeOutEvent };
	
  __property   TNotifyEvent EventInitReady = { read = NfyInitReadyEvent, write = NfyInitReadyEvent };
	
  __property   TNotifyEvent EventNewDataFromDT = { read = NfyNewDataFromDT_Event, write = NfyNewDataFromDT_Event };
	
  __property   TNotifyEvent EventCodeAlarmFromDT = { read = NfyCodeAlarmFromDT_Event, write = NfyCodeAlarmFromDT_Event };

	
  __property   TNotifyEvent EventNumBlockHID = { read = NfyNumBlockHID_Event, write = NfyNumBlockHID_Event };

  __property   USHORT NumCommandDT = { read = NumCommandDT_read, write = NumCommandDT_write};
  __property   USHORT ErrorCommandDT = { read = ErrorCommandDT_read, write = ErrorCommandDT_write};
 
  __property   USHORT NumBlockForDataDT =  { read = NumBlockForDataDT_read, write = NumBlockForDataDT_write};
  
   __property   USHORT NumBlockFromUSBDev =  { read = NumBlockFromUSBDev_read};
 
  

   __property   bool EventTimeOutFlag = { read = EventTimeOutFlag_read, write = EventTimeOutFlag_write};
   __property   bool EventInitReadyFlag = { read = EventInitReadyFlag_read, write = EventInitReadyFlag_write};
   __property   bool EventNewDataFromDTFlag = { read = EventNewDataFromDTFlag_read, write = EventNewDataFromDTFlag_write};
   __property   bool EventCodeAlarmFromDTFlag = { read = EventCodeAlarmFromDTFlag_read, write = EventCodeAlarmFromDTFlag_write};

   __property   bool EventNumBlockHID_EventFlag = { read = EventNumBlockHID_EventFlag_read, write = EventNumBlockHID_EventFlag_write};
 //-----------------input report----------------------------
 // __property   BYTE CodeAlarmDevUSB = { read = CodeAlarmDevUSB_read};
 // __property   BYTE ReadyInitDevUSB = { read = ReadyInitDevUSB_read};
  //	__declspec(property(get = OutWidth_Target_Window)) int Width_Target_Window_P;
 //_property int          	Width_Target_Window_P  = { read = OutWidth_Target_Window };//   флаг ошибки опроса модуля


//S32 Depth_from_HID;
//U32 Time_betw_Depth_from_HID;
unsigned int Speed_Dev;
double Step_Depth_Real;
double Time_Single_Tick_Time_from_HID;

 void __fastcall Set_USB_Dev();
 void __fastcall Reset_Depth();


 #pragma pack (1)
typedef struct  {
 // BYTE HIDAdd;
  BYTE Num_Block;
  BYTE Code_Alarm;
  } NumAlarmBlockForReturnT;
	#pragma pack ()

	 
  #pragma pack (1)
 typedef struct   {
 // BYTE HIDAdd;
  BYTE ID_Block; 
  BYTE Code_Alarm;
  BYTE Init_READY_AT64_ATUSB;  
  BYTE NewData_READY;  
  S32 Depth_From_HID;
  U32 Time_Betw_Depth_from_HID;
  BYTE AnswError;   
  S16 Label_Depth;
  U16 ADC1;
  U16 ADC2;
  }BlockDataInServiceT;
  #pragma pack ()

 #pragma pack (1)
typedef struct  {
 // BYTE HIDAdd;
  BYTE Num_Block;
  BYTE Code_Alarm;
  BYTE Data[62];  
  }BlockDataInDT_T;
  #pragma pack ()


 #pragma pack (1)
typedef struct  {
   BYTE DataHID[64];  
  }BlockDataInHID_T ;
   #pragma pack ()


  #pragma pack (1)
typedef struct {
BYTE M_type_device;  
BYTE M_type_command; 
BYTE M_Index_Begin_Block;  
BYTE M_Index_End_Block;   
BYTE M_Time_for_Curr_Pause;  
BYTE M_TimeOut_for_Data;  
UINT16  M_Number_Word_Devce; 
BYTE M_LSB_Number_Chanels;  
BYTE M_MSB_Number_Chanels;  

} M_Init_Selected_Device;
  #pragma pack ()
 //NumAlarmBlockForReturnT NumAlarmBlockForReturn;
 void __fastcall Data_Transfer(BYTE);
 BlockDataInServiceT *BlockDataInService;
 BlockDataInDT_T *BlockDataInDT;

 BlockDataInHID_T BaseBlockDataInHID[100];
 M_Init_Selected_Device Init_Selected_Device;




 TDev_Proc()
 {
  BlockDataInService = (BlockDataInServiceT*)&BaseBlockDataInHID[0];
  EventTimeOutFlagVar=true; 
  EventInitReadyFlagVar=true;
  EventNewDataFromDTFlagVar=true;
  EventCodeAlarmFromDTFlagVar=true;
  EventNumBlockHIDFlagVar=true;
  NumBlockForDataDT_Var=0;


 }

 ///
 ///Не///
  __property   BYTE CodeAlarmDevUSB = { read = CodeAlarmDevUSB_read, write = CodeAlarmDevUSB_write};

  bool __fastcall IsReadyInitDevUSB() { return ((this->BlockDataInService->Init_READY_AT64_ATUSB &  INIT_AT64_ATUSB_READY)  ? TRUE : FALSE);}
  bool __fastcall IsNewDataReadyFromDownhTool() { return ((this->BlockDataInService->NewData_READY & NEW_DATA_READY)  ? TRUE : FALSE);}

  void __fastcall InitDefaultCommandForDownholeTool (BYTE Value);


  #pragma pack (1)
 struct head  {
  unsigned Size_Name_Well;
  char *Name_Well;
};
head Head_Data;

 #pragma pack ()

  #pragma pack (1)
  typedef struct   {
  BYTE Id;
  int Count_Depth;      
  int Depth;           
  unsigned int Time_betw_Depth;
  unsigned int Time_Sec;
  unsigned int Time_Milsec;
 Data_File ()
 {
		Id=0x77;    
 }                 
   } Data_File;              

   #pragma pack ()
   Data_File Data_FileFunc;
 Data_File Data_File_Depth[5000];
 Data_File Data_File_Depth_1[5000]; //для двойной буферизации


};
extern TDev_Proc *Dev_Proc ;

//---------------------------------------------------------------------------
#endif
