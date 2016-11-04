//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "frmMain.h"
#include "MagicPoints.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
//---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btnLocateClick(TObject *Sender)
{
	MainFrm->lstPointsData->Clear();
	int points = LocateMagicPoint(cmbCompiler->ItemIndex);
	lblMagiCalls->Caption = points;
	if(points > 0)
		ShowMessage("Magic Points are successfully located, watch breakpoints to manage them");
	else
		ShowMessage("Magic Points couldn't be located, be sure that you have selected the correct compiler for the debugged application");
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::FormShow(TObject *Sender)
{
	lblMagiCalls->Caption = "0";
	MainFrm->lstPointsData->Clear();
}
//---------------------------------------------------------------------------


