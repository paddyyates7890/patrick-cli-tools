#include "devtool.h"
#include "app.h"
#include "../linked-list/linkedList.h"
#include "../devtools/phptools.h"
#include "../devtools/nginxtools.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getDevTools(){
    getDevToolMenu();

    printf("%s \n\n", WHT);
    linkedList *tools = getToolList();
    int toolLen = LLcount(tools);

    int i;
    char* tool = LLindex(tools, 0);
    for (i = 1; i <= toolLen; i++){
        printf("%d: %s  ",i, tool);
        if (i == 10) {
            printf("\n");
        }
        tool = LLindex(tools, i);
    }

    LLdestroy(tools);

    devtoolInput();
}

void goToDevCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        system("clear");
        getBody();
        homeInput();
    }else if (isdigit(command)){
        linkedList *tools = getToolList();
        int commandNum = (int)command - '0';
        commandNum = commandNum - 1;
        char* thisTool = LLindex(tools, commandNum);
        LLdestroy(tools);
        runDevTool(thisTool); 
    }else {
        printf("Not a command");
        devtoolInput();
    }
}

void devtoolInput(){
    char command;
    printf("\n\n");
    
    printf("%s(Development Tools) %sEnter Command: ",GRN, WHT);
    scanf(" %c", &command);

    goToDevCommand(command);
}

// This is abit rubish but every devtool will need to be added
// any other ideas?
linkedList* getToolList(){
    linkedList *tools = create_list();
    LLpush(tools, "php");
    LLpush(tools, "nginx");
    return tools;
}

void runDevTool(char *devtoolstr){
    
    if (!strcmp(devtoolstr, "php")) {
        getPhpDev();
    }else if (!strcmp(devtoolstr, "nginx")) {
        getNginxTools();
    }else {
        printf("That is not a tool");
    }
}

void getDevToolCommands(){
    printf("%s(digit) enter command digit for tool ", BLU);
    printf("%s(X) Back to home ", RED);
}

void getDevToolMenu(){
    system("clear");
    printf("\n");
    getDevToolCommands();
}

