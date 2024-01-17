#include "nginxtools.h"
#include <ctype.h>
#include <stdio.h>
#include "../cli/interface.h"
#include "../cli/devtoolscli/nginxinterface.h"
#include "../app/devtool.h"
#include "runCliCommands.h"

void getNginxTools(){
    getNginxMenu(); 
    getNginxInput();
}

void getNginxInput(){
    char command;
    printf("\n\n");

    printf("%s(NGINX)%s Enter Command: ", GRN, WHT);
    scanf(" %c", &command);

    goToNginxCommand(command);
}

void goToNginxCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        getDevTools();
    }else if (command == 'S'){
        getStatus();
        getNginxTools();
    }else if(command == 'E') {
        getErrorLog();
        getNginxTools();
    }else {
        printf("That was not a command");
        getNginxInput();
    }

}

void getStatus(){
    char* command = "systemctl status nginx";
    runCliCommand(command);
}

void getErrorLog(){
    char* command = "tail /var/log/nginx/error.log";
    runCliCommand(command);
}


