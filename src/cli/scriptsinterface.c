#include "scriptsinterface.h"
#include <stdio.h>
#include "interface.h"
#include "stdlib.h"
#include "string.h"

void getScriptCommands(){
    getPadding(35);
    printf("%s(A) Add Script ", MAG); 
    printf("%s(R) Run script ", YEL);
    printf("%s(X) Back to home", RED);
}

void getScriptsMenu(){
    system("clear");
    printf("\n");
    getHeader();
    getScriptCommands();
}

void getScriptsList(char *scripts){
    int size, i;
    
    printf("%s\n", WHT);
    getPadding(50);
    // in the future i will need to stop it printing after a certain length 
    // or certain number of words but not today
    printf("%s\n", scripts); 
}
