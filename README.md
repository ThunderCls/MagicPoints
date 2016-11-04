# MagicPoints
MagicPoints plugin for x64dbg

MagicPoints v1 plugin by ThunderCls - 2016

Blog: http://reversec0de.wordpress.com


MagicPoints is a plugin for the x86/x64 x64dbg debugger by @mrexodia. This plugin is intended to give the user the option to access certain points of the debugged application when events addresses are calculated, thus permiting to intercept such points to stop execution right before those events are executed.

There are several papers explaining such procedure in more details at:
- [Point HMEMCPY Explained](http://ricardonarvaja.info/WEB/CURSO%20NUEVO/TEORIAS%20NUMERADAS/000-100/030-PUNTO%20HMEMCPY%20EN%20OLLYDBG%20EN%20XP.zip)
- [Magic Points Explained](http://ricardonarvaja.info/WEB/CURSO%20NUEVO/TEORIAS%20NUMERADAS/301-400/343-Puntos%20Magicos%20por%20AkirA.rar)

After magic points are located for the current debugged application, such points are marked by a breakpoint and a comment for the user to recognize them.

Plugin based on papers by: AkirA & Ricardo Narvaja

---

Installation:
 - Copy MagicPoints.dp32 to x32 plugins directory of x64dbg
 - Look under the "Plugins" menu in the main x64dbg window or in the secondary menu in the Disasm window as well

---

Features & Usage:
 - Define the compiler for the current debugged application
 - Select such compiler from the dropdown menu
 - Click on the Locate button
 - A message will pop up whether magic points were located or not and a breakpoint along with a comment is setted in those points
 - Run your .exe and after the magic point breakpoint is hitted, place another BP on your exe code section and Run
 - If you did it right and everything was fine, you'll be landing exactly in the hot spot of your application
 
 ---
 
 Video Demo:
 
 <a href="http://www.youtube.com/watch?feature=player_embedded&v=4uoIWgkFXT8
" target="_blank"><img src="http://img.youtube.com/vi/4uoIWgkFXT8/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
