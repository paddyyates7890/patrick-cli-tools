#include "../cli/interface.h"
#include "app.h"
#include <stdio.h>
#include <stdlib.h>

void goToCommand(char command){
    if (command == 'X') {
        system("clear");
        exit(0);
    }
    else if (command == 'H') {
        getPadding(50);
        printf("\n Help is not complete");
        homeInput();
    }
    else if (command == 'D') {
        getPadding(50);
        printf("\n Development tools is not complete");
        homeInput();
    }
}

void homeInput(){
    char command;
    getPadding(50);

    printf("%s\n Enter Command: ", WHT);
    scanf(" %c", &command);

    goToCommand(command);
}
