#include "phptools.h"
#include <ctype.h>
#include <stdio.h>
#include "../cli/interface.h"
#include "../cli/devtoolscli/phpinterface.h"
#include "../app/devtool.h"
#include "runCliCommands.h"

void getPhpDev(){
    getPhpMenu();
    getPhpInput();
}

void getPhpInput(){
    char command;
    printf("\n\n");

    printf("%s(PHP)%s Enter Command: ", GRN, WHT);
    scanf(" %c", &command);

    goToPhpCommand(command);
}

void goToPhpCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        getDevTools();
    }else if (command == 'V'){
        getPhpVersion();
        getPhpDev();
    }else {
        printf("That was not a command");
        getPhpInput();
    }
}

// get the current version from the terminal.
void getPhpVersion(){
    char * command = "php --version";
    runCliCommand(command);
}
