//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main_Form.h"
#include "About.h"
//-----------------------------------------------------------------------

//---------------------------------------------------------------------



//#pragma link "ALed"
//#pragma link "UDES8"
#pragma resource "*.dfm"


TForm_Main *Form_Main;

 //double Temp_Depth;
 //double tempCorrDepth, tempCorrDepth1, tempCorrDepthPrev, tempDepthReal, FixChangeDepthReal;
 //bool FixInversDepthPLUS, FixInversDepthMINUS, FixInversDepthPLUS_dop, FixInversDepthMINUS_dop;
 //bool FlagScalePLUSMore, FlagScaleMINUSMore;
//double ScaleForDepth, ScaleForDepthPrev;
//---------------------------------------------------------------------------
//=================================================================================

int index_number_write=0;
//#define Num_Buffer  10

//HANDLE hTimer = NULL;
//HANDLE hTimerQueue = NULL;
//int arg = 123;
//  bool Flag_Overfl_Timer_timeSetEvent=false;
	UINT uTimer=NULL;
    __int64   Time1_test, Time2_test;

   //--------------------------------------------------------------------
   //SYSTEMTIME SystemTime;
TDateTime __fastcall TForm_Main::GetCurrentDateTime()
{
  //SYSTEMTIME SystemTime;
  GetLocalTime(&SystemTime);
  //GetSystemTime(&SystemTime);
  return SystemTimeToDateTime(SystemTime);
}
//-----------------------------------------------------------
  //  SYSTEMTIME st;
 //  MMTIME sys_m;
 //  UINT aaa;

//struct timeb t;

// short G;
// int hread_test=0;
//bool Result, Result1;



   bool FlagINC;   
	  bool FlagEnableINC=false;
	 bool FlagDepthChange;

   //  AnsiString Vers_Prog = "Version 1.0";

	 AnsiString ms_visual = " ms";

   //	 AnsiString TempText = "";
	 AnsiString NotErrorText = "  ";

	 int AddMyIntCountDepth=0;

	 #define TIME_POLING_HID       12   
										
   //	 AnsiString CodeAlarmText [8] = {"Time Out","Prev. Data Not Read", "Test", "Test1"};
 //==========================================================================================================
//-------------------------------------------------------------------
//---------------------------------------------------------------------
__fastcall TForm_Main::TForm_Main(TComponent *AOwner)
	: TForm(AOwner)
{

  Num_Buffer = 100;  
  Flag_Start_Wrie=false;
  Flag_Stop_Wrie=false;

  	 Depth_Flag_Start_Write=false;
	 Depth_Flag_Stop_Write=false;

pbVisualFreeSectorsSD->Position=0;
NumPressShowClose = 0;

//PostMessage(pbVisualFreeSectorsSD->Handle,0x0409,0,clRed);
//Start_Polling_USB();
FixInversDepthPLUS=false;
FixInversDepthMINUS = false;
FixInversDepthPLUS_dop=false;
FixInversDepthMINUS_dop = false;
FlagScaleMINUSMore = false;
FlagScalePLUSMore = false ;

NumPointMainSonde_N1=15;
NumPointMagnSens_Vs1 =10;
 NumPointMainSonde_N2=16;
  NumPointMainSonde_N3=17;
   NumPointMainSonde_N4=18;
 ScaleForDepth = StrToFloat(cbbScaleDepth->Text);
 FlagDepthChange = false  ;

event_close_file=false;
Depth_event_close_file=false;
Vers_Prog = "Version 1.0";

CombFileDes = new CombFileDesT;
CombFileDes->Header.Service.NumMagnSens=NumberMagneticSensors;
CombFileDes->Header.Service.TimePolingGyrAccel = TimeIntervPolingGyrAcceler;
CombFileDes->Header.Service.TimeForSetTimePar = TimeIntervForSetTimePar;
CombFileDes->Header.Service.TimeSampleADC24 = TimePollingADC24;
CombFileDes->Header.Service.KoeSubSampl = KoefSubSampl;

CombFileDes->Header.VersFile = 3;//DES_DATA_THROUGH_CABLE;


  /*
 AnsiString  As = "Ñîâõîçíîå ÓÏÕÃ ¹1456Ð";

char gg[100];

 //SetCodePage(As,1251);

int ff=As.Length();
//TByteDynArray ggn ;
//ggn.set_length(ff+1);
//ggn = As.BytesOf() ;
//ff=ggn.get_length();



//UINT8 *gg1 = ggn;//As.c_str() ;
//UINT16 hh = As.CodePage();

for(int u=0;u<ff;u++)gg[u]=((UINT8*)As.c_str())[u];
 */

Label3->Caption="";
Label8->Caption="";
Label9->Caption="";
btnStartWriteToFile->Visible=false;    //ñòàðò çàïèñè
btnStopWriteToFile->Visible=false;   //ñòîï çàïèñè


MouseDown_Flag = false;
STOP_BATTON = true;
InitializeCriticalSection(&CS);
  Error_Flag_Load_HID_DLL=false;
  Error_Flag_Load_Dev_HID=false;
  Error_Flag_Atrib_HID=false;
  Flag_Wrie_Read=false;
  FlagWriteReadSucces1 = false;
	    	Form_Main->Result_Write=false;
		   Form_Main->Result_Read=false;
		   Result_ReadFirst =false;
		   Form_Main->Result_Read_1 = false;
		   Form_Main->NumBlockTo_HID = 0;
		   FlagINC=true;
		   NumBlockFromSizeDataDT = 1;   
		   FladFirsREAD = false;
  countMyTimerProc=0;
//Timer2->Enabled=true;

  Thread_Write_to_File = new Write_File(true); 
  Thread_DepthWrite_File = new DepthWrite_File(true); 


  Thread_Write_to_File->FreeOnTerminate=True;  
  Thread_Write_to_File->Priority = tpNormal;

  MY_HID = new TMY_HID();
  Dev_Proc = new TDev_Proc();
 //Form_Main->TimerForUnixTimeInStatusBar->Enabled=true;

  Flag_Buf = true;
  Flag_Buf_1=false;
	// Thread_Write_to_File->Temp_Count_Depth=0;
	// Thread_Write_to_File->SizeBytes_for_Hread_Write_to_File=0;
 //----------create objects of the command

  PingM = new Ping_Data;
  InitSondeM = new InitSonde_Data;
  InitMagneticSensorsM = new InitMagneticSensors_Data;
  Init_Gyro_Acceler_sensorsM = new Init_Gyro_Acceler_sensors;
 // Data_RequestM = new Data_Request;
  Data_RequestM = new Data_Request;
  Setting_Pot_gain_offsetM = new Setting_Pot_gain_offset;
  Start_Autocalibr_MagnSensM = new Start_Autocalibr_MagnSens;
  EchoM = new Echo;
  Set_TransmSpeedM = new Set_TransmSpeed;
  Query_WordStateDeviceM = new Query_WordStateDevice;
  Start_ContinRecordM = new Start_ContinRecord;
  Stop_ContinRecordM = new Stop_ContinRecord;
  Reset_SpeedMoveM = new Reset_SpeedMove;
  Reset_AzimuthM = new Reset_Azimuth;
  Set_Service_ParM = new Set_Service_Par;
  Set_TimeM = new Set_Time;
  Set_DepthM = new Set_Depth;

	DT_DES8M = new DT_DES8;
	FladSendingCommandToDT=false;

	 Dev_Proc->EventDepthÑhanged =  MethodOnChageDepth;
   //	Reset_Depth();
  //----------------------------------------

}
//-------------------------------------------------------------------------

 void __fastcall TForm_Main::MethodOnChageDepth(TObject* Sender)
 {

   DEPTH_temp =  Dev_Proc->BlockDataInService->Depth_From_HID;

  if(ToolbtnVisualDataFoTimer->ImageIndex==32)DEPTH_out=Depth_Correct*100-CountSecondsForVisualData;

   else DEPTH_out=Depth_Correct*100-DEPTH_temp;

if(Depth_Flag_Start_Write) // åñëè ñòàðò çàïèñè â ôàéë ãëóáèíû ñî âðåìåíåì
  {
   if(count_Timer_for_Hread_Write_to_File==0)
	{  
  if(Flag_Buf&&(DEPTH_temp!=Dev_Proc->Data_File_Depth_1[Num_Buffer-1].Count_Depth))
		{
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Id = 0x77;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Count_Depth = DEPTH_temp;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Depth = (int)DEPTH_out;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_betw_Depth = Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_Sec = DateTimeToUnix(GetCurrentDateTime());
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_Milsec = SystemTime.wMilliseconds;
   count_Timer_for_Hread_Write_to_File++;
   //AddMyIntCountDepth++;
		 }
 
  if(Flag_Buf_1&&(DEPTH_temp!=Dev_Proc->Data_File_Depth[Num_Buffer-1].Count_Depth))
		 {
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Id = 0x77;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Count_Depth = DEPTH_temp;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Depth = (int)DEPTH_out;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_betw_Depth = Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_Sec = DateTimeToUnix(GetCurrentDateTime());
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_Milsec = SystemTime.wMilliseconds;
  count_Timer_for_Hread_Write_to_File++;
  //AddMyIntCountDepth++;
		  }
	  } //end if(count_Timer_for_Hread_Write_to_File==0)
//----------------------------------------------------
if(count_Timer_for_Hread_Write_to_File>0)
	 {
  if(Flag_Buf&&(DEPTH_temp!=Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File-1].Count_Depth))  //åñëè äðóãîé áóôåð îòðàáîòàë è èçìåíèëàñü ãëóáèíà
	   {
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Id = 0x77;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Count_Depth = DEPTH_temp;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Depth = (int)DEPTH_out;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_betw_Depth = Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID;
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_Sec = DateTimeToUnix(GetCurrentDateTime());
  Dev_Proc->Data_File_Depth[count_Timer_for_Hread_Write_to_File].Time_Milsec = SystemTime.wMilliseconds;
   count_Timer_for_Hread_Write_to_File++;
 //  AddMyIntCountDepth++;
		}

  if(Flag_Buf_1&&(DEPTH_temp!=Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File-1].Count_Depth))  //åñëè äðóãîé áóôåð îòðàáîòàë è èçìåíèëàñü ãëóáèíà
		 {
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Id = 0x77;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Count_Depth = DEPTH_temp;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Depth = (int)DEPTH_out;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_betw_Depth = Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID;
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_Sec = DateTimeToUnix(GetCurrentDateTime());
  Dev_Proc->Data_File_Depth_1[count_Timer_for_Hread_Write_to_File].Time_Milsec = SystemTime.wMilliseconds;
   count_Timer_for_Hread_Write_to_File++;
  // AddMyIntCountDepth++;
		 }
	  } //end if(count_Timer_for_Hread_Write_to_File>0)

//-----------------------------------------------------------------
	  if(count_Timer_for_Hread_Write_to_File==Num_Buffer)      //1000-ðàçìåð ìàññèâà ñòðóêòóð
       {
		   if(Flag_Buf)
					 {
					 Flag_Buf=false; Flag_Buf_1=true;
					 Flag_Event_Buf = true;
					 }  //Flag_Event_Buf - ÷òîáû íå ñðàáîòàë ñëåäóþùèé if
		   if(Flag_Buf_1&&!Flag_Event_Buf)
					 {
					 Flag_Buf_1=false; Flag_Buf=true;
					 }
				//	 AddMyIntCountDepth=count_Timer_for_Hread_Write_to_File;
		   count_Timer_for_Hread_Write_to_File=0;

		   Thread_DepthWrite_File->Resume();                //enable hread for write to file Time depth

           Flag_Event_Buf = false;
	   }
   } 
 }
// for read

//-----------------------------------------------------------------------

void __fastcall TForm_Main::FileNew1Execute(TObject *Sender)
{
  // Do nothing

}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::FileSave1Execute(TObject *Sender)
{
  SaveDialog->Execute();        
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::FileExit1Execute(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::HelpAbout1Execute(TObject *Sender)
{
  AboutBox->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::About1Click(TObject *Sender)
{
 AboutBox->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::ToolButton1Click(TObject *Sender)
{
Sevice_USB->Cleat_Edits();

MY_HID->Close_HID();


//time_count_test=0;
  MY_HID->Set_HID_Func();
  if(!MY_HID->Load_HID_DLL())
 {
  MessageBox (NULL, L"Can't load HID.DLL", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
  return;
  }

MY_HID->Load_Dev_HID();

Sevice_USB->Edit1->Text = "SetupDiGetClassDevs - "+SysErrorMessage(MY_HID->ErrorCode_SetupDiGetClassDevs);
Sevice_USB->Edit2->Text = "SetupDiEnumDeviceInterfaces - "+SysErrorMessage(MY_HID->ErrorCode_SetupDiEnumDeviceInterfaces);
Sevice_USB->Edit3->Text = "SetupDiGetInterfaceDeviceDetail - "+SysErrorMessage(MY_HID->ErrorCode_SetupDiGetInterfaceDeviceDetail);
Sevice_USB->Edit4->Text = "CreateFile - "+SysErrorMessage(MY_HID->ErrorCode_CreateFile);

Sevice_USB->Memo1->Lines->Add((AnsiString)MY_HID->DevInfoDetail->DevicePath);


  MY_HID->Attributes.Size = sizeof(MY_HID->Attributes);
  MY_HID->Result = MY_HID->HidD_GetAttributes(MY_HID->DeviceHandle,&MY_HID->Attributes);
  if(MY_HID->Result) {
  Sevice_USB->Memo1->Lines->Add("VendorID = "+(AnsiString)MY_HID->Attributes.VendorID);
  Sevice_USB->Memo1->Lines->Add("ProductID = "+(AnsiString)MY_HID->Attributes.ProductID);
  Sevice_USB->Memo1->Lines->Add("VersionNumber = "+(AnsiString)MY_HID->Attributes.VersionNumber);
			  }
			  else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetAttributes");

  MY_HID->Result = MY_HID->HidD_GetNumInputBuffers(MY_HID->DeviceHandle,&MY_HID->inputBuffer);
  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("Number input buffers = "+(AnsiString)MY_HID->inputBuffer);
			  else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetNumInputBuffers");

 //	LPTSTR Buffer = NULL;
 //	LocalFree(Buffer);

	  ZeroMemory(MY_HID->Buffer,sizeof(MY_HID->Buffer));
	  MY_HID->Result = MY_HID->HidD_GetProductString(MY_HID->DeviceHandle,MY_HID->Buffer,MY_HID->BufferLength);
	  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("Product = " + (AnsiString)MY_HID->Buffer);
				else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetProductString");

	  ZeroMemory(MY_HID->Buffer,sizeof(MY_HID->Buffer));
	  MY_HID->Result = MY_HID->HidD_GetManufacturerString(MY_HID->DeviceHandle,MY_HID->Buffer,MY_HID->BufferLength);
	  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("Manufacturer = " + (AnsiString)MY_HID->Buffer);
				else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetManufacturerString");

	  ZeroMemory(MY_HID->Buffer,sizeof(MY_HID->Buffer));
	  MY_HID->Result = MY_HID->HidD_GetSerialNumberString(MY_HID->DeviceHandle,MY_HID->Buffer,MY_HID->BufferLength);
	  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("SerNum = " + (AnsiString)MY_HID->Buffer);
				else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetSerialNumberString");

  MY_HID->Result = MY_HID->HidD_GetPreparsedData(MY_HID->DeviceHandle,&MY_HID->PreparsedData);
  if(MY_HID->Result)
		   {
		   MY_HID->HidP_GetCaps(MY_HID->PreparsedData, &MY_HID->Capabilities);
		   Sevice_USB->Memo1->Lines->Add("UsagePage = " + (AnsiString)MY_HID->Capabilities.UsagePage);
		   Sevice_USB->Memo1->Lines->Add("InputReportByteLength = " + (AnsiString)MY_HID->Capabilities.InputReportByteLength);
		   Sevice_USB->Memo1->Lines->Add("OutputReportByteLength = " + (AnsiString)MY_HID->Capabilities.OutputReportByteLength);
		   Sevice_USB->Memo1->Lines->Add("FeatureReportByteLength = " + (AnsiString)MY_HID->Capabilities.FeatureReportByteLength);
		}
			else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetPreparsedData");

	  ZeroMemory(MY_HID->InputDataHID,sizeof(MY_HID->InputDataHID));

	  MY_HID->Result = MY_HID->HidD_GetInputReport(MY_HID->DeviceHandle, &MY_HID->InputDataHID, MY_HID->ReportBufferLength);
	  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("Read = " + (AnsiString)((char)MY_HID->InputDataHID));
				else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetInputReport");

	  if (MY_HID->Capabilities.FeatureReportByteLength > 0)
					  {
	  ZeroMemory(MY_HID->InputDataHID,sizeof(MY_HID->InputDataHID));
	  MY_HID->Result = MY_HID->HidD_GetFeature(MY_HID->DeviceHandle, MY_HID->InputDataHID, MY_HID->Capabilities.FeatureReportByteLength);
	  if(MY_HID->Result)Sevice_USB->Memo1->Lines->Add("Read = " + (AnsiString)(char)MY_HID->InputDataHID);
				else Sevice_USB->Memo1->Lines->Add("ERROR HidD_GetFeature");
					  }
					  else Sevice_USB->Memo1->Lines->Add("ERROR FeatureReport don't support");

//------------------------------------------------------------------------
 ZeroMemory(MY_HID->OutputReport,sizeof(MY_HID->OutputReport));
//Dev_Proc->type_device = SEMD;
//Dev_Proc->type_command = INIT_DEVICE;
Dev_Proc->TypeCommand = INIT_DEVICE;
//Dev_Proc->Index_Begin_Block = 0;
Dev_Proc->IndexBeginBloc = 0;
//Dev_Proc->Index_End_Block = 1;
Dev_Proc->IndexEndBloc=1;
//Dev_Proc->Time_for_Curr_Pause=1;;
Dev_Proc->TimeCurrentPause=1;
//Dev_Proc->TimeOut_for_Data=1;
Dev_Proc->TimeOutReceivData=1;
//Dev_Proc->Number_Word_Devce=1;// äëÿ øóìîìåðà 1023
Dev_Proc->NumberWordsFromDownholeTool=1;
	  /*
	  ZeroMemory(MY_HID->OutputReport,sizeof(MY_HID->OutputReport));
	 //	MY_HID->OutputReport[1] =  Dev_Proc->type_device;
		MY_HID->OutputReport[2] =  Dev_Proc->type_command;
		MY_HID->OutputReport[3] =  Dev_Proc->Index_Begin_Block;
		MY_HID->OutputReport[4] = Dev_Proc->Index_End_Block;
		MY_HID->OutputReport[5] = Dev_Proc->Time_for_Curr_Pause;
		MY_HID->OutputReport[6] = Dev_Proc->TimeOut_for_Data;
		MY_HID->OutputReport[7] = LSB(Dev_Proc->Number_Word_Devce);
		MY_HID->OutputReport[8] = MSB(Dev_Proc->Number_Word_Devce);
	  */
if(MY_HID->Capabilities.OutputReportByteLength > 0)Write_Read();

 //------------------------------------------------------------------------


Sevice_USB->Edit6->Text = "WriteFile - "+SysErrorMessage(MY_HID->ErrorCode_WriteFile);
Sevice_USB->Edit7->Text = "ReadFile - "+SysErrorMessage(MY_HID->ErrorCode_ReadFile);
  Dev_Proc->Set_USB_Dev();

MY_HID->MemberIndex++;

Sevice_USB->ShowModal();

}
//---------------------------------------------------------------------------

void CALLBACK TForm_Main::MyTimerProc(UINT uTimerID, UINT uMsg,
                              DWORD dwUser, DWORD dw1, DWORD dw2)
{

try {


 Form_Main->Time1_t=Form_Main->Time1_t;

  //	while(!Form_Main->Write_HID());
  //	   for(int r=0;r<1000000;r++);
  //	while(!Form_Main->Read_HID());
						Form_Main->Res_read=false;
if(MY_HID->Capabilities.InputReportByteLength > 0&&Form_Main->Write_Read())  //åñëè çàïðîñ-÷òåíèå áëîêà óñïåøíî
  {
  

  Form_Main->Flag_Wrie_Read = true;
 Time1_test = Time2_test;
 Time2_test = Form_Main->SystemTime.wMilliseconds+1000*DateTimeToUnix(Form_Main->GetCurrentDateTime());

  //---------------
  if(MY_HID->InputDataHID[1]==0x77)
  {
   Form_Main->NumBlockFromHID = 0;
  }
  else
	  Form_Main->NumBlockFromHID = MY_HID->InputDataHID[1];
   
   Dev_Proc->Data_Transfer(Form_Main->NumBlockFromHID);

  
			   MY_HID->InputDataHID[0] = MY_HID->InputDataHID[0];

 }   // end if(Res_read)
 else 
	 {
	  if(!Form_Main->FladSendingCommandToDT)  
	  {
	 Form_Main->Flag_Wrie_Read = false;
	 Form_Main->TimerForErrorUSB->Enabled=true;
	 timeKillEvent(uTimer);  // stop timer
	 Form_Main->NumBlockTo_HID=0;
	 FlagINC=true;
       }
	 }

	 Form_Main->countMyTimerProc++;
	 } catch (...) {
	 return;
	}
 }

void __fastcall TForm_Main::TimerForDepthTimer(TObject *Sender)
{
  //Dev_Proc->BlockDataInService = (TDev_Proc::BlockDataInServiceT*)&Dev_Proc->BlockDataInHID[0];
 //Timer1_Write=true;
 //Label2->Caption=hread_test;
//Dev_Proc->Speed_Dev =0;

try {


if(Res_read)
//if(Result_Write&&Result_Read)
{    

  pnlReadDatafromUSB->Color=clLime; //ALedReadDatafromUSB->Value=false;

   if(Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID>0&&Dev_Proc->Time_Single_Tick_Time_from_HID>0)
   {
	Dev_Proc->Speed_Dev = Dev_Proc->Step_Depth_Real*3600/((double)Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID*Dev_Proc->Time_Single_Tick_Time_from_HID);
	}

if(Temp_Depth>DEPTH_out)
{
 FixInversDepthPLUS_dop = false;
 FixInversDepthMINUS_dop = true;
}

if(Temp_Depth<DEPTH_out)
{
 FixInversDepthPLUS_dop = true;
 FixInversDepthMINUS_dop = false;
}

if(Temp_Depth!=DEPTH_out)
{

}
//--------------------------------------------------------------------------------------

Temp_Depth=DEPTH_out;

Label1->Caption=FloatToStrF(DEPTH_out/100,ffFixed,8,2);

Label2->Caption=Dev_Proc->Speed_Dev;
		   }
	} catch (...)
	   {
	   return;
	   }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm_Main::TimerForNameFormTimer(TObject *Sender)
{
static int CountTimerThis=0;
 if(CountTimerThis==0)
 {
		TimerForNameForm->Enabled=false;
	//    Form_Main->Caption="Regisration data video.  "+Vers_Prog;
	AboutBox->ProductName->Caption="Test downhole electro-\nmagnetic flaw detector\nDEMFD\n(Kimry)";
	AboutBox->Version->Caption=Vers_Prog;
	AboutBox->Copyright->Caption="2013 NIIGT, All Rights Reserved.";
	AboutBox->Comments->Caption="Laboratory gas-dynamic research (Ivanov O.)";

	
	 Depth_Correct=DEPTH_out/100;
	 Reset_Depth();
 }
 try {
 if(CountTimerThis>0)
  {
	   TimerForNameForm->Enabled=false;
	   PanelRespCommand->Color=clBtnFace;
	   PanelRespCommand->Refresh();
	   PanelRespCommand->Repaint();
	   PanelRespCommand->Update();
  }
  CountTimerThis++;
	 } catch (...)
		 {
		 return;
		 }
 

}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::TimerForUnixTimeInStatusBarTimer(TObject *Sender)
{
try {


 BYTE TempCodeAlarmDevUSB;
TempCodeAlarmDevUSB = Dev_Proc->CodeAlarmDevUSB;
if(TempCodeAlarmDevUSB)     //> 0
  {
  if(IsÑheckBits(TempCodeAlarmDevUSB,ALARM_TIME_OUT))pnlErrTimeOut->Color=clRed;
  if(IsÑheckBits(TempCodeAlarmDevUSB,ALARM_DATA_PREV_NOT_READ)) pnlErrDataNotRead->Color=clRed;
  }
   else
	   {
	   pnlErrTimeOut->Color= clSilver;
	   pnlErrDataNotRead->Color= clSilver;
	   }
//Label3->Caption=Time1_test;
//if(!ComboBoxForError->DroppedDown)ComboBoxForError->DroppedDown=true;
//ListViewForError->AddItem(IntToStr(1),reinterpret_cast<TObject*>(11));
//ListViewForError->AddItem(IntToStr(2),reinterpret_cast<TObject*>(11));


 //AnsiString TempText1 = "";

StatusBar1->SimpleText=(AnsiString)Time1_test+ms_visual;
//Label4->Caption=Time2_test;
StatusBar3->SimpleText=(AnsiString)Time2_test+ms_visual;
int tempddd= Time1_test-Time2_test;
int tt1= abs(tempddd);
 // Label5->Caption=abs(Time1_test-Time2_test);
 // StatusBar2->SimpleText= (AnsiString)abs(Time1_test-Time2_test)+ms_visual; //ïðîáëåìû ñ 64 áèòíîé êîìïèëÿöèåé!!!!!!!!!!!!!!
 StatusBar2->SimpleText= (AnsiString)tt1+ms_visual;

	  } catch (...)
	  {
	  return;
		}

}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Reset_Depth()
{
Label1->Caption=Depth_Correct; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!3
Label2->Caption=0;
hrzlnsrsT1->Clear();
hrzlnsrsT2->Clear();
 hrzlnsrsMS1 ->Clear();
 hrzlnsrsMS2 ->Clear();
 hrzlnsrsMS3 ->Clear();
 hrzlnsrsMS4 ->Clear();
 hrzlnsrsMS5 ->Clear();
 hrzlnsrsMS6 ->Clear();
 hrzlnsrsMS7 ->Clear();
 hrzlnsrsMS8 ->Clear();
hrzlnsrsAccelerX->Clear();
hrzlnsrsAccelerY->Clear();
hrzlnsrsAccelerZ->Clear();
hrzlnsrsGK->Clear();

ScaleForDepth = StrToFloat(cbbScaleDepth->Text);
tempCorrDepth = DEPTH_out/100-Depth_Correct;
 // if(FixInversDepthMINUS)
// {
// chtVisualDataMainSonde->LeftAxis->SetMinMax(Depth_Correct- Depth_Correct,ScaleForDepth);
// }

// if(FixInversDepthPLUS)
// {
// chtVisualDataMainSonde->LeftAxis->SetMinMax(Depth_Correct, Depth_Correct+ScaleForDepth);  //äëÿ ïëþñ
// }
 chtVisualDataMainSonde->LeftAxis->SetMinMax(Depth_Correct-ScaleForDepth/2, Depth_Correct+ScaleForDepth/2);
 chtVisualDataUIGir->LeftAxis->SetMinMax(Depth_Correct-ScaleForDepth/2, Depth_Correct+ScaleForDepth/2);
 chtVisualDataMagnSens->LeftAxis->SetMinMax(Depth_Correct-ScaleForDepth/2, Depth_Correct+ScaleForDepth/2);

 chtVisualDataMainSonde->BottomAxis->SetMinMax(0, 17000000);
 chtVisualDataMagnSens->BottomAxis->SetMinMax(0, 65535);
 chtVisualDataUIGir ->BottomAxis->SetMinMax(-8200, 100000);



//count_Timer_for_Hread_Write_to_File=0;
 Stop_Polling_USB();
 Dev_Proc->Reset_Depth();// MY_HID->OutputReport[2] = RESET_M_Depth_Magnet_Mark;
 if(Write_Read()) Start_Polling_USBforERROR(0,0);
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::Start_Polling_USB()
{
//Reset_Depth();
ToolButton1->Enabled=false;

 // count_Timer_for_Hread_Write_to_File=0;
   count_Timer_timeSetEvent=0;
  Thread_Write_to_File->SizeBytes_for_Hread_Write_to_File=0;
	  timeBeginPeriod(0);
	  uTimer = timeSetEvent(TIME_POLING_HID,0,(LPTIMECALLBACK)MyTimerProc,1,TIME_PERIODIC);   

}
//---------------------------------------------------------------------------
void __fastcall TForm_Main::Start_Polling_USBforERROR(BYTE begBlock, BYTE endBlock  )    
{
ToolButton1->Enabled=false;
	  // MY_HID->OutputReport[2] = 0;
	   Dev_Proc->TypeCommand=RECEIVING_DATA;
	   //MY_HID->OutputReport[3] = begBlock;  
		Dev_Proc->IndexBeginBloc  =  begBlock;

		 Dev_Proc->IndexEndBloc = endBlock;

	  timeBeginPeriod(0);
	  uTimer = timeSetEvent(TIME_POLING_HID,0,(LPTIMECALLBACK)MyTimerProc,1,TIME_PERIODIC);   
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm_Main::Start_Polling_USBforINIT(BYTE begBlock, BYTE endBlock  )    
{
	  ToolButton1->Enabled=false;

		 Dev_Proc->IndexBeginBloc  =  begBlock;


	  timeBeginPeriod(0);
	  uTimer = timeSetEvent(TIME_POLING_HID,0,(LPTIMECALLBACK)MyTimerProc,1,TIME_PERIODIC);   //3 ms - ïåðèîä â XP íå ðàáîòàåò (ñ òî÷íîñòüþ 15,6 ms)
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Stop_Polling_USB()
{
ToolButton1->Enabled=true;
//count_Timer_for_Hread_Write_to_File=0;
Thread_Write_to_File->SizeBytes_for_Hread_Write_to_File=0;
count_Timer_timeSetEvent=0;

timeKillEvent(uTimer);  // stop timer
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm_Main::Label1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   MouseDown_Flag = true;
 if(STOP_BATTON&&!Error_Flag_Load_HID_DLL&&!Error_Flag_Load_Dev_HID&&!Error_Flag_Atrib_HID)
			 {
			 Label1->Color=(TColor)0x00DB9D80;//clCream;
			  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Label1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
  if(STOP_BATTON&&MouseDown_Flag == false)
	   {
	  Label1->Color=(TColor)0x00EFD3CA;//clGradientActiveCaption;
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Label1MouseLeave(TObject *Sender)
{
   if(MouseDown_Flag == false)
		 {
		 Label1->Color=clBtnFace;
			 }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Label1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
MouseDown_Flag = false;
   if(STOP_BATTON&&!Error_Flag_Load_HID_DLL&&!Error_Flag_Load_Dev_HID&&!Error_Flag_Atrib_HID)
				 {
				Label1->Color=clBtnFace;
                               Application->RestoreTopMosts();

                               // MessageBox(L"This should be on top.", L"Look", MB_YESNO);
                                if(MessageBox (NULL, L"Do you want change DEPTH?", L"WARNING", MB_YESNO|MB_ICONWARNING|MB_TASKMODAL)==IDYES)
				Form_Corr_Depth->ShowModal();
                                 else return;
				  }
}
//---------------------------------------------------------------------------





void __fastcall TForm_Main::TimerForErrorUSBTimer(TObject *Sender)
{

 try {


	Form_Main->pnlReadDatafromUSB->Color=clRed; 
 if(Dev_Proc->Time_Single_Tick_Time_from_HID>0)MY_HID->Close_HID();

 MY_HID->Set_HID_Func();
 if(!MY_HID->Load_HID_DLL())  Error_Flag_Load_HID_DLL = true;
 else  Error_Flag_Load_HID_DLL = false;
if(Error_Flag_Load_HID_DLL){pnlLoadHID->Color=clRed;}// ALedLoadHID->Value=true;}
else   {pnlLoadHID->Color=clLime; }/

 if(!MY_HID->Load_Dev_HID())  Error_Flag_Load_Dev_HID = true;
 else  Error_Flag_Load_Dev_HID = false;
 if(Error_Flag_Load_Dev_HID){pnlLoadDeviceHID->Color=clRed; }//ALedLoadDeviceHID->Value=true;}
else   {pnlLoadDeviceHID->Color=clLime; }// 

 if(!MY_HID->Atrib_HID())  Error_Flag_Atrib_HID = true;
 else  Error_Flag_Atrib_HID = false;
 if(Error_Flag_Atrib_HID){pnlAtributesHID->Color=clRed;}// ALedAtributesHID->Value=true;}
else   {pnlAtributesHID->Color=clLime; }//

 //------------------------------------------------------------------------
if(!Error_Flag_Load_HID_DLL&&!Error_Flag_Load_Dev_HID&&!Error_Flag_Atrib_HID)
  {
 Label8->Caption="";
 btnStartWriteToFile->Visible=true;

if(!STOP_BATTON&&RUN_BATTON){
 Label3->Font->Color=clGreen;
// Label3->Caption="";
 Label9->Caption="";
 //Label9->Font->Name="System";
 Label3->Caption="Ðåãèñòðàöèÿ\n   äàííûõ";
		 }

	  if(uTimer!=NULL) Stop_Polling_USB();
	  ZeroMemory(MY_HID->OutputReport,sizeof(MY_HID->OutputReport));

  Dev_Proc->InitDefaultCommandForDownholeTool(Dev_Proc->Init_Selected_Device.M_type_device);

 bool tempErrHear;


	do{
	 tempErrHear=Write_HID();
	 for(int r=0;r<1000000;r++);
	   }while(!tempErrHear);

  i=i;

	do{
	   tempErrHear=Write_Read();
		for(int r=0;r<1000000;r++);//çàäåðæêà
	  }while(!tempErrHear);

   Dev_Proc->Set_USB_Dev();
   TimerForErrorUSB->Enabled=false;

   Start_Polling_USBforERROR(0,0);   
  //	Start_Polling_USB();
	Form_Main->TimerForUnixTimeInStatusBar->Enabled=true;

	if(FormTestDES8->chkSetDepthDataReq->Checked)  FormTestDES8->Send_CommandToDT(FormTestDES8->NumSend_CommandToDT);


   }
   else
	 {
		   btnStartWriteToFile->Visible=false;
	  Label8->Caption="No connect with\nwith USB device";

		  if(!STOP_BATTON&&RUN_BATTON){
			 Label9->Font->Color=clRed;
			// Label9->Caption="";
			 Label3->Caption="";
		   //  Label9->Font->Name="Times New Roman";
		   //  Label9->Font->Size=8;
			 Label9->Caption="Çàïèñü ïðèîñòàíîâëåíà";
							 }
	   Form_Main->TimerForUnixTimeInStatusBar->Enabled=false;
	  // EditForError->Color=clWhite;
	 }
 Dev_Proc->CodeAlarmDevUSB=0; // EditForError->Text = NotErrorText;
 pnlErrTimeOut->Color= clSilver;
 pnlErrDataNotRead->Color= clSilver;
	   } catch (...) {
	   return;
	  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::ToolButton3Click(TObject *Sender)
{
 Start_Polling_USB();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::ToolButton4Click(TObject *Sender)
{
 Stop_Polling_USB();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::ToolButton6Click(TObject *Sender)
{
 Reset_Depth();
}
//---------------------------------------------------------------------------



void __fastcall TForm_Main::Servicebuttons1Click(TObject *Sender)
{
  if(Servicebuttons1->Checked) {
  Servicebuttons1->Checked=false;
	ToolButton3->Enabled=false; ToolButton4->Enabled=false; ToolButton6->Enabled=false;
  }
  else {
  Servicebuttons1->Checked=true;
  ToolButton3->Enabled=true; ToolButton4->Enabled=true; ToolButton6->Enabled=true;
  }
}
//---------------------------------------------------------------------------
bool __fastcall TForm_Main::Open_File()
{


   Handl_Create_File = CreateFile (NameFile.w_str(),
								  FILE_APPEND_DATA,//GENERIC_READ|GENERIC_WRITE,
								  FILE_SHARE_READ,//FILE_SHARE_READ|FILE_SHARE_WRITE,
								  NULL,
								  OPEN_ALWAYS,
								  FILE_ATTRIBUTE_ARCHIVE,
								  NULL);
 if(Handl_Create_File == INVALID_HANDLE_VALUE)       //| O_APPEND
						   {
  MessageBox (NULL, L"Can't open file for Data", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
  return false;
  }
  else return true;
}
//-----------------------------------------------------------------------------
bool __fastcall TForm_Main::DepthOpen_File()
{


 TIME_DEPTH_Handl_Create_File = CreateFile (Time_NameFile.w_str(),
								  FILE_APPEND_DATA,//GENERIC_READ|GENERIC_WRITE,
								  FILE_SHARE_READ,//FILE_SHARE_READ|FILE_SHARE_WRITE,
								  NULL,
								  OPEN_ALWAYS,
								  FILE_ATTRIBUTE_ARCHIVE,
								  NULL);

if(TIME_DEPTH_Handl_Create_File == INVALID_HANDLE_VALUE)       //| O_APPEND
						   {
  MessageBox (NULL, L"Can't open file for Depth Time", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
  return false;
  }
  else return true;
}
//------------------------------------------------------------------------------
void __fastcall TForm_Main::Close_File()
{

  CloseHandle(Handl_Create_File);

  event_close_file=true;
 }
//------------------------------------------------------------------------------
void __fastcall TForm_Main::Close_File_Depth()
{
   CloseHandle(TIME_DEPTH_Handl_Create_File);
   Depth_event_close_file=true;
 }
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void __fastcall TForm_Main::btnStartWriteToFileClick(TObject *Sender)
{

FormTestDES8->FLAG_Start_WRITE=false;

if(Error_Flag_Load_HID_DLL||Error_Flag_Load_Dev_HID||Error_Flag_Atrib_HID)  //åñëè îøèáêè
		{
			Label9->Font->Color=clRed;
						Label9->Caption="";
                        Label3->Caption="";
		}
		else
			{   //åñëè âñå íîðìàëüíî
//-----------------------------------ñòàðò çïèñè â ñêâàæèííîì ïðèáîðå
//if(Flag_Stop_Wrie)
//{
	Flag_Stop_Wrie=false;
 

 //FormTestDES8->NumSend_CommandToDT = Start_Continuous_recordingConst;
 if(!FormTestDES8->chkSetDepthDataReq->Checked)   
  {
  FormTestDES8->NumSend_CommandToDT = Start_Continuous_recordingConst;
  FormTestDES8->Send_CommandToDT(FormTestDES8->NumSend_CommandToDT) ;   
  }


//}
//----------------------------------------------------------------------------------
 Thread_Write_to_File->ClearArrForWriteToFile();

 count_Timer_for_Hread_Write_to_File=0;   
 Thread_Write_to_File->SizeBytes_for_Hread_Write_to_File=0;

   NameFile="";
   Time_NameFile="";
   GetCurrentDateTime();

   NameFile=(UnicodeString)FormWell->Name_Well+ ";" + SystemTime.wYear + "-"+ SystemTime.wMonth + "-"+SystemTime.wDay+
   "-"+SystemTime.wHour+ "-" + SystemTime.wMinute + "-" + SystemTime.wSecond + "-" +SystemTime.wMilliseconds + ".COMBDES";

   Time_NameFile=(UnicodeString)FormWell->Name_Well+ ";" + SystemTime.wYear + "-"+ SystemTime.wMonth + "-"+SystemTime.wDay+
   "-"+SystemTime.wHour+ "-" + SystemTime.wMinute + "-" + SystemTime.wSecond + "-" +SystemTime.wMilliseconds + ".TIMEDEPTH";



 
  //------------------------------------------------------------
if(Open_File()) // åñëè óñïåøíî ñîçäàëè è îòêðûëè ôàéë
   {

 delete [] CombFileDes->Data.ArrMagnSence;
  Well1->Enabled=false;   //âûêë. ìåíþ "Well"
  Servicebuttons1->Enabled=false;
  Flag_Start_Wrie=true;
  Flag_Stop_Wrie=false;

//  	Thread_DepthWrite_File->Start();    //Resume();        //äëÿ ïðîâåðêè
//------------------------------------------------------------------------------------


CombFileDes->Header.TimeStartCurrentPause = InitSondeM->TimeBeforeBeginCurrentPause;
CombFileDes->Header.TimeEndCurrentPause = InitSondeM->TimeBeforeEndCurrentPause;
CombFileDes->Header.TimeStartAdc24 = InitSondeM->TimeBeforeStartMainADC;
CombFileDes->Header.Adc24_SizeDataForWritingToFlash = InitSondeM->NumPointsSondeWriteFlash;
CombFileDes->Header.Adc24_SizeDataToTransferForCable = InitSondeM->NumPointsSondeSendCable;
CombFileDes->Header.SizeDataMainSonde = InitSondeM->NumPointsSondeSendCable;
CombFileDes->Header.SizeMagneticData =  InitMagneticSensorsM->NumPointsTimeSliceForCable; 
CombFileDes->Header.SizeDataUI =Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;
CombFileDes->Header.Nds = InitMagneticSensorsM->NumPointsTimeSliceForCable;
CombFileDes->Header.Nof = InitMagneticSensorsM->StepOffsetFirstSensor;
CombFileDes->Header.Nstep = InitMagneticSensorsM->NumSensDisBetwGroup;
CombFileDes->Header.Nit =  InitMagneticSensorsM->NumPolingCycleBefRes;
CombFileDes->Header.Ngr = InitMagneticSensorsM->NumSensInGroup;
CombFileDes->Header.null_value = 0;
//std::strcpy(CombFileDes->Header.WellPlace, FormWell->Name_Area.c_str());
//std::strcpy(CombFileDes->Header.WellName,  FormWell->Name_Well.c_str());

std::strcpy((char*)CombFileDes->Header.WellPlace, FormWell->Name_Area.c_str());
std::strcpy((char*)CombFileDes->Header.WellName,  FormWell->Name_Well.c_str());

UINT32 TempDepthM=Depth_Correct*100;
 CombFileDes->Header.StartDepth[0] = LSB0(TempDepthM);
 CombFileDes->Header.StartDepth[1] = LSB1(TempDepthM);
 CombFileDes->Header.StartDepth[2] = LSB2(TempDepthM);

 CombFileDes->Header.StopDepth[0] = LSB0(TempDepthM); 
 CombFileDes->Header.StopDepth[1] = LSB1(TempDepthM);  
 CombFileDes->Header.StopDepth[2] = LSB2(TempDepthM); 

 CombFileDes->Header.SyncTime = Set_TimeM->CurrentTimeUnix;
 CombFileDes->Header.debug_flug = 0; 

 CombFileDes->Header.SizeDataGyrAccelInTimeMeasur = 0;


 CombFileDes->Header.SizeArrGyrAccelOutTimeMeasur = 0; 

   res_write_head = WriteFile(Handl_Create_File, &CombFileDes->Header, sizeof(CombFileDes->Header), &NumbBytesWrittenData, NULL);

 CombFileDes->Data.ArrMagnSence = new CombFileDesT::MagnSenceStr [CombFileDes->Header.SizeMagneticData+10];

 
//------------------------------------------------------------------------------------
			STOP_BATTON = false;
			RUN_BATTON = true;
			WRITE_BEGIN = true;

			btnStartWriteToFile->Visible=false;
			btnStopWriteToFile->Visible=true;

			Label3->Font->Color=clGreen;
                        Label3->Caption="";
                        Label9->Caption="";
			Label3->Caption="Ðåãèñòðàöèÿ\n   äàííûõ";
	   //	if(!event_close_file) Close_File();      

//
 Close_File();   

	}
//------------------------------------------------------------------------
  if(DepthOpen_File())
   {
	 Depth_Flag_Start_Write=true;
	 Depth_Flag_Stop_Write=false;
	 DWORDsize_buf_for_write = sizeof(FormWell->numberCharNameWell);
	
	 Depth_res_write_head=WriteFile (TIME_DEPTH_Handl_Create_File, &FormWell->numberCharNameWell, DWORDsize_buf_for_write, &NumbBytesWrittenData, NULL);


	DWORDsize_buf_for_write = FormWell->numberCharNameWell;
	Depth_res_write_head=WriteFile (TIME_DEPTH_Handl_Create_File, FormWell->charNameWell, DWORDsize_buf_for_write, &NumbBytesWrittenData, NULL);
	Close_File_Depth();
   }


			}    //end else
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::btnStopWriteToFileClick(TObject *Sender)
{
//if(ToolbtnStartPolling->ImageIndex==19) ToolbtnStartPollingClick(Sender);

FormTestDES8->FLAG_Stop_WRITE=false;

 RUN_BATTON = false;
STOP_BATTON = true;
WRITE_BEGIN = false;

//SpeedButton1->Visible=true;
btnStopWriteToFile->Visible=false;
Label3->Caption="";
Label9->Caption="";


if(Flag_Start_Wrie)//&&count_Timer_for_Hread_Write_to_File>0)  
 {
Flag_Stop_Wrie=true;
Flag_Start_Wrie = false;

 if(!FormTestDES8->chkSetDepthDataReq->Checked) 
 {
 FormTestDES8->NumSend_CommandToDT = Stop_Continuous_recordingConst;
 FormTestDES8->Send_CommandToDT(FormTestDES8->NumSend_CommandToDT) ;  
 }


while(!Thread_Write_to_File->Suspended); 

//Thread_Write_to_File->Suspended;
 }
//WriteData_toFile(PData_File_Depth);

if(!event_close_file)
 {
   Close_File();   
   }
event_close_file=false;
//======================================================================================================================================

if(Depth_Flag_Start_Write&&count_Timer_for_Hread_Write_to_File>0)  
 {
Depth_Flag_Stop_Write=true;
Depth_Flag_Start_Write=false;

while(!Thread_DepthWrite_File->Suspended);
Thread_DepthWrite_File->Resume();
while(!Thread_DepthWrite_File->Suspended); 
 }

if(!Depth_event_close_file)
 {
   Close_File_Depth();   
 }
Depth_event_close_file=false;

Well1->Enabled=true;     

	 index_number_write++;
 btnStartWriteToFile->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Well1Click(TObject *Sender)
{
 FormWell->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall TForm_Main::FormShow(TObject *Sender)
{
 FormTestDES8->outfile.open(L"Log Errorss.txt",ios::out);
  FormTestDES8->FLAG_Start_WRITE=false; FormTestDES8->FLAG_Stop_WRITE=false;
 FormWell->ValueListEditor1->Values["Name Area"] ="ONGKM" ;
 FormWell->ValueListEditor1->Values["Name Well"]="TEST";
 FormWell->Name_Area = FormWell->ValueListEditor1->Values["Name Area"];
 FormWell->Name_Well=FormWell->ValueListEditor1->Values["Name Well"];
FormWell->numberCharNameWell=FormWell->Name_Well.Length();
FormWell->charNameWell=new char[FormWell->numberCharNameWell];
ZeroMemory(FormWell->charNameWell,FormWell->numberCharNameWell);
FormWell->charNameWell=FormWell->Name_Well.c_str();
Form_Main->Caption="";
FormWell->Number="   ( Name Well - ";
//SEMD1->Checked=true;// default choice device SEMD-90;
DES81->Checked=false;  
//if(DES81->Checked)
//{
DES81Click(Sender);  
//AutoSemd381Click(Sender);
//}
 FormWell->NumberFormShow=0; 
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::EMDS1Click(TObject *Sender)
{
if(!EMDS1->Checked) {
					 EMDS1->Checked=true; SEMD1->Checked=false; DES81->Checked=false; AutoSemd381->Checked=false;
					  SendCommand1->Enabled=false;
					 }
Form_Main->Caption= "Downhole electro magnetic flaw detector.  "+ Form_Main->Vers_Prog + FormWell->Number+ FormWell->Name_Well+" ) Device type:  EMDS-I";
Dev_Proc->Init_Selected_Device.M_type_device = EMDS_I;
Dev_Proc->Init_Selected_Device.M_type_command = INIT_DEVICE;
Dev_Proc->Init_Selected_Device.M_Index_Begin_Block = 0;
Dev_Proc->Init_Selected_Device.M_Index_End_Block = 0;
Dev_Proc->Init_Selected_Device.M_Time_for_Curr_Pause=1;;
Dev_Proc->Init_Selected_Device.M_TimeOut_for_Data=1;
Dev_Proc->Init_Selected_Device.M_Number_Word_Devce=1;

}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::SEMD1Click(TObject *Sender)
{
 if(!SEMD1->Checked) {
					 EMDS1->Checked=false; SEMD1->Checked=true; DES81->Checked=false;  AutoSemd381->Checked=false;
					  SendCommand1->Enabled=false;
					 }
 Form_Main->Caption= "Downhole electro magnetic flaw detector.  "+ Form_Main->Vers_Prog + FormWell->Number+ FormWell->Name_Well+" ) Device type:  SEMD-90";
Dev_Proc->Init_Selected_Device.M_type_device = SEMD;
Dev_Proc->Init_Selected_Device.M_type_command = INIT_DEVICE;
Dev_Proc->Init_Selected_Device.M_Index_Begin_Block = 0;
Dev_Proc->Init_Selected_Device.M_Index_End_Block = 0;
Dev_Proc->Init_Selected_Device.M_Time_for_Curr_Pause=129;
Dev_Proc->Init_Selected_Device.M_TimeOut_for_Data=1;
Dev_Proc->Init_Selected_Device.M_Number_Word_Devce=1;
//Dev_Proc->TypeDevice = SEMD;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::DES81Click(TObject *Sender)
{
if(!DES81->Checked) {
					 EMDS1->Checked=false; SEMD1->Checked=false; DES81->Checked=true; AutoSemd381->Checked=false;
					  SendCommand1->Enabled=true;
					 }
Form_Main->Caption= "Downhole electro magnetic flaw detector.  "+ Form_Main->Vers_Prog + FormWell->Number+ FormWell->Name_Well+" ) Device type:  SEMD-38";
Dev_Proc->Init_Selected_Device.M_type_device = DES8;
Dev_Proc->Init_Selected_Device.M_type_command = INIT_DEVICE;

Dev_Proc->Init_Selected_Device.M_Index_Begin_Block = 0;
Dev_Proc->Init_Selected_Device.M_Index_End_Block = 0;

Dev_Proc->Init_Selected_Device.M_Time_for_Curr_Pause=1;  

Dev_Proc->Init_Selected_Device.M_TimeOut_for_Data=50;   // 31.25 ms îäèí òàêò / 10 - 312.5 ms è ò.ä.     
														
Dev_Proc->Init_Selected_Device.M_Number_Word_Devce=PingM->NumberResponseWords;
FormTestDES8->rb_Ping->Enabled=true;
FormTestDES8->rb_Init_Sonde->Enabled=true;
FormTestDES8->rb_Init_Magnetic_sensors->Enabled=true;
FormTestDES8->rb_Init_Gyro_Acceler_sensors->Enabled=true;
FormTestDES8->rb_Setting_Pot_gain_offset->Enabled=true;
FormTestDES8->rb_Start_Auto_calibr_magnetic_sensors->Enabled=true;
FormTestDES8->rb_Echo->Enabled=true;
//rb_SettingTransmitSpeed->Enabled=false;
FormTestDES8->rb_Query_Word_state_device->Enabled=true;
FormTestDES8->rb_Start_Continuous_recording->Enabled=true;
FormTestDES8->rb_Stop_Continuous_recording->Enabled=true;
FormTestDES8->rb_Reset_SpeedMove->Enabled=true;
FormTestDES8->rb_Reset_Azimuth->Enabled=true;
FormTestDES8->rb_Set_Service_Parameters->Enabled=true;
FormTestDES8->rb_SetTime->Enabled=true;
FormTestDES8->rb_SetDepth->Enabled=true;

Form_Main->TimerForErrorUSB->Enabled=true;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::SendCommand1Click(TObject *Sender)
{
  if(DES81->Checked) {
  FormTestDES8->PingClick();
 // FormTestDES8->Show();
  ToolbtnShowTestFormClick(Sender);
	 }

 }
//---------------------------------------------------------------------------
 void __fastcall TForm_Main::Visual_Data()
{
	 double total_size =Data_RequestM->Total_NubersSectorsSD;
	 double free_size = Data_RequestM->NuberFreeSectorsSD;
	 pbVisualFreeSectorsSD->Position = 100*free_size/total_size;

  if(Data_RequestM->WriteToSD_Card)
  {
 //  pbVisualFreeSectorsSD->Enabled=true;
  if(pbVisualFreeSectorsSD->Position<5)
   {
   pbVisualFreeSectorsSD->BarColor=clRed;
   lblFreeSD->Font->Color=clRed;//åñëè ìåíåå 5% òîãäà êðàñíûé
	lblTotalSizeSD->Font->Color =clRed;
   }
	else
	   {
		pbVisualFreeSectorsSD->BarColor=clGreen;
		lblFreeSD->Font->Color=clGreen;
		lblTotalSizeSD->Font->Color =  clBlack;
		lblNameFileDT->Font->Color =  clBlack;
	   //	   pbVisualFreeSectorsSD->Realign();
	 //  pbVisualFreeSectorsSD->Refresh();
   //		   pbVisualFreeSectorsSD->Repaint();
	   }
  }
	 else
		{

 //	   pbVisualFreeSectorsSD->BarColor=clYellow;
   //	   pbVisualFreeSectorsSD->Enabled=false;


		//	pbVisualFreeSectorsSD->Position -=1;
	   lblFreeSD->Font->Color=(TColor)0x000080FF;
	   lblTotalSizeSD->Font->Color=(TColor)0x000080FF;
	   lblNameFileDT->Font->Color = (TColor)0x000080FF;
	  // pbVisualFreeSectorsSD->Position -=10;

  //	   pbVisualFreeSectorsSD->Realign();
	//   pbVisualFreeSectorsSD->Refresh();
   //		   pbVisualFreeSectorsSD->Repaint();
        }



  lblTotalSizeSD->Caption= "Total size: "+FloatToStrF(total_size*512/(1024*1024),ffFixed,8,2)+" MiB";
  lblFreeSD->Caption=      "Free size: "+FloatToStrF(free_size*512/(1024*1024),ffFixed,8,2)+" MiB";

 // if(ToolbtnVisualDataFoTimer->ImageIndex==32) tempDepthReal = (double)CountSecondsForVisualData/100;   
 // else
  tempDepthReal = DEPTH_out/100;

  hrzlnsrsT1->AddXY(DT_DES8M->DataMain[NumPointMainSonde_N1], tempDepthReal);
  hrzlnsrsT2->AddXY(DT_DES8M->DataMain[NumPointMainSonde_N2], tempDepthReal);

  if(FormTestDES8->Vs_Cos->Checked)
  {
  hrzlnsrsMS1 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos1, tempDepthReal);
  hrzlnsrsMS2 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos2, tempDepthReal);
  hrzlnsrsMS3 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos3, tempDepthReal);
  hrzlnsrsMS4 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos4, tempDepthReal);
  hrzlnsrsMS5 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos5, tempDepthReal);
  hrzlnsrsMS6 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos6, tempDepthReal);
  hrzlnsrsMS7 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos7, tempDepthReal);
  hrzlnsrsMS8 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Cos8, tempDepthReal);
  }
  //-------------------------------------
	if(FormTestDES8->Vs_Sin->Checked)
  {
  hrzlnsrsMS1 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin1, tempDepthReal);
  hrzlnsrsMS2 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin2, tempDepthReal);
  hrzlnsrsMS3 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin3, tempDepthReal);
  hrzlnsrsMS4 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin4, tempDepthReal);
  hrzlnsrsMS5 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin5, tempDepthReal);
  hrzlnsrsMS6 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin6, tempDepthReal);
  hrzlnsrsMS7 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin7, tempDepthReal);
  hrzlnsrsMS8 -> AddXY(DT_DES8M->DTMagneticSensorsStruct[NumPointMagnSens_Vs1].Sens_Sin8, tempDepthReal);
  }
 //---------------------------------------
  hrzlnsrsAccelerX -> AddXY(DT_DES8M->StructDataAccelGyr->AccelerationX, tempDepthReal);
  hrzlnsrsAccelerY -> AddXY(DT_DES8M->StructDataAccelGyr->AccelerationY, tempDepthReal);
  hrzlnsrsAccelerZ -> AddXY(DT_DES8M->StructDataAccelGyr->AccelerationZ, tempDepthReal);

 double TempGK_Data= Data_RequestM->GK ; double TempGK_TimeData= Data_RequestM->TimeGK;
  if(TempGK_TimeData==0) TempGK_TimeData=1;
  double GK_Data= TempGK_Data /((TempGK_TimeData*500)/60000000);     
  hrzlnsrsGK -> AddXY(GK_Data, tempDepthReal);
  //hrzlnsrsGK -> AddXY(TempGK_TimeData, tempDepthReal);   

  tempCorrDepthPrev=0;

  tempCorrDepthPrev = tempCorrDepth;
  tempCorrDepth = (tempDepthReal-Depth_Correct);

  tempCorrDepth1 = (tempDepthReal - FixChangeDepthReal);  

	 FixLeftMax = chtVisualDataMainSonde->LeftAxis->Maximum; 
	 FixLeftMin = chtVisualDataMainSonde->LeftAxis->Minimum; 
	 MeanMaxMin = (FixLeftMax + FixLeftMin)/2;

	 tempCorrDepth_BettwMaxReal = FixLeftMax -tempDepthReal;
	 tempCorrDepth_BettwMinReal = FixLeftMin -tempDepthReal;

 if(tempCorrDepthPrev<tempCorrDepth)
  {
	 FixInversDepthMINUS=false;
	 FixInversDepthPLUS =true;
  if(!FlagDepthChange)
  {
  if(tempDepthReal>(MeanMaxMin+ScaleForDepth/2))//ScaleForDepth/2)
	{
	chtVisualDataMainSonde->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
	chtVisualDataUIGir->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
	chtVisualDataMagnSens->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
	}
  //	 else
  //		{
  //	chtVisualDataMainSonde->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
  //	chtVisualDataUIGir->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
  //	chtVisualDataMagnSens->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
   //     }

   }
   else   
	   {
	   if(fabs(tempCorrDepth1)>ScaleForDepth/2)
		{
		chtVisualDataMainSonde->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
		chtVisualDataUIGir->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
		chtVisualDataMagnSens->LeftAxis->SetMinMax(FixLeftMin+fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax+fabs(tempCorrDepthPrev-tempCorrDepth));
		}
	   }
  }
 //-----------------------
 if(tempCorrDepthPrev>tempCorrDepth)
  {

	FixInversDepthPLUS = false;
	FixInversDepthMINUS=true;
	  if(!FlagDepthChange)
	  {
		if(tempDepthReal<(MeanMaxMin-ScaleForDepth/2))   
		{
		 chtVisualDataMainSonde->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		 chtVisualDataUIGir->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		 chtVisualDataMagnSens->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		}
	  }
	   else
	   {   
		if(fabs(tempCorrDepth1)>ScaleForDepth/2)
		 {
		  chtVisualDataMainSonde->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		  chtVisualDataUIGir->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		  chtVisualDataMagnSens->LeftAxis->SetMinMax(FixLeftMin-fabs(tempCorrDepthPrev-tempCorrDepth), FixLeftMax-fabs(tempCorrDepthPrev-tempCorrDepth));
		 }
	  }
  }
 //----------------------------------
}

void __fastcall TForm_Main::cbbScaleDepthChange(TObject *Sender)
{
tempCorrDepth =DEPTH_out/100-Depth_Correct;

 //static double TempScale;
 //TempScale=ScaleForDepth;
 ScaleForDepthPrev = ScaleForDepth;
 ScaleForDepth = StrToFloat(cbbScaleDepth->Text);
	 FixLeftMax = chtVisualDataMainSonde->LeftAxis->Maximum; 
	 FixLeftMin = chtVisualDataMainSonde->LeftAxis->Minimum; 
 if(ScaleForDepth>ScaleForDepthPrev)
   {
     FlagDepthChange = true;
	 chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);

	 chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
	 chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
	 FixChangeDepthReal= tempDepthReal;
	}
	 else
		{
		if(FlagDepthChange)
			 {
			 if(FixInversDepthPLUS)
			  {
			  chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  }
			  if(FixInversDepthMINUS)
			  {
			  chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  }
			 }
			  else    //FlagDepthChange = true
				  {
		 if(FixInversDepthPLUS)
			  {
			  chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  }
		 if(FixInversDepthMINUS)
			  {
			  chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
			  }

				  }
			 FlagDepthChange = false;
		}

		ScaleForDepth=ScaleForDepth;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::ToolbtnShowTestFormClick(TObject *Sender)
{
//rmTestDES8->PingClick();
 if(ToolbtnShowTestForm->ImageIndex==21) { FormTestDES8->Show(); return;}
 if(ToolbtnShowTestForm->ImageIndex==22) { FormTestDES8->Close(); }
}




void __fastcall TForm_Main::ToolbtnStartPollingClick(TObject *Sender)
{
  FormTestDES8->rb_Data_RequestClick(FormTestDES8->rb_Data_Request);  
  FormTestDES8->rb_Data_Request->Checked=true;
 // chkSetDepthDataReqClick

   if(!FormTestDES8->chkSetDepthDataReq->Checked)
   {
	FormTestDES8->chkSetDepthDataReq->Checked=true;
  //	btnStartWriteToFile->Visible=true;
  //	FormTestDES8->chkSetDepthDataReqClick(FormTestDES8->chkSetDepthDataReq); 
	}
	else
	   {
	TimerForNameForm->Enabled=true;
	FormTestDES8->chkSetDepthDataReq->Checked=false;
   //	FormTestDES8->chkSetDepthDataReqClick(FormTestDES8->chkSetDepthDataReq); 
		}
}
//---------------------------------------------------------------------------



void __fastcall TForm_Main::ToolbtnVisualDataFoTimerClick(TObject *Sender)
{

  if(ToolbtnVisualDataFoTimer->ImageIndex==28)
											 {
											 ToolbtnVisualDataFoTimer->ImageIndex=32;
											 ToolbtnVisualDataFoTimer->Down=true;
											 tmrForVisualData->Enabled=true;
											 Reset_Depth();
											 CountSecondsForVisualData=0;
											

											 return;
											 }

  if(ToolbtnVisualDataFoTimer->ImageIndex==32)
											  {
											  ToolbtnVisualDataFoTimer->ImageIndex=28;
											  ToolbtnVisualDataFoTimer->Down=false;
											  tmrForVisualData->Enabled=false;
										  //	  return;
											  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::tmrForVisualDataTimer(TObject *Sender)
{
   if(DepthPLUS->Checked) CountSecondsForVisualData++;
   if(DepthMINUS->Checked)CountSecondsForVisualData--; 
   MethodOnChageDepth(Sender);
  // Visual_Data();   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
//---------------------------------------------------------------------------
void __fastcall TForm_Main::ChageDepth(TObject *Sender)
{
 MethodOnChageDepth(Sender);
}

//------------------------------------------------------------------------------

void __fastcall TForm_Main::btnClearGraphSesMagClick(TObject *Sender)
{
  hrzlnsrsMS1 -> Clear();
  hrzlnsrsMS2 -> Clear();
  hrzlnsrsMS3 -> Clear();
  hrzlnsrsMS4 -> Clear();
  hrzlnsrsMS5 -> Clear();
  hrzlnsrsMS6 -> Clear();
  hrzlnsrsMS7 -> Clear();
  hrzlnsrsMS8 -> Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::btnClearGraphMainSondeClick(TObject *Sender)
{
  hrzlnsrsT1->Clear();
  hrzlnsrsT2->Clear();
 //	 chtVisualDataMainSonde->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
 //	 chtVisualDataUIGir->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
 //	 chtVisualDataMagnSens->LeftAxis->SetMinMax(tempDepthReal-ScaleForDepth/2, tempDepthReal+ScaleForDepth/2);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::btnClearGraphGyrAccelerClick(TObject *Sender)
{
  hrzlnsrsAccelerX -> Clear();
  hrzlnsrsAccelerY -> Clear();
  hrzlnsrsAccelerZ -> Clear();
  hrzlnsrsGK ->  Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::AutoSemd381Click(TObject *Sender)
{
 if(!AutoSemd381->Checked) {
					 EMDS1->Checked=false; SEMD1->Checked=false; DES81->Checked=false;  AutoSemd381->Checked=true;
					  SendCommand1->Enabled=true;
					 }
Form_Main->Caption= "Downhole electro magnetic flaw detector.  "+ Form_Main->Vers_Prog + FormWell->Number+ FormWell->Name_Well+" ) Device type:  SEMD-38";
Dev_Proc->Init_Selected_Device.M_type_device = AutoDES8;
Dev_Proc->Init_Selected_Device.M_type_command = INIT_DEVICE;

Dev_Proc->Init_Selected_Device.M_Index_Begin_Block = 0;
Dev_Proc->Init_Selected_Device.M_Index_End_Block = 0;

Dev_Proc->Init_Selected_Device.M_Time_for_Curr_Pause=1; 

Dev_Proc->Init_Selected_Device.M_TimeOut_for_Data=50; 
Dev_Proc->Init_Selected_Device.M_Number_Word_Devce=PingM->NumberResponseWords;

InitSondeM->TimeBeforeBeginCurrentPause  = 0;
InitSondeM->TimeBeforeEndCurrentPause =   7000;
InitSondeM->TimeBeforeStartMainADC =   1;
InitSondeM->NumPointsSondeWriteFlash = 7000;
InitSondeM->NumPointsSondeSendCable = 96;

	   InitMagneticSensorsM->NumPointsTimeSliceForCable = 20;
	   InitMagneticSensorsM->StepOffsetFirstSensor = 0;
	   InitMagneticSensorsM->NumSensDisBetwGroup =   0;
	   InitMagneticSensorsM->NumPolingCycleBefRes = 0;
	   InitMagneticSensorsM->NumSensInGroup = 2;
	   InitMagneticSensorsM->Reserv = 0;

	   Init_Gyro_Acceler_sensorsM->NumPointsUIforCable = 3;

	   Setting_Pot_gain_offsetM->GainPotentiometer1 = 7;
	   Setting_Pot_gain_offsetM->OffsetPotentiometer1 = 70;
	   Setting_Pot_gain_offsetM->GainPotentiometer2 = 255;
	   Setting_Pot_gain_offsetM->OffsetPotentiometer2 = 75;
	   Setting_Pot_gain_offsetM->NumberPointSwitchGainMain = 6500;   

   Data_RequestM->FlagsCommand->ReqDataCurrent=true;
   Data_RequestM->FlagsCommand->ReqDataVolt=false;
   Data_RequestM->FlagsCommand->ReqDataMain=true;
   Data_RequestM->FlagsCommand->ReqDataSensMagn=true;
   Data_RequestM->FlagsCommand->ReqDataAccelGyr=true;
   Data_RequestM->FlagsCommand->AutoCalibSensMagn=false;


//FormTestDES8->btn_Send_Command->Enabled = false;
//FormTestDES8->rb_Ping->Enabled=false;
FormTestDES8->rb_Init_Sonde->Enabled=false;
FormTestDES8->rb_Init_Magnetic_sensors->Enabled=false;
FormTestDES8->rb_Init_Gyro_Acceler_sensors->Enabled=false;
FormTestDES8->rb_Setting_Pot_gain_offset->Enabled=false;
FormTestDES8->rb_Start_Auto_calibr_magnetic_sensors->Enabled=false;
FormTestDES8->rb_Echo->Enabled=false;
//rb_SettingTransmitSpeed->Enabled=false;
FormTestDES8->rb_Query_Word_state_device->Enabled=false;
FormTestDES8->rb_Start_Continuous_recording->Enabled=false;
FormTestDES8->rb_Stop_Continuous_recording->Enabled=false;
FormTestDES8->rb_Reset_SpeedMove->Enabled=false;
FormTestDES8->rb_Reset_Azimuth->Enabled=false;
FormTestDES8->rb_Set_Service_Parameters->Enabled=false;
FormTestDES8->rb_SetTime->Enabled=false;
FormTestDES8->rb_SetDepth->Enabled=false;

Form_Main->TimerForErrorUSB->Enabled=true;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
//---------------------------------------------------------------------------


void __fastcall TForm_Main::DepthPLUSClick(TObject *Sender)
{
if(!DepthPLUS->Checked){
   DepthPLUS->Checked=true;
   DepthMINUS->Checked=false;
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::DepthMINUSClick(TObject *Sender)
{
   if(!DepthMINUS->Checked) {
   DepthMINUS->Checked=true;
   DepthPLUS->Checked=false;
   }
}
//---------------------------------------------------------------------------

