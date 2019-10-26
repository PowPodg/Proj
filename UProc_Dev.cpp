//---------------------------------------------------------------------------


#pragma hdrstop

#include "UProc_Dev.h"
 //using namespace HIDSpace;
//---------------------------------------------------------------------------
 TDev_Proc *Dev_Proc;

#pragma package(smart_init)
//TMY_HID *TMY_HID_Proc;
BYTE TempCodeAlarmDevUSB=0;

int Depth_From_HID_Last=0;
int Depth_From_HID_Actual =0;

void __fastcall TDev_Proc::Set_USB_Dev()
{

Step_Depth_Real=0.01;  // depth step - 1 sm
Time_Single_Tick_Time_from_HID = 0.000004; //4us - time single tick of time
//TDev_Proc *Pr = new TDev_Proc();

}
//------------------------------------------------------------------------------------
 USHORT __fastcall TDev_Proc::NumBlockFromUSBDev_read()
 {
 return MY_HID->InputDataHID[1];
 }
 

void __fastcall TDev_Proc::Data_Transfer(BYTE NumBlock)
{

 for(int i=1;i<=64;i++)
 {
  BaseBlockDataInHID[NumBlock].DataHID[i-1]= MY_HID->InputDataHID[i];  //i-1, ïîòîìó ÷òî ïðè ÷òåíèè ÷åðåç HID äîáàâëÿåòñÿ â íà÷àëå åùå áàéò
 }

 NumCommandDT=0;

 if(NumBlock==0) //ñåðâèñíûå äàííûå (ãëóáèíà è ò.ä.)
	 {

	 //-------------------------------------------------------------------------
	 //ñîçäàåì ñîáûòèå, åñëè ãëóáèíà èçìåíèëàñü
	 Depth_From_HID_Actual = this->BlockDataInService->Depth_From_HID;

	 if(Depth_From_HID_Actual!=Depth_From_HID_Last)
	 {
	  if(NfyDepthÑhangedEvent)
					  {
					  NfyDepthÑhangedEvent(this);
					  }
     }

	 Depth_From_HID_Last = this->BlockDataInService->Depth_From_HID;
	 //-------------------------------------------------------------------------------
		
	 TempCodeAlarmDevUSB=0;
	 TempCodeAlarmDevUSB = this->BlockDataInService->Code_Alarm;

	 if(!EventTimeOutFlagVar&&(TempCodeAlarmDevUSB&ALARM_TIME_OUT)) {
											 if(NfyTimeOutEvent) {
												 ErrorCommandDT=this->BlockDataInService->AnswError;
											 Form_Main->FladSendingCommandToDT=false;
																 NumCommandDT=TypeCommandForDownholeTool;
																 if(ErrorCommandDT==0)  ErrorCommandDT=0xFFFF;
																 if(ErrorCommandDT>0)  ErrorCommandDT=ErrorCommandDT;
																 NfyTimeOutEvent(this);
																 EventTimeOutFlagVar=true;
																 }
											 }
	     -
	 TempCodeAlarmDevUSB=0;
	 TempCodeAlarmDevUSB = this->BlockDataInService->Init_READY_AT64_ATUSB;
	 if(!EventInitReadyFlagVar&&(TempCodeAlarmDevUSB&INIT_AT64_ATUSB_READY))
							{
							if(NfyInitReadyEvent){ NumCommandDT=TypeCommandForDownholeTool; NfyInitReadyEvent(this); EventInitReadyFlagVar =true;}
							}
		
	 TempCodeAlarmDevUSB=0;
	 TempCodeAlarmDevUSB = this->BlockDataInService->NewData_READY;
	 if(!EventNewDataFromDTFlagVar&&(TempCodeAlarmDevUSB&NEW_DATA_READY))
					 {
					 if(NfyNewDataFromDT_Event)
											{
					 NumCommandDT=TypeCommandForDownholeTool;
					 ErrorCommandDT=this->BlockDataInService->AnswError;
					 NfyNewDataFromDT_Event(this);   EventNewDataFromDTFlagVar=true;
											}
					 }
		
	 TempCodeAlarmDevUSB=0;
	  TempCodeAlarmDevUSB = this->BlockDataInService->AnswError;
		
	 switch(this->BlockDataInService->AnswError) {
		 case 200:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 201:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 202:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 203:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 204:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 205:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 206:
		 FlagErrorDataReceiveOn=true;
		 break;

 		 case 207:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 208:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 209:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 210:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 211:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 13:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 14:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 15:
		 FlagErrorDataReceiveOn=true;
		 break;

		 case 16:
		 FlagErrorDataReceiveOn=true;
		 break;

		 default:
		 FlagErrorDataReceiveOn=false;

	 }	//end switch(Number_Command_Temp)

	  if(FlagErrorDataReceiveOn==false)
	  {
	 if(!EventCodeAlarmFromDTFlagVar&&TempCodeAlarmDevUSB) {
							 if(NfyCodeAlarmFromDT_Event)
											   {
							 NumCommandDT=TypeCommandForDownholeTool; ErrorCommandDT=this->BlockDataInService->AnswError;
							 NfyCodeAlarmFromDT_Event(this); EventCodeAlarmFromDTFlagVar =true;
											   }
							 }
	  }
	 }

  if(NumBlock>0) 
	{ 
	 this->BlockDataInDT =  (TDev_Proc::BlockDataInDT_T*)&this->BaseBlockDataInHID[NumBlock];

	 if(!EventNumBlockHIDFlagVar&&BlockDataInDT->Num_Block==NumBlockForDataDT)
					   {
						if(NfyNumBlockHID_Event)
											   {
											   NfyNumBlockHID_Event(this); EventNumBlockHIDFlagVar =true;
											   }
                       }
	}

}
//----------------------ïåðåñûëêà äàííûõ èç HID ðåïîðòà â áàçîâóþ ñòðóêòóðy (ñ óêàçàíèåì íîìåðà áëîêà ïî 64 áàéò) äëÿ ÷òåíèÿ äàííûõ ÷åðåç USB HID

//-----------------------------------------------------
void __fastcall TDev_Proc::Reset_Depth()
{
MY_HID->OutputReport[2] = RESET_M_Depth_Magnet_Mark;
}

//-----------------------------------
BYTE __fastcall TDev_Proc::TypeDevice_read() { return  MY_HID->OutputReport[1];}
void __fastcall TDev_Proc::TypeDevice_write(BYTE type_dev) {MY_HID->OutputReport[1]=type_dev;}
//-------------------------------------
  BYTE __fastcall TDev_Proc::TypeCommand_read(){return  MY_HID->OutputReport[2];}
 void __fastcall TDev_Proc::TypeCommand_write(BYTE type_com){MY_HID->OutputReport[2]=type_com;}
 //-------------------------------------------
 BYTE __fastcall TDev_Proc::IndexBeginBloc_read(){return MY_HID->OutputReport[3];}
 void __fastcall TDev_Proc::IndexBeginBloc_write(BYTE IndBeg){MY_HID->OutputReport[3]=IndBeg;}
 //-------------------------------------------IndexEndBloc
  BYTE __fastcall TDev_Proc::IndexEndBloc_read(){return MY_HID->OutputReport[4];}
 void __fastcall TDev_Proc::IndexEndBloc_write(BYTE IndEnd){MY_HID->OutputReport[4]=IndEnd;}
 //-------------------------------------------------   TimeCurrentPause
  BYTE __fastcall TDev_Proc::TimeCurrentPause_read(){return MY_HID->OutputReport[5];}
 void __fastcall TDev_Proc::TimeCurrentPause_write(BYTE Value){MY_HID->OutputReport[5]=Value;}
 //-------------------------------------------------TimeOutReceivData
 BYTE __fastcall TDev_Proc::TimeOutReceivData_read(){return MY_HID->OutputReport[6];}
 void __fastcall TDev_Proc::TimeOutReceivData_write(BYTE Value){MY_HID->OutputReport[6]=Value;}
 //------------------------------------------------NumberWordsFromDownholeTool
 USHORT __fastcall TDev_Proc::NumberWordsFromDownholeTool_read()
 {
 USHORT Value;
 LSB(Value)= MY_HID->OutputReport[7];  MSB(Value)= MY_HID->OutputReport[8];
 return Value;
 }
 void __fastcall TDev_Proc::NumberWordsFromDownholeTool_write(USHORT Value)
 {
 MY_HID->OutputReport[7]=LSB(Value);    MY_HID->OutputReport[8]=MSB(Value);
 }
 //----------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------
 BYTE __fastcall TDev_Proc::CodeAlarmDevUSB_read()
 {
 /*
  BYTE tempOut;
  try {
   tempOut = this->BlockDataInService->Code_Alarm;
  } catch (...) {
  tempOut = NOT_VALID;
  }
	return tempOut; */
  return this->BlockDataInService->Code_Alarm;
  }
 //BYTE __fastcall TDev_Proc::ReadyInitDevUSB_read(){return this->BlockDataInService->Init_READY_AT64_ATUSB;}
 //BYTE __fastcall TDev_Proc::NewDataReadyFromDownhTool_read(){return this->BlockDataInService->NewData_READY;}
 void __fastcall TDev_Proc::CodeAlarmDevUSB_write(BYTE Value)
 {
 this->BlockDataInService->Code_Alarm = Value;
 }
 
 BYTE __fastcall TDev_Proc::TimePeriodForManch_read(){ return  MY_HID->OutputReport[9];}
 void __fastcall TDev_Proc::TimePeriodForManch_write(BYTE Value){ MY_HID->OutputReport[9]=Value;}
 
 BYTE __fastcall TDev_Proc::NumberBytesInCommandForDownholeTool_read(){ return  MY_HID->OutputReport[10];}
 void __fastcall TDev_Proc::NumberBytesInCommandForDownholeTool_write(BYTE Value){ MY_HID->OutputReport[10]=Value;}
 
 BYTE __fastcall TDev_Proc::TypeCommandForDownholeTool_read(){ return  MY_HID->OutputReport[11];}
 void __fastcall TDev_Proc::TypeCommandForDownholeTool_write(BYTE Value){ MY_HID->OutputReport[11]=Value;}
 //----------------------------------------------------------------------------------------------
 
 void __fastcall TDev_Proc::InitDefaultCommandForDownholeTool (BYTE Value)
 {
	 if(Value==DES8||Value==AutoDES8)
	 {
	  this->TypeDevice=Init_Selected_Device.M_type_device;
	  this->TypeCommand = Init_Selected_Device.M_type_command;
	
	  this->IndexBeginBloc = Init_Selected_Device.M_Index_Begin_Block;
	  this->IndexEndBloc = Init_Selected_Device.M_Index_End_Block;
	  this->TimeCurrentPause = Init_Selected_Device.M_Time_for_Curr_Pause;  
	  this->TimeOutReceivData = Init_Selected_Device.M_TimeOut_for_Data;   
	  this->NumberWordsFromDownholeTool = Init_Selected_Device.M_Number_Word_Devce;
	  this->TimePeriodForManch = TIME_PERIOD_MANCH_50us;
	  this->NumberBytesInCommandForDownholeTool = PingM->NumberSentBytesInCommand;
	  this->TypeCommandForDownholeTool = 0;_MagnSensM->NumerCommand; //PingM->NumerCommand;

	 }

	  if(Value==SEMD||Value==EMDS_I)
	 {
	  this->TypeDevice=Init_Selected_Device.M_type_device;
	  this->TypeCommand = Init_Selected_Device.M_type_command;
	
	  this->IndexBeginBloc = Init_Selected_Device.M_Index_Begin_Block;
	  this->IndexEndBloc = Init_Selected_Device.M_Index_End_Block;
	  this->TimeCurrentPause = Init_Selected_Device.M_Time_for_Curr_Pause; 
	  this->TimeOutReceivData = Init_Selected_Device.M_TimeOut_for_Data;   
	  this->NumberWordsFromDownholeTool = Init_Selected_Device.M_Number_Word_Devce;
	  }
 }

