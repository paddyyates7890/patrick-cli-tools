#include "nginxinterface.h"
#include "../interface.h"
#include <stdio.h>
#include <stdlib.h>


void getNginxCommands(){
    printf("%s(S) Status ", BLU);
    printf("%s(E) Error log ", GRN);
    printf("%s(X) Exit to dev tools %s", RED, WHT); 
}

void getNginxMenu(){
    system("clear");
    printf("\n");
    printf("%sNGINX\n\n%s", GRN, WHT);
    getNginxCommands();
}
