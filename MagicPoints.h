#pragma once

#include <windows.h>
#include "pluginmain.h"

typedef enum{
	COMPILER_VB5 = 0,
	COMPILER_VB6,
	COMPILER_BORLAND,
	COMPILER_VC6,
	COMPILER_VC10_MFC_DYNAMIC_DEBUG,
	COMPILER_VC10_MFC_DYNAMIC_RELEASE,
	COMPILER_VC10_MFC_STATIC_DEBUG,
	COMPILER_VC10_MFC_STATIC_RELEASE,
	COMPILER_VC12_MFC_DYNAMIC_DEBUG,
	COMPILER_VC12_MFC_DYNAMIC_RELEASE,
	COMPILER_VC12_MFC_STATIC_DEBUG,
	COMPILER_VC12_MFC_STATIC_RELEASE,
	COMPILER_VC14_MFC_DYNAMIC_DEBUG,
	COMPILER_VC14_MFC_DYNAMIC_RELEASE,
	COMPILER_VC14_MFC_STATIC_DEBUG,
	COMPILER_VC14_MFC_STATIC_RELEASE,
	POINT_HMEMCPY
}COMPILER_TYPE;

typedef struct _stMagicPoint{
	COMPILER_TYPE compiler;
	AnsiString module;
	int section;
	int bp_displacement;
	const unsigned char pattern[50];
	bool loop;
}stMagicPoint;


//functions
int LocateMagicPoint(COMPILER_TYPE compiler);
int FindPattern(stMagicPoint *MagicPoint);
bool cbSetMagicPoints(int argc, char* argv[]);
void ShowAboutForm();
void OnInitDbg(PLUG_CB_INITDEBUG* info);

