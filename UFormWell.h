//---------------------------------------------------------------------------

#ifndef UFormWellH
#define UFormWellH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
#include "Main_Form.h"
//---------------------------------------------------------------------------
class TFormWell : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TValueListEditor *ValueListEditor1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
unsigned int i;
public:		// User declarations
AnsiString Name_Well;
AnsiString Number;
AnsiString Name_Area;
char *charNameWell;
unsigned int numberCharNameWell;
int NumberFormShow;
        void __fastcall SetNameWell();
	__fastcall TFormWell(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWell *FormWell;
//---------------------------------------------------------------------------
#endif
