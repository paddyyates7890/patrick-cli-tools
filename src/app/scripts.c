#include "scripts.h"
#include "../cli/interface.h"
#include "../cli/scriptsinterface.h"
#include "app.h"
#include <stdio.h>

char* getAllScripts(){
// read the scripts from a file 
}

int saveNewScript(){
// save a new script name to the file and return bool
}

void getScripts(){
    getScriptsMenu();

    char *scripts = getAllScripts();

    getScriptsList(scripts);
    scriptsInput();
}

void goToScriptCommand(char command){

}

void scriptsInput(){
    char command;
    printf("\n\n");
    getPadding(50);
    printf("%s(Scripts) %sEnter Command ",GRN, WHT);
    scanf(" %c", &command);

    goToScriptCommand(command);
}
