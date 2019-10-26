//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDES8.h"
#pragma package(smart_init)
TIniFile *ini;
AnsiString IniFileName;
DT_DES8 *DT_DES8M;
Ping_Data *PingM;
InitSonde_Data *InitSondeM;
InitMagneticSensors_Data *InitMagneticSensorsM;
Init_Gyro_Acceler_sensors *Init_Gyro_Acceler_sensorsM;
//Data_Request *Data_RequestM;
Data_Request *Data_RequestM;
Setting_Pot_gain_offset *Setting_Pot_gain_offsetM;
Start_Autocalibr_MagnSens *Start_Autocalibr_MagnSensM;
Echo *EchoM;
Set_TransmSpeed *Set_TransmSpeedM;
Query_WordStateDevice *Query_WordStateDeviceM;
Start_ContinRecord *Start_ContinRecordM;
Stop_ContinRecord *Stop_ContinRecordM;
Reset_SpeedMove *Reset_SpeedMoveM;
Reset_Azimuth *Reset_AzimuthM;
Set_Service_Par * Set_Service_ParM;
Set_Time *Set_TimeM;
Set_Depth *Set_DepthM;
//-----------------------------------------------------------------------------------------
INT32  __fastcall Set_Time::CurrentTimeUnix_read()
  {
  CurrentTimeUnixVar = DateTimeToUnix(Form_Main->GetCurrentDateTime());
  return CurrentTimeUnixVar;
  }

//-----------------------------------------------------------------------------------------
INT32  __fastcall Set_Service_Par::CurrentTimeUnix_read()
  {
  CurrentTimeUnixVar = DateTimeToUnix(Form_Main->GetCurrentDateTime());
  return CurrentTimeUnixVar;
  }

//-------------------------------------------------------------------------
void   __fastcall Set_Service_Par::NameArea_write(AnsiString in)
  {
  this->NameAreaAnsiStr = in ;
	if(this->NameAreaAnsiStr.Length()>this->SizeNameAreaBytePr)
	{
	 MessageBox (NULL, L"The number of characters in this field\n shall not be greater than 30!!!!", L"Error input!", MB_OK);
	 this->NameAreaAnsiStr.SetLength(this->SizeNameAreaBytePr) ;
	 return;
	}
  }
//-------------------------------------------------------------------
void   __fastcall Set_Service_Par::NameHole_write(AnsiString in)
  {
  this->NameHoleAnsiStr = in ;
  if(this->NameHoleAnsiStr.Length()>this->SizeNumberNameHoleBytePr)
   {
	MessageBox (NULL, L"The number of characters in this field\n shall not be greater than 10!!!!", L"Error input!", MB_OK);
   //	ShowMessage("Error input","The number of characters in this field\n shall not be greater than 14!!!");
	this->NameHoleAnsiStr.SetLength(this->SizeNumberNameHoleBytePr);
	return ;
	}
  }

//TDES8 *DES8;
//---------------------------------------------------------------------------
void __fastcall FormTestDES8BlinkDisable()
{
//FormTestDES8->hld_response_command->Blink=false;
}
//-------------------------------------------------------------
DT_DES8::DT_DES8()
 {
 DataCurrent = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];//+2 на всякий случай
 DataVolt = new USHORT [Init_Gyro_Acceler_sensorsM->NumPointsUIforCable+2];
 DataMain = new UINT32 [InitSondeM->NumPointsSondeSendCable+2];
 DataMagneticSensors = new USHORT [(16*InitMagneticSensorsM->NumPointsTimeSliceForCable)+2];
 DTMagneticSensorsStruct = new MagneticSensors [InitMagneticSensorsM->NumPointsTimeSliceForCable+1] ;   //???????????????
 DataForRequestCommandStruct = (DataForRequestCommand*) DataRequestCommand;
 StructDataAccelGyr=(S_DataAccelGyr*) DataAccelGyr;

 } //конструктор
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
 void __fastcall IniWrite(AnsiString Section, AnsiString TypeComand, USHORT Value)
{
 ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
 ini->WriteInteger( Section, TypeComand, Value );
 delete ini;
}
//-------------------------------------------------------------------------------
 void __fastcall IniWriteBool(AnsiString Section, AnsiString TypeComand, bool Value)
{
 ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
 ini->WriteBool( Section, TypeComand, Value );
 delete ini;
}
//-------------------------------------------------------------------------------
//после этой функции нужно delete ini;
 USHORT __fastcall IniRead(AnsiString Section, AnsiString TypeComand)
{
 ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
 return ini->ReadInteger ( Section, TypeComand,  0);
}
//-----------------------------------------------------------------------------------------
bool __fastcall IniReadBool(AnsiString Section, AnsiString TypeComand)
{
 ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );

return ini->ReadBool ( Section, TypeComand,  0);

}
//-------------------------------------------------------------------------------------
bool __fastcall IsIniReadCection(AnsiString Section)
{
bool TempTrue;
 TStringList* ListSections = new TStringList;
 ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );

  ini->ReadSections(Section, ListSections);
  if(ListSections->Count>0)TempTrue=true;
  else TempTrue=false;

 delete ListSections;
 return TempTrue;
}

 //void __fastcall Data_Request::BitsFlagsCommand::bit0_write(bool in) {bit0_p=in; FormTestDES8->BlinkDisable();}

