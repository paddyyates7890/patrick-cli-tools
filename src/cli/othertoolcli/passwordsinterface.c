#include "passwordinterface.h"
#include "../interface.h"
#include <stdio.h>
#include <stdlib.h>

void getPasswordCommands(){
    printf("%s(A) Add password ", GRN);
    printf("%s(S) Show passwords ", BLU);
    printf("%s(X) Exit to other tools: ", RED);
}

void getPasswordMenu(){
    system("clear");
    printf("\n");
    printf("%sPASSWORDS\n\n%s", MAG, WHT);
    getPasswordCommands();
}
