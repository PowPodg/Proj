//---------------------------------------------------------------------------

#ifndef USB_ServiceH
#define USB_ServiceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
 #include "Main_Form.h"
 #include "UHID_MY.h"
//---------------------------------------------------------------------------
class TSevice_USB : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TMemo *Memo1;
	TButton *Button1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
          	void __fastcall Cleat_Edits();
	__fastcall TSevice_USB(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TSevice_USB *Sevice_USB;
//---------------------------------------------------------------------------
#endif
