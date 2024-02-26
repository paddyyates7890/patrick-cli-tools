#include "../linked-list/linkedList.h"

#ifndef _SCRIPTS_ACTIVE
#define _SCRIPTS_ACTIVE

#define SCRIPT_FILE "/scripts.txt"

void getAllScripts();
void printScripts(linkedList *scripts);
void goToScriptCommand(char command);
void scriptInput();
void addCommand();
void runCommand();
void getScriptsMenu();
void getScriptsList(char *scripts);
#endif // !_SCRIPTS_ACTIVE
