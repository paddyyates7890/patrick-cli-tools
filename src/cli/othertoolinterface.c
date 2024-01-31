#include "othertoolinterface.h"
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

void getotherToolCommands(){
    printf("%s(digit) enter command digit for tool ", BLU);
    printf("%s(X) Back to home ", RED);
}

void getotherToolMenu(){
    system("clear");
    printf("\n");
    getotherToolCommands();
}

