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
        int err = system("clear");
        exit(0);
    }
    else if (command == 'H') {
        printf("\n");
        getHelp(); 
        homeInput();
    }
    else if (command == 'D') {
        printf("\n");
        
        getDevTools();
        homeInput();
    }
    else if (command == 'T'){
        printf("\n");
        
        runTests();
        homeInput();
    }
    else if (command == 'O'){
        printf("\n");
        
        printf("The other tools are not complete");
        homeInput();
    }
    else if (command == 'S'){
        printf("\n");
        
        getAllScripts();
        homeInput();
    }
}

void homeInput(){
    char command;
    printf("\n\n");
    
    printf("%sEnter Command: ", WHT);
    int err = scanf(" %c", &command);

    goToCommand(command);
}
