#include "devtoolinterface.h"
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

void getDevToolCommands(){
    printf("%s(X) Back to home", RED);
}

void getDevToolMenu(){
    system("clear");
    printf("\n");
    getHeader();
    getDevToolCommands();
}

