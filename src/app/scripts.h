#ifndef _SCRIPTS_ACTIVE
#define _SCRIPTS_ACTIVE

#define SCRIPT_FILE "scripts.txt"

char* getAllScripts();
int saveNewScript(char *script);
void addNewScript();
void getScripts();
void goToScriptCommand(char command);
void scriptsInput();

#endif // !_SCRIPTS_ACTIVE

