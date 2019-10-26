//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormWell.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormWell *FormWell;

//---------------------------------------------------------------------------
__fastcall TFormWell::TFormWell(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormWell::FormClose(TObject *Sender, TCloseAction &Action)
{
Name_Well=ValueListEditor1->Values["Name Well"];
Name_Area = ValueListEditor1->Values["Name Area"];
Set_Service_ParM->NameAreaPr= Name_Area;
Set_Service_ParM->NumberNameHolePr = Name_Well;

numberCharNameWell=Name_Well.Length();
charNameWell=new char[numberCharNameWell];
ZeroMemory(charNameWell,numberCharNameWell);
charNameWell=Name_Well.c_str();
Form_Main->Caption="";
Form_Main->Caption= "Test downhole electro magnetic flaw detector.  "+ Form_Main->Vers_Prog + Number+ Name_Well+" )";

 if(!FormTestDES8->chkSetDepthDataReq->Checked)  
  {
   FormTestDES8->NumSend_CommandToDT = Set_Service_Parameters;
   FormTestDES8->Send_CommandToDT(FormTestDES8->NumSend_CommandToDT) ;  
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormWell::SetNameWell()
{

}
//---------------------------------------------------------------------------

void __fastcall TFormWell::FormShow(TObject *Sender)
{
Number="   ( Name Well - ";
if(NumberFormShow==0)
   {
   ValueListEditor1->Values["Name Area"] ="ONGKM" ;
   ValueListEditor1->Values["Name Well"]="TEST";
   }
   else
	  {
	  ValueListEditor1->Values["Name Area"] =Name_Area ;
	  ValueListEditor1->Values["Name Well"]=Name_Well;
	 }

   Set_Service_ParM->NameAreaPr= ValueListEditor1->Values["Name Area"];
   Set_Service_ParM->NumberNameHolePr = ValueListEditor1->Values["Name Well"];


NumberFormShow++;
delete [] charNameWell;

 if(FormTestDES8->chkSetDepthDataReq->Checked)   Form_Main->ToolbtnStartPollingClick(Form_Main->ToolbtnStartPolling);
}
//---------------------------------------------------------------------------


