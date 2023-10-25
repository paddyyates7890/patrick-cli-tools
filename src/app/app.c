#include "../cli/interface.h"
#include "app.h"
#include "devtool.h"
#include "help.h"
#include "../test/test.h"
#include "scripts.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void goToCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        system("clear");
        exit(0);
    }
    else if (command == 'H') {
        printf("\n");
        getHelp(); 
        homeInput();
    }
    else if (command == 'D') {
        printf("\n");
        getPadding(50);
        getDevTools();
        homeInput();
    }
    else if (command == 'T'){
        printf("\n");
        getPadding(50);
        runTests();
        homeInput();
    }
    else if (command == 'O'){
        printf("\n");
        getPadding(50);
        printf("The other tools are not complete");
        homeInput();
    }
    else if (command == 'S'){
        printf("\n");
        getPadding(50);
        getScritps();
        homeInput();
    }
}

void homeInput(){
    char command;
    printf("\n\n");
    getPadding(50);
    printf("%sEnter Command: ", WHT);
    scanf(" %c", &command);

    goToCommand(command);
}
