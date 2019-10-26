//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class UDepthWrite_File : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall UDepthWrite_File(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
