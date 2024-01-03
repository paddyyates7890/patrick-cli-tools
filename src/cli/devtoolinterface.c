#include "devtoolinterface.h"
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

void getDevToolCommands(){
    printf("%s(digit) enter command digit for tool ", BLU);
    printf("%s(X) Back to home ", RED);
}

void getDevToolMenu(){
    system("clear");
    printf("\n");
    getDevToolCommands();
}

