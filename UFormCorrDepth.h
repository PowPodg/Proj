//---------------------------------------------------------------------------

#ifndef UFormCorrDepthH
#define UFormCorrDepthH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "Main_Form.h"
//------------------------------------------------------------------------------
class TForm_Corr_Depth : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

	__fastcall TForm_Corr_Depth(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Corr_Depth *Form_Corr_Depth;
//---------------------------------------------------------------------------
#endif
