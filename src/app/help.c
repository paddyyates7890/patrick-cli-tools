#include "../cli/interface.h"
#include "help.h"
#include <stdio.h>
void drawHelp(){ // Home help
    getPadding(50);
    printf("%sWELCOME TO THE HOME HELP\n", WHT);
    getPadding(50);
    printf("Commands:");
}
