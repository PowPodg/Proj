//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UWrite_File.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Write_File::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }


Write_File *Thread_Write_to_File;

//---------------------------------------------------------------------------
/*
void __fastcall Write_File::BufferForWriteToFile_Filling(BYTE NUM_BLOCK)
{
 if(NUM_BLOCK==0&&(Dev_Proc->BlockDataInService->Depth_From_HID!=this->Temp_Count_Depth))
 {
  if(this->Flag_Buf)
  {  //ïðîåöèðóåì óêàçàòåëü íà îäèí áóôåð
   this->Temp_StructForService = (Write_File::ServiceData_File*)&this->New_ForWriteToFile[this->SizeBytes_for_Hread_Write_to_File];
  }
  if(this->Flag_Buf_1)
   { 
	this->Temp_StructForService = (Write_File::ServiceData_File*)&this->New_ForWriteToFile_1[this->SizeBytes_for_Hread_Write_to_File];
   }
  this->Temp_StructForService->Id = 0x77;  //íóæíî çàáèâàòü - óêàçàòåëü òèïà ýòîé ñòðóêòóðû - ïîýòîìó êîíñòðóêòîð ðàáîòàòü íå áóäåò - ñàì îáüåêò íå ñîçäàâàëñÿ
  this->Temp_StructForService->Count_Depth = Dev_Proc->BlockDataInService->Depth_From_HID;
  this->Temp_StructForService->Depth = (int)Form_Main->DEPTH_out;
  this->Temp_StructForService->Time_betw_Depth = Dev_Proc->BlockDataInService->Time_Betw_Depth_from_HID;
  this->Temp_StructForService->Time_Sec = DateTimeToUnix(Form_Main->GetCurrentDateTime());
  this->Temp_StructForService->Time_Milsec = Form_Main->SystemTime.wMilliseconds;

   this->Temp_Count_Depth = Dev_Proc->BlockDataInService->Depth_From_HID;
   this->SizeBytes_for_Hread_Write_to_File+=sizeof(*this->Temp_StructForService);
   Form_Main->count_Timer_for_Hread_Write_to_File++;
  }//end if(NUM_BLOCK==0)
 //---------------------------------------------------

  /*   ïîêà íå àêòóàëüíî!!!!!!!!!!!!!!!!!!
 
 if(NUM_BLOCK>0)
 {
	  if(NUM_BLOCK==1)     // òîëüêî â 1 áëîêå çàãîëîâîê äàííûõ ñêâàæèííîãî ïðèáîðà
	  {
		 if(this->Flag_Buf)
		 {
		 this->Temp_DT_Header_File = (Write_File::DT_Header_File*)&this->New_ForWriteToFile[this->SizeBytes_for_Hread_Write_to_File];
		 }
		 if(this->Flag_Buf_1)
		 {
		 this->Temp_DT_Header_File = (Write_File::DT_Header_File*)&this->New_ForWriteToFile_1[this->SizeBytes_for_Hread_Write_to_File];
		 }
		 this->Temp_DT_Header_File->Id = 0x55;  //íóæíî çàáèâàòü - óêàçàòåëü òèïà ýòîé ñòðóêòóðû - ïîýòîìó êîíñòðóêòîð ðàáîòàòü íå áóäåò - ñàì îáüåêò íå ñîçäàâàëñÿ
		 this->Temp_DT_Header_File->NumDataCurrent = Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;
		 this->Temp_DT_Header_File->NumDataVolt = Init_Gyro_Acceler_sensorsM->NumPointsUIforCable;
		 this->Temp_DT_Header_File->NumDataMain = InitSondeM->NumPointsSondeSendCable;
		 this->Temp_DT_Header_File->MagnSens.NumPointsTimeSlice = InitMagneticSensorsM->NumPointsTimeSliceForCable;
		 this->Temp_DT_Header_File->MagnSens.StepOffsetFirstSensor = InitMagneticSensorsM->StepOffsetFirstSensor;
		 this->Temp_DT_Header_File->MagnSens.NumSensDisBetwGroup = InitMagneticSensorsM->NumSensDisBetwGroup;
		 this->Temp_DT_Header_File->MagnSens.NumPolingCycleBefRes = InitMagneticSensorsM->NumPolingCycleBefRes;
		 this->Temp_DT_Header_File->MagnSens.NumSensInGroup = InitMagneticSensorsM->NumSensInGroup;
		 this->Temp_DT_Header_File->NumAccelGyr = 42;//áàéòà - âñåãäà ïîñòîÿííî ñì. ïðîòîêîë îáìåíà
		 this->Temp_DT_Header_File->AutoCalibSensMagn = Data_RequestM->FlagsCommand->AutoCalibSensMagn;

		 this->SizeBytes_for_Hread_Write_to_File+=sizeof(*this->Temp_DT_Header_File);
	  }
 }  */

//-----------------------------------------------------------------
/*
//  count_Timer_for_Hread_Write_to_File++;    
  if(this->SizeBytes_for_Hread_Write_to_File>=50000) 
													  
	   {
		   if(this->Flag_Buf) {this->Flag_Buf=false; this->Flag_Buf_1=true; this->Flag_Event_Buf = true;}  //Flag_Event_Buf - ÷òîáû íå ñðàáîòàë ñëåäóþùèé if
		   if(this->Flag_Buf_1&&!this->Flag_Event_Buf) {this->Flag_Buf_1=false; this->Flag_Buf=true;}
		   Form_Main->count_Timer_for_Hread_Write_to_File=0;
		   DWsize_buf_for_write = this->SizeBytes_for_Hread_Write_to_File; //ðàçìåð áóôåðà äëÿ çàïèñè â ôàéë, ò.å. ïîñëå òîãî
																		   //êàê íàáðàëñÿ çàäàííûé ðàçìåð áëîêà - ôèêñèðóåì ðàçìåð äëÿ çàïèñè â ôàéë
		   this->SizeBytes_for_Hread_Write_to_File = 0;
		   if(Form_Main->Flag_Start_Wrie) Resume();                //enable hread for write to file
		   this->Flag_Event_Buf = false;
	   }
	   */
//}
//----------------------------------------------------------------------------------------------------------------
__fastcall Write_File::Write_File(bool CreateSuspended)
	: TThread(CreateSuspended)
{
 this->SizeArrForWriteToFile =  100*(1000+sizeof(ServiceData_File));  //ðàçìåð ìàññèâà äëÿ çàïèñè â ôàéë (èñïîëüçóåòñÿ â main)
}
//---------------------------------------------------------------------------
void __fastcall Write_File::ClearArrForWriteToFile ()
{
  ZeroMemory(this->New_ForWriteToFile,this->SizeArrForWriteToFile);
  ZeroMemory(this->New_ForWriteToFile_1,this->SizeArrForWriteToFile);
}
//---------------------------------------------------------------------------
void __fastcall Write_File::Execute()
{

   //	  FreeOnTerminate = true; // îñâîáîäèòü çàíÿòóþ ïîòîêîì ïàìÿòü ïî îêîí÷àíèè åãî ðàáîòû
//---- Place thread code here ----
        while(1)
        {
//##############################################################################################
if(Form_Main->Flag_Start_Wrie&&!Form_Main->Flag_Stop_Wrie)  //åñëè óñïåøíî îïÿòü îòêðûëè ñ äîáàâëåíèåì è ñòàðò çàïèñè
   {
   if(Form_Main->Open_File())  //îòêðûâàåì ôàéë êàæäûé ðàç ïðè çàïèñè áëîêà (ìàêñ. ðàçìåð áëîêà < 65535 áàéò) äëÿ write ôóíêöèè
	  {                        //äëÿ WriteFile íàäî ïðîâåðèòü ðàçìåð áëîêà ìàêñ.
	//DWsize_buf_for_write = this->SizeBytes_for_Hread_Write_to_File;
  //-------------------------------------------
   //  EnterCriticalSection(&Form_Main->CS); 
 	 Form_Main->dwPos = SetFilePointer(Form_Main->Handl_Create_File, 0, NULL, FILE_END);    
   //	 LockFile(Form_Main->Handl_Create_File, Form_Main->dwPos, 0, DWsize_buf_for_write, 0);  
res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.CurrentDepth,sizeof(CombFileDes->Data.CurrentDepth), &Form_Main->NumbBytesWrittenData, NULL);
res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.count,sizeof(CombFileDes->Data.count), &Form_Main->NumbBytesWrittenData, NULL);
res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.time,sizeof(CombFileDes->Data.time), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, DT_DES8M->DataMain,
InitSondeM->NumPointsSondeSendCable*sizeof(*DT_DES8M->DataMain),&Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, CombFileDes->Data.ArrMagnSence,
CombFileDes->Header.SizeMagneticData*sizeof(*CombFileDes->Data.ArrMagnSence), &Form_Main->NumbBytesWrittenData, NULL);

//if(Data_RequestM->FlagsCommand->ReqDataCurrent)
   res_write=WriteFile (Form_Main->Handl_Create_File, DT_DES8M->DataCurrent,
   Init_Gyro_Acceler_sensorsM->NumPointsUIforCable*sizeof(*DT_DES8M->DataCurrent), &Form_Main->NumbBytesWrittenData, NULL);

//if(Data_RequestM->FlagsCommand->ReqDataVolt)
   res_write=WriteFile (Form_Main->Handl_Create_File, DT_DES8M->DataVolt,
   Init_Gyro_Acceler_sensorsM->NumPointsUIforCable*sizeof(*DT_DES8M->DataVolt), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.CalGyrAccInTimeMeasur,
sizeof(CombFileDes->Data.CalGyrAccInTimeMeasur), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.CalCRC32inTime,
sizeof(CombFileDes->Data.CalCRC32inTime), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.FilCRC32inTime,
sizeof(CombFileDes->Data.FilCRC32inTime), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.NumPointsGyrAccelOutTimeMeasur,
sizeof(CombFileDes->Data.NumPointsGyrAccelOutTimeMeasur), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.CalCRC32outTime,
sizeof(CombFileDes->Data.CalCRC32outTime), &Form_Main->NumbBytesWrittenData, NULL);

res_write=WriteFile (Form_Main->Handl_Create_File, &CombFileDes->Data.FilCRC32outTime,
sizeof(CombFileDes->Data.FilCRC32outTime), &Form_Main->NumbBytesWrittenData, NULL);


  //	 LeaveCriticalSection(&Form_Main->CS); // çàêðûòü êðèòè÷åñêèé ðàçäåë (ïîêèíóòü êðèòè÷åñêèé ðàçäåë)
 //--------------------------------------------

	  Form_Main->Close_File();      
	   } //if(Form_Main->Open_File())
	} // end Flag_Start_Wrie

		 this->Suspend();      
		 if(Terminated) break; 
		}
         //      Synchronize(Access_Ext_Form);
}
//---------------------------------------------------------------------------
 void __fastcall Write_File::Access_Ext_Form()
{
//Form1->Speed_Dev = Form1->Step_Depth_Real*3600/((double)Form1->Time_betw_Depth_from_HID*Form1->Time_Single_Tick_Time_from_HID);


//Form1->Label2->Caption=Form1->Speed_Dev;
    //  static int n = 0;

    //  n++;  // if(n>5000) n = 0;

    //   Form1->Label1->Caption = n;
     //  Application->ProcessMessages();
}
