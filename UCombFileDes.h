//---------------------------------------------------------------------------

#ifndef UCombFileDesH
#define UCombFileDesH
//---------------------------------------------------------------------------
#include "Main_Form.h"
class CombFileDesT : public  TObject
 {
 private:

  public:
   void	CombFileDes(){;}

 #pragma pack (1)
typedef struct {
	UINT8  NumMagnSens;                               
	UINT16 TimePolingGyrAccel;//              
	UINT8  TimeForSetTimePar ;//               
	UINT8  TimeSampleADC24 ;//                     
	UINT8  KoeSubSampl ;//                       
} ServiceStr;
 #pragma pack ()

#pragma pack (1)
typedef struct {
	ServiceStr Service;
	UINT8 VersFile;
	UINT16 TimeStartCurrentPause;
	UINT16 TimeEndCurrentPause;
	UINT16 TimeStartAdc24;
	UINT16 Adc24_SizeDataForWritingToFlash;
	UINT16 Adc24_SizeDataToTransferForCable;
    UINT16 SizeDataMainSonde; 
    UINT16 SizeMagneticData;   
	UINT16 SizeDataUI;       
	UINT8  Nds;                            
	UINT8  Nof;                         
	UINT8  Nstep;                        
	UINT8  Nit;                          
	UINT8  Ngr;                        
	UINT8  null_value;                 
   //	UINT32 SizeStructAllData;           
   	UINT8 WellPlace[30];
	UINT8 WellName[10];  
	UINT8 StartDepth[3]; 
	UINT8 StopDepth[3];  
	UINT32 SyncTime;     
	UINT32 debug_flug;
	UINT16 SizeDataGyrAccelInTimeMeasur;  
	UINT16 SizeArrGyrAccelOutTimeMeasur;   
} Header_Str;
#pragma pack ()
 Header_Str Header;
 #pragma pack (1)
typedef struct
{
	UINT16 PointNumADC24;
	UINT16 MagnSens[16];
} MagnSenceStr;
 #pragma pack ()
 #pragma pack (1)
 typedef struct
{
	INT16 aX;
	INT16 aY;
	INT16 aZ;
	INT16 w;
	UINT32 Time;  
 } GyrAccMeasurStruct;
 #pragma pack ()
 #pragma pack (1)
 typedef struct
{
	UINT8 Count_Overflow_X_PLUS;
	UINT8 Count_Overflow_X_MINUS;
	UINT8 Count_Overflow_Y_PLUS;
	UINT8 Count_Overflow_Y_MINUS;
	UINT8 Count_Overflow_Z_PLUS;
	UINT8 Count_Overflow_Z_MINUS;
	INT32 Sum_forSpeed_X;
	INT32 Sum_forSpeed_Y;
	INT32 Sum_forSpeed_Z;
	INT64  Sum_forMove_X;
	//INT64  Sum_forMove_Y;
	UINT32 NumberBlocks;
	UINT32  FileNameNun;
	//INT64  Sum_forMove_Z;
	UINT32 All_NubersSectors;
	UINT32 NuberFreeSectors;
	INT32  Sum_Giro_Gyroscope;
	UINT16 Temperature_Acceler;
	UINT16 Temperature_Gyroscope;
	UINT16 GK_Data;
	UINT16 GK_Time;
 } CalclateGyrAccInTimeMeasurStruct;
 #pragma pack ()


 #pragma pack (1)
typedef struct {
    INT32 CurrentDepth;
	UINT32 count;
	UINT32 time; 
	
	UINT32 *ADC24;
	MagnSenceStr *ArrMagnSence;     
	UINT16 *I;
	UINT16 *U;
	GyrAccMeasurStruct *GyrAccInTimeMeasur; 
	CalclateGyrAccInTimeMeasurStruct CalGyrAccInTimeMeasur; 
	UINT32  CalCRC32inTime;                   
	UINT32  FilCRC32inTime;                   
	UINT16 NumPointsGyrAccelOutTimeMeasur;    
	GyrAccMeasurStruct *GyrAccOutTimeMeasur;  
	UINT32  CalCRC32outTime;                   
	UINT32  FilCRC32outTime;                  
} Data_Str;
#pragma pack ()
Data_Str Data;

   INT64 NumberBlocks;
   INT64 SizeFile;
   int SizeBlockSingle;
  // DWORD  NumbBytesReadDataTemp;

   protected:

 __published:


 };
  extern CombFileDesT *CombFileDes;
#endif
