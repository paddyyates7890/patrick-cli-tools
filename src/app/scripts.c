#include "scripts.h"
#include "../cli/interface.h"
#include "../cli/scriptsinterface.h"
#include "../files/fileLib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "app.h"

void getAllScripts(){
    getScriptsMenu();
    printf("%s", WHT);
    char* file = getFile(SCRIPT_FILE);
    printListFile(file, 1);
    free(file);

    scriptInput();
}

void goToScriptCommand(char command){
    command = toupper(command); 

    if (command == 'X') {
        system("clear");
        getBody();
        homeInput();
    }else if (command == 'A'){
        addCommand();
    }else if (command == 'R'){
        runCommand();
    }
    else {
        printf("That was not a command option");
        scriptInput();
    }

    getAllScripts();
}

void scriptInput(){
    char command;
    printf("\n\n");

    printf("%s(Scripts) %s Enter Command: ", GRN, WHT);
    scanf(" %c", &command);

    goToScriptCommand(command);    
}

void addCommand(){
    char script[50];

    printf("\n\n");
    printf("Enter the script: ");
    scanf("%49s", script);

    write_line(script, getFile(SCRIPT_FILE));
}

void runCommand(){
    char command;
    int commandNum;

    printf("\n\n");
    printf("Enter the number of the command: ");
    scanf(" %c", &command);
    
    if (isdigit(command)) {
        commandNum = (int)command - '0';
        commandNum = commandNum - 1;
        char* line = read_line(commandNum, getFile(SCRIPT_FILE));
        system(line);
        
        free(line);
    }else {
        printf("That Was Not A Number");
        runCommand();
    }
}
