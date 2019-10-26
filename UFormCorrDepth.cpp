//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormCorrDepth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm_Corr_Depth *Form_Corr_Depth;
//---------------------------------------------------------------------------
__fastcall TForm_Corr_Depth::TForm_Corr_Depth(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm_Corr_Depth::FormClose(TObject *Sender, TCloseAction &Action)

{
 Form_Main->Depth_Correct = StrToFloat(Edit1->Text);
 Form_Main->Coef_Correct = StrToFloat(Edit2->Text);
 Form_Main->Reset_Depth();
 Set_Service_ParM->BeginDepth = Form_Main->Depth_Correct*100 ;

  if(!FormTestDES8->chkSetDepthDataReq->Checked)   
  {
  FormTestDES8->NumSend_CommandToDT = Set_DepthDT;
  FormTestDES8->Send_CommandToDT(FormTestDES8->NumSend_CommandToDT) ;   
  }

  Form_Main->ChageDepth(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm_Corr_Depth::FormShow(TObject *Sender)
{
 Edit1->SetFocus();

 Edit1->Text=FloatToStrF(Form_Main->DEPTH_out/100,ffFixed,8,2);
 Edit1->SelectAll();

 if(FormTestDES8->chkSetDepthDataReq->Checked)   Form_Main->ToolbtnStartPollingClick(Form_Main->ToolbtnStartPolling);
 //Edit1->SelStart=0;
 //Edit1->SelLength = 10;
}

//---------------------------------------------------------------------------

void __fastcall TForm_Corr_Depth::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key==13)this->Close();  
}
//---------------------------------------------------------------------------

void __fastcall TForm_Corr_Depth::Button1Click(TObject *Sender)
{
 this->Close();
}
//---------------------------------------------------------------------------

