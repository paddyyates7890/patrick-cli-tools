#include "help.h"
#include "../files/fileLib.h"
#include <stdlib.h>

void getHelp(){
    char* file = getFile(HELP_FILE); 
    printListFile(file, 0); 
    free(file);
}
