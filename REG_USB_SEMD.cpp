//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UFormCorrDepth.cpp", Form_Corr_Depth);
USEFORM("UFormTestDES8.cpp", FormTestDES8);
USEFORM("UFormWell.cpp", FormWell);
USEFORM("USB_Service.cpp", Sevice_USB);
USEFORM("Main_Form.CPP", Form_Main);
USEFORM("About.cpp", AboutBox);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
try {
  Application->Initialize();
		Application->CreateForm(__classid(TForm_Main), &Form_Main);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TSevice_USB), &Sevice_USB);
		Application->CreateForm(__classid(TFormWell), &FormWell);
		Application->CreateForm(__classid(TFormTestDES8), &FormTestDES8);
		Application->CreateForm(__classid(TForm_Corr_Depth), &Form_Corr_Depth);
		Application->Run();

  } catch (...) {
  return 0;

  }


	return 0;
}
//---------------------------------------------------------------------
