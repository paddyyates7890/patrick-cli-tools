#include "scripts.h"
#include "../cli/interface.h"
#include "../cli/scriptsinterface.h"
#include "app.h"
#include "../files/fileLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* getAllScripts(){
    return rFileConcat();
}

int saveNewScript(char *script){
    return write_line(script);
}

void addNewScript(){
    char *script;
    
    getPadding(50);
    printf("%s(Scripts) %sEnter Script Name: ",GRN,WHT);
    scanf(" %s", script);
    
    getPadding(50);
    saveNewScript(script);
    printf("\n the script has been saved");
    scriptsInput();
}

void getScripts(){
    getScriptsMenu();

    char *scripts = getAllScripts();

    getScriptsList(scripts);
    free(scripts);
    scriptsInput();
}

void goToScriptCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        system("clear");
        getHeader();
        getBody();
        homeInput();
    }
    else if (command == 'H'){
        printf("\n");
        printf("not complete");
        scriptsInput();
    }
    else if (command == 'R') {
        printf("\n");
        printf("not complete");
        scriptsInput();
    }
    else if (command == 'A'){
        printf("\n");
        addNewScript();
    }
}

void scriptsInput(){
    char command;
    printf("\n\n");
    getPadding(50);
    printf("%s(Scripts) %sEnter Command: ",GRN, WHT);
    scanf(" %c", &command);

    goToScriptCommand(command);
}