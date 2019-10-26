//---------------------------------------------------------------------------

//поток для файла с глубиной и временем
#ifndef UDepthWrite_FileH
#define UDepthWrite_FileH
#include "setupapi.h"
#include "devguid.h"


#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#include <Winbase.h>
#include <windows.h>
#include "hidusage.h"
#include "hidpi.h"
#include <pshpack4.h>
//#include <fstream.h>

#include "Compile.h"

//#include "HID_M.h"


 #include "Main_Form.h"
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class DepthWrite_File : public TThread
{
protected:
	void __fastcall Execute();
	DWORD DWsize_buf_for_write;
	bool res_write;
public:
	__fastcall DepthWrite_File(bool CreateSuspended);
};
 extern DepthWrite_File *Thread_DepthWrite_File;
//---------------------------------------------------------------------------
#endif
