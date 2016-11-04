#include "MagicPoints.h"
#include <windows.h>
#include <vcl.h>
#include "frmMain.h"
#include "frmAbout.h"
#include "pluginmain.h"
#include "dll_link.h"
#include "_scriptapi_module.h"
/*=============================================================================================*/
//---------------------------------------------------------------------------
/* global functions pointers */
//---------------------------------------------------------------------------
_DebugSetBreakpoint DebugSetBreakpoint;
_PatternFindMem PatternFindMem;
_CommentSet CommentSet;
_ModuleGetMainModuleName ModuleGetMainModuleName;
_ModuleSectionFromName ModuleSectionFromName;
_ModuleSectionListFromName ModuleSectionListFromName;
/*=============================================================================================*/

bool cbSetMagicPoints(int argc, char* argv[])
{
	// Create Form
	if(!MainFrm)
		MainFrm = new TMainFrm(NULL);

	MainFrm->ShowModal();

	delete MainFrm;
	MainFrm = NULL;
	return true;
}
/*=============================================================================================*/

void ShowAboutForm()
{
	if(!AboutFrm)
		AboutFrm = new TAboutFrm(NULL);

	AboutFrm->ShowModal();
	delete AboutFrm;
	AboutFrm = NULL;
}
/*=============================================================================================*/

void OnInitDbg(PLUG_CB_INITDEBUG* info)
{
	// get dinamic dll functions
	GetDllFunctions();
}
/*=============================================================================================*/

int LocateMagicPoint(COMPILER_TYPE compiler)
{
	stMagicPoint MagicPoint;
	char *name;
	int result = 0;

	MagicPoint.compiler = compiler;
	switch(compiler)
	{
		case COMPILER_VB5:
			MagicPoint.module = "msvbvm50.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 2;
			strcpy(MagicPoint.pattern, "F3A5FFD08BE55D8945FC8B45FC5F5E8BE55DC20C"); // VB5 pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VB6:
			MagicPoint.module = "msvbvm60.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 2;
			strcpy(MagicPoint.pattern, "F3A5FFD08BE55D8945FC8B45FC5F5EC9C20C"); // VB6 pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_BORLAND:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 0;
				MagicPoint.bp_displacement = 10;
				strcpy(MagicPoint.pattern, "740E8BD38B83????????FF93????????"); // DELPHI pattern
				MagicPoint.loop = true;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC6:
			MagicPoint.module = "mfc42d.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 10;
			strcpy(MagicPoint.pattern, "CC33C085C075E38B4D08FF55FCE94804????33C985C97401CC"); // VC6 pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC10_MFC_DYNAMIC_DEBUG:
			MagicPoint.module = "mfc100ud.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 4;
			strcpy(MagicPoint.pattern, "CC8B4D08FF55F8E9????????837D18007411"); // VC10 DYNAMIC DEBUG pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC10_MFC_DYNAMIC_RELEASE:
			MagicPoint.module = "mfc100u.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 15;
			strcpy(MagicPoint.pattern, "8B550C83C2C783FA0B0F87????????FF2495????????"); // VC10 DYNAMIC RELEASE pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC10_MFC_STATIC_DEBUG:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 1;
				MagicPoint.bp_displacement = 4;
				strcpy(MagicPoint.pattern, "CC8B4D08FF55F8E9????????837D18007411"); // VC10 STATIC DEBUG pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC10_MFC_STATIC_RELEASE:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 0;
				MagicPoint.bp_displacement = 16;
				strcpy(MagicPoint.pattern, "8B451C83C0C75683F80B0F87????????FF2485????????"); // VC10 STATIC RELEASE pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC12_MFC_DYNAMIC_DEBUG:
			MagicPoint.module = "mfc120ud.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 6;
			strcpy(MagicPoint.pattern, "CC8BF48B4D08FF55F83BF4E8????????E9????????"); // VC12 DYNAMIC DEBUG pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC12_MFC_DYNAMIC_RELEASE:
			MagicPoint.module = "mfc120u.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 15;
			strcpy(MagicPoint.pattern, "8B451483C0C683F80B0F87????????FF2485????????"); // VC12 DYNAMIC RELEASE pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC12_MFC_STATIC_DEBUG:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 1;
				MagicPoint.bp_displacement = 6;
				strcpy(MagicPoint.pattern, "CC8BF48B4D08FF55F83BF4E8????????E9????????"); // VC12 STATIC DEBUG pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC12_MFC_STATIC_RELEASE:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 0;
				MagicPoint.bp_displacement = 16;
				strcpy(MagicPoint.pattern, "8B451C83C0C65683F80B0F87????????FF2485????????"); // VC12 STATIC RELEASE pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC14_MFC_DYNAMIC_DEBUG:
			MagicPoint.module = "mfc140ud.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 3;
			strcpy(MagicPoint.pattern, "8B4D08FF55B83BF4E8????????E9????????"); // VC14 DYNAMIC DEBUG pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC14_MFC_DYNAMIC_RELEASE:
			MagicPoint.module = "mfc140u.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 16;
			strcpy(MagicPoint.pattern, "8B451483C0C65783F80B0F87????????FF2485????????"); // VC14 DYNAMIC RELEASE pattern
			MagicPoint.loop = false;
		break;
		case COMPILER_VC14_MFC_STATIC_DEBUG:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 1;
				MagicPoint.bp_displacement = 3;
				strcpy(MagicPoint.pattern, "8B4D08FF55B83BF4E8????????E9????????"); // VC14 STATIC DEBUG pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case COMPILER_VC14_MFC_STATIC_RELEASE:
			name = new char[MAX_MODULE_SIZE];
			if(ModuleGetMainModuleName(name))
			{
				MagicPoint.module = name;
				MagicPoint.section = 0;
				MagicPoint.bp_displacement = 16;
				strcpy(MagicPoint.pattern, "8B451C83C0C65783F80B0F87????????FF2485????????"); // VC14 STATIC RELEASE pattern
				MagicPoint.loop = false;
				delete[] name;
			}
			else
			{
				delete[] name;
				return result;
			}
		break;
		case POINT_HMEMCPY:
			MagicPoint.module = "user32.dll";
			MagicPoint.section = 0;
			MagicPoint.bp_displacement = 3;
			strcpy(MagicPoint.pattern, "515053E88429010083C40C8BCF"); // HMEMCPY pattern
			MagicPoint.loop = false;
		break;
		default:
		break;
	}

	return FindPattern(&MagicPoint);
}
/*=============================================================================================*/

int FindPattern(stMagicPoint *MagicPoint)
{
	int result = 0;

	Script::Module::ModuleSectionInfo *modInfo = new Script::Module::ModuleSectionInfo;
	if(!ModuleSectionFromName(MagicPoint->module.c_str(), MagicPoint->section, modInfo))
		return result;

	duint rvaCodeSection = modInfo->addr; // get section address
	duint sectionSize = modInfo->size;    // get section size

	TListItem *Item;
	DWORD lpPattern = -1;
	DWORD startRVA = rvaCodeSection;
	do
	{
		lpPattern = PatternFindMem(rvaCodeSection, sectionSize, MagicPoint->pattern);
		if(lpPattern > 0)
		{
			rvaCodeSection = lpPattern + MagicPoint->bp_displacement;
			DebugSetBreakpoint(rvaCodeSection);                  // set breakpoint
			CommentSet(rvaCodeSection, "<<-- MAGIC_POINT", true); // set comment

			// populate gui info listview
			Item = MainFrm->lstPointsData->Items->Add();
			Item->Caption = MagicPoint->module;
			Item->SubItems->Add(IntToHex((__int64)rvaCodeSection, 8));

			// recalculate section size
			sectionSize = sectionSize - (lpPattern - startRVA);
			startRVA = lpPattern;

			result++;
		}
		else
			break;
	}while(MagicPoint->loop);

	return result;
}
