//----------------------------------------------------------------------------
#ifndef Main_FormH
#define Main_FormH
 #include "Compile.h"
 #include <string.h>
 #include <math.h>

//----------------------------------------------------------------------------
 #include "aclapi.h"

#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
//#include <System.Classes.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
//----------------------------------------------------------------------------
#include <string.h>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <dstring.h>
#include <stdio.h>

// #include <vector>

//#include <fcntl.h>

//#include "trayicon.h"

#include <System.Actions.hpp>
//#include "ALed.hpp"
#include <systdate.h>
#include <System.ImageList.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <sys\timeb.h>
#include <time.h>

#include <math.h>
#include <System.IniFiles.hpp>


#include <sys\stat.h>
 #include <process.h>
 #include <share.h>
 #include <stdlib.h>

 #include <cstring>
#include <string>
#include <string.h>


#include <pshpack4.h>
//#include <fstream.h>
#include <fstream>
#include "Mmsystem.h"
#include   <DateUtils.hpp>

//#include "iomanip.h"
 #include "UFormCorrDepth.h"
//--------------------------------------------------------------------------
#include "UDataDES.h"
  #include "UCombFileDes.h"
 #include "UDES8.h"
#include "Compile.h"

#include "UDepthWrite_File.h"
#include "UWrite_File.h"

#include "USB_Service.h"

 #include "UProc_Dev.h"
 #include "UHID_MY.h"

 #include "UFormWell.h"
 #include "UFormTestDES8.h"



//------------------------------------------------------------------------------
class TForm_Main : public TForm
{

__published:

    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    TActionList *ActionList1;
    TAction *FileNew1;
    TAction *FileOpen1;
    TAction *FileSave1;
    TAction *FileSaveAs1;
    TAction *FileExit1;
    TEditCut *EditCut1;
    TEditCopy *EditCopy1;
    TEditPaste *EditPaste1;
    TAction *HelpAbout1;
    TImageList *ImageList1;
    TMainMenu *MainMenu1;
	TMenuItem *Setup1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TTimer *TimerForDepth;
	TTimer *TimerForErrorUSB;
	TTimer *TimerForNameForm;
	TTimer *TimerForUnixTimeInStatusBar;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TMenuItem *Servicebuttons1;
	TPanel *Panel3;
	TPanel *Panel2;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButtonShowHide;
	TToolButton *ToolButton6;
	TPanel *Panel4;
	TLabel *Label9;
	TMenuItem *Well1;
	TPanel *Panel6;
	TStatusBar *StatusBar1;
	TStatusBar *StatusBar2;
	TStatusBar *StatusBar3;
	TStatusBar *StatusBar4;
	TSpeedButton *btnStartWriteToFile;
	TSpeedButton *btnStopWriteToFile;
	TLabel *Label3;
	TPanel *Panel5;
	TMenuItem *Device1;
	TMenuItem *EMDS1;
	TMenuItem *SEMD1;
	TMenuItem *DES81;
	TMenuItem *est1;
	TMenuItem *SendCommand1;
	TPanel *PanelVisualError;
	TPanel *pnlVisualDataMainSonde;
	TPanel *pnlVisualDataMagnSens;
	TSplitter *Splitter1;
	TSplitter *spl1;
	TPanel *pnlVisualDataIUGir;
	TSplitter *spl2;
	TScrollBar *scrlbrForGraph;
	TChart *chtVisualDataMainSonde;
	TChart *chtVisualDataMagnSens;
	TChart *chtVisualDataUIGir;
	THorizLineSeries *hrzlnsrsT1;
	THorizLineSeries *hrzlnsrsT2;
	THorizLineSeries *hrzlnsrsT3;
	THorizLineSeries *hrzlnsrsMS1;
	THorizLineSeries *hrzlnsrsMS2;
	THorizLineSeries *hrzlnsrsMS3;
	THorizLineSeries *hrzlnsrsMS4;
	THorizLineSeries *hrzlnsrsMS5;
	THorizLineSeries *hrzlnsrsMS6;
	THorizLineSeries *hrzlnsrsI;
	THorizLineSeries *hrzlnsrsGyr;
	THorizLineSeries *hrzlnsrsGK;
	TComboBox *cbbScaleDepth;
	THorizLineSeries *hrzlnsrsU;
	TToolBar *ToolBarAddService;
	TToolButton *ToolbtnShowTestForm;
	TPanel *PanelServiceForPolingData;
	TToolBar *ToolBar2;
	TToolButton *ToolbtnStartPolling;
	TLabel *labelErrorForDataReq;
	TLabel *lblNameErrDataReq;
	TPanel *PanelRespCommand;
	TPanel *pnlErrDataNotRead;
	TPanel *pnlErrTimeOut;
	TPanel *pnlLoadHID;
	TPanel *pnlLoadDeviceHID;
	TPanel *pnlAtributesHID;
	TPanel *pnlReadDatafromUSB;
	THorizLineSeries *hrzlnsrsAccelerX;
	THorizLineSeries *hrzlnsrsAccelerZ;
	THorizLineSeries *hrzlnsrsAccelerY;
	THorizLineSeries *hrzlnsrsMS7;
	THorizLineSeries *hrzlnsrsMS8;
	TPopupMenu *pmAcceler;
	TMenuItem *AccelerX1;
	TMenuItem *AccelerX2;
	TMenuItem *AccelerZ1;
	TLabel *lblTotalSizeSD;
	TLabel *lblFreeSD;
	TToolButton *ToolButton5;
	TToolButton *ToolbtnVisualDataFoTimer;
	TTimer *tmrForVisualData;
	TMenuItem *GKpmn1;
	TProgressBar *pbVisualFreeSectorsSD;
	TLabel *lblNameFileDT;
	TButton *btnClearGraphMainSonde;
	TButton *btnClearGraphSesMag;
	TButton *btnClearGraphGyrAcceler;
	TMenuItem *AutoSemd381;
	TMenuItem *DepthPLUS;
	TMenuItem *DepthMINUS;void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileSave1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall TimerForDepthTimer(TObject *Sender);
	void __fastcall TimerForNameFormTimer(TObject *Sender);
	void __fastcall TimerForUnixTimeInStatusBarTimer(TObject *Sender);
	void __fastcall Label1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Label1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label1MouseLeave(TObject *Sender);
	void __fastcall Label1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall TimerForErrorUSBTimer(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall Servicebuttons1Click(TObject *Sender);
	void __fastcall btnStartWriteToFileClick(TObject *Sender);
	void __fastcall btnStopWriteToFileClick(TObject *Sender);
	void __fastcall Well1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EMDS1Click(TObject *Sender);
	void __fastcall SEMD1Click(TObject *Sender);
	void __fastcall DES81Click(TObject *Sender);
	void __fastcall SendCommand1Click(TObject *Sender);
	void __fastcall cbbScaleDepthChange(TObject *Sender);
	void __fastcall ToolbtnShowTestFormClick(TObject *Sender);
	void __fastcall ToolbtnStartPollingClick(TObject *Sender);
	void __fastcall ToolbtnVisualDataFoTimerClick(TObject *Sender);
	void __fastcall tmrForVisualDataTimer(TObject *Sender);
	void __fastcall btnClearGraphSesMagClick(TObject *Sender);
	void __fastcall btnClearGraphMainSondeClick(TObject *Sender);
	void __fastcall btnClearGraphGyrAccelerClick(TObject *Sender);
	void __fastcall AutoSemd381Click(TObject *Sender);
	void __fastcall DepthPLUSClick(TObject *Sender);
	void __fastcall DepthMINUSClick(TObject *Sender);

//------------------------------------------------------------------------------------
private:


int i;
bool Init_Device;

 static VOID CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired);

 static void CALLBACK MyTimerProc(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);

  //ïðîöåäóðà òàéìåðà
   //	static void CALLBACK MyTimerProc(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);

	// User declarations
bool MouseDown_Flag, STOP_BATTON, RUN_BATTON, WRITE_BEGIN;
DWORD DWORDsize_buf_for_write;
  void __fastcall MethodOnChageDepth(TObject* Sender);
//---------------------------------------------------------------------------------
public:

 double Temp_Depth;
 double tempCorrDepth, tempCorrDepth1, tempCorrDepthPrev, tempDepthReal, FixChangeDepthReal;
 double tempCorrDepth_BettwMaxReal, tempCorrDepth_BettwMinReal;
 bool FixInversDepthPLUS, FixInversDepthMINUS, FixInversDepthPLUS_dop, FixInversDepthMINUS_dop;
 bool FlagScalePLUSMore, FlagScaleMINUSMore;
double ScaleForDepth, ScaleForDepthPrev;


	bool Flag_Event_Buf;

	   bool Flag_Buf; //ôëàã äëÿ çàïèñè â îäèí áóôåð
		 bool Flag_Buf_1;  //ôëàã äëÿ çàïèñè â äðóãîé áóôåð

 int NumPressShowClose;

 int CountSecondsForVisualData;

 //__int64   Time1_test, Time2_test;


 double Depth_Correct, Coef_Correct, FixInversDepth_Correct, FixLeftMax, FixLeftMin;
 double MeanMaxMin;

	bool Timer1_Write;	// User declarations
   bool event_close_file, Depth_event_close_file;
int Time1_t;
 BYTE NumBlockFromHID;
 BYTE NumBlockTo_HID;

   bool   Flag_Start_Wrie; 
	 bool Flag_Stop_Wrie;
	bool FladFirsREAD;

   bool   Depth_Flag_Start_Write; 
   bool Depth_Flag_Stop_Write;

   int Num_Buffer;

   int Handle_write_to_file;


	int count_Timer_for_Hread_Write_to_File, count_Timer_timeSetEvent;
	int countMyTimerProc;

		  bool Res_read, Res_wr;

	bool Result_Read, Result_ReadFirst, Result_Read_1, Result_Write;
	BYTE NumBlockFromSizeDataDT;

	bool Res_wr_Succes;
  bool FlagWriteReadSucces1;
  double DEPTH_out; 
  INT32  DEPTH_temp;

  bool Error_Flag_Load_HID_DLL;
  bool Error_Flag_Load_Dev_HID;
  bool Error_Flag_Atrib_HID;
  bool Flag_Wrie_Read; 
  bool res_write_head, Depth_res_write_head;
  AnsiString Vers_Prog;

 HANDLE Handl_Create_File, TIME_DEPTH_Handl_Create_File;
 DWORD  NumbBytesWrittenData,dwPos;
 UnicodeString NameFile, Time_NameFile, Dvoet;

 bool FladSendingCommandToDT;

 int NumPointMainSonde_N1, NumPointMainSonde_N2, NumPointMainSonde_N3, NumPointMainSonde_N4;    
  int NumPointMagnSens_Vs1; 

  SYSTEMTIME SystemTime;
//--------------------------------------------------------------
  #pragma pack (1)
  typedef struct   {
  BYTE Id;
  int Count_Depth;     
  int Depth;            
  unsigned int Time_betw_Depth;
  unsigned int Time_Sec;
  unsigned int Time_Milsec;
 void Data_File ()
 {
		Id=0x77;     
 }                  
   } Data_FileNN;               

   #pragma pack (8)

//-------------------------------------------------------------
   CRITICAL_SECTION CS;
 bool __fastcall Write_Read();
 bool __fastcall Write_HID();
 bool __fastcall Read_HID();
 void __fastcall Reset_Depth();
 void __fastcall Start_Polling_USB();
 void __fastcall Stop_Polling_USB();
 void __fastcall Start_Polling_USBforERROR(BYTE, BYTE);  
 void __fastcall Start_Polling_USBforINIT(BYTE, BYTE);
 bool __fastcall Open_File();
  bool __fastcall  DepthOpen_File() ;
 void __fastcall Close_File();
 void __fastcall Close_File_Depth();
 void __fastcall Visual_Data();

 void __fastcall ChageDepth(TObject *Sender);

// bool __fastcall WriteData_toFile(Data_FileNN *);
	virtual __fastcall TForm_Main(TComponent *AOwner);
	TDateTime __fastcall GetCurrentDateTime();
};
//----------------------------------------------------------------------------
extern TForm_Main *Form_Main;
extern bool FlagControlChangeNumBlockHID; 
//TMY_HID *TMY_HID_Proc;

//extern TDev_Proc *Dev_Proc;
//----------------------------------------------------------------------------
#endif
