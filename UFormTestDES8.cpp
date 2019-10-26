//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormTestDES8.h"
//#include "CRC32.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "ALed"
#pragma link "IxGrids"
#pragma link "IxInspector"
#pragma link "IxItemListEditor"
#pragma link "IxObjectInspector"
#pragma resource "*.dfm"

TObject *TempTObj;
int indexForArray=0;
int iFileHandleDepth=-2;
int ddd;
	  AnsiString TempSymv = "";
AnsiString  NameFileTemp = "GP3.smd";
int d;
 int k ;

// extern TDev_P;roc *Dev_Proc;
extern UINT uTimer;

TFormTestDES8 *FormTestDES8;
int i,i1, i2;
int TempCodeAlrm0;
int TempCodeAlarmPr=0;
USHORT ErrorTimeOut=0;;

 //ofstream outfile;//(L"Test Commands.txt",ios::out);
 BYTE TempCodeAlarmDevUSB1=0;
 BYTE TempAnswError =0;

 int TestNumComand=0 ;
 int TestErrComand=0 ;
 int TestNumComand1=0 ;  
 int TestErrComand1=0 ;  
 bool FlagEventTimeOut = false;
  int u=0;
  int pp=0;
  bool FlagButtonCommand=false;
  bool FlagCycleCommand=false;
    bool FlagCycleSetDepthDataReq=false;
  bool FlagErrorDataReceiveOn=false;
  bool FlagControlMethodOnChage = false;
  bool FlagControlChangeNumBlockHID = false;

//---------------------------------------------------------------------------
__fastcall TFormTestDES8::TFormTestDES8(TComponent* Owner)
	: TForm(Owner)
{

}
//--------------------------------------------------------

void __fastcall TFormTestDES8::To_MY_HID_OutputReport(UINT16 TempMy)
{
	 MY_HID->OutputReport[i] = LSB(TempMy); i++;
	 MY_HID->OutputReport[i] = MSB(TempMy); i++;
}
//--------------------------------------------------------

void __fastcall TFormTestDES8::To_MY_HID_OutputReport32(UINT32 TempMy)
{
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB3(TempMy); i++;
}
//--------------------------------------------------------

//------------------------------------------------------------
void __fastcall TFormTestDES8::btn_Send_CommandClick(TObject *Sender)
{
 TimerForControlEvent->Enabled=true;
 FlagControlMethodOnChage =false; 
 FlagControlChangeNumBlockHID = false ;
 try {

 pnlEventControlChNunBlHID->Color = clBtnFace;
 pnlEventControlMethodOnChage->Color = clBtnFace;

 //iFileHandleDepth = open(NameFileTemp.c_str(),O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE); //ñîçäàåì è îòêðûâàåì ôàéë

  pnl_response_command->Color=clBtnFace;
  Form_Main->PanelRespCommand->Color=clBtnFace;
 
  if(!Form_Main->Error_Flag_Load_HID_DLL&&!Form_Main->Error_Flag_Load_Dev_HID&&!Form_Main->Error_Flag_Atrib_HID)
  {

Form_Main->Stop_Polling_USB(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



Form_Main->FladSendingCommandToDT=true;

  i=11;
   for(i1=i; i1<=64; i1++) MY_HID->OutputReport[i1]=0;
  //UINT16 TempMy;
 if(rb_Ping->Checked)
	{
	 MY_HID->OutputReport[i] = PingM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = PingM->FlagsCommand;  i++;
	 Dev_Proc->NumberWordsFromDownholeTool =  PingM->NumberResponseWords;
	 }
	//----------
 if(rb_Init_Sonde->Checked)
	{
	delete [] DT_DES8M->DataMain ;
	 MY_HID->OutputReport[i] = InitSondeM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = InitSondeM->FlagsCommand; i++;
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeBeginCurrentPause);
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeEndCurrentPause);
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeStartMainADC);
	 To_MY_HID_OutputReport(InitSondeM->NumPointsSondeWriteFlash);
	 To_MY_HID_OutputReport(InitSondeM->NumPointsSondeSendCable);
	 Dev_Proc->NumberWordsFromDownholeTool =  InitSondeM->NumberResponseWords;
	 DT_DES8M->DataMain = new UINT32 [InitSondeM->NumPointsSondeSendCable+2];
	}
	//--------
 if(rb_Init_Magnetic_sensors->Checked)
 {
	 delete [] DT_DES8M->DataMagneticSensors;
	 delete [] DT_DES8M->DTMagneticSensorsStruct;       //???????????????
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->FlagsCommand; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumPointsTimeSliceForCable; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->StepOffsetFirstSensor; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumSensDisBetwGroup; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumPolingCycleBefRes; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumSensInGroup; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->Reserv; i++;
	 Dev_Proc->NumberWordsFromDownholeTool = InitMagneticSensorsM->NumberResponseWords;
	 DT_DES8M->DataMagneticSensors = new USHORT [(16*InitMagneticSensorsM->NumPointsTimeSliceForCable)+2];
	 DT_DES8M->DTMagneticSensorsStruct =  new DT_DES8::MagneticSensors [InitMagneticSensorsM->NumPointsTimeSliceForCable+1];  //???????????????
 }
 //----------
 if(rb_Init_Gyro_Acceler_sensors->Checked)
 {
  delete [] DT_DES8M->DataCurrent;
  delete [] DT_DES8M->DataVolt;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->FlagsCommand; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->NumPointsUIforCable; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->Reserv;i++;
  Dev_Proc->NumberWordsFromDownholeTool = Init_Gyro_Acceler_sensorsM->NumberResponseWords;
  DT_DES8M->DataCurrent = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
  DT_DES8M->DataVolt = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
  }
  //-----------
  if(rb_Data_Request->Checked)
  {
   MY_HID->OutputReport[i] = Data_RequestM->NumerCommand; i++;
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataCurrent<<0);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataVolt<<1);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataMain<<2);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataSensMagn<<3);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataAccelGyr<<4);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->AutoCalibSensMagn<<5);
   MY_HID->OutputReport[i] |= (0<<6);
   MY_HID->OutputReport[i] |= (0<<7);
   i++;
	Data_RequestM->CurrentDepth=Form_Main->DEPTH_out;
   INT32  TempMy = Data_RequestM->CurrentDepth;     
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB3(TempMy); i++;
   
   Dev_Proc->NumberWordsFromDownholeTool = Data_RequestM->NumberResponseWords;
 	
  // Dev_Proc->NumberWordsFromDownholeTool += sizeof(DT_DES8M->TimeInBlockData)/2;
  }
  //-------------
  if(rb_Setting_Pot_gain_offset->Checked)
  {
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->NumerCommand;   i++;
  MY_HID->OutputReport[i] |= (Setting_Pot_gain_offsetM->FlagsCommand->WriteToFlashValuePot<<0); i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->GainPotentiometer1; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->OffsetPotentiometer1; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->GainPotentiometer2; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->OffsetPotentiometer2; i++;
  To_MY_HID_OutputReport(Setting_Pot_gain_offsetM->NumberPointSwitchGainMain);
  Dev_Proc->NumberWordsFromDownholeTool = Setting_Pot_gain_offsetM->NumberResponseWords;
  }
  //--------------------
 if(rb_Start_Auto_calibr_magnetic_sensors->Checked)
 {
  MY_HID->OutputReport[i] = Start_Autocalibr_MagnSensM->NumerCommand; i++ ;
  MY_HID->OutputReport[i] = Start_Autocalibr_MagnSensM->FlagsCommand;  i++;
  Dev_Proc->NumberWordsFromDownholeTool = Start_Autocalibr_MagnSensM->NumberResponseWords;
  }
 //------------------
 if(rb_Echo->Checked)
 {
   MY_HID->OutputReport[i] = EchoM->NumerCommand; i++;
   MY_HID->OutputReport[i] = EchoM->FlagsCommand; i++;
   To_MY_HID_OutputReport(EchoM->DataCommand);
   Dev_Proc->NumberWordsFromDownholeTool = EchoM->NumberResponseWords;
  }
 //-----------------
 if(rb_SettingTransmitSpeed->Checked)
 {
   MY_HID->OutputReport[i] = Set_TransmSpeedM->NumerCommand; i++;
   MY_HID->OutputReport[i] = Set_TransmSpeedM->FlagsCommand; i++;
   To_MY_HID_OutputReport(Set_TransmSpeedM->TimeForSpeedManch);
   Dev_Proc->NumberWordsFromDownholeTool = Set_TransmSpeedM->NumberResponseWords;
 }
 //-----------------
 if(rb_Query_Word_state_device->Checked)
 {
  MY_HID->OutputReport[i] = Query_WordStateDeviceM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Query_WordStateDeviceM->FlagsCommand; i++;
  rb_Data_Request->Enabled=true;   
									
   Dev_Proc->NumberWordsFromDownholeTool = Query_WordStateDeviceM->NumberResponseWords;
   }
 //-----------------
 if(rb_Start_Continuous_recording->Checked)
 {
   MY_HID->OutputReport[i] =  Start_ContinRecordM->NumerCommand; i++;
   MY_HID->OutputReport[i] =  Start_ContinRecordM->FlagsCommand; i++;
   Dev_Proc->NumberWordsFromDownholeTool = Start_ContinRecordM->NumberResponseWords;
 }
 //----==
 if(rb_Stop_Continuous_recording->Checked)
 {
	 MY_HID->OutputReport[i] =  Stop_ContinRecordM->NumerCommand; i++;
	 MY_HID->OutputReport[i] =  Stop_ContinRecordM->FlagsCommand; i++;
	 Dev_Proc->NumberWordsFromDownholeTool = Stop_ContinRecordM->NumberResponseWords;
 }
 //-------------
 if(rb_Reset_SpeedMove->Checked)
 {
   MY_HID->OutputReport[i] = Reset_SpeedMoveM->NumerCommand; i++;
   MY_HID->OutputReport[i] = Reset_SpeedMoveM->FlagsCommand; i++;
   Dev_Proc->NumberWordsFromDownholeTool = Reset_SpeedMoveM->NumberResponseWords;
 }
 //--------------
 if(rb_Reset_Azimuth->Checked)
 {
  MY_HID->OutputReport[i] = Reset_AzimuthM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Reset_AzimuthM->FlagsCommand; i++;
  Dev_Proc->NumberWordsFromDownholeTool = Reset_AzimuthM->NumberResponseWords;
 }
 //------------------
 if(rb_Set_Service_Parameters->Checked)
 {
  MY_HID->OutputReport[i] = Set_Service_ParM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_Service_ParM->FlagsCommand; i++;

  //èìÿ ïëîùàäè
  int temp_i=i;
  int tmp_i;
  for(i=temp_i;i< (temp_i+Set_Service_ParM->NameArea.Length());i++)
  {
   MY_HID->OutputReport[i]= ((UINT8*)Set_Service_ParM->NameArea.c_str())[i-temp_i];
  }

   if (i<(temp_i+Set_Service_ParM->SizeNameAreaBytePr))
  {
	tmp_i=temp_i;
	temp_i=i;
	for(i=temp_i;i<(tmp_i+Set_Service_ParM->SizeNameAreaBytePr);i++)  MY_HID->OutputReport[i]= 0;
  }

  temp_i=i;
  for(i=temp_i;i< (temp_i+Set_Service_ParM->NumberNameHole.Length());i++)
  {
   MY_HID->OutputReport[i]= ((UINT8*)Set_Service_ParM->NumberNameHole.c_str())[i-temp_i];
  }

  if (i< (temp_i+Set_Service_ParM->SizeNumberNameHoleBytePr))
  {
	tmp_i=temp_i;
	temp_i=i;
	for(i=temp_i;i<(tmp_i+Set_Service_ParM->SizeNumberNameHoleBytePr);i++)  MY_HID->OutputReport[i]= 0;
  }
 
	 INT32  TempMy = Set_Service_ParM->BeginDepth;
	 if(TempMy&(1<<31)) TempMy |= (1<<23);
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;

	 TempMy = Set_Service_ParM->EndDepth;
	 if(TempMy&(1<<31)) TempMy |= (1<<23);
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;

  To_MY_HID_OutputReport32(Set_Service_ParM->CurrentTimeUnix);

  Dev_Proc->NumberWordsFromDownholeTool = Set_Service_ParM->NumberResponseWords;

 }
 //--------------
 if(rb_SetTime->Checked)
 {
  MY_HID->OutputReport[i] = Set_TimeM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_TimeM->FlagsCommand; i++;
  To_MY_HID_OutputReport32(Set_TimeM->CurrentTimeUnix);
  Dev_Proc->NumberWordsFromDownholeTool = Set_TimeM->NumberResponseWords;
 }
 //------------------------
 if(rb_SetDepth->Checked)
 {
  MY_HID->OutputReport[i] = Set_DepthM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_DepthM->FlagsCommand; i++;
  Set_DepthM->CurrentDepth=Form_Main->DEPTH_out;//ãëóáèíà
  INT32  TempMy = Set_DepthM->CurrentDepth;
  	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB3(TempMy); i++;
  Dev_Proc->NumberWordsFromDownholeTool = Set_DepthM->NumberResponseWords;
 }
 //------------------------
 Dev_Proc->NumberBytesInCommandForDownholeTool  = i-11;  //îáùåå ê-âî áàéò â êîìàíäå äëÿ ïåðåäà÷è â ñêâàæèííûé ïðèáîð
// MY_HID->OutputReport[10] = i-11;



 Dev_Proc->NumBlockForDataDT = Dev_Proc->NumberWordsFromDownholeTool/(SIZE_BLOCK_DATA_WORDS_IN) + ((Dev_Proc->NumberWordsFromDownholeTool%(SIZE_BLOCK_DATA_WORDS_IN))>0);

 Dev_Proc->TypeCommand=INIT_DEVICE;
 //hld_response_command->Blink=true;
/*
BYTE uu =10;
const std::type_info& ti1 = typeid(uu);
lbTestCommand->Caption=ti1.name();
*/
//lbTestCommand->Caption=Dev_Proc->NumberBytesInCommandForDownholeTool;
MY_HID->InputDataHID[0]= MY_HID->InputDataHID[0];

ZeroMemory(Dev_Proc->BaseBlockDataInHID,sizeof(Dev_Proc->BaseBlockDataInHID));
ZeroMemory(DT_DES8M->DataAll_DT,sizeof(DT_DES8M->DataAll_DT));

 FlagEventTimeOut=false;

 Form_Main->NumBlockFromSizeDataDT =0;

  bool TempFlagWr1=false;

 //----------------------1 ýòàï-------------------------------------------------------------------------------------------------------------------
 
	Dev_Proc->EventInitReadyFlag=false;    //ïîäãîòàâëèâàåì ê îäíîêðàòíîìó ñðàáàòûâàíþ ñîáûòèå ãîòîâíîñòü èíèöèàëèçàöèè
int count_read1=0;
 try {



 do{
	TempFlagWr1=Form_Main->Write_Read();    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Dev_Proc->Data_Transfer(0);
	for(int r=0;r<1000000;r++);//çàäåðæêà
	count_read1++;
	}  while(!Dev_Proc->EventInitReadyFlag&&count_read1<40) ;   
						 
	if(count_read1>=40)    //åñëè îøèáêà ÷òåíèÿ áîëüøå 400 ðàç!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ìîæåò íóæíî áîëüøå - ðàíüøå áûëî 40000
	{
 
	i=i;
	}

  } catch (...) {
  return;
 }

 //----------------------2 ýòàï-------------------------------------------------------------------------------------------------------------------

   /*
   Dev_Proc->TypeCommand=0;
	 do {
		if(Form_Main->Write_Read())Dev_Proc->Data_Transfer(0); //ïåðåñûëêà, åñëè óñïåøíî ïðî÷èòàëè
		TempCodeAlarmDevUSB1 = Dev_Proc->CodeAlarmDevUSB;
		for(int r=0;r<1000000;r++);//çàäåðæêà
	 //	Form_Main->Read_HID(); //íóæíî îáÿçàòåëüíî ïðî÷åñòü ÷òîáû î÷èñòèòü áóôåð USB (èëè â êîðîáî÷êå ?????) îò ïðåäûäóùèõ äàííûõ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		TempCodeAlarmDevUSB1 = Dev_Proc->CodeAlarmDevUSB;
	//	for(int r=0;r<1000000;r++);//çàäåðæêà
		} while(TempCodeAlarmDevUSB1);
		*/
   }  //ïðîâåðêà USB
  else {
		MessageBox (NULL, L"USB Device Error!", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
	  // ShowMessage("USB Device Error!");
	   return;
	   }

   //	   do(
	//		if(Form_Main->Write_Read()) Dev_Proc->Data_Transfer(0); //ïåðåñûëêà, åñëè óñïåøíî ïðî÷èòàëè
   //		  }while(


//  TempFlagWr=false;
//  do{
  // Form_Main->Read_HID();   Form_Main->Read_HID();
 //for(int r=0;r<1000000;r++);//çàäåðæêà
 //  Form_Main->Read_HID();
  //	   }   while(!TempFlagWr);

 /*
 //----------------------3 ýòàï-------------------------------------------------------------------------------------------------------------------

	
   */
 //if(Form_Main->Flag_Wrie_Read );
 //

	 }
	  catch (...) {
  return;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::FormClose(TObject *Sender, TCloseAction &Action)
{
 //hld_response_command->Blink=false;
 //ValueListEditor_Cont_command->Strings->Clear();
 //Timer1->Enabled=false;
  //IxObjectInspector1->Objects->Clear() ;


  Form_Main->ToolbtnShowTestForm->ImageIndex=21;
  Form_Main->ToolbtnShowTestForm->Hint="Show Test Form";
  //outfile.close();
 // Form_Main->NumPressShowClose++;
 //	if(Form_Main->NumPressShowClose>=2)  Form_Main->NumPressShowClose=0;

 }
//---------------------------------------------------------------------------

//--------------------------

 void __fastcall TFormTestDES8::PingClick()
 {
  //IxObjectInspector1->Objects->Clear() ;
 //IxObjectInspector1->Objects->Add(PingM);
 // MY_HID->OutputReport[8] = PingM->NumerCommand;
   //	Dev_Proc->EventInitReadyFlag=false;   
  rb_PingClick(rb_Ping);
  // btn_Send_CommandClick(btn_Send_Command) ;

 }




void __fastcall TFormTestDES8::rb_PingClick(TObject *Sender)
{
try {
  NumSend_CommandToDT= PingConst;

 // ValueListEditor_Cont_command->Values[Ping_Description_String.NumCommand]=Ping_out.NumCommand;
 // ValueListEditor_Cont_command->Values[Ping_Description_String.Flags]=Ping_out.Flags;
 //Timer1->Enabled=false;
 IxObjectInspector1->Objects->BeginUpdate();   
 IxObjectInspector1->Objects->Clear() ;
 //IxObjectInspector1->Objects->BeginUpdate();
 IxObjectInspector1->Objects->Add(PingM);
 		IxObjectInspector1->Refresh();
		IxObjectInspector1->Rescan();  
 //IxObjectInspector1->Objects->EndUpdate();

//IxObjectInspector1->TitleCaptions->Text= L"";
//IxObjectInspector1->TitleCaptions->Add(L"");
//IxObjectInspector1->TitleCaptions->Delete(0);
//IxObjectInspector1->Items->Add(L"Description",L"Value")  ;

 //Timer1->Enabled=true;
  IxObjectInspector1->Objects->EndUpdate();    
	} catch (...) {
	return;
}
}

//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::ValueListEditor_Cont_commandValidate(TObject *Sender, int ACol,
		  int ARow, const UnicodeString KeyName, const UnicodeString KeyValue)
{
 // if(ARow<3) ValueListEditor_Cont_command->RestoreCurrentRow();   // for command and flags can't be change
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Init_SondeClick(TObject *Sender)
{
NumSend_CommandToDT = Init_SondeConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();  
IxObjectInspector1->Objects->Clear() ;
//IxObjectInspector1->Objects->BeginUpdate();
IxObjectInspector1->Objects->Add(InitSondeM);
	   //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan();  
 //IxObjectInspector1->Objects->EndUpdate();
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();   
 	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Init_Magnetic_sensorsClick(TObject *Sender)
{
NumSend_CommandToDT = Init_Magnetic_sensorsConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
IxObjectInspector1->Objects->Clear() ;
IxObjectInspector1->Objects->Add(InitMagneticSensorsM);
	  //	IxObjectInspector1->Refresh();
		IxObjectInspector1->Rescan();  
		IxObjectInspector1->Objects->EndUpdate();    
			IxObjectInspector1->Repaint();
//Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Init_Gyro_Acceler_sensorsClick(TObject *Sender)

{
NumSend_CommandToDT = Init_Gyro_Acceler_sensorsConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
IxObjectInspector1->Objects->Clear() ;
IxObjectInspector1->Objects->Add(Init_Gyro_Acceler_sensorsM);
	 //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan();  
//Timer1->Enabled=true;
IxObjectInspector1->Objects->EndUpdate();     
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Data_RequestClick(TObject *Sender)
{
try {
NumSend_CommandToDT = Data_RequestConst;
	Data_RequestM->CurrentDepth=Form_Main->DEPTH_out;//ãëóáèíà
// TIxItemProperty Item_t;
//Timer1->Enabled=false;
   //	IxObjectInspector1->Objects->Delete(0) ;
IxObjectInspector1->Objects->BeginUpdate();   
 IxObjectInspector1->Objects->Clear() ;
 //IxObjectInspector1->Objects->Add(Data_RequestM);

   volatile unsigned NumPointsSondeTemp = 3*InitSondeM->NumPointsSondeSendCable;
   if(NumPointsSondeTemp%2) { NumPointsSondeTemp +=1; NumPointsSondeTemp /=2;}
   else NumPointsSondeTemp /=2;

   Data_RequestM->NumberResponseWordsPr = 2+1+NumPointsSondeTemp+16*InitMagneticSensorsM->NumPointsTimeSliceForCable+
   2*Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+GroupDataGyroACccel_Const+CRC32_Const;//2* äëÿ òîêà è íàïðÿæåíèÿ


   if(!Data_RequestM->FlagsCommand->ReqDataCurrent) Data_RequestM->NumberResponseWordsPr -=Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;
   if(!Data_RequestM->FlagsCommand->ReqDataVolt) Data_RequestM->NumberResponseWordsPr -=Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;
   if(!Data_RequestM->FlagsCommand->ReqDataMain) Data_RequestM->NumberResponseWordsPr -=NumPointsSondeTemp;
   if(!Data_RequestM->FlagsCommand->ReqDataSensMagn)Data_RequestM->NumberResponseWordsPr -= 16*InitMagneticSensorsM->NumPointsTimeSliceForCable;
   if(!Data_RequestM->FlagsCommand->ReqDataAccelGyr)Data_RequestM->NumberResponseWordsPr -= GroupDataGyroACccel_Const;

  // if(chkAutonomMode->Checked)Data_RequestM->NumberResponseWordsPr = 1;

  IxObjectInspector1->Objects->Add(Data_RequestM);
	 //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan();  
 IxObjectInspector1->Objects->EndUpdate();    
 

	 TempTObj= Data_RequestM;

   } catch (...) {
   return;
}
  //Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Setting_Pot_gain_offsetClick(TObject *Sender)
{
NumSend_CommandToDT = Setting_Pot_gain_offsetConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();  
IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Setting_Pot_gain_offsetM);
	   //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan(); 
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Start_Auto_calibr_magnetic_sensorsClick(TObject *Sender)

{
NumSend_CommandToDT =  Start_Auto_calibr_magnetic_sensorsConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Start_Autocalibr_MagnSensM);
	   //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan();  
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_EchoClick(TObject *Sender)
{
NumSend_CommandToDT = EchoConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
 IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(EchoM);
	
		IxObjectInspector1->Rescan(); 
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();     
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_SettingTransmitSpeedClick(TObject *Sender)
{
NumSend_CommandToDT = Setting_Transmit_speedConst;
 //Timer1->Enabled=false;
 IxObjectInspector1->Objects->BeginUpdate();   
IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Set_TransmSpeedM);
	   //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan(); 
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();     
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Query_Word_state_deviceClick(TObject *Sender)
{
NumSend_CommandToDT = Query_Word_state_deviceConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();  
IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Query_WordStateDeviceM);
	 
		IxObjectInspector1->Rescan();  
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Start_Continuous_recordingClick(TObject *Sender)

{
NumSend_CommandToDT = Start_Continuous_recordingConst;

IxObjectInspector1->Objects->BeginUpdate();  !
 IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Start_ContinRecordM);

		IxObjectInspector1->Rescan(); 
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();     
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Stop_Continuous_recordingClick(TObject *Sender)

{
NumSend_CommandToDT = Stop_Continuous_recordingConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
 IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Stop_ContinRecordM);
	
		IxObjectInspector1->Rescan(); 
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::rb_Reset_SpeedMoveClick(TObject *Sender)
{
NumSend_CommandToDT = Reset_SpeedMoveConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
 IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Reset_SpeedMoveM);
	  
		IxObjectInspector1->Rescan();  
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Reset_AzimuthClick(TObject *Sender)
{
NumSend_CommandToDT = Reset_AzimuthConst;
//Timer1->Enabled=false;
IxObjectInspector1->Objects->BeginUpdate();   
  IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Reset_AzimuthM);
	
		IxObjectInspector1->Rescan();  
 //Timer1->Enabled=true;
 IxObjectInspector1->Objects->EndUpdate();    
	IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::rb_Set_Service_ParametersClick(TObject *Sender)
{
NumSend_CommandToDT = Set_Service_Parameters;
 //Timer1->Enabled=false;
 IxObjectInspector1->Objects->BeginUpdate();   
  IxObjectInspector1->Objects->Clear() ;
 IxObjectInspector1->Objects->Add(Set_Service_ParM);

		IxObjectInspector1->Rescan();  
		IxObjectInspector1->Objects->EndUpdate();     
			IxObjectInspector1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFormTestDES8::rb_SetTimeClick(TObject *Sender)
{
NumSend_CommandToDT =  Set_TimeDT;


  IxObjectInspector1->Objects->BeginUpdate();  
  IxObjectInspector1->Objects->Clear() ;
  IxObjectInspector1->Objects->Add(Set_TimeM);
	   //	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan();  
		IxObjectInspector1->Objects->EndUpdate();    //íàâåðíîå òîæå íóæíî!!!!! íå óñïåâàåò ïåðåðèñîâûâàòüñÿ!!!!!!!!!!!!!!!!!!!!!!!!!!
}
//---------------------------------------------------------------------------
 void __fastcall TFormTestDES8::rb_SetDepthClick(TObject *Sender)
{
  //Timer1->Enabled=false;
  try {

  NumSend_CommandToDT =  Set_DepthDT;
  Set_DepthM->CurrentDepth=Form_Main->DEPTH_out;
IxObjectInspector1->Objects->BeginUpdate();  
	IxObjectInspector1->Objects->Clear() ;
  //IxObjectInspector1->Objects->Remove(TempTObj);

  IxObjectInspector1->Objects->Add(Set_DepthM);
	  	IxObjectInspector1->Refresh(); 
		IxObjectInspector1->Rescan(); 
		 IxObjectInspector1->RefreshValues();   
	IxObjectInspector1->Objects->EndUpdate();     
	IxObjectInspector1->Repaint();

   //	int ddd= IxObjectInspector1->Objects->Count;   
   } catch (...) {
  return;
  }
}
//---------------------------------------------------------------------------



void __fastcall TFormTestDES8::IxObjectInspector1PropertyChanged(TObject *Sender,
          const TIxItemProperty *Item)
{
if(rb_Data_Request->Checked) rb_Data_RequestClick(Sender);

	if(rb_Set_Service_Parameters->Checked)
   {
	IxObjectInspector1->Objects->BeginUpdate();   
	 IxObjectInspector1->Objects->Clear() ;
	 IxObjectInspector1->Objects->Add(Set_Service_ParM);
	  IxObjectInspector1->Rescan();  
	// IxObjectInspector1->InplaceCollections=true;
	IxObjectInspector1->Objects->EndUpdate();  
   }

 //hld_response_command->Blink=false;  
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::FormShow(TObject *Sender)
{
 // rb_Data_Request->Enabled=false;
 rb_Data_RequestClick(Sender) ;
 rb_Data_Request->Checked=true;
 Form_Main->ToolbtnShowTestForm->ImageIndex=22;
 Form_Main->ToolbtnShowTestForm->Hint="Close Test Form";

 //Form_Main->NumPressShowClose++;
// if(Form_Main->NumPressShowClose>=2)  Form_Main->NumPressShowClose=0;
}
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::TimerForControlEventTimer(TObject *Sender)
{

VisualCompChange(TIME_OUT_EVENT);
//Åñëè ñòàáîòàë òàéìåð àíàëèçèðóåì - êàêèå-òî ñîáûòèÿ íå ïðîøëè
static int CountTimer=0;

	Form_Main->TimerForErrorUSB->Enabled=true; 

if(FlagControlChangeNumBlockHID) pnlEventControlChNunBlHID->Color = clRed;
pnlEventControlChNunBlHID->Refresh(); pnlEventControlChNunBlHID->Repaint();
 if(FlagControlMethodOnChage) pnlEventControlMethodOnChage->Color = clRed;
 pnlEventControlMethodOnChage->Refresh(); pnlEventControlMethodOnChage->Repaint();
 //TimerForControlEvent->Enabled=false;
 // Send_CommandToDT(Data_RequestConst) ;  

 // chkSetDepthDataReq->Checked=false;
  //FlagCycleSetDepthDataReq=false;
  //FlagCycleCommand = false;
  
  if(!FlagControlChangeNumBlockHID&&!FlagControlMethodOnChage&&!Form_Main->Res_read)
  {
 // Form_Main->Start_Polling_USBforINIT(0,0);
 // Send_CommandToDT(PingConst) ;
  //	Form_Main->TimerForErrorUSB->Enabled=true; //çàïóñêàåì òàéìåð äëÿ ïåðåïîäêëþ÷ååíèÿ USB
   //	TimerForControlEvent->Enabled=false;   return;
  }

  if(!FlagControlChangeNumBlockHID&&!FlagControlMethodOnChage)
  {
 // Form_Main->Start_Polling_USBforINIT(0,0);
 // Send_CommandToDT(PingConst) ;
 //	Form_Main->TimerForErrorUSB->Enabled=true; //çàïóñêàåì òàéìåð äëÿ ïåðåïîäêëþ÷ååíèÿ USB
  //	TimerForControlEvent->Enabled=false;   return;
 // }



  if(CountTimer>0)
   {
 
	CountTimer=0;
   }
  }
  CountTimer++;    
}
//---------------------------------------------------------------------------





void __fastcall TFormTestDES8::Timer2Timer(TObject *Sender)
{
static int CountComand=0; ;
//static int TestNumComand=0 ;


//IxObjectInspector1->Reset();

 //LabelError->Caption= IxObjectInspector1->ItemCount;
 for(i1=0;i1<IxObjectInspector1->ItemCount;i1++)
 {
 IxObjectInspector1->Item[i1]->Font->Color=clBlack;
 IxObjectInspector1->Item[i1]->ValueFont->Color=clNavy;
  }



switch(CountComand) {

case 0: rb_Init_SondeClick(Sender); rb_Init_Sonde->Checked=true;

		 break;
case 1: rb_Init_Magnetic_sensorsClick(Sender); rb_Init_Magnetic_sensors->Checked=true;

		 break;
case 3: rb_Init_Gyro_Acceler_sensorsClick(Sender); rb_Init_Gyro_Acceler_sensors->Checked=true;

		 break;
case 4: rb_Data_RequestClick(Sender); rb_Data_Request->Checked=true;

		break;
case 5: rb_Setting_Pot_gain_offsetClick(Sender); rb_Setting_Pot_gain_offset->Checked=true;

		 break;
case 6: rb_Start_Auto_calibr_magnetic_sensorsClick(Sender); rb_Start_Auto_calibr_magnetic_sensors->Checked=true;

		break;
case 7: rb_Query_Word_state_deviceClick(Sender); rb_Query_Word_state_device->Checked=true;

		break;
case 8: rb_Start_Continuous_recordingClick(Sender); rb_Start_Continuous_recording->Checked = true;

		break;
case 9: rb_Stop_Continuous_recordingClick(Sender); rb_Stop_Continuous_recording->Checked = true;

		 break;
case 10: rb_Reset_SpeedMoveClick(Sender); rb_Reset_SpeedMove->Checked = true;

		 break;
case 11: rb_Reset_AzimuthClick(Sender); rb_Reset_Azimuth->Checked = true;

		 break;
case 12: rb_PingClick(Sender); rb_Ping->Checked = true;

		 break;
}

btn_Send_CommandClick(Sender);
// while(IxObjectInspector1->Item[i1]->Name!=L"CodeAlarm") i1++;  //íàõîäèì èíäåêñ ïîçèöèè  CodeAlarm


// while(IxObjectInspector1->Item[i]->Name!=L"NumerCommand") i++;

/*
switch(CountComand) {

case 0:
		 TestNumComand = InitSondeM->NumerCommand; //TestErrComand = InitSondeM->CodeAlarm;
		 break;
case 1:
		 TestNumComand = InitMagneticSensorsM->NumerCommand; //TestErrComand =InitMagneticSensorsM->CodeAlarm ;
		 break;
case 3:
		 TestNumComand = Init_Gyro_Acceler_sensorsM->NumerCommand; //TestErrComand = Init_Gyro_Acceler_sensorsM->CodeAlarm;
		 break;
case 4:
		TestNumComand =Data_RequestM->NumerCommand; //TestErrComand = Data_RequestM->CodeAlarm;
		break;
case 5:
		 TestNumComand =Setting_Pot_gain_offsetM->NumerCommand;//TestErrComand =Setting_Pot_gain_offsetM->CodeAlarm;
		 break;
case 6:
		TestNumComand =Start_Autocalibr_MagnSensM->NumerCommand; //TestErrComand = Start_Autocalibr_MagnSensM->CodeAlarm;
		break;
case 7:
		TestNumComand =Query_WordStateDeviceM->NumerCommand; //TestErrComand = Query_WordStateDeviceM->CodeAlarm;
		break;
case 8:
		TestNumComand =Start_ContinRecordM->NumerCommand; //TestErrComand = Start_ContinRecordM->CodeAlarm;
		break;
case 9:
		 TestNumComand =Stop_ContinRecordM->NumerCommand;// TestErrComand =  Stop_ContinRecordM->CodeAlarm;
		 break;
case 10:
		 TestNumComand = Reset_SpeedMoveM->NumerCommand; // TestErrComand = Reset_SpeedMoveM->CodeAlarm;
		 break;
case 11:
		 TestNumComand = Reset_AzimuthM->NumerCommand; //TestErrComand = Reset_AzimuthM->CodeAlarm;
		 break;
case 12:
		 TestNumComand = PingM->NumerCommand; //TestErrComand = Reset_AzimuthM->CodeAlarm;
		 break;
}

 */
 //  outfile<< setiosflags(ios::fixed)<<setiosflags(ios::right)<<"Numer Command: "<<setw(3)<<TestNumComand<<"      Error: "<<setw(3)<<TestErrComand<<endl;

 //ErrorTimeOut=0;   TestErrComand=0 ;

CountComand = RandomRange(0,12);
//if(CountComand>14)CountComand=0;
//outfile<< setiosflags(ios::fixed)<<setiosflags(ios::right)<<"Numer Command: "<<setw(3)<<TestNumComand1<<"      Error: "<<setw(3)<<TestErrComand1<<endl;

}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::chkAutoRandomCommClick(TObject *Sender)
{
  if(chkAutoRandomComm->Checked)
  {
   chkCycleComman->Checked=false;
   chkSetDepthDataReq->Checked=false;
  Timer2->Enabled =true;
 //  outfile.open(L"Test Commands.txt",ios::out);
   FlagButtonCommand=true; // ÷òîáû ñîáûòèÿ íå ñðàáîòàëè ñðàçó ïðè ñîçëàíèè ôîðìû (íå ðàáîòàåò çàïèñü â ôàéë out)
  } //} ofstream outfile(L"Test Commands.txt",ios::out);}
  else {Timer2->Enabled=false; // outfile.close();
  }

}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------
void __fastcall TFormTestDES8::InitUSBHID(TObject *Sender)
{
try {

static int tt=0;
tt++;
LbEventInitReady->Caption=tt;
LbEventInitReady->Repaint();

		Dev_Proc->EventTimeOutFlag=false;
		Dev_Proc->EventNewDataFromDTFlag = false; 
		Dev_Proc->EventCodeAlarmFromDTFlag=false;
		FlagButtonCommand=true; 
		Dev_Proc->TypeCommand=RECEIVING_DATA; 
							
		Form_Main->Start_Polling_USBforINIT(0,0);
}
		catch (...) {
		return;
}
  
}
//-----------------------------------------------------------------------------------
//îáðàáîò÷èê ñîáûòèé =======================================================================================================
//1. ñîáûòèå òàéìàóòà ïðè ïðèåìå äàííûõ ñ ïðèáîðà
//2. ñîáûòèå - îøèáêà ñ ïðèáîðà
//2. ñîáûòèå - åñòü íîâûå äàííûå
//ýòîò îáðàáîò÷èê ïîêëþ÷åí ê òðåì ñîáûòèÿì
 void __fastcall TFormTestDES8::MethodOnChage(TObject* Sender)
{
// TimerForControlEvent->Enabled=false;//âûêëþ÷àåì òàéìåð, êîíòðîëèðóþùèé ïðîõîæäåíèå ñîáûòèÿ
 FlagControlMethodOnChage = true; //êîíòðîëü ñîáûòèÿ
 try {
 pnlEventControlMethodOnChage->Color = clGreen;
//FlagEventTimeOut=true;
FlagErrorDataReceiveOn=false;
TestNumComand1 = Dev_Proc->NumCommandDT;
TestErrComand1 = Dev_Proc->ErrorCommandDT;
 int NumBlockFromUSBDev_temp;

if(FlagButtonCommand){


VisualCompChange(TestErrComand1);   

}

bool TempFlagWr=false;

int countBlock = 1;


	 switch(TestErrComand1) {
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


if(!TestErrComand1||FlagErrorDataReceiveOn==true) 
	{
 /*
	Form_Main->Stop_Polling_USB();
	bool tempErrHear;
	do{
	 tempErrHear=Form_Main->Write_HID();//Write_Read(); 
	 for(int r=0;r<1000000;r++);//çàäåðæêà
	   }while(!tempErrHear);
   */
  //	Dev_Proc->TypeCommand=RESET_DEVICE;  
 /*	do{
	   tempErrHear=Form_Main->Write_Read();
		for(int r=0;r<1000000;r++);//çàäåðæêà
	  }while(!tempErrHear);
   */
  //	Form_Main->Start_Polling_USBforINIT(0,Dev_Proc->NumBlockForDataDT);
	Dev_Proc->IndexEndBloc=Dev_Proc->NumBlockForDataDT; 
  //	Dev_Proc->IndexBeginBloc=0;   


	Dev_Proc->EventNumBlockHID_EventFlag=false;
	/*  do{
	Dev_Proc->IndexBeginBloc=countBlock;   
	Dev_Proc->IndexEndBloc=countBlock;
	if(Form_Main->Write_Read())	{Dev_Proc->Data_Transfer(Dev_Proc->NumBlockFromUSBDev); countBlock++;} 
	for(int r=0;r<1000000;r++);//çàäåðæêà

	}while(Dev_Proc->NumBlockFromUSBDev!=Dev_Proc->NumBlockForDataDT);//Dev_Proc->NumBlockForDataDT);
 */

	}
	else Series1->Clear();
 //--------------------------------------------------

LabelError->Caption =pp;pp++;     //äëÿ îòëàäêè è òåñòà
 //LabelError->Caption =  Dev_Proc->NumberWordsFromDownholeTool ;
					  }

 catch (...) {
return;
}

}

void __fastcall TFormTestDES8::ChangeNumBlockHID(TObject *Sender)
{
 try {
TimerForControlEvent->Enabled=false;
FlagControlChangeNumBlockHID = true; 
pnlEventControlChNunBlHID->Color = clGreen;
  
  Dev_Proc->IndexEndBloc=0; 
 /// Form_Main->Start_Polling_USBforINIT(0,0);
  // btn_Send_Command->co
  pnl_response_command->Color=(TColor)0x0061DE71;
  Form_Main->PanelRespCommand->Color=(TColor)0x0061DE71;
 // VisualCompChange(TestErrComand1);  



      ArrayPack(Dev_Proc->TypeCommandForDownholeTool);

   Form_Main->lblNameFileDT->Caption = "Number File DT: " + IntToStr(Data_RequestM->FileNumDT);

 
	if(Form_Main->Flag_Start_Wrie)
		{
		   if(rb_Data_Request->Checked)  
			 {
			 
			 CombFileDes->Data.CurrentDepth = Data_RequestM->CurrentDepth;//  Set_DepthM->CurrentDepth;
			 CombFileDes->Data.count = 0; 
			 CombFileDes->Data.time = Set_TimeM->CurrentTimeUnix;
			 
			 int j2=0;
			  for (int j=0;j<InitMagneticSensorsM->NumPointsTimeSliceForCable;j++)
				{
				 for (int j1=0; j1 < 16; j1++) {
				  CombFileDes->Data.ArrMagnSence[j].MagnSens[j1]=DT_DES8M->DataMagneticSensors[j2];
				  j2++;
				 }
				}

			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_X_PLUS = 0;  
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_X_MINUS = 0;  
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_Y_PLUS = 0;  
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_Y_MINUS = 0; 
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_Z_PLUS = 0; 
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Count_Overflow_Z_MINUS = 0; 
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forSpeed_X = DT_DES8M->StructDataAccelGyr->SpeedX;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forSpeed_Y = DT_DES8M->StructDataAccelGyr->SpeedY;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forSpeed_Z = DT_DES8M->StructDataAccelGyr->SpeedZ;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forMove_X =  DT_DES8M->StructDataAccelGyr->MoveX;
			// CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forMove_Y =  DT_DES8M->StructDataAccelGyr->MoveY;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.NumberBlocks =  DT_DES8M->StructDataAccelGyr->NumberBlocks;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.FileNameNun =  DT_DES8M->StructDataAccelGyr->FileNameNun;
			// CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_forMove_Z =  DT_DES8M->StructDataAccelGyr->MoveZ;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.All_NubersSectors =  DT_DES8M->StructDataAccelGyr->All_NubersSectors;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.NuberFreeSectors =  DT_DES8M->StructDataAccelGyr->NuberFreeSectors;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Sum_Giro_Gyroscope = 0; 
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Temperature_Acceler = DT_DES8M->StructDataAccelGyr->TemperAccel;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.Temperature_Gyroscope = 0; 
			 CombFileDes->Data.CalGyrAccInTimeMeasur.GK_Data = DT_DES8M->StructDataAccelGyr->GK;
			 CombFileDes->Data.CalGyrAccInTimeMeasur.GK_Time = DT_DES8M->StructDataAccelGyr->TimeGK;
			 CombFileDes->Data.CalCRC32inTime = DT_DES8M->CRC32_Calculated;  
			 CombFileDes->Data.FilCRC32inTime = DT_DES8M->CRC32_FromDT;
			 CombFileDes->Data.NumPointsGyrAccelOutTimeMeasur = 0;   
			 CombFileDes->Data.CalCRC32outTime = 0;                  
			 CombFileDes->Data.FilCRC32outTime = 0;                 

			 Thread_Write_to_File->Resume();    //Resume();              //enable hread for write to file

			 }
		}

      if(rb_Data_Request->Checked)	 Form_Main->Visual_Data();                 //âèçóàëèçàöèÿ äàííûõ

   //----------------------------------------------------------------------------------------------------------

	if(FlagCycleCommand)
	{

 int NumBlockFromUSBDev_temp;

if(FlagButtonCommand){

 //outfile<< setiosflags(ios::fixed)<<setiosflags(ios::right)<<"Numer Command: "<<setw(3)<<TestNumComand1<<"      Error: "<<setw(3)<<TestErrComand1<<endl;
//FlagButtonCommand=false;
	for(long int f=0;f<1000000;f++);
   //	while(uTimer==NULL);
	Form_Main->Stop_Polling_USB();
	btn_Send_CommandClick(Sender);
					 }
	 }

  //----------------------------------------------



	if(FlagCycleSetDepthDataReq)
	{
		/*
			if(Dev_Proc->TypeCommandForDownholeTool==Data_RequestConst)
		   {
				  try {
				  NumSend_CommandToDT=Set_DepthDT;
					Send_CommandToDT(NumSend_CommandToDT);
					goto End_ChangeNumBlockHID;
						} catch (...) {
									  return;
									  }
		   } */
		if(Form_Main->Flag_Start_Wrie&&!FLAG_Start_WRITE)
		 {
			NumSend_CommandToDT = Start_Continuous_recordingConst;
			Send_CommandToDT(NumSend_CommandToDT);
			FLAG_Start_WRITE=true;   
			return;
		 }

		if(Form_Main->Flag_Stop_Wrie&&!FLAG_Stop_WRITE)
		 {
			NumSend_CommandToDT = Stop_Continuous_recordingConst;
			Send_CommandToDT(NumSend_CommandToDT);
			FLAG_Stop_WRITE=true;  
			return;
		 }

	 //	if(CountCycleSetDepthDataReq>0)
	//	   {
			NumSend_CommandToDT = Data_RequestConst;
			Send_CommandToDT(NumSend_CommandToDT);


	 }
		} catch (...)
		{
		return;
   }
}
//-----------------------------------------------------------------------------------

inline void __fastcall TFormTestDES8::ArrayPack(BYTE CommandForDownholeTool)
{
  for (i=1; i <= Dev_Proc->NumBlockForDataDT; i++) {
					Dev_Proc->BlockDataInDT =  (TDev_Proc::BlockDataInDT_T*)&Dev_Proc->BaseBlockDataInHID[i];
					i=i;
				for(i1=0;i1<=61;i1++) {
				   DT_DES8M->DataAll_DT[i1+((i-1)*62)]=Dev_Proc->BlockDataInDT->Data[i1];
				   i1=i1;
										   }

	Form_Main->FladSendingCommandToDT=false;

 indexForArray=0;
 DT_DES8M->NumCommand = DT_DES8M->DataAll_DT[indexForArray];
 indexForArray +=sizeof(DT_DES8M->NumCommand);
 DT_DES8M->CodeError = DT_DES8M->DataAll_DT[indexForArray];
 indexForArray +=sizeof(DT_DES8M->CodeError);


 
 if(CommandForDownholeTool==Data_RequestConst)
   {

	DT_DES8M->TimeInBlockData = *((UINT32*)&(DT_DES8M->DataAll_DT[indexForArray]));
	indexForArray +=sizeof(DT_DES8M->TimeInBlockData);
	//--------------------------
	if(Data_RequestM->FlagsCommand->ReqDataCurrent)
	{
	for (int j=0;j<Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;j++)
	   {
	   DT_DES8M->DataCurrent[j]= *((UINT16*)&(DT_DES8M->DataAll_DT[indexForArray]));
	   indexForArray +=sizeof(UINT16);
	   }
	 // write(iFileHandleDepth, DT_DES8M->DataAll_DT, Init_Gyro_Acceler_sensorsM->NumPointsUIforCable*1000);
 	}


	 //----------------------------
		if(Data_RequestM->FlagsCommand->ReqDataVolt)
	for (int j=0;j<Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;j++)
	   {
	   DT_DES8M->DataVolt[j]= *((UINT16*)&(DT_DES8M->DataAll_DT[indexForArray]));
	   indexForArray +=sizeof(UINT16);
	   }
	 //----------------------------
		if(Data_RequestM->FlagsCommand->ReqDataMain){
		ZeroMemory(DT_DES8M->DataMain,InitSondeM->NumPointsSondeSendCable);

	for (int j=0;j<InitSondeM->NumPointsSondeSendCable;j++)
	   {
	   DT_DES8M->DataMain[j] = 0;
	   DT_DES8M->DataMain[j] |= *((BYTE*)&(DT_DES8M->DataAll_DT[indexForArray]));
	   DT_DES8M->DataMain[j] ^= (1<<7); 
	   DT_DES8M->DataMain[j] <<=16; DT_DES8M->DataMain[j] &= ~0x00FFFF;
	   indexForArray +=sizeof(BYTE);
	   DT_DES8M->DataMain[j] |= ((*((BYTE*)&(DT_DES8M->DataAll_DT[indexForArray])))<<8);  
	   indexForArray +=sizeof(BYTE);
	   DT_DES8M->DataMain[j] |= *((BYTE*)&(DT_DES8M->DataAll_DT[indexForArray]));
	   DT_DES8M->DataMain[j] =  pow(2.,24)-DT_DES8M->DataMain[j];
	   indexForArray +=sizeof(BYTE);
	   }
	   if(indexForArray%2) indexForArray ++;

	   Series1->Clear();
	   for(int j=0;j<InitSondeM->NumPointsSondeSendCable;j++)
	   Series1->Add(DT_DES8M->DataMain[j],j) ;

													   }
	   //----------------------------
	   if(Data_RequestM->FlagsCommand->ReqDataSensMagn)
	   {
	   for (int j=0;j<(16*InitMagneticSensorsM->NumPointsTimeSliceForCable);j++)
		{
		 DT_DES8M->DataMagneticSensors[j]= *((UINT16*)&(DT_DES8M->DataAll_DT[indexForArray]));
		 indexForArray +=sizeof(UINT16);
		}

			 k=0;
		for (int j=0;j<(16*InitMagneticSensorsM->NumPointsTimeSliceForCable);j++)
		{
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin1 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos1 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin2 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos2 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin3 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos3 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin4 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos4 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin5 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos5 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin6 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos6 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin7 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos7 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Sin8 = DT_DES8M->DataMagneticSensors[j]; j++;
		 DT_DES8M->DTMagneticSensorsStruct[k].Sens_Cos8 = DT_DES8M->DataMagneticSensors[j];
		 k++;
		}
	 //	DT_DES8M->DTMagneticSensorsStruct =  (DT_DES8::MagneticSensors*)&DT_DES8M->DataMagneticSensors[0];
       FastLineSeries1->Clear();  FastLineSeries2->Clear();  FastLineSeries3->Clear(); FastLineSeries4->Clear();
	   FastLineSeries5->Clear();  FastLineSeries6->Clear();  FastLineSeries7->Clear(); FastLineSeries8->Clear();
	   FastLineSeries9->Clear();  FastLineSeries10->Clear();  FastLineSeries11->Clear(); FastLineSeries12->Clear();
	   FastLineSeries13->Clear();  FastLineSeries14->Clear();  FastLineSeries15->Clear(); FastLineSeries16->Clear();


	   for(int j=0;j<InitMagneticSensorsM->NumPointsTimeSliceForCable;j++) {

	   FastLineSeries1->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin1,j) ;
	   FastLineSeries2->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos1,j) ;
	   FastLineSeries3->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin2,j) ;
	   FastLineSeries4->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos2,j) ;
	   FastLineSeries5->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin3,j) ;
	   FastLineSeries6->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos3,j) ;
	   FastLineSeries7->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin4,j) ;
	   FastLineSeries8->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos4,j) ;
	   FastLineSeries9->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin5,j) ;
	   FastLineSeries10->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos5,j) ;
	   FastLineSeries11->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin6,j) ;
	   FastLineSeries12->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos6,j) ;
	   FastLineSeries13->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin7,j) ;
	   FastLineSeries14->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos7,j) ;
	   FastLineSeries15->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Sin8,j) ;

	   FastLineSeries16->Add(DT_DES8M->DTMagneticSensorsStruct[j].Sens_Cos8,j) ;
																		  }
	   }
//-------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
	   if(Data_RequestM->FlagsCommand->ReqDataAccelGyr)
	   {
	   for (int j=0;j<GroupDataGyroACccel_Const;j++)
		{
		 DT_DES8M->DataAccelGyr[j]= *((UINT16*)&(DT_DES8M->DataAll_DT[indexForArray]));
		 indexForArray +=sizeof(UINT16);
		}
		DT_DES8M->StructDataAccelGyr=(DT_DES8::S_DataAccelGyr*) DT_DES8M->DataAccelGyr;
		int y=0;
	   }
	   //-----------------------------------CRC32--------------------------------
	  // indexForArray+=1;
	DT_DES8M->CRC32_FromDT = *((UINT32*)&(DT_DES8M->DataAll_DT[indexForArray]));

	for (int j=indexForArray;j<indexForArray+10;j++)DT_DES8M->DataAll_DT[j]=0;

	indexForArray -=1;

	if(indexForArray%4)indexForArray += 4-(indexForArray%4);


	DT_DES8M->CRC32_Calculated = sw_calculate_soft_crc((UINT32*)&DT_DES8M->DataAll_DT[1],indexForArray/4);



	try {
 
		IxObjectInspector1->RefreshValues();  
  //IxObjectInspector1->Objects->EndUpdate();
				 } catch (...) {
  return;
  }

     if(Data_RequestM->FlagsCommand->ReqDataAccelGyr)
	   {

			try            {

	  i1=0;

	  while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"GYR_ACCELER") i1++;  
	 i2=0;
	  while(i2<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i2]->Name!=L"CRC32_Calculated") i2++;  

	 // IxObjectInspector1->Item[i2]->Value=DT_DES8M->CRC32_Calculated;
	 // IxObjectInspector1->Objects->BeginUpdate();
	// IxObjectInspector1->RefreshValues();
	   //	IxObjectInspector1->Refresh(); 
	   for(i=i1;i<=i2;i++)
	   {
		IxObjectInspector1->Item[i]->Font->Color=clTeal;

	   }
	  //  IxObjectInspector1->RefreshValues();



	   if(DT_DES8M->CRC32_Calculated!=DT_DES8M->CRC32_FromDT)
	   {
	   CRC_Control=false;
	   IxObjectInspector1->Item[i2]->Font->Color= clRed;

	   int ErrorComandTemp = DT_DES8M->CodeError;
	   GetLocalTime(&Time_Tenp);
	   outfile<< setiosflags(ios::fixed)<<std::setiosflags(ios::right)<<std::setw(3)
	   <<Time_Tenp.wYear<<"."<<Time_Tenp.wMonth<<"."<<Time_Tenp.wDay<<" "
	   <<Time_Tenp.wHour<<":"<<Time_Tenp.wMinute<<":"<<Time_Tenp.wSecond<<"::"<<Time_Tenp.wMilliseconds
	   <<"      Numer Command:"<<std::setw(3)<<NumSend_CommandToDT<<"      Error: "<<std::setw(3)<<ErrorComandTemp
	   <<"      CRC32: "<<std::setw(3)<< "Error" <<std::endl;


		Form_Main->TimerForErrorUSB->Enabled=true;

	   }
		else   CRC_Control=true;

		// 	IxObjectInspector1->Rescan();  
		IxObjectInspector1->Refresh(); 
	//   IxObjectInspector1->Objects->EndUpdate();
				   }
				   catch(...)
				   {
				   return;
				   }
	   }
	   else
	   {
				try    {
	  i1=0;
	  while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"CRC32_FromDT") i1++;  //íàõîäèì èíäåêñ ïîçèöèè  BlockAnswWords
	  IxObjectInspector1->Refresh(); 
	  IxObjectInspector1->Item[i1]->Font->Color=clTeal;
	  IxObjectInspector1->Item[i1+1]->Font->Color=clTeal;
	 //		IxObjectInspector1->Rescan(); 
	  IxObjectInspector1->Refresh();


				   }
				   catch(...) {
				   return;
				   }


	  }

   int temp_i1=0;

	try {
	while(temp_i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[temp_i1]->Name!=L"FileNumDT") temp_i1++;  //íàõîäèì èíäåêñ ïîçèöèè  FileNumDT
 IxObjectInspector1->Item[temp_i1]->Font->Color=(TColor)0x00FF0080;

  IxObjectInspector1->Refresh(); 


	} catch (...) {
	return;
	}
   //---------------------------------------

			i1=0;
	try {
	while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"WriteToSD_Card") i1++;  
 if(!Data_RequestM->WriteToSD_Card)IxObjectInspector1->Item[i1]->Font->Color=(TColor)0x000080FF;
 else  IxObjectInspector1->Item[i1]->Font->Color= clTeal;

  IxObjectInspector1->Refresh(); 


	} catch (...) {
	return;
	}

	//---------------------------------------CRC32---------------------------------------

	if(FlagErrorDataReceiveOn==true)
	{
	i1=0;
   try {
   while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"CodeAlarm") i1++;  //íàõîäèì èíäåêñ ïîçèöèè  CodeAlarm
 IxObjectInspector1->Item[i1]->Font->Color=clRed;

  IxObjectInspector1->Refresh();


   } catch (...) {
   return;
   }

	 }
   //-----------------------------------
   }  //çàïðîñ äàííûõ êîíåö
   else
   {
   if(!FlagCycleSetDepthDataReq)
	   {
	   FastLineSeries1->Clear();  FastLineSeries2->Clear();  FastLineSeries3->Clear(); FastLineSeries4->Clear();
	   FastLineSeries5->Clear();  FastLineSeries6->Clear();  FastLineSeries7->Clear(); FastLineSeries8->Clear();
	   FastLineSeries9->Clear();  FastLineSeries10->Clear();  FastLineSeries11->Clear(); FastLineSeries12->Clear();
	   FastLineSeries13->Clear();  FastLineSeries14->Clear();  FastLineSeries15->Clear(); FastLineSeries16->Clear();
	   Series1->Clear();
	   }
   }

 
 if(CommandForDownholeTool==Query_Word_state_deviceConst)
	 {
	   for (int j=0;j<Query_WordStateDeviceM->NumberResponseWords*2;j++)
	   {
	   DT_DES8M->DataRequestCommand[j] = DT_DES8M->DataAll_DT[indexForArray];
	   indexForArray +=sizeof(BYTE);
	   }
	   DT_DES8M->DataForRequestCommandStruct = (DT_DES8::DataForRequestCommand*) DT_DES8M->DataRequestCommand;
 
	   InitSondeM->TimeBeforeBeginCurrentPause  = DT_DES8M->DataForRequestCommandStruct->TimeBeforeBeginCurrentPause;
	   InitSondeM->TimeBeforeEndCurrentPause =  DT_DES8M->DataForRequestCommandStruct->TimeBeforeEndCurrentPause;
	   InitSondeM->TimeBeforeStartMainADC = DT_DES8M->DataForRequestCommandStruct->TimeBeforeStartMainADC;
	   InitSondeM->NumPointsSondeWriteFlash = DT_DES8M->DataForRequestCommandStruct->NumPointsSondeWriteFlash;
	   InitSondeM->NumPointsSondeSendCable = DT_DES8M->DataForRequestCommandStruct->NumPointsSondeSendCable;

	   InitMagneticSensorsM->NumPointsTimeSliceForCable = DT_DES8M->DataForRequestCommandStruct->NumPointsTimeSliceForCable;
	   InitMagneticSensorsM->StepOffsetFirstSensor = DT_DES8M->DataForRequestCommandStruct->StepOffsetFirstSensor;
	   InitMagneticSensorsM->NumSensDisBetwGroup =   DT_DES8M->DataForRequestCommandStruct->NumSensDisBetwGroup;
	   InitMagneticSensorsM->NumPolingCycleBefRes = DT_DES8M->DataForRequestCommandStruct->NumPolingCycleBefRes;
	   InitMagneticSensorsM->NumSensInGroup = DT_DES8M->DataForRequestCommandStruct->NumSensInGroup;
	   InitMagneticSensorsM->Reserv = DT_DES8M->DataForRequestCommandStruct->Reserv;

	   Init_Gyro_Acceler_sensorsM->NumPointsUIforCable = DT_DES8M->DataForRequestCommandStruct->NumPointsUIforCable;

	   Setting_Pot_gain_offsetM->GainPotentiometer1 = DT_DES8M->DataForRequestCommandStruct->GainPotentiometer1;
	   Setting_Pot_gain_offsetM->OffsetPotentiometer1 = DT_DES8M->DataForRequestCommandStruct->OffsetPotentiometer1;
	   Setting_Pot_gain_offsetM->GainPotentiometer2 = DT_DES8M->DataForRequestCommandStruct->GainPotentiometer2;
	   Setting_Pot_gain_offsetM->OffsetPotentiometer2 = DT_DES8M->DataForRequestCommandStruct->OffsetPotentiometer2;
	   Setting_Pot_gain_offsetM->NumberPointSwitchGainMain = DT_DES8M->DataForRequestCommandStruct->NumberPointSwitchGainMain;
   //--------------------------------------------------------------


	 IxObjectInspector1->RefreshValues();  



	try            {
		i1=0;
	  while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"ANSWER_WORDS") i1++;  //íàõîäèì èíäåêñ ïîçèöèè  BlockAnswWords
	// IxObjectInspector1->Item[i1]->Font->Color=clTeal;
	// IxObjectInspector1->Item[i1]->ValueFont->Color=clTeal;


	   for(i=i1;i<IxObjectInspector1->Items->Count-1;i++)
	   {
		IxObjectInspector1->Item[i]->Font->Color=clTeal;
		 IxObjectInspector1->Refresh(); 
	 //	IxObjectInspector1->Item[i]->ValueFont->Color=clTeal;
	   }

      		i1=0;
	  while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"MountSD") i1++;  //íàõîäèì èíäåêñ ïîçèöèè

		  if(DT_DES8M->DataForRequestCommandStruct->MountSD) IxObjectInspector1->Item[i1]->Font->Color=clTeal;
		  else IxObjectInspector1->Item[i1]->Font->Color=clRed;
		   IxObjectInspector1->Refresh(); 
				   }
				   catch(...)
					{
					return;
					 }
					  // catch(EAbort&) return;

	 }

 if(CommandForDownholeTool==EchoConst)
	 {
	  EchoM->AnswerWord= *((UINT16*)&(DT_DES8M->DataAll_DT[indexForArray]));
	  indexForArray +=sizeof(USHORT);


		 IxObjectInspector1->RefreshValues();   

		i1=0;
		while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"CodeAlarm") i1++;  
		for(i=i1;i<IxObjectInspector1->Items->Count;i++)
	   {
		IxObjectInspector1->Item[i]->Font->Color=clTeal;
		 IxObjectInspector1->Refresh(); 
		//IxObjectInspector1->Item[i]->ValueFont->Color=clTeal;
	   }
	 }




}

//----------------------------------------------------------------------------------------------------------------------------------------
inline void __fastcall TFormTestDES8::VisualCompChange(USHORT TestErrComand_In)
{
	TempCodeAlarmDevUSB1 = Dev_Proc->CodeAlarmDevUSB;


if(TestErrComand_In==TIME_OUT_DT)    
  {
 //	 hld_response_command->Blink=false;
	 pnl_response_command->Color=clRed;
	 Form_Main->PanelRespCommand->Color=clRed;
   //	 Send_CommandToDT(NumSend_CommandToDT) ;   
   //	 hld_response_command->TrueColor=clRed;
   }

  if(TestErrComand_In<TIME_OUT_DT)    
  {
 //	 hld_response_command->Blink=false;
   pnl_response_command->Color =(TColor)0x004080FF;   
   Form_Main->PanelRespCommand->Color=(TColor)0x004080FF;
  //	 hld_response_command->TrueColor=clYellow;
   }
if(!TestErrComand_In&&!TempCodeAlarmDevUSB1)
	   {
//	   hld_response_command->Blink=false;
	  pnl_response_command->Color=clGreen;
	   Form_Main->PanelRespCommand->Color=clGreen;
	 //  hld_response_command->TrueColor=clGreen;
	   }

	   pnl_response_command->Refresh();
	   Form_Main->PanelRespCommand->Refresh();
	   pnl_response_command->Repaint();
	   pnl_response_command->Update();
	   Form_Main->PanelRespCommand->Repaint();
	   Form_Main->PanelRespCommand->Update();




 //----------------------------------------------------------------------------------------------------
  if(TestErrComand_In) 
 {

if(rb_Ping->Checked) PingM->CodeAlarmPr = TestErrComand_In;
if(rb_Init_Sonde->Checked) InitSondeM->CodeAlarmPr = TestErrComand_In;
if(rb_Init_Magnetic_sensors->Checked) InitMagneticSensorsM->CodeAlarmPr = TestErrComand_In;
if(rb_Init_Gyro_Acceler_sensors->Checked) Init_Gyro_Acceler_sensorsM->CodeAlarmPr = TestErrComand_In;
if(rb_Data_Request->Checked) Data_RequestM->CodeAlarmPr = TestErrComand_In;
if(rb_Setting_Pot_gain_offset->Checked) Setting_Pot_gain_offsetM->CodeAlarmPr = TestErrComand_In;
if(rb_Start_Auto_calibr_magnetic_sensors->Checked) Start_Autocalibr_MagnSensM->CodeAlarmPr = TestErrComand_In;
if(rb_Echo->Checked) EchoM->CodeAlarmPr = TestErrComand_In;
if(rb_SettingTransmitSpeed->Checked) Set_TransmSpeedM->CodeAlarmPr = TestErrComand_In;
if(rb_Query_Word_state_device->Checked) Query_WordStateDeviceM->CodeAlarmPr = TestErrComand_In;
if(rb_Start_Continuous_recording->Checked) Start_ContinRecordM->CodeAlarmPr = TestErrComand_In;
if(rb_Stop_Continuous_recording->Checked) Stop_ContinRecordM->CodeAlarmPr = TestErrComand_In;
if(rb_Reset_SpeedMove->Checked) Reset_SpeedMoveM->CodeAlarmPr = TestErrComand_In;
if(rb_Reset_Azimuth->Checked) Reset_AzimuthM->CodeAlarmPr = TestErrComand_In;
if(rb_Set_Service_Parameters->Checked) Set_Service_ParM->CodeAlarmPr = TestErrComand_In;
if(rb_SetTime->Checked) Set_TimeM->CodeAlarmPr = TestErrComand_In;
if(rb_SetDepth->Checked) Set_DepthM->CodeAlarmPr = TestErrComand_In;



//CountCycleSetDepthDataReq=0;
if(outfile.is_open())    

	  {
	   GetLocalTime(&Time_Tenp);
	   outfile<< setiosflags(ios::fixed)<<std::setiosflags(ios::right)<<std::setw(3)
	   <<Time_Tenp.wYear<<"."<<Time_Tenp.wMonth<<"."<<Time_Tenp.wDay<<" "
	   <<Time_Tenp.wHour<<":"<<Time_Tenp.wMinute<<":"<<Time_Tenp.wSecond<<"::"<<Time_Tenp.wMilliseconds
	   <<"    Numer Command:"<<std::setw(3)<<NumSend_CommandToDT<<"      Error: "<<std::setw(3)<<TestErrComand_In<<std::endl;
	   }
  }
  else
  {
 if(rb_Ping->Checked) PingM->CodeAlarmPr = 0;
if(rb_Init_Sonde->Checked) InitSondeM->CodeAlarmPr = 0;
if(rb_Init_Magnetic_sensors->Checked) InitMagneticSensorsM->CodeAlarmPr = 0;
if(rb_Init_Gyro_Acceler_sensors->Checked) Init_Gyro_Acceler_sensorsM->CodeAlarmPr = 0;
if(rb_Data_Request->Checked) Data_RequestM->CodeAlarmPr = 0;
if(rb_Setting_Pot_gain_offset->Checked) Setting_Pot_gain_offsetM->CodeAlarmPr = 0;
if(rb_Start_Auto_calibr_magnetic_sensors->Checked) Start_Autocalibr_MagnSensM->CodeAlarmPr = 0;
if(rb_Echo->Checked) EchoM->CodeAlarmPr = 0;
if(rb_SettingTransmitSpeed->Checked) Set_TransmSpeedM->CodeAlarmPr = 0;
if(rb_Query_Word_state_device->Checked) Query_WordStateDeviceM->CodeAlarmPr = 0;
if(rb_Start_Continuous_recording->Checked) Start_ContinRecordM->CodeAlarmPr = 0;
if(rb_Stop_Continuous_recording->Checked) Stop_ContinRecordM->CodeAlarmPr = 0;
if(rb_Reset_SpeedMove->Checked) Reset_SpeedMoveM->CodeAlarmPr = 0;
if(rb_Reset_Azimuth->Checked) Reset_AzimuthM->CodeAlarmPr = 0;
if(rb_Set_Service_Parameters->Checked) Set_Service_ParM->CodeAlarmPr = 0;
if(rb_SetTime->Checked) Set_TimeM->CodeAlarmPr =0;
if(rb_SetDepth->Checked) Set_DepthM->CodeAlarmPr = 0;
  }

 i1=0;
 try {
  while(i1<IxObjectInspector1->ItemCount-1&&IxObjectInspector1->Item[i1]->Name!=L"CodeAlarm") i1++;  //íàõîäèì èíäåêñ ïîçèöèè  CodeAlarm

 } catch (...) {

 // goto End_VisualCompChange;
 return;
 }


 if(IxObjectInspector1->Items->Count>3)
			   {
 IxObjectInspector1->Item[i1]->Value=TestErrComand_In ;
if(!TestErrComand_In)
 {
  IxObjectInspector1->Item[i1]->Font->Color=clTeal;
  }
  else
	{
	TestErrComand_In=TestErrComand_In;
	 IxObjectInspector1->Item[i1]->Font->Color=clRed;
		if(Dev_Proc->TypeCommandForDownholeTool==Set_DepthDT)
		{
			CountErrorSetDepthT0DT++;
			//labelErrorForSetDepth->Caption= CountErrorSetDepthT0DT;
			//labelErrorForSetDepth->Font->Color=clRed;
			//lblNameErrSetDepth->Font->Color=clRed;
		   //	Form_Main->labelErrorForSetDepth->Caption= CountErrorSetDepthT0DT;
		  //	Form_Main->labelErrorForSetDepth->Font->Color=clRed;
		  //	Form_Main->lblNameErrSetDepth->Font->Color=clRed;

		}

		if(Dev_Proc->TypeCommandForDownholeTool==Data_RequestConst)
		{
			CountErrorData_Request++;
			labelErrorForDataReq->Caption = CountErrorData_Request;
			labelErrorForDataReq->Font->Color=clRed;
			lblNameErrDataReq->Font->Color=clRed;

			Form_Main->labelErrorForDataReq->Caption = CountErrorData_Request;

			Form_Main->labelErrorForDataReq->Font->Color=clRed;
			Form_Main->lblNameErrDataReq->Font->Color=clRed;
			Application->ProcessMessages();
		}


	}



 //IxObjectInspector1->Refresh();
 //IxObjectInspector1->Repaint();
			  }
 // End_VisualCompChange:

 //IxObjectInspector1->RefreshValues();
   //IxObjectInspector1->Refresh();
 //IxObjectInspector1->Repaint();
  }

//-------------------------------------------------------------------------------------------------------
void __fastcall TFormTestDES8::FormCreate(TObject *Sender)
{
//ïðèâÿçûâàåì ñîáûòèÿ íà îáðàáîò÷èêè
 Dev_Proc->EventTimeOut = MethodOnChage;
 Dev_Proc->EventNewDataFromDT = MethodOnChage;
 Dev_Proc->EventCodeAlarmFromDT = MethodOnChage;

 Dev_Proc->EventInitReady =  InitUSBHID;

 Dev_Proc->EventNumBlockHID = ChangeNumBlockHID;


 /*
 DT_DES8M->DataCurrent = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];//+2 íà âñÿêèé ñëó÷àé
 DT_DES8M->DataVolt = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
 DT_DES8M->DataMain = new UINT32 [InitSondeM->NumPointsSondeSendCable+2];
 DT_DES8M->DataMagneticSensors = new USHORT [(16*InitMagneticSensorsM->NumPointsTimeSliceForCable)+2];
 */
 }
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::chkCycleCommanClick(TObject *Sender)
{
 if(chkCycleComman->Checked)
 {
  chkSetDepthDataReq->Checked=false;
  chkAutoRandomComm->Checked =false;
  //outfile.open(L"Test Commands.txt",ios::out);
  FlagCycleCommand =true;
  FlagCycleSetDepthDataReq=false;

 }
 else  {
	  ///	if(FlagCycleCommand) close (iFileHandleDepth);
		FlagCycleCommand = false;

	   }
}
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::btn2Click(TObject *Sender)
{
  //	close (iFileHandleDepth);
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::chkSetDepthDataReqClick(TObject *Sender)
{
rb_Data_RequestClick(Sender);   
rb_Data_Request->Checked=true;
 CountCycleSetDepthDataReq=0;

if(chkSetDepthDataReq->Checked)
 {

   //	outfile.open(L"Log Errorss.txt",ios::out);
   //	outfile.close();
	Form_Main->ToolbtnStartPolling->ImageIndex=19;
	Form_Main->ToolbtnStartPolling->Hint="Disable Polling DT";

 CountErrorSetDepthT0DT=0;
 CountErrorData_Request=0;

 btn_Send_Command->Enabled = false;
 rb_Ping->Enabled=false;
rb_Init_Sonde->Enabled=false;
rb_Init_Magnetic_sensors->Enabled=false;
rb_Init_Gyro_Acceler_sensors->Enabled=false;
rb_Setting_Pot_gain_offset->Enabled=false;
rb_Start_Auto_calibr_magnetic_sensors->Enabled=false;
rb_Echo->Enabled=false;
//rb_SettingTransmitSpeed->Enabled=false;
rb_Query_Word_state_device->Enabled=false;
rb_Start_Continuous_recording->Enabled=false;
rb_Stop_Continuous_recording->Enabled=false;
rb_Reset_SpeedMove->Enabled=false;
rb_Reset_Azimuth->Enabled=false;
rb_Set_Service_Parameters->Enabled=false;
rb_SetTime->Enabled=false;
rb_SetDepth->Enabled=false;

 //IxObjectInspector1->Objects->Clear() ;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!óáðàòü
 chkCycleComman->Checked=false;
 chkAutoRandomComm->Checked=false;
   FlagCycleSetDepthDataReq = true;
   FlagCycleCommand=false;
  // rb_Data_Request->Checked=true;//íà÷èíàåì ñ êîìàíäû çàïðîñà äàííûõ
  NumSend_CommandToDT=Set_TimeDT;//Data_RequestConst;//Set_TimeDT;
	Send_CommandToDT(NumSend_CommandToDT) ;  
  }
 else  {

    FLAG_Start_WRITE=false; FLAG_Stop_WRITE=false;  
	outfile.close();
	Form_Main->TimerForNameForm->Enabled=true;
	Form_Main->ToolbtnStartPolling->ImageIndex=20;
	Form_Main->ToolbtnStartPolling->Hint="Enable Polling DT";
	 //	labelErrorForSetDepth->Font->Color=clBlack;
	 //	lblNameErrSetDepth->Font->Color=clBlue;
	 //	Form_Main->labelErrorForSetDepth->Font->Color=clBlack;
	  //	Form_Main->lblNameErrSetDepth->Font->Color=clBlue;

		labelErrorForDataReq->Font->Color =clBlack;
		lblNameErrDataReq->Font->Color= clBlue ;
		Form_Main->labelErrorForDataReq->Font->Color =clBlack;
		Form_Main->lblNameErrDataReq->Font->Color= clBlue ;


		btn_Send_Command->Enabled = true;
		rb_Ping->Enabled=true;
		rb_Init_Sonde->Enabled=true;
		rb_Init_Magnetic_sensors->Enabled=true;
		rb_Init_Gyro_Acceler_sensors->Enabled=true;
		rb_Setting_Pot_gain_offset->Enabled=true;
		rb_Start_Auto_calibr_magnetic_sensors->Enabled=true;
		rb_Echo->Enabled=true;
	   //rb_SettingTransmitSpeed->Enabled=false;
		rb_Query_Word_state_device->Enabled=true;
		rb_Start_Continuous_recording->Enabled=true;
		rb_Stop_Continuous_recording->Enabled=true;
		rb_Reset_SpeedMove->Enabled=true;
		rb_Reset_Azimuth->Enabled=true;
		rb_Set_Service_Parameters->Enabled=true;
		rb_SetTime->Enabled=true;
		rb_SetDepth->Enabled=true;

		FlagCycleSetDepthDataReq = false;
	   }

}
//---------------------------------------------------------------------------

//------------------------------------------------------------
void __fastcall TFormTestDES8::Send_CommandToDT(UINT16 NumCommandIn)
{
 TimerForControlEvent->Enabled=true;
 FlagControlMethodOnChage =false; 
 FlagControlChangeNumBlockHID = false ; 
 try {

  pnlEventControlChNunBlHID->Color = clBtnFace;
  pnlEventControlMethodOnChage->Color = clBtnFace;
  pnl_response_command->Color=clBtnFace;
  Form_Main->PanelRespCommand->Color=clBtnFace;


   if(!Form_Main->Error_Flag_Load_HID_DLL&&!Form_Main->Error_Flag_Load_Dev_HID&&!Form_Main->Error_Flag_Atrib_HID)
  {
  Form_Main->Stop_Polling_USB();

  Form_Main->FladSendingCommandToDT=true;

  i=11;
   for(i1=i; i1<=64; i1++) MY_HID->OutputReport[i1]=0;
  //UINT16 TempMy;
 if(NumCommandIn==PingConst)
	{
	 MY_HID->OutputReport[i] = PingM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = PingM->FlagsCommand;  i++;
	 Dev_Proc->NumberWordsFromDownholeTool =  PingM->NumberResponseWords;
	 }
	//----------
 if(NumCommandIn==Init_SondeConst)
	{
	delete [] DT_DES8M->DataMain ;
	 MY_HID->OutputReport[i] = InitSondeM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = InitSondeM->FlagsCommand; i++;
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeBeginCurrentPause);
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeEndCurrentPause);
	 To_MY_HID_OutputReport(InitSondeM->TimeBeforeStartMainADC);
	 To_MY_HID_OutputReport(InitSondeM->NumPointsSondeWriteFlash);
	 To_MY_HID_OutputReport(InitSondeM->NumPointsSondeSendCable);
	 Dev_Proc->NumberWordsFromDownholeTool =  InitSondeM->NumberResponseWords;
	 DT_DES8M->DataMain = new UINT32 [InitSondeM->NumPointsSondeSendCable+2];
	}
	//--------
 if(NumCommandIn==Init_Magnetic_sensorsConst)
 {
	 delete [] DT_DES8M->DataMagneticSensors;
	 delete [] DT_DES8M->DTMagneticSensorsStruct;       //???????????????
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumerCommand; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->FlagsCommand; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumPointsTimeSliceForCable; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->StepOffsetFirstSensor; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumSensDisBetwGroup; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumPolingCycleBefRes; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->NumSensInGroup; i++;
	 MY_HID->OutputReport[i] = InitMagneticSensorsM->Reserv; i++;
	 Dev_Proc->NumberWordsFromDownholeTool = InitMagneticSensorsM->NumberResponseWords;
	 DT_DES8M->DataMagneticSensors = new USHORT [(16*InitMagneticSensorsM->NumPointsTimeSliceForCable)+2];
	 DT_DES8M->DTMagneticSensorsStruct =  new DT_DES8::MagneticSensors [InitMagneticSensorsM->NumPointsTimeSliceForCable+1];  //???????????????
 }
 //----------
 if(NumCommandIn==Init_Gyro_Acceler_sensorsConst)
 {
  delete [] DT_DES8M->DataCurrent;
  delete [] DT_DES8M->DataVolt;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->FlagsCommand; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->NumPointsUIforCable; i++;
  MY_HID->OutputReport[i] = Init_Gyro_Acceler_sensorsM->Reserv;i++;
  Dev_Proc->NumberWordsFromDownholeTool = Init_Gyro_Acceler_sensorsM->NumberResponseWords;
  DT_DES8M->DataCurrent = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
  DT_DES8M->DataVolt = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
  }
  //-----------
  if(NumCommandIn==Data_RequestConst)
  {
   MY_HID->OutputReport[i] = Data_RequestM->NumerCommand; i++;
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataCurrent<<0);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataVolt<<1);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataMain<<2);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataSensMagn<<3);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->ReqDataAccelGyr<<4);
   MY_HID->OutputReport[i] |= (Data_RequestM->FlagsCommand->AutoCalibSensMagn<<5);
   MY_HID->OutputReport[i] |= (0<<6);
   MY_HID->OutputReport[i] |= (0<<7);
   i++;
	 Data_RequestM->CurrentDepth=Form_Main->DEPTH_out;//ãëóáèíà
	 INT32  TempMy = Data_RequestM->CurrentDepth;     //äîáàâèëè óñòàíîâêó ãëóáèíû !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB3(TempMy); i++;

   Dev_Proc->NumberWordsFromDownholeTool = Data_RequestM->NumberResponseWords;

  // Dev_Proc->NumberWordsFromDownholeTool += sizeof(DT_DES8M->TimeInBlockData)/2;
  }
  //-------------
  if(NumCommandIn==Setting_Pot_gain_offsetConst)
  {
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->NumerCommand;   i++;
  MY_HID->OutputReport[i] |= (Setting_Pot_gain_offsetM->FlagsCommand->WriteToFlashValuePot<<0); i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->GainPotentiometer1; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->OffsetPotentiometer1; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->GainPotentiometer2; i++;
  MY_HID->OutputReport[i] = Setting_Pot_gain_offsetM->OffsetPotentiometer2; i++;
  To_MY_HID_OutputReport(Setting_Pot_gain_offsetM->NumberPointSwitchGainMain);
  Dev_Proc->NumberWordsFromDownholeTool = Setting_Pot_gain_offsetM->NumberResponseWords;
  }
  //--------------------
 if(NumCommandIn==Start_Auto_calibr_magnetic_sensorsConst)
 {
  MY_HID->OutputReport[i] = Start_Autocalibr_MagnSensM->NumerCommand; i++ ;
  MY_HID->OutputReport[i] = Start_Autocalibr_MagnSensM->FlagsCommand;  i++;
  Dev_Proc->NumberWordsFromDownholeTool = Start_Autocalibr_MagnSensM->NumberResponseWords;
  }
 //------------------
 if(NumCommandIn==EchoConst)
 {
   MY_HID->OutputReport[i] = EchoM->NumerCommand; i++;
   MY_HID->OutputReport[i] = EchoM->FlagsCommand; i++;
   To_MY_HID_OutputReport(EchoM->DataCommand);
   Dev_Proc->NumberWordsFromDownholeTool = EchoM->NumberResponseWords;
  }
 //-----------------
 if(NumCommandIn==Setting_Transmit_speedConst)
 {
   MY_HID->OutputReport[i] = Set_TransmSpeedM->NumerCommand; i++;
   MY_HID->OutputReport[i] = Set_TransmSpeedM->FlagsCommand; i++;
   To_MY_HID_OutputReport(Set_TransmSpeedM->TimeForSpeedManch);
   Dev_Proc->NumberWordsFromDownholeTool = Set_TransmSpeedM->NumberResponseWords;
 }
 //-----------------
 if(NumCommandIn==Query_Word_state_deviceConst)
 {
  MY_HID->OutputReport[i] = Query_WordStateDeviceM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Query_WordStateDeviceM->FlagsCommand; i++;
  rb_Data_Request->Enabled=true;    
   Dev_Proc->NumberWordsFromDownholeTool = Query_WordStateDeviceM->NumberResponseWords;
   }
 //-----------------
 if(NumCommandIn==Start_Continuous_recordingConst)
 {
   MY_HID->OutputReport[i] =  Start_ContinRecordM->NumerCommand; i++;
   MY_HID->OutputReport[i] =  Start_ContinRecordM->FlagsCommand; i++;
   Dev_Proc->NumberWordsFromDownholeTool = Start_ContinRecordM->NumberResponseWords;
 }
 //----==
 if(NumCommandIn==Stop_Continuous_recordingConst)
 {
	 MY_HID->OutputReport[i] =  Stop_ContinRecordM->NumerCommand; i++;
	 MY_HID->OutputReport[i] =  Stop_ContinRecordM->FlagsCommand; i++;
	 Dev_Proc->NumberWordsFromDownholeTool = Stop_ContinRecordM->NumberResponseWords;
 }
 //-------------
 if(NumCommandIn==Reset_SpeedMoveConst)
 {
   MY_HID->OutputReport[i] = Reset_SpeedMoveM->NumerCommand; i++;
   MY_HID->OutputReport[i] = Reset_SpeedMoveM->FlagsCommand; i++;
   Dev_Proc->NumberWordsFromDownholeTool = Reset_SpeedMoveM->NumberResponseWords;
 }
 //--------------
 if(NumCommandIn==Reset_AzimuthConst)
 {
  MY_HID->OutputReport[i] = Reset_AzimuthM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Reset_AzimuthM->FlagsCommand; i++;
  Dev_Proc->NumberWordsFromDownholeTool = Reset_AzimuthM->NumberResponseWords;
 }
 //------------------
 if(NumCommandIn==Set_Service_Parameters)
 {
  MY_HID->OutputReport[i] = Set_Service_ParM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_Service_ParM->FlagsCommand; i++;


  int temp_i=i;
  int tmp_i;
  for(i=temp_i;i< (temp_i+Set_Service_ParM->NameArea.Length());i++)
  {
   MY_HID->OutputReport[i]= ((UINT8*)Set_Service_ParM->NameArea.c_str())[i-temp_i];
  }

   if (i<(temp_i+Set_Service_ParM->SizeNameAreaBytePr))
  {
	tmp_i=temp_i;
	temp_i=i;
	for(i=temp_i;i<(tmp_i+Set_Service_ParM->SizeNameAreaBytePr);i++)  MY_HID->OutputReport[i]= 0;
  }

  temp_i=i;
  for(i=temp_i;i< (temp_i+Set_Service_ParM->NumberNameHole.Length());i++)
  {
   MY_HID->OutputReport[i]= ((UINT8*)Set_Service_ParM->NumberNameHole.c_str())[i-temp_i];
  }

  if (i< (temp_i+Set_Service_ParM->SizeNumberNameHoleBytePr))
  {
	tmp_i=temp_i;
	temp_i=i;
	for(i=temp_i;i<(tmp_i+Set_Service_ParM->SizeNumberNameHoleBytePr);i++)  MY_HID->OutputReport[i]= 0;
  }

	 INT32  TempMy = Set_Service_ParM->BeginDepth;
	 if(TempMy&(1<<31)) TempMy |= (1<<23);
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;

	 TempMy = Set_Service_ParM->EndDepth;
	 if(TempMy&(1<<31)) TempMy |= (1<<23);
	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;

  To_MY_HID_OutputReport32(Set_Service_ParM->CurrentTimeUnix);

  Dev_Proc->NumberWordsFromDownholeTool = Set_Service_ParM->NumberResponseWords;

 }
 //--------------
 if(NumCommandIn==Set_TimeDT)
 {
  MY_HID->OutputReport[i] = Set_TimeM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_TimeM->FlagsCommand; i++;
  To_MY_HID_OutputReport32(Set_TimeM->CurrentTimeUnix);
  Dev_Proc->NumberWordsFromDownholeTool = Set_TimeM->NumberResponseWords;
 }
 //------------------------
 if(NumCommandIn==Set_DepthDT)
 {
  MY_HID->OutputReport[i] = Set_DepthM->NumerCommand; i++;
  MY_HID->OutputReport[i] = Set_DepthM->FlagsCommand; i++;
  Set_DepthM->CurrentDepth=Form_Main->DEPTH_out;//ãëóáèíà
  INT32  TempMy = Set_DepthM->CurrentDepth;
  	 MY_HID->OutputReport[i] = LSB0(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB1(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB2(TempMy); i++;
	 MY_HID->OutputReport[i] = LSB3(TempMy); i++;
  Dev_Proc->NumberWordsFromDownholeTool = Set_DepthM->NumberResponseWords;
 }
 //------------------------
 Dev_Proc->NumberBytesInCommandForDownholeTool  = i-11; 



 Dev_Proc->NumBlockForDataDT = Dev_Proc->NumberWordsFromDownholeTool/SIZE_BLOCK_DATA_WORDS_IN + ((Dev_Proc->NumberWordsFromDownholeTool%SIZE_BLOCK_DATA_WORDS_IN)>0);

 Dev_Proc->TypeCommand=INIT_DEVICE;

MY_HID->InputDataHID[0]= MY_HID->InputDataHID[0];

ZeroMemory(Dev_Proc->BaseBlockDataInHID,sizeof(Dev_Proc->BaseBlockDataInHID));
ZeroMemory(DT_DES8M->DataAll_DT,sizeof(DT_DES8M->DataAll_DT));

 FlagEventTimeOut=false;

 Form_Main->NumBlockFromSizeDataDT =0;

  bool TempFlagWr=false;

 Dev_Proc->EventInitReadyFlag=false;    
 int count_read=0;
 try {

 do{
	TempFlagWr=Form_Main->Write_Read();
	Dev_Proc->Data_Transfer(0);
	for(int r=0;r<1000000;r++);//çàäåðæêà
	count_read++;
	}while(!Dev_Proc->EventInitReadyFlag&&count_read<40) ;   
						



  } catch (...) {
  return;
 }

  }  
//====================================================================================
  else {
		MessageBox (NULL, L"USB Device Error!", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
	  // ShowMessage("USB Device Error!");
	   return;
  }

	 }
	  catch (...) {
  return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormTestDES8::Chart1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   fstForChoicePoint -> Clear();
   int WidtLeftAxis= Chart1->LeftAxis->PosAxis;
   int WidthGrapth = Chart1->Width;
   int MaxDataY = Series1->MaxYValue();
   int MinDataY = Series1->MinYValue();
   int MaxDataX = Series1->MaxXValue();
   int DiffPosLeftAzis = WidtLeftAxis*MaxDataX/WidthGrapth;
   int XdataCalcul = (X*MaxDataX)/(WidthGrapth-WidtLeftAxis)-DiffPosLeftAzis;

   fstForChoicePoint -> AddXY(XdataCalcul, MaxDataY);
   fstForChoicePoint -> AddXY(XdataCalcul, MinDataY);
	lblNumPointsForChart->Caption = XdataCalcul;

}
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::N11Click(TObject *Sender)
{
  Form_Main->NumPointMainSonde_N1= StrToInt(lblNumPointsForChart->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::N21Click(TObject *Sender)
{
 Form_Main->NumPointMainSonde_N2= StrToInt(lblNumPointsForChart->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::N31Click(TObject *Sender)
{
 Form_Main->NumPointMainSonde_N3= StrToInt(lblNumPointsForChart->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::N41Click(TObject *Sender)
{
 Form_Main->NumPointMainSonde_N4= StrToInt(lblNumPointsForChart->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::Chart2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	fstForChoicePointMagnSens -> Clear();
   int WidtLeftAxis= Chart2->LeftAxis->PosAxis;
   int WidthGrapth = Chart2->Width;
   int MaxDataY = Chart2->LeftAxis->Maximum;  //FastLineSeries2->MinYValue();
   int MinDataY = Chart2->LeftAxis->Minimum; //FastLineSeries2->MinYValue();
   int MaxDataX = FastLineSeries2->MaxXValue();
   int DiffPosLeftAzis = WidtLeftAxis*MaxDataX/WidthGrapth;
   int XdataCalcul = (X*MaxDataX)/(WidthGrapth-WidtLeftAxis)-DiffPosLeftAzis;

   fstForChoicePointMagnSens -> AddXY(XdataCalcul, MaxDataY);
   fstForChoicePointMagnSens -> AddXY(XdataCalcul, MinDataY);
	lblNumPointsForChartMagnSens->Caption = XdataCalcul;
}
//---------------------------------------------------------------------------


void __fastcall TFormTestDES8::Vs_SinClick(TObject *Sender)
{
 Form_Main->NumPointMagnSens_Vs1 = StrToInt(lblNumPointsForChartMagnSens->Caption);
 Vs_Sin->Checked=true;
 Vs_Cos->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormTestDES8::Vs_CosClick(TObject *Sender)
{
 Form_Main->NumPointMagnSens_Vs1 = StrToInt(lblNumPointsForChartMagnSens->Caption);
 Vs_Sin->Checked=false;
 Vs_Cos->Checked=true;
}
//---------------------------------------------------------------------------



