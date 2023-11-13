#include "../cli/interface.h"
#include "help.h"
#include "../files/fileLib.h"
#include <stdio.h>
#include <stdlib.h>

void getHelp(){
    char* help = rFileConcat(HELP_FILE);
    printf("%s%s", WHT, help);
    free(help);
}
