#pragma once
#include "pluginmain.h"

enum
{
	MENU_GET_MC,
	MENU_ABOUT,
};

//functions
bool pluginInit(PLUG_INITSTRUCT* initStruct);
bool pluginStop();
void pluginSetup();
