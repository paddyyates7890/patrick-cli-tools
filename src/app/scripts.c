#include "scripts.h"
#include "../cli/interface.h"
#include "../cli/scriptsinterface.h"
#include "../files/fileLib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../linked-list/linkedList.h"
#include "app.h"

void getAllScripts(){
    getScriptsMenu();
    
    linkedList *scripts = rFileList(SCRIPT_FILE);
    printf("%s \n\n", WHT);
    
    int scriptLen = LLcount(scripts);

    int i;
    char* script = LLindex(scripts, 0);
    for (i = 1; i <= scriptLen; i++){
        printf("%d: %s",i, script);
        script = LLindex(scripts, i);
    }

    LLdestroy(scripts);
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
        printf("test");        
    }
    else {
        printf("That was not a command option");
        scriptInput();
    }
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
    printf("Enter the name of the script of the command to be run : ");
    scanf("%49s", script);
    
    write_line(script, SCRIPT_FILE);

    getAllScripts();
}
