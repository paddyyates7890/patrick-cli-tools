#include <stdlib.h>
#include "app/app.h"
#include "app/othertool.h"
#include "app/devtool.h"
#include "app/help.h"
#include "test/test.h"
#include "app/scripts.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    system("clear"); 
    getBody();
    homeInput();    
    return 0;
}

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
        
        getOtherTools();
        homeInput();
    }
    else if (command == 'S'){
        printf("\n");
        
        getAllScripts();
        homeInput();
    }else {
        printf("that is not a command");
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

void getCommands(){
    printf("https://github.com/paddyyates7890/patrick-cli-tools/issues\nPlease add any possible improvements or bugs here :) \n\n");

    printf("%s(O) other tools ", MAG);
    printf("%s(S) Scripts ", YEL);
    printf("%s(D) Development Tools ", CYN);
    printf("%s(H) Help ", GRN);
    printf("%s(X) Exit ", RED); // DO NOT REMOVE !!!!
    printf("%s(T) Test ", WHT);
}

void getBody(){
    getCommands();
}

// testing
void testColours(){
    printf("%s RED\n", RED);
    printf("%s GRN\n", GRN);
    printf("%s YEL\n", YEL);
    printf("%s BLU\n", BLU);
    printf("%s MAG\n", MAG);
    printf("%s CYN\n", CYN);
    printf("%s WHT\n", WHT);
}


