#pragma once

#include <windows.h>
#include "pluginmain.h"

/*variables*/
const wchar_t *x32dbg_module = L".\\x32dbg.dll";

/*functions*/
void GetDllFunctions();

/* global functions pointers*/
//---------------------------------------------------------------------------
typedef duint (__cdecl *_DebugSetBreakpoint)(
	duint
);

typedef bool (__cdecl *_DebugDeleteBreakpoint)(
	duint address
);

typedef duint (__cdecl *_ModuleEntryFromName)(
	const char* name
);

typedef duint (__cdecl *_PatternFind)(
	unsigned char* data,
	duint datasize,
	const char* pattern
);

typedef duint (__cdecl *_PatternFindMem)(
	duint start,
	duint size,
	const char* pattern
);

typedef bool (__cdecl *_CommentSet)(
	duint addr,
	const char* text,
	bool manual = false
);

typedef bool (__cdecl *_LabelSet)(
	duint addr,
	const char* text,
	bool manual = false
);

typedef duint (__cdecl *_ModuleBaseFromName)(
	const char* name
);

typedef bool (__cdecl *_ModuleSectionListFromName)(
	const char* name,
	ListOf(ModuleSectionInfo) list
);

typedef bool (__cdecl *_ModuleSectionFromName)(
	const char* name,
	int number,
	Script::Module::ModuleSectionInfo* section
);

typedef bool (__cdecl *_ModuleGetMainModuleSectionList)(
	ListOf(ModuleSectionInfo) list
);

typedef bool (__cdecl *_ModuleGetMainModuleName)(
	char* name
);

typedef bool (__cdecl *_DisassemblySelectionSet)(
	duint start,
	duint end
);


extern _DebugSetBreakpoint DebugSetBreakpoint;
extern _PatternFindMem PatternFindMem;
extern _CommentSet CommentSet;
extern _ModuleGetMainModuleName ModuleGetMainModuleName;
extern _ModuleSectionFromName ModuleSectionFromName;
extern _ModuleSectionListFromName ModuleSectionListFromName;
