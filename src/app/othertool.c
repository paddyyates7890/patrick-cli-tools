#include "othertool.h"
#include "app.h"
#include "../linked-list/linkedList.h"
#include "../othertools/passwords.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getOtherTools(){
    getotherToolMenu();

    printf("%s \n\n", WHT);
    linkedList *tools = getOtherToolList();
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

    othertoolInput();
}

void goTootherCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        system("clear");
        getBody();
        homeInput();
    }else if (isdigit(command)){
        linkedList *tools = getOtherToolList();
        int commandNum = (int)command - '0';
        commandNum = commandNum - 1;
        char* thisTool = LLindex(tools, commandNum);
        LLdestroy(tools);
        runotherTool(thisTool); 
    }else {
        printf("Not a command");
        othertoolInput();
    }
}

void othertoolInput(){
    char command;
    printf("\n\n");
    
    printf("%s(Other Tools) %sEnter Command: ",GRN, WHT);
    scanf(" %c", &command);

    goTootherCommand(command);
}

// This is abit rubish but every othertool will need to be added
// any other ideas?
linkedList* getOtherToolList(){
    linkedList *tools = create_list();
    LLpush(tools, "passwords");
    return tools;
}

void runotherTool(char *toolstr){
    
    if(!strcmp(toolstr, "passwords")){
        getPasswords();
    }else {
        printf("That is not a tool");
    }
}

void getotherToolCommands(){
    printf("%s(digit) enter command digit for tool ", BLU);
    printf("%s(X) Back to home ", RED);
}

void getotherToolMenu(){
    system("clear");
    printf("\n");
    getotherToolCommands();
}
