#include "plugin.h"
#include "MagicPoints.h"
#include "icons.h"
/*====================================================================================
CBINITDEBUG - Called by debugger when a program is debugged - needs to be EXPORTED

Arguments: cbType
cbInfo - a pointer to a PLUG_CB_INITDEBUG structure.
The szFileName item contains name of file being debugged.

--------------------------------------------------------------------------------------*/
PLUG_EXPORT void __cdecl CBINITDEBUG(CBTYPE cbType, PLUG_CB_INITDEBUG* info)
{
	OnInitDbg(info);
}
/*====================================================================================*/

PLUG_EXPORT void __cdecl CBSTOPDEBUG(CBTYPE cbType, PLUG_CB_STOPDEBUG* info)
{
}
/*====================================================================================*/

PLUG_EXPORT void __cdecl CBEXCEPTION(CBTYPE cbType, PLUG_CB_EXCEPTION* info)
{
}
/*====================================================================================*/

PLUG_EXPORT void __cdecl CBDEBUGEVENT(CBTYPE cbType, PLUG_CB_DEBUGEVENT* info)
{
}
/*====================================================================================
CBSYSTEMBREAKPOINT - Called by debugger at system breakpoint - needs to be EXPORTED

Arguments: cbType
cbInfo - a pointer to a PLUG_CB_SYSTEMBREAKPOINT structure

--------------------------------------------------------------------------------------*/
PLUG_EXPORT void __cdecl CBSYSTEMBREAKPOINT(CBTYPE cbType, PLUG_CB_SYSTEMBREAKPOINT* cbInfo)
{
}
/*====================================================================================*/

PLUG_EXPORT void __cdecl CBBREAKPOINT(CBTYPE cbType, PLUG_CB_BREAKPOINT* bpInfo)
{
}
/*====================================================================================*/

PLUG_EXPORT void __cdecl CBLOADDLL(CBTYPE cbType, PLUG_CB_LOADDLL *cbInfo)
{
}

/*====================================================================================
CBMENUENTRY - Called by debugger when a menu item is clicked - needs to be EXPORTED

Arguments: cbType
cbInfo - a pointer to a PLUG_CB_MENUENTRY structure. The hEntry contains
the resource id of menu item identifiers

Notes:     hEntry can be used to determine if the user has clicked on your plugins
menu item(s) and to do something in response to it.

--------------------------------------------------------------------------------------*/
PLUG_EXPORT void __cdecl CBMENUENTRY(CBTYPE cbType, PLUG_CB_MENUENTRY* info)
{
    switch(info->hEntry)
    {
	case MENU_GET_MC:
		DbgCmdExec("GetMagicPoints");
		break;
	case MENU_ABOUT:
		ShowAboutForm();
		break;
    default:
		break;
	}
}
/*====================================================================================*/

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
	_plugin_registercommand(pluginHandle, "GetMagicPoints", cbSetMagicPoints, true);

	return true; //Return false to cancel loading the plugin.
}
/*====================================================================================*/

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
	_plugin_unregistercommand(pluginHandle, "GetMagicPoints");

	_plugin_menuclear(hMenu);
    _plugin_menuclear(hMenuDisasm);
    _plugin_menuclear(hMenuDump);
	_plugin_menuclear(hMenuStack);

	return true;
}
/*====================================================================================*/

//Do GUI/Menu related things here.
void pluginSetup()
{
	ICONDATA menu_icon;
	menu_icon.data = icon;
	menu_icon.size = sizeof(icon);

	// Plugin Menu
	_plugin_menuseticon(hMenu, &menu_icon);

	_plugin_menuaddentry(hMenu, MENU_GET_MC, "&Find Magic Points");
	_plugin_menuaddseparator(hMenu);
	_plugin_menuaddentry(hMenu, MENU_ABOUT, "&About...");
}
/*====================================================================================*/
