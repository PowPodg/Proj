//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USB_Service.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSevice_USB *Sevice_USB;
//extern TMY_HID  *MY_HID;
//extern TForm_Main *Form_Main;

//---------------------------------------------------------------------------
__fastcall TSevice_USB::TSevice_USB(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSevice_USB::Cleat_Edits()
{
Edit1->Clear();
Edit2->Clear();
Edit3->Clear();
Edit4->Clear();
Edit5->Clear();
Edit6->Clear();
Edit7->Clear();
Sevice_USB->Memo1->Lines->Clear();
}
//------------------------------------------------------
void __fastcall TSevice_USB::FormClose(TObject *Sender, TCloseAction &Action)
{
 Form_Main->Start_Polling_USB();
}
//---------------------------------------------------------------------------


