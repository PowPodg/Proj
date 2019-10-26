//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "UDepthWrite_File.h"
#pragma package(smart_init)

DepthWrite_File *Thread_DepthWrite_File;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall DepthWrite_File::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall DepthWrite_File::DepthWrite_File(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall DepthWrite_File::Execute()
{
  //	NameThreadForDebugging(System::String(L"UDepthWrite_File"));
	//---- Place thread code here ----
	while(1)
	{
	 if(Form_Main->Depth_Flag_Start_Write&&!Form_Main->Depth_Flag_Stop_Write)  
	  {
		if(Form_Main->DepthOpen_File())  
		 {
		 DWsize_buf_for_write = Form_Main->Num_Buffer*sizeof(Dev_Proc->Data_FileFunc);
		

			 EnterCriticalSection(&Form_Main->CS); 

	 if(!Form_Main->Flag_Buf) {
							   Form_Main->dwPos = SetFilePointer(Form_Main->TIME_DEPTH_Handl_Create_File, 0, NULL, FILE_END);
							   LockFile(Form_Main->TIME_DEPTH_Handl_Create_File, Form_Main->dwPos, 0, DWsize_buf_for_write, 0);
			  res_write=WriteFile (Form_Main->TIME_DEPTH_Handl_Create_File, Dev_Proc->Data_File_Depth,DWsize_buf_for_write, &Form_Main->NumbBytesWrittenData, NULL);
		  if(!res_write){
						MessageBox (NULL, L"Can't write DATA to file", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
						return;
						}
							  }

		   LeaveCriticalSection(&Form_Main->CS); 
		   //------------------------------------------------------------------------
		   EnterCriticalSection(&Form_Main->CS); 
	if(!Form_Main->Flag_Buf_1) {
							  Form_Main->dwPos = SetFilePointer(Form_Main->TIME_DEPTH_Handl_Create_File, 0, NULL, FILE_END);
							  LockFile(Form_Main->TIME_DEPTH_Handl_Create_File, Form_Main->dwPos, 0, DWsize_buf_for_write, 0);
							  res_write=WriteFile (Form_Main->TIME_DEPTH_Handl_Create_File, Dev_Proc->Data_File_Depth_1,DWsize_buf_for_write, &Form_Main->NumbBytesWrittenData, NULL);
		  if(!res_write)  {
						   MessageBox (NULL, L"Can't write DATA to file", L"Error", MB_OK|MB_ICONERROR|MB_TASKMODAL);
						   return;
						   }
								}
	 LeaveCriticalSection(&Form_Main->CS); 
	 Form_Main->Close_File_Depth(); 
		  }
	   }
	   //------------------------------------------------------




	   this->Suspend();       
	   if(Terminated) break; 
	}
}
//---------------------------------------------------------------------------
