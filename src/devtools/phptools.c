#include "phptools.h"
#include <ctype.h>
#include <stdio.h>
#include "../cli/interface.h"
#include "../cli/devtoolscli/phpinterface.h"
#include "../app/devtool.h"

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

void getPhpVersion(){
    FILE *phpV = popen("php --version", "r");
    char result[128];
    while(fgets(result, sizeof(result), phpV) != NULL){
        printf("%s", result);
    }
    pclose(phpV);
    
    getchar();
    printf("Press Enter to Continue");
    while( getchar() != '\n' );    
}
