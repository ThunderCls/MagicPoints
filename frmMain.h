//---------------------------------------------------------------------------
#pragma once
#ifndef frmMainH
#define frmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TMainFrm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *lblMagiCalls;
	TListView *lstPointsData;
	TGroupBox *GroupBox1;
	TComboBox *cmbCompiler;
	TButton *btnLocate;
	void __fastcall btnLocateClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TList *lstBreakInfo; // Global variable that holds all the info for the current module
	__fastcall TMainFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
