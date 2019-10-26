//---------------------------------------------------------------------------

#ifndef UFormTestDES8H
#define UFormTestDES8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//#include "ALed.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include "Main_Form.h"
#include "IxGrids.hpp"
#include "IxInspector.hpp"
#include "IxItemListEditor.hpp"
#include "IxObjectInspector.hpp"
#include <Vcl.Graphics.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.TeeFunci.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include "CRC32.h"

//#include "Main_Form.h"
#include <io.h>
#include <fcntl.h>
//#include "fstream"
//#include "iostream"
#include "iomanip"
#include <iostream>
#include <ostream>
#include <fstream>
//---------------------------------------------------------------------------
class TFormTestDES8 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TRadioButton *rb_Start_Continuous_recording;
	TRadioButton *rb_Stop_Continuous_recording;
	TRadioButton *rb_Query_Word_state_device;
	TRadioButton *rb_SettingTransmitSpeed;
	TRadioButton *rb_Echo;
	TRadioButton *rb_Start_Auto_calibr_magnetic_sensors;
	TRadioButton *rb_Setting_Pot_gain_offset;
	TRadioButton *rb_Data_Request;
	TRadioButton *rb_Init_Gyro_Acceler_sensors;
	TRadioButton *rb_Ping;
	TRadioButton *rb_Init_Magnetic_sensors;
	TRadioButton *rb_Init_Sonde;
	TLabel *Label1;
	TPanel *Panel2;
	TButton *btn_Send_Command;
	TPanel *Panel3;
	TLabel *Label2;
	TIxObjectInspector *IxObjectInspector1;
	TRadioButton *rb_Reset_SpeedMove;
	TRadioButton *rb_Reset_Azimuth;
	TTimer *TimerForControlEvent;
	TLabel *LabelError;
	TTimer *Timer2;
	TCheckBox *chkAutoRandomComm;
	TChart *Chart1;
	TFastLineSeries *Series1;
	TAddTeeFunction *TeeFunction1;
	TChart *Chart2;
	TFastLineSeries *FastLineSeries1;
	TAddTeeFunction *AddTeeFunction1;
	TFastLineSeries *FastLineSeries2;
	TFastLineSeries *FastLineSeries3;
	TFastLineSeries *FastLineSeries4;
	TFastLineSeries *FastLineSeries5;
	TFastLineSeries *FastLineSeries6;
	TFastLineSeries *FastLineSeries7;
	TFastLineSeries *FastLineSeries8;
	TFastLineSeries *FastLineSeries9;
	TFastLineSeries *FastLineSeries10;
	TFastLineSeries *FastLineSeries11;
	TFastLineSeries *FastLineSeries12;
	TFastLineSeries *FastLineSeries13;
	TFastLineSeries *FastLineSeries14;
	TFastLineSeries *FastLineSeries15;
	TFastLineSeries *FastLineSeries16;
	TCheckBox *chkCycleComman;
	TLabel *LbEventInitReady;
	TRadioButton *rb_Set_Service_Parameters;
	TRadioButton *rb_SetTime;
	TRadioButton *rb_SetDepth;
	TCheckBox *chkSetDepthDataReq;
	TLabel *labelErrorForDataReq;
	TLabel *lblNameErrDataReq;
	TFastLineSeries *fstForChoicePoint;
	TLabel *lblNumPointsForChart;
	TPopupMenu *pmPointFromMainSonde;
	TMenuItem *N11;
	TMenuItem *N21;
	TImageList *ImageList1;
	TPanel *pnl_response_command;
	TPanel *pnlEventControlChNunBlHID;
	TPanel *pnlEventControlMethodOnChage;
	TFastLineSeries *Series2;
	TAddTeeFunction *TeeFunction2;
	TFastLineSeries *fstForChoicePointMagnSens;
	TLabel *lblNumPointsForChartMagnSens;
	TPopupMenu *pmPointFromMagnSens;
	TMenuItem *Vs_Sin;
	TMenuItem *Vs_Cos;
	void __fastcall btn_Send_CommandClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall rb_PingClick(TObject *Sender);
	void __fastcall ValueListEditor_Cont_commandValidate(TObject *Sender, int ACol,
          int ARow, const UnicodeString KeyName, const UnicodeString KeyValue);
	void __fastcall rb_Init_SondeClick(TObject *Sender);
	void __fastcall rb_Init_Magnetic_sensorsClick(TObject *Sender);
	void __fastcall rb_Init_Gyro_Acceler_sensorsClick(TObject *Sender);
	void __fastcall rb_Data_RequestClick(TObject *Sender);
	void __fastcall rb_Setting_Pot_gain_offsetClick(TObject *Sender);
	void __fastcall rb_Start_Auto_calibr_magnetic_sensorsClick(TObject *Sender);
	void __fastcall rb_EchoClick(TObject *Sender);
	void __fastcall rb_SettingTransmitSpeedClick(TObject *Sender);
	void __fastcall rb_Query_Word_state_deviceClick(TObject *Sender);
	void __fastcall rb_Start_Continuous_recordingClick(TObject *Sender);
	void __fastcall rb_Stop_Continuous_recordingClick(TObject *Sender);
	void __fastcall rb_Reset_SpeedMoveClick(TObject *Sender);
	void __fastcall rb_Reset_AzimuthClick(TObject *Sender);
	void __fastcall IxObjectInspector1PropertyChanged(TObject *Sender, const TIxItemProperty *Item);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerForControlEventTimer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall chkAutoRandomCommClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall chkCycleCommanClick(TObject *Sender);
	void __fastcall btn2Click(TObject *Sender);
	void __fastcall rb_Set_Service_ParametersClick(TObject *Sender);
	void __fastcall rb_SetTimeClick(TObject *Sender);
	void __fastcall rb_SetDepthClick(TObject *Sender);
	void __fastcall chkSetDepthDataReqClick(TObject *Sender);
	void __fastcall Chart1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall Chart2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Vs_SinClick(TObject *Sender);
	void __fastcall Vs_CosClick(TObject *Sender);


private:	// User declarations
void __fastcall MethodOnChage(TObject* Sender);
void __fastcall ChangeNumBlockHID(TObject *Sender);
//void __fastcall ChangeNumBlockHID();
inline void __fastcall VisualCompChange(USHORT);
void __fastcall InitUSBHID(TObject *Sender);

void __fastcall To_MY_HID_OutputReport(UINT16 TempMy);
void __fastcall To_MY_HID_OutputReport32(UINT32 TempMy) ;
//void __fastcall To_MY_HID_OutputReportNumWordsDownTool(UINT16 TempMy);

public:		// User declarations
	__fastcall TFormTestDES8(TComponent* Owner);
//__fastcall To_MY_HID_OutputReport(UINT16 TempMy, int i);
	void __fastcall PingClick();
 inline	void __fastcall ArrayPack(BYTE);
 inline void __fastcall AutonomModeArrayPack(BYTE);

 void __fastcall Send_CommandToDT(UINT16);
 UINT16 CountErrorSetDepthT0DT, CountErrorData_Request;
 UINT16 NumSend_CommandToDT;
 ofstream outfile;
 int CountCycleSetDepthDataReq;
 bool CRC_Control;   SYSTEMTIME Time_Tenp;
 bool FLAG_Stop_WRITE, FLAG_Start_WRITE;

};
//---------------------------------------------------------------------------
extern  TFormTestDES8 *FormTestDES8;
	extern  bool FlagErrorDataReceiveOn;
	extern  bool  FlagControlMethodOnChage; 
	extern bool FlagControlChangeNumBlockHID; 
//---------------------------------------------------------------------------
#endif

