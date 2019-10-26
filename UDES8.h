//---------------------------------------------------------------------------

#ifndef UDES8H
#define UDES8H
//---------------------------------------------------------------------------
 #include <windows.h>
#include <System.Classes.hpp>
#include <dinput.h>
#include <assert.h>

#include "UFormTestDES8.h"
#include "Main_Form.h"



//---------------------------------------------------------------------------
void __fastcall FormTestDES8BlinkDisable();
 extern TIniFile *ini;
 extern AnsiString IniFileName;
   void __fastcall IniWrite(AnsiString Section, AnsiString TypeComand, USHORT Value);
    void __fastcall IniWriteBool(AnsiString Section, AnsiString TypeComand, bool Value);
   USHORT __fastcall IniRead(AnsiString Section, AnsiString TypeComand);
   bool __fastcall IniReadBool(AnsiString Section, AnsiString TypeComand);
   bool __fastcall IsIniReadCection(AnsiString Section);

 //ошибки
#define TIME_OUT_DT                                     0xFFFF
#define TIME_OUT_EVENT                                  33333
//---------------------------------------------------------------------------


 #define PingConst                                1
 #define Init_SondeConst                          2
 #define Init_Magnetic_sensorsConst               3
 #define Init_Gyro_Acceler_sensorsConst           4
 #define Data_RequestConst                        5
 #define Setting_Pot_gain_offsetConst             6
 #define Start_Auto_calibr_magnetic_sensorsConst  7
 #define EchoConst                                8
 #define Setting_Transmit_speedConst              9 
 #define Query_Word_state_deviceConst             10
 #define Start_Continuous_recordingConst          11
 #define Stop_Continuous_recordingConst           12
 #define Reset_SpeedMoveConst                     13
 #define Reset_AzimuthConst                       14
 #define Set_Service_Parameters                   15
 #define Set_TimeDT                               16
 #define Set_DepthDT                              17
/
 #define Flag_Data_currentConst                       0x01
 #define Flag_Data_voltageConst                       0x02
 #define Flag_Data_zondeConst                         0x04
 #define Flag_Data_magnetic_sensorsConst              0x08
 #define Flag_Data_gyro_acceler_sensorsConst          0x10
 #define Flag_Start_auto_calibr_mag_sensConst         0x20
 
 #define Flag_record_potent_value_EEPROM_Const        0x01



  #define GroupDataGyroACccel_Const        27  
  #define CRC32_Const                      2  



 class TAttrTest  : public TCustomAttribute
 {
 };
 //Класс для данных с прибора ДЭС8
 class DT_DES8 : public  TObject
{
private:


 public:
 DT_DES8();



 BYTE DataAll_DT[10000];
 BYTE NumCommand;
 BYTE CodeError;
 UINT32 TimeInBlockData;  

 USHORT *DataCurrent;
 USHORT *DataVolt;
 UINT32 *DataMain;
 USHORT *DataMagneticSensors;

 #pragma pack (1)
typedef struct  {
 // BYTE HIDAdd;

  USHORT Sens_Sin1;
  USHORT Sens_Cos1;
  USHORT Sens_Sin2;
  USHORT Sens_Cos2;
  USHORT Sens_Sin3;
  USHORT Sens_Cos3;
  USHORT Sens_Sin4;
  USHORT Sens_Cos4;
  USHORT Sens_Sin5;
  USHORT Sens_Cos5;
  USHORT Sens_Sin6;
  USHORT Sens_Cos6;
  USHORT Sens_Sin7;
  USHORT Sens_Cos7;
  USHORT Sens_Sin8;
  USHORT Sens_Cos8;


  } MagneticSensors;
	#pragma pack ()

  MagneticSensors *DTMagneticSensorsStruct;

   #pragma pack (1)
  typedef struct  {
	U16 TimeBeforeBeginCurrentPause;
	U16 TimeBeforeEndCurrentPause;
	U16 TimeBeforeStartMainADC;
	U16 NumPointsSondeWriteFlash;
	U16 NumPointsSondeSendCable;
	U8  NumPointsTimeSliceForCable;
	U8  StepOffsetFirstSensor;
	U8  NumSensDisBetwGroup;
	U8  NumPolingCycleBefRes;
	U8  NumSensInGroup;
	U8  Reserv;
	U8  NumPointsUIforCable;
	U8  Res2;
	U8  GainPotentiometer1;
	U8  OffsetPotentiometer1;
	U8  GainPotentiometer2;
	U8  OffsetPotentiometer2;
	U16 NumberPointSwitchGainMain;
	U8  Res;
	U8  MountSD;
} DataForRequestCommand;
   #pragma pack ()

DataForRequestCommand *DataForRequestCommandStruct;
BYTE DataRequestCommand [30];  //должно быть с прибора 22 байта


 #pragma pack (1)
  typedef struct  {
	INT16    AccelerationX;
	INT16    AccelerationY;
	INT16    AccelerationZ;
	INT16    Angular_speed;
	INT32  SpeedX;
	INT32  SpeedY;
	INT32  SpeedZ;
	INT64  MoveX;
   //	INT64  MoveY;
	INT32 NumberBlocks;
	INT32  FileNameNun; 
	//INT64  MoveZ;
	UINT32 All_NubersSectors; 
	UINT32 NuberFreeSectors; 
	UINT16 TemperAccel;
	INT32  Angle;
	UINT16 GK;
	UINT16 TimeGK;
} S_DataAccelGyr;
   #pragma pack ()
   S_DataAccelGyr *StructDataAccelGyr;
   USHORT DataAccelGyr[GroupDataGyroACccel_Const+2];

   UINT32 CRC32_Calculated;
   UINT32 CRC32_FromDT;

};
extern DT_DES8 *DT_DES8M;


//----------------Command Ping------------------------------------------
 class Ping_Data : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

	AnsiString Sep ;
  BYTE NumberSentBytes;             
  UINT16 NumberRespWords;            

  USHORT CodeAlr;


 USHORT  __fastcall Comm() { NumCommand=PingConst; return NumCommand; }
USHORT  __fastcall FlagCom() {  return Flags=0; }
 AnsiString  __fastcall Separ() {  return Sep="-----------"; }
 USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
 USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

 USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
 void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Ping_Data() {;} 
 __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

 __published:   

 
 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

 __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Ping_Data *PingM;
//------------------------Command InitSonde---------------------------------------------------
class InitSonde_Data : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;
	UINT16 NumIntervTime1;             
  UINT16 NumIntervTime2;             
  UINT16 NumIntervTime3;             
  UINT16 NumPointsSonde_forFlash;    
  UINT16 NumPointsSonde_forCable;   

	AnsiString Sep ;
   UINT16 NumberRespWords;            //к-во ответных на команду с прибора слов
   BYTE NumberSentBytes;              
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Init_SondeConst; return NumCommand; }
 USHORT  __fastcall FlagCom() { return Flags=0;}

 UINT16  __fastcall NumIntervTime1_read() { return NumIntervTime1;}
 void  __fastcall NumIntervTime1_write(UINT16 in) { NumIntervTime1 = in; IniWrite(this->ClassName(), "TimeBeforeBeginCurrentPause", in);}

 UINT16  __fastcall NumIntervTime2_read() { return NumIntervTime2;}
 void   __fastcall NumIntervTime2_write(UINT16 in) { NumIntervTime2 = in; IniWrite(this->ClassName(), "TimeBeforeEndCurrentPause", in);}

 UINT16  __fastcall NumIntervTime3_read() { return NumIntervTime3;}
 void   __fastcall NumIntervTime3_write(UINT16 in) { NumIntervTime3 = in; IniWrite(this->ClassName(), "TimeBeforeStartMainADC", in);}

 UINT16  __fastcall NumPointsSonde_forFlash_read() { return NumPointsSonde_forFlash;}
 void  __fastcall NumPointsSonde_forFlash_write(UINT16 in) { NumPointsSonde_forFlash = in;IniWrite(this->ClassName(), "NumPointsSondeWriteFlash", in);}

 UINT16  __fastcall NumPointsSonde_forCable_read() { return NumPointsSonde_forCable;}
 void   __fastcall NumPointsSonde_forCable_write(UINT16 in) {NumPointsSonde_forCable = in;IniWrite(this->ClassName(), "NumPointsSondeSendCable", in);}

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=12; }

  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 InitSonde_Data()
 {
 IniFileName = ChangeFileExt( Application->ExeName, ".INI" );
 if (!FileExists(IniFileName))
		   {
		   NumIntervTime1=0; IniWrite(this->ClassName(), "TimeBeforeBeginCurrentPause", NumIntervTime1);
		   NumIntervTime2=5000; IniWrite(this->ClassName(), "TimeBeforeEndCurrentPause", NumIntervTime2);
		   NumIntervTime3=4900; IniWrite(this->ClassName(), "TimeBeforeStartMainADC", NumIntervTime3);
		   NumPointsSonde_forFlash = 20000;   IniWrite(this->ClassName(), "NumPointsSondeWriteFlash", NumPointsSonde_forFlash);//default 20000 time main "decrement curve" 160 ms !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		   NumPointsSonde_forCable = 50; IniWrite(this->ClassName(), "NumPointsSondeSendCable", NumPointsSonde_forCable);
		   }
		   else
			{
			 NumIntervTime1=IniRead(this->ClassName(), "TimeBeforeBeginCurrentPause");
			 NumIntervTime2=IniRead(this->ClassName(), "TimeBeforeEndCurrentPause");
			 NumIntervTime3=IniRead(this->ClassName(), "TimeBeforeStartMainADC");
			 NumPointsSonde_forFlash=IniRead(this->ClassName(), "NumPointsSondeWriteFlash");
			 NumPointsSonde_forCable=IniRead(this->ClassName(), "NumPointsSondeSendCable");
			}
 }

 __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };
 __property   UINT16 TimeBeforeBeginCurrentPause = { read = NumIntervTime1_read, write = NumIntervTime1_write};
 __property   UINT16 TimeBeforeEndCurrentPause = { read = NumIntervTime2_read, write = NumIntervTime2_write};
 __property   UINT16 TimeBeforeStartMainADC = {read = NumIntervTime3_read, write = NumIntervTime3_write};
 __property   UINT16 NumPointsSondeWriteFlash = {read = NumPointsSonde_forFlash_read, write = NumPointsSonde_forFlash_write};
 __property   UINT16 NumPointsSondeSendCable = {read = NumPointsSonde_forCable_read, write = NumPointsSonde_forCable_write};
 __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern InitSonde_Data *InitSondeM;
//------------------------Command Init_Magnetic_sensors---------------------------------------------------
class InitMagneticSensors_Data : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;
  UINT16 NumPoints_forCable;           
  BYTE StepOffset;                  
  BYTE NumStep;                     
  BYTE NumPolingCycle;             
  BYTE NumSensGroup;               
  BYTE Res;



	AnsiString Sep ;
  UINT16 NumberRespWords;          
  BYTE NumberSentBytes;             

  USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Init_Magnetic_sensorsConst; return NumCommand; }
 USHORT  __fastcall FlagCom() { return Flags=0;}

 UINT16  __fastcall NumPoints_forCable_read() { return NumPoints_forCable;}
 void  __fastcall NumPoints_forCable_write(UINT16 in) { NumPoints_forCable = in ;IniWrite(this->ClassName(), "NumPointsTimeSliceForCable", in);}

 UINT16  __fastcall StepOffset_read() { return StepOffset;}
 void  __fastcall StepOffset_write(UINT16 in) { StepOffset = in ;IniWrite(this->ClassName(), "StepOffsetFirstSensor", in);}

 UINT16  __fastcall NumStep_read() { return NumStep;}
 void  __fastcall NumStep_write(UINT16 in) { NumStep = in ; IniWrite(this->ClassName(), "NumSensDisBetwGroup", in);}

 UINT16  __fastcall NumPolingCycle_read() { return NumPolingCycle;}
 void  __fastcall NumPolingCycle_write(UINT16 in) { NumPolingCycle = in ;IniWrite(this->ClassName(), "NumPolingCycleBefRes", in);}

 UINT16  __fastcall NumSensGroup_read() { return NumSensGroup;}     //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall NumSensGroup_write(UINT16 in) { NumSensGroup = in ;IniWrite(this->ClassName(), "NumSensInGroup", in);}

  BYTE ReservByte;
 UINT16  __fastcall Reserv_read() { return ReservByte;}
 void  __fastcall Reserv_write(UINT16 in) { ReservByte = in ;IniWrite(this->ClassName(), "Reserv", in);}

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=8; }

   USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 InitMagneticSensors_Data()
 {
 IniFileName = ChangeFileExt( Application->ExeName, ".INI" );
 if (!FileExists(IniFileName))
		   {
			NumPoints_forCable=3; IniWrite(this->ClassName(), "NumPointsTimeSliceForCable", NumPoints_forCable);
			StepOffset=0;   IniWrite(this->ClassName(), "StepOffsetFirstSensor", StepOffset);
			NumStep=0; IniWrite(this->ClassName(), "NumSensDisBetwGroup", NumStep);
			NumPolingCycle = 0;  IniWrite(this->ClassName(), "NumPolingCycleBefRes", NumPolingCycle); //default  time main "decrement curve" 160 ms
			NumSensGroup = 1;   IniWrite(this->ClassName(), "NumSensInGroup", NumSensGroup);
			ReservByte =0; IniWrite(this->ClassName(), "Reserv", ReservByte);
		   }
		   else
			{
			 if(IsIniReadCection(this->ClassName()))
			 {
			 NumPoints_forCable=IniRead(this->ClassName(), "NumPointsTimeSliceForCable");
			 StepOffset=IniRead(this->ClassName(), "StepOffsetFirstSensor");
			 NumStep=IniRead(this->ClassName(), "NumSensDisBetwGroup");
			 NumPolingCycle=IniRead(this->ClassName(), "NumPolingCycleBefRes");
			 NumSensGroup=IniRead(this->ClassName(), "NumSensInGroup");
			 ReservByte=IniRead(this->ClassName(), "Reserv");
			 }
			  else
			   {
			NumPoints_forCable=3; IniWrite(this->ClassName(), "NumPointsTimeSliceForCable", NumPoints_forCable);
			StepOffset=0;   IniWrite(this->ClassName(), "StepOffsetFirstSensor", StepOffset);
			NumStep=0; IniWrite(this->ClassName(), "NumSensDisBetwGroup", NumStep);
			NumPolingCycle = 0;  IniWrite(this->ClassName(), "NumPolingCycleBefRes", NumPolingCycle); //default  time main "decrement curve" 160 ms
			NumSensGroup = 1;   IniWrite(this->ClassName(), "NumSensInGroup", NumSensGroup);
			ReservByte =0; IniWrite(this->ClassName(), "Reserv", ReservByte);
			   }
			}

 }
 __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };
 __property   UINT16 NumPointsTimeSliceForCable = { read = NumPoints_forCable_read, write = NumPoints_forCable_write};
 __property   UINT16 StepOffsetFirstSensor = { read = StepOffset_read, write = StepOffset_write};
 __property   UINT16 NumSensDisBetwGroup = {read = NumStep_read, write = NumStep_write};
 __property   UINT16 NumPolingCycleBefRes = {read = NumPolingCycle_read, write = NumPolingCycle_write};
 __property   UINT16 NumSensInGroup = {read = NumSensGroup_read, write = NumSensGroup_write};
 __property   UINT16 Reserv = {read = Reserv_read, write = Reserv_write};
  __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern InitMagneticSensors_Data *InitMagneticSensorsM;
//---------------------------------------------------------------------------
//----------------Command Init_Gyro_Acceler_sensors------------------------------------------
 class Init_Gyro_Acceler_sensors : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;
  BYTE NumPointsUI_forCable;                
  BYTE Res;

   AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Init_Gyro_Acceler_sensorsConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

 UINT16  __fastcall NumPointsUI_forCable_read() { return NumPointsUI_forCable;}
 void    __fastcall NumPointsUI_forCable_write(UINT16 in) { NumPointsUI_forCable = in ;IniWrite(this->ClassName(), "NumPointsUIforCable", in);}

 UINT16  __fastcall Res_read() { return Res=0;}
 void  __fastcall Res_write(UINT16 in) { Res = in ;}

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=4; }

     USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Init_Gyro_Acceler_sensors() {
 IniFileName = ChangeFileExt( Application->ExeName, ".INI" );
 if (!FileExists(IniFileName))
		   {
		   NumPointsUI_forCable=3;  IniWrite(this->ClassName(), "NumPointsUIforCable", NumPointsUI_forCable);
		   }
			else
			{
			 if(IsIniReadCection(this->ClassName()))
			 {
			 NumPointsUI_forCable=IniRead(this->ClassName(), "NumPointsUIforCable");
			 }
			  else
			   {
				NumPointsUI_forCable=3;  IniWrite(this->ClassName(), "NumPointsUIforCable", NumPointsUI_forCable);
			   }
			}
                             } //пустой конструктор
 __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };
  __property   UINT16 NumPointsUIforCable = { read = NumPointsUI_forCable_read, write = NumPointsUI_forCable_write};
 __property   UINT16 Reserv = {read = Res_read, write = Res_write};

   __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

};

extern Init_Gyro_Acceler_sensors *Init_Gyro_Acceler_sensorsM;

//----------------Command Data_Request------------------------------------------

 class Data_Request : public  TObject
{
private:
  BYTE NumCommand;
  USHORT CodeAlr;
//use class for 'drop-down list' - bits flags -----------------------
  class BitsFlagsCommand : public TObject
  {
 private:
 bool bit0_p;
 bool bit1_p;
 bool bit2_p;
 bool bit3_p;
 bool bit4_p;
 bool bit5_p;



 bool __fastcall bit0_read() {return bit0_p;}
 void __fastcall bit0_write(bool in) {bit0_p=in; IniWriteBool(Data_Request::ClassName(), "ReqDataCurrent", in);}

 bool __fastcall bit1_read() {return bit1_p;}
 void __fastcall bit1_write(bool in){bit1_p=in; IniWriteBool(Data_Request::ClassName(), "ReqDataVolt", in);}

 bool __fastcall bit2_read() {return bit2_p;}
 void __fastcall bit2_write(bool in) {bit2_p=in; IniWriteBool(Data_Request::ClassName(), "ReqDataMain", in);}

 bool __fastcall bit3_read() {return bit3_p;}
 void __fastcall bit3_write(bool in){bit3_p=in; IniWriteBool(Data_Request::ClassName(), "ReqDataSensMagn", in);}

 bool __fastcall bit4_read() {return bit4_p;}
 void __fastcall bit4_write(bool in) {bit4_p=in;IniWriteBool(Data_Request::ClassName(), "ReqDataAccelGyr", in);}

 bool __fastcall bit5_read() {return bit5_p;}
 void __fastcall bit5_write(bool in){bit5_p=in; IniWriteBool(Data_Request::ClassName(), "AutoCalibSensMagn", in);}

protected:

 public:
 BitsFlagsCommand()
 {
 //bit0_p = 1;  bit1_p = 0;  bit2_p = 1; bit3_p = 1; bit4_p = 1; bit5_p = 0;
 }

__published:
__property   bool ReqDataCurrent  = { read = bit0_read,  write = bit0_write};
__property   bool ReqDataVolt  = { read = bit1_read, write = bit1_write};
__property   bool ReqDataMain  = { read = bit2_read, write = bit2_write};
__property   bool ReqDataSensMagn  = { read = bit3_read, write = bit3_write};
__property   bool ReqDataAccelGyr  = { read = bit4_read, write = bit4_write};
__property   bool AutoCalibSensMagn  = { read = bit5_read, write = bit5_write};
};
 //-------------------------------------------------
	AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;             


 USHORT  __fastcall Comm() { NumCommand=Data_RequestConst; return NumCommand; }

  void  __fastcall FuncNumberResponseWords_write(UINT16 in) { NumberRespWords = in ;}
	USHORT  __fastcall FuncNumberResponseWords_read() { return NumberRespWords; }

    INT32  CurrentDepthVar;
	INT32  __fastcall CurrentDepth_read(){return CurrentDepthVar;}
	void   __fastcall CurrentDepth_write(INT32 in) { CurrentDepthVar = in ;}


  AnsiString  __fastcall Separ() {  return Sep="-----------"; }

  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=6; }   

  BitsFlagsCommand *FlagCom;

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

  INT16  __fastcall AccelerationX_read()     {return  DT_DES8M->StructDataAccelGyr->AccelerationX;}
  INT16  __fastcall AccelerationY_read()     {return  DT_DES8M->StructDataAccelGyr->AccelerationY;}
  INT16  __fastcall AccelerationZ_read()     {return  DT_DES8M->StructDataAccelGyr->AccelerationZ;}
  INT16   __fastcall Angular_speed_read()     {return  DT_DES8M->StructDataAccelGyr->Angular_speed;}
  INT32   __fastcall SpeedX_read()            {return  DT_DES8M->StructDataAccelGyr->SpeedX;}
  INT32   __fastcall SpeedY_read()            {return  DT_DES8M->StructDataAccelGyr->SpeedY;}
  INT32   __fastcall SpeedZ_read()            {return  DT_DES8M->StructDataAccelGyr->SpeedZ;}
  INT64   __fastcall MoveX_read()             {return  DT_DES8M->StructDataAccelGyr->MoveX;}
  //INT64   __fastcall MoveY_read()             {return  DT_DES8M->StructDataAccelGyr->MoveY;}
  INT32   __fastcall NumberBlocks_read()            {return  DT_DES8M->StructDataAccelGyr->NumberBlocks;}
  INT32   __fastcall FileNameNun_read()             {return  DT_DES8M->StructDataAccelGyr->FileNameNun;}
 // INT64   __fastcall MoveZ_read()             {return  DT_DES8M->StructDataAccelGyr->MoveZ;}
  UINT32   __fastcall All_NubersSectors_read()             {return  DT_DES8M->StructDataAccelGyr->All_NubersSectors;}
  UINT32   __fastcall NuberFreeSectors_read()             {return  DT_DES8M->StructDataAccelGyr->NuberFreeSectors;}

  UINT16  __fastcall TemperAccel_read()       {return  DT_DES8M->StructDataAccelGyr->TemperAccel;}
  INT32   __fastcall Angle_read()             {return  DT_DES8M->StructDataAccelGyr->Angle;}
  UINT16  __fastcall GK_read()                {return  DT_DES8M->StructDataAccelGyr->GK;}
  UINT16  __fastcall TimeGK_read()            {return  DT_DES8M->StructDataAccelGyr->TimeGK;}
  UINT64  __fastcall CRC32_FromDT_read()      {return  DT_DES8M->CRC32_FromDT;}
  UINT64  __fastcall CRC32_Calculated_read()   {return  DT_DES8M->CRC32_Calculated;;}

 public:
 Data_Request()
 {
  FlagCom = new BitsFlagsCommand;

  IniFileName = ChangeFileExt( Application->ExeName, ".INI" );
  if (!FileExists(IniFileName))
		   {
			FlagCom->ReqDataCurrent = true;  IniWriteBool(this->ClassName(), "ReqDataCurrent", FlagCom->ReqDataCurrent);
			FlagCom->ReqDataVolt=false;  IniWriteBool(this->ClassName(), "ReqDataVolt", FlagCom->ReqDataVolt);
			FlagCom->ReqDataMain=true;  IniWriteBool(this->ClassName(), "ReqDataMain", FlagCom->ReqDataMain);
			FlagCom->ReqDataSensMagn=true;  IniWriteBool(this->ClassName(), "ReqDataSensMagn", FlagCom->ReqDataSensMagn);
			FlagCom->ReqDataAccelGyr=true;  IniWriteBool(this->ClassName(), "ReqDataAccelGyr", FlagCom->ReqDataAccelGyr);
			FlagCom->AutoCalibSensMagn=false;  IniWriteBool(this->ClassName(), "AutoCalibSensMagn", FlagCom->AutoCalibSensMagn);
		   }
			else
			{
			 if(IsIniReadCection(this->ClassName()))
			 {
			 FlagCom->ReqDataCurrent = IniReadBool(this->ClassName(), "ReqDataCurrent");
			 FlagCom->ReqDataVolt = IniReadBool(this->ClassName(), "ReqDataVolt");
			 FlagCom->ReqDataMain = IniReadBool(this->ClassName(), "ReqDataMain");
			 FlagCom->ReqDataSensMagn = IniReadBool(this->ClassName(), "ReqDataSensMagn");
			 FlagCom->ReqDataAccelGyr = IniReadBool(this->ClassName(), "ReqDataAccelGyr");
			 FlagCom->AutoCalibSensMagn = IniReadBool(this->ClassName(), "AutoCalibSensMagn");
			 }
			  else
			   {
				FlagCom->ReqDataCurrent = true;  IniWriteBool(this->ClassName(), "ReqDataCurrent", FlagCom->ReqDataCurrent);
				FlagCom->ReqDataVolt=false;  IniWriteBool(this->ClassName(), "ReqDataVolt", FlagCom->ReqDataVolt);
				FlagCom->ReqDataMain=true;  IniWriteBool(this->ClassName(), "ReqDataMain", FlagCom->ReqDataMain);
				FlagCom->ReqDataSensMagn=true;  IniWriteBool(this->ClassName(), "ReqDataSensMagn", FlagCom->ReqDataSensMagn);
				FlagCom->ReqDataAccelGyr=true;  IniWriteBool(this->ClassName(), "ReqDataAccelGyr", FlagCom->ReqDataAccelGyr);
		    	FlagCom->AutoCalibSensMagn=false;  IniWriteBool(this->ClassName(), "AutoCalibSensMagn", FlagCom->AutoCalibSensMagn);
			   }
			}

 NumberRespWords=1;
 } 

 
 __property USHORT NumberResponseWordsPr = { read = FuncNumberResponseWords_read, write = FuncNumberResponseWords_write };
 __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:


 __property   USHORT NumerCommand  = { read = Comm };
 __property   BitsFlagsCommand *FlagsCommand = { read = FlagCom, write = FlagCom};
 __property   INT32 CurrentDepth = { read = CurrentDepth_read, write = CurrentDepth_write };

 __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property USHORT NumberResponseWords = { read = FuncNumberResponseWords_read };  
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };


  __property   AnsiString GYR_ACCELER = { read = Separ };

  __property   INT16  AccelerationX = {read = AccelerationX_read};
  __property   INT16  AccelerationY = {read = AccelerationY_read};
  __property   INT16  AccelerationZ = {read = AccelerationZ_read};
  __property   INT16   AngularSpeed  = {read = Angular_speed_read};
  __property   INT32   SpeedX  = {read = SpeedX_read};
  __property   INT32   SpeedY  = {read = SpeedY_read};
  __property   INT32   SpeedZ  = {read = SpeedZ_read};
  __property   INT64   WriteToSD_Card  = {read = MoveX_read};
  //__property   INT64   MoveY  = {read = MoveY_read};
 
  __property   INT32   NumBlocksWriteToFile  = {read = NumberBlocks_read};
  __property   INT32   FileNumDT  = {read = FileNameNun_read};     
	
   __property   INT32   Total_NubersSectorsSD  = {read = All_NubersSectors_read};
   __property   INT32   NuberFreeSectorsSD  = {read = NuberFreeSectors_read};

  __property   UINT16  TemperAccel  = {read = TemperAccel_read};
  __property   INT32   Angle  = {read = Angle_read};
  __property   UINT16  GK  = {read = GK_read};
  __property   UINT16  TimeGK  = {read = TimeGK_read};
  __property   UINT64  CRC32_FromDT  = {read = CRC32_FromDT_read};
  __property   UINT64  CRC32_Calculated  = {read = CRC32_Calculated_read};
};
extern Data_Request *Data_RequestM;

//----------------Command Setting_Pot_gain_offset------------------------------------------
 class Setting_Pot_gain_offset : public  TObject
{
private:
  BYTE NumCommand;

  USHORT CodeAlr;
//use class for 'drop-down list' - bits flags -----------------------
class BitsFlagsCommand : public TObject
{
private:
bool bit0_p;

 bool __fastcall bit0_read() {return bit0_p;}
 void __fastcall bit0_write(bool in) {bit0_p=in; IniWriteBool(Setting_Pot_gain_offset::ClassName(), "WriteToFlashValuePot", in);}


protected:

 public:
 BitsFlagsCommand()
 {
 //bit0_p = 1;
 }

__published:
__property   bool WriteToFlashValuePot  = { read = bit0_read,  write = bit0_write};

};
 //-------------------------------------------------
	AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;             


 USHORT  __fastcall Comm() { NumCommand=Setting_Pot_gain_offsetConst; return NumCommand; }

   BYTE ValueGainPotentiometer1;
 USHORT  __fastcall GainPotentiometer_read1() {return ValueGainPotentiometer1;} //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall GainPotentiometer_write1(UINT16 in) { ValueGainPotentiometer1 = in ;IniWrite(this->ClassName(), "GainPotentiometer1", in);}
   BYTE ValueGainPotentiometer2;
 USHORT  __fastcall GainPotentiometer_read2() {return ValueGainPotentiometer2;} //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall GainPotentiometer_write2(UINT16 in) { ValueGainPotentiometer2 = in ;IniWrite(this->ClassName(), "GainPotentiometer2", in);}

   BYTE ValueOffsetPotentiometer1;
  USHORT  __fastcall OffsetPotentiometer_read1() {return ValueOffsetPotentiometer1;} //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall OffsetPotentiometer_write1(UINT16 in) { ValueOffsetPotentiometer1 = in ;IniWrite(this->ClassName(), "OffsetPotentiometer1", in);}
   BYTE ValueOffsetPotentiometer2;
  USHORT  __fastcall OffsetPotentiometer_read2() {return ValueOffsetPotentiometer2;} //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall OffsetPotentiometer_write2(UINT16 in) { ValueOffsetPotentiometer2 = in ;IniWrite(this->ClassName(), "OffsetPotentiometer2", in);}

 USHORT NumberPointSwitchGainMainVar ;
  USHORT  __fastcall NumberPointSwitchGainMain_read() {return NumberPointSwitchGainMainVar;} //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 void  __fastcall NumberPointSwitchGainMain_write(UINT16 in) { NumberPointSwitchGainMainVar = in ;IniWrite(this->ClassName(), "NumberPointSwitchGainMain", in);}

   AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=6; }

  BitsFlagsCommand *FlagCom;

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Setting_Pot_gain_offset()
 {
 FlagCom = new BitsFlagsCommand;

 if (!FileExists(IniFileName))
		   {
		   FlagCom->WriteToFlashValuePot=true; IniWriteBool(this->ClassName(), "WriteToFlashValuePot", FlagCom->WriteToFlashValuePot);
		   ValueGainPotentiometer1=1; IniWrite(this->ClassName(), "GainPotentiometer1", ValueGainPotentiometer1);
		   ValueGainPotentiometer2=1; IniWrite(this->ClassName(), "GainPotentiometer2", ValueGainPotentiometer2);
			ValueOffsetPotentiometer1=100;  IniWrite(this->ClassName(), "OffsetPotentiometer1", ValueOffsetPotentiometer1);
			ValueOffsetPotentiometer2=100;  IniWrite(this->ClassName(), "OffsetPotentiometer2", ValueOffsetPotentiometer2);
			NumberPointSwitchGainMainVar =55; IniWrite(this->ClassName(), "NumberPointSwitchGainMain", NumberPointSwitchGainMainVar);
		   }
			else
			{
			 if(IsIniReadCection(this->ClassName()))
			 {
				FlagCom->WriteToFlashValuePot=IniReadBool(this->ClassName(), "WriteToFlashValuePot");
				ValueGainPotentiometer1= IniRead(this->ClassName(), "GainPotentiometer1");
				ValueGainPotentiometer2= IniRead(this->ClassName(), "GainPotentiometer2");
				ValueOffsetPotentiometer1 = IniRead(this->ClassName(), "OffsetPotentiometer1");
				ValueOffsetPotentiometer2 = IniRead(this->ClassName(), "OffsetPotentiometer2");
				NumberPointSwitchGainMainVar = IniRead(this->ClassName(), "NumberPointSwitchGainMain");
			 }
			  else
			   {
				 FlagCom->WriteToFlashValuePot=true; IniWriteBool(this->ClassName(), "WriteToFlashValuePot", FlagCom->WriteToFlashValuePot);
				 ValueGainPotentiometer1=1; IniWrite(this->ClassName(), "GainPotentiometer1", ValueGainPotentiometer1);
				 ValueGainPotentiometer2=1; IniWrite(this->ClassName(), "GainPotentiometer2", ValueGainPotentiometer2);
				 ValueOffsetPotentiometer1=100;  IniWrite(this->ClassName(), "OffsetPotentiometer1", ValueOffsetPotentiometer1);
				 ValueOffsetPotentiometer2=100;  IniWrite(this->ClassName(), "OffsetPotentiometer2", ValueOffsetPotentiometer2);
				 NumberPointSwitchGainMainVar=55;  IniWrite(this->ClassName(), "NumberPointSwitchGainMain", NumberPointSwitchGainMainVar);
			   }
			}

 } //пустой конструктор
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   BitsFlagsCommand *FlagsCommand = { read = FlagCom, write = FlagCom};
  __property  USHORT GainPotentiometer1  = { read = GainPotentiometer_read1, write = GainPotentiometer_write1};
  __property  USHORT OffsetPotentiometer1  = { read = OffsetPotentiometer_read1, write = OffsetPotentiometer_write1};
  __property  USHORT GainPotentiometer2  = { read = GainPotentiometer_read2, write = GainPotentiometer_write2};
  __property  USHORT OffsetPotentiometer2  = { read = OffsetPotentiometer_read2, write = OffsetPotentiometer_write2};
  __property  USHORT NumberPointSwitchGainMain  = { read = NumberPointSwitchGainMain_read, write = NumberPointSwitchGainMain_write};

 __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

};
extern Setting_Pot_gain_offset *Setting_Pot_gain_offsetM;
//----------------Command Start_Auto_calibr_magnetic_sensors-----------------------------------------
 class Start_Autocalibr_MagnSens : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

  AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;              
 USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Start_Auto_calibr_magnetic_sensorsConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Start_Autocalibr_MagnSens() {;} 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

	 __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
  __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Start_Autocalibr_MagnSens *Start_Autocalibr_MagnSensM;
//----------------Command Echo-----------------------------------------
 class Echo : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;
   UINT16 DataCom;

  	  AnsiString Sep ;
   UINT16 NumberRespWords;            
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=EchoConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  UINT16  __fastcall DataCom_read() {  return DataCom; }
  void  __fastcall DataCom_write(UINT16 in) {  DataCom = in; }

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=2; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=4; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}
  USHORT  AnswWord;
  USHORT  __fastcall AnswerWord_read(){return  AnswWord;}
  void   __fastcall AnswerWord_write(USHORT in) { AnswWord = in ;}

 public:
 Echo() {DataCom=12345; AnswWord=0;} //default value
   __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };
  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };
 __property   UINT16 DataCommand =  { read = DataCom_read, write = DataCom_write };

    __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
   __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };
   __property   UINT16 AnswerWord = { read = AnswerWord_read, write = AnswerWord_write };

};
extern Echo *EchoM;
//----------------Command Setting_Transmit_speed-----------------------------------------
 class Set_TransmSpeed : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;
  UINT16 TimeData;

  	  AnsiString Sep ;
   UINT16 NumberRespWords;          
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Setting_Transmit_speedConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  UINT16  __fastcall TimeData_read() {  return TimeData; }
  void  __fastcall TimeData_write(UINT16 in) {  TimeData = in; }

AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=4; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 
 Set_TransmSpeed() {TimeData=96;}
   __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };
 __property   UINT16 TimeForSpeedManch =  { read = TimeData_read, write = TimeData_write };

    __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
	__property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

};
extern Set_TransmSpeed *Set_TransmSpeedM;
//----------------Command Query_Word_state_device-----------------------------------------
 class Query_WordStateDevice : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

   AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;              
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Query_Word_state_deviceConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

	AnsiString  __fastcall Separ() {  return Sep="-----------"; }
	 AnsiString  __fastcall Separ1() {  return Sep="ANSW. WORDS"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=14; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

   USHORT  __fastcall TimeBeforeBeginCurrentPause_read() {  return DT_DES8M->DataForRequestCommandStruct->TimeBeforeBeginCurrentPause; }
   USHORT  __fastcall TimeBeforeEndCurrentPause_read() {  return DT_DES8M->DataForRequestCommandStruct->TimeBeforeEndCurrentPause; }
   USHORT  __fastcall TimeBeforeStartMainADC_read() {  return DT_DES8M->DataForRequestCommandStruct->TimeBeforeStartMainADC; }
   USHORT  __fastcall NumPointsSondeWriteFlash_read() {  return DT_DES8M->DataForRequestCommandStruct->NumPointsSondeWriteFlash; }
   USHORT  __fastcall NumPointsSondeSendCable_read() {  return DT_DES8M->DataForRequestCommandStruct->NumPointsSondeSendCable; }
   USHORT  __fastcall NumPointsTimeSliceForCable_read() {  return DT_DES8M->DataForRequestCommandStruct->NumPointsTimeSliceForCable; }
   USHORT  __fastcall NumPointsUIforCable_read() {  return DT_DES8M->DataForRequestCommandStruct->NumPointsUIforCable; }
   USHORT  __fastcall GainPotentiometer_read1() {  return DT_DES8M->DataForRequestCommandStruct->GainPotentiometer1; }
   USHORT  __fastcall OffsetPotentiometer_read1() {  return DT_DES8M->DataForRequestCommandStruct->OffsetPotentiometer1; }

   USHORT  __fastcall GainPotentiometer_read2() {  return DT_DES8M->DataForRequestCommandStruct->GainPotentiometer2; }
   USHORT  __fastcall OffsetPotentiometer_read2() {  return DT_DES8M->DataForRequestCommandStruct->OffsetPotentiometer2; }
   USHORT  __fastcall NumberPointSwitchGainMain_read() {  return DT_DES8M->DataForRequestCommandStruct->NumberPointSwitchGainMain; }
   USHORT  __fastcall Reserv_read() {return DT_DES8M->DataForRequestCommandStruct->Reserv;}
   BYTE MountSD_var;
   USHORT   __fastcall MountSD_read() {return DT_DES8M->DataForRequestCommandStruct->MountSD;}



 public:
 Query_WordStateDevice() {MountSD_var=0;} //пустой конструктор
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };
   __property   AnsiString ANSWER_WORDS = { read = Separ };

  __property   UINT16 TimeBeforeBeginCurrentPause = { read = TimeBeforeBeginCurrentPause_read };
  __property   UINT16 TimeBeforeEndCurrentPause = { read = TimeBeforeEndCurrentPause_read };
  __property   UINT16 TimeBeforeStartMainADC = { read = TimeBeforeStartMainADC_read };
  __property   UINT16 NumPointsSondeWriteFlash = { read = NumPointsSondeWriteFlash_read };
  __property   UINT16 NumPointsSondeSendCable = { read = NumPointsSondeSendCable_read };
  __property   UINT16 NumPointsTimeSliceForCable = { read = NumPointsTimeSliceForCable_read };
  __property   UINT16 NumPointsUIforCable = { read = NumPointsUIforCable_read };
  __property   UINT16 GainPotentiometer1 = { read = GainPotentiometer_read1 };
  __property   UINT16 OffsetPotentiometer1 = { read = OffsetPotentiometer_read1 };

  __property   UINT16 GainPotentiometer2 = { read = GainPotentiometer_read2 };
   __property   UINT16 OffsetPotentiometer2 = { read = OffsetPotentiometer_read2 };
  __property   UINT16 NumberPointSwitchGainMain = { read =  NumberPointSwitchGainMain_read };
  __property   UINT16 Reserv = { read = Reserv_read };
  //__property   UINT16 MountSD = { read = MountSD_read };
   __property   UINT16 MountSD_NumFreeSectors = { read = MountSD_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;      Query_WordStateDeviceM->GainPotentiometer
};
extern Query_WordStateDevice *Query_WordStateDeviceM;
//----------------Command Start_Continuous_recording-----------------------------------------
 class Start_ContinRecord : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

   	  AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;              
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Start_Continuous_recordingConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Start_ContinRecord() {;} 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

	__property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Start_ContinRecord *Start_ContinRecordM;
//----------------Command Stop_Continuous_recording-----------------------------------------
 class Stop_ContinRecord : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

   	  AnsiString Sep ;
   UINT16 NumberRespWords;          
   BYTE NumberSentBytes;            
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Stop_Continuous_recordingConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Stop_ContinRecord() {;} 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Stop_ContinRecord *Stop_ContinRecordM;
//----------------Command Reset_SpeedMove-----------------------------------------
 class Reset_SpeedMove : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

   	  AnsiString Sep ;
   UINT16 NumberRespWords;          
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Reset_SpeedMoveConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Reset_SpeedMove() {;}
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
  __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Reset_SpeedMove *Reset_SpeedMoveM;
//----------------Command Reset_Azimuth-----------------------------------------
 class Reset_Azimuth : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

  	  AnsiString Sep ;
   UINT16 NumberRespWords;            
   BYTE NumberSentBytes;              
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Reset_AzimuthConst; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

 AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=2; }

  	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

 public:
 Reset_Azimuth() {;} //пустой конструктор
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
  __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Reset_Azimuth *Reset_AzimuthM;
//---------------------------------------------------------------------------
//----------------Command Set_Service_Parameters-----------------------------------------
 class Set_Service_Par : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

	  AnsiString Sep ;
   UINT16 NumberRespWords;            
   BYTE NumberSentBytes;             
   USHORT CodeAlr;


 USHORT  __fastcall Comm() { NumCommand=Set_Service_Parameters; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

  AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=50; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

   AnsiString NameAreaAnsiStr;
   AnsiString  __fastcall NameArea_read() {  return NameAreaAnsiStr; }            
   void   __fastcall NameArea_write(AnsiString in);// {NameAreaAnsiStr = in ;}

   AnsiString NameHoleAnsiStr ;
   AnsiString  __fastcall NameHole_read() {  return NameHoleAnsiStr; }            
   void   __fastcall NameHole_write(AnsiString in);// {NameHoleAnsiStr = in ; }
  // int ff= NameHoleAnsiStr.WideCharBufSize();
	
	INT32 DepthBeginVar;
	INT32  __fastcall DepthBegin_read()        {  return DepthBeginVar; }
  void  __fastcall DepthBegin_write(INT32 in) {  DepthBeginVar = in; }

	INT32 DepthEndVar;
	INT32  __fastcall DepthEnd_read()          {  return DepthEndVar; }
	void  __fastcall DepthEnd_write(INT32 in) {  DepthEndVar = in; }

	INT32 CurrentTimeUnixVar;
	INT32  __fastcall CurrentTimeUnix_read();

   UINT16 SizeNameAreaByte;
   UINT16  __fastcall SizeNameAreaByte_read() {  return SizeNameAreaByte; }
   UINT16 SizeNumberNameHoleByte;
   UINT16  __fastcall SizeNumberNameHoleByte_read() {  return SizeNumberNameHoleByte; }


	//enum  Temp_text  {a,b,c} TTT;

   // Temp_text  __fastcall Text_read() {  return TTT; }
  //	void  __fastcall Text_write(Temp_text in) {  TTT = in; }
 //  TStrings *my1;
 //TStrings*  __fastcall Text_read() {  return my1; }


 public:
 Set_Service_Par()
 {
 //my1 = new TStrings;
 NameAreaAnsiStr = "ОНГКМ";
 NameHoleAnsiStr="Тест00";
 DepthBeginVar=0;
 DepthEndVar=0;
 SizeNameAreaByte=30;
 SizeNumberNameHoleByte=10;
 } 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };
  __property   UINT16 SizeNameAreaBytePr = { read = SizeNameAreaByte_read };
  __property   UINT16 SizeNumberNameHoleBytePr = { read = SizeNumberNameHoleByte_read };

 __property   AnsiString NameAreaPr = { read = NameArea_read,  write = NameArea_write };
 __property   AnsiString NumberNameHolePr = { read = NameHole_read,  write = NameHole_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };

 __property   AnsiString NameArea = { read = NameArea_read};//,  write = NameArea_write };
 __property   AnsiString NumberNameHole = { read = NameHole_read};//,  write = NameHole_write };
 __property   INT32 BeginDepth   =  { read = DepthBegin_read, write = DepthBegin_write};
 __property   INT32 EndDepth  =  { read = DepthEnd_read, write = DepthEnd_write};
 __property   INT32 CurrentTimeUnix = { read = CurrentTimeUnix_read };
 //__property   Temp_text Txt = { read = Text_read, write  = Text_write  };
  //__property TStrings* Txt = { read = Text_read};
   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Set_Service_Par *Set_Service_ParM;
//---------------------------------------------------------------------------

//----------------Command Set Time-----------------------------------------
 class Set_Time : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

  	  AnsiString Sep ;
   UINT16 NumberRespWords;           
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Set_TimeDT; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

 AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=4; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

  	INT32 CurrentTimeUnixVar;
	INT32  __fastcall CurrentTimeUnix_read();

 public:
 Set_Time() {;} 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };
 __property   INT32 CurrentTimeUnix = { read = CurrentTimeUnix_read };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Set_Time *Set_TimeM;
//---------------------------------------------------------------------------

//----------------Command Set Time-----------------------------------------
 class Set_Depth : public  TObject
{
private:

  BYTE NumCommand;
  BYTE Flags;

  	  AnsiString Sep ;
   UINT16 NumberRespWords;            
   BYTE NumberSentBytes;             
   USHORT CodeAlr;

 USHORT  __fastcall Comm() { NumCommand=Set_DepthDT; return NumCommand; }
 USHORT  __fastcall FlagCom() {  return Flags=0; }

 AnsiString  __fastcall Separ() {  return Sep="-----------"; }
  USHORT  __fastcall FuncNumberResponseWords_read() {  return NumberRespWords=1; }
  USHORT  __fastcall NumberSentBytesInCommand_read() {  return NumberSentBytes=4; }

	  USHORT  __fastcall CodeAlarmM_read() {  return CodeAlr; }
  void   __fastcall CodeAlarmM_write(USHORT in) { CodeAlr = in ;}

	INT32  CurrentDepthVar;
	INT32  __fastcall CurrentDepth_read(){return CurrentDepthVar;}
	void   __fastcall CurrentDepth_write(INT32 in) { CurrentDepthVar = in ;}

 public:
 Set_Depth()
 {
 CurrentDepthVar=5432;
 } 
  __property   UINT16 CodeAlarmPr = { read = CodeAlarmM_read, write = CodeAlarmM_write };

  protected:

__published:

 __property   USHORT NumerCommand  = { read = Comm };
 __property   USHORT FlagsCommand = { read = FlagCom };

     __property   AnsiString Separator = { read = Separ };
 __property   UINT16 NumberSentBytesInCommand = { read = NumberSentBytesInCommand_read };
 __property   UINT16 NumberResponseWords = { read = FuncNumberResponseWords_read };
 __property   UINT16 CodeAlarm = { read = CodeAlarmM_read };
 __property   INT32 CurrentDepth = { read = CurrentDepth_read, write = CurrentDepth_write };

   //	 __declspec (property(get = Ping1)) S_Ping_out NumerCommand;
};
extern Set_Depth *Set_DepthM;
//---------------------------------------------------------------------------

#endif
