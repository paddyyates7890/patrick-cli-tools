#include "phpinterface.h"
#include "../interface.h"
#include <stdio.h>
#include <stdlib.h>

void getPhpCommands(){
    printf("%s(V) version ", BLU);
    printf("%s(X) Exit to dev tools " , RED);
}

void getPhpMenu(){
    system("clear");
    printf("\n");
    printf("%sPHP\n\n%s", GRN, WHT);
    getPhpCommands();
}
