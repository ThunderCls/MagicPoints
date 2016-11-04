#include "dll_link.h"
#include <windows.h>

void GetDllFunctions()
{
	DebugSetBreakpoint = (_DebugSetBreakpoint)GetProcAddress(GetModuleHandle(x32dbg_module), "?SetBreakpoint@Debug@Script@@YA_NK@Z");
	PatternFindMem = (_PatternFindMem)GetProcAddress(GetModuleHandle(x32dbg_module), "?FindMem@Pattern@Script@@YAKKKPBD@Z");
	CommentSet = (_CommentSet)GetProcAddress(GetModuleHandle(x32dbg_module), "?Set@Comment@Script@@YA_NKPBD_N@Z");
	ModuleGetMainModuleName = (_ModuleGetMainModuleName)GetProcAddress(GetModuleHandle(x32dbg_module), "?GetMainModuleName@Module@Script@@YA_NPAD@Z");
	ModuleSectionFromName = (_ModuleSectionFromName)GetProcAddress(GetModuleHandle(x32dbg_module), "?SectionFromName@Module@Script@@YA_NPBDHPAUModuleSectionInfo@12@@Z");
	ModuleSectionListFromName = (_ModuleSectionListFromName)GetProcAddress(GetModuleHandle(x32dbg_module), "?SectionListFromName@Module@Script@@YA_NPBDPAUListInfo@@@Z");
}

