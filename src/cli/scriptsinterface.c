#include "scriptsinterface.h"
#include <stdio.h>
#include "interface.h"
#include "stdlib.h"

void getScriptCommands(){
    
    printf("%s(A) Add Script ", MAG); 
    printf("%s(R) Run script ", YEL);
    printf("%s(X) Back to home", RED);
}

void getScriptsMenu(){
    system("clear");
    printf("\n");
    getScriptCommands();
}
