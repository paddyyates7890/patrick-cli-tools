#include "devtool.h"
#include "../cli/devtoolinterface.h"
#include "../cli/interface.h"
#include "app.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void getDevTools(){
    getDevToolMenu();
    devtoolInput();
}

void goToDevCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        system("clear");
        getBody();
        homeInput();
    }
}

void devtoolInput(){
    char command;
    printf("\n\n");
    
    printf("%s(Development Tools) %sEnter Command: ",GRN, WHT);
    scanf(" %c", &command);

    goToDevCommand(command);
}
