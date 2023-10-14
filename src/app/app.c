#include "../cli/interface.h"
#include "app.h"
#include "help.h"
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
        drawHelp(); 
        homeInput();
    }
    else if (command == 'D') {
        printf("\n");
        getPadding(50);
        printf("Development tools is not complete");
        homeInput();
    }
    else if (command == 'T'){
        printf("\n");
        getPadding(50);
        printf("Test is mot complete");
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
        printf("Scripts are not complete");
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
