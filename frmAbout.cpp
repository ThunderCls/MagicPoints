//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutFrm *AboutFrm;
//---------------------------------------------------------------------------
__fastcall TAboutFrm::TAboutFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutFrm::Label3Click(TObject *Sender)
{
	ShellExecute(AboutFrm->Handle, L"open", L"https://github.com/ThunderCls/MagicPoints", NULL, NULL, SW_SHOWMAXIMIZED);
}
//---------------------------------------------------------------------------
void __fastcall TAboutFrm::Label5Click(TObject *Sender)
{
	ShellExecute(AboutFrm->Handle, L"open", L"https://reversec0de.wordpress.com", NULL, NULL, SW_SHOWMAXIMIZED);
}
//---------------------------------------------------------------------------

