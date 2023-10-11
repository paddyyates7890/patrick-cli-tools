#include "../cli/interface.h"
#include "app.h"
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
        getPadding(50);
        printf("Help is not complete");
        homeInput();
    }
    else if (command == 'D') {
        printf("\n");
        getPadding(50);
        printf("Development tools is not complete");
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
