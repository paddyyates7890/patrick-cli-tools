#include "help.h"
#include "../files/fileLib.h"
#include <string.h>
#include <stdlib.h>

void getHelp(){
    char* file = malloc(strlen(getenv("HOME")) + strlen(HELP_FILE) + 1);
    strcpy(file, getenv("HOME"));
    strcat(file, HELP_FILE);
    
    printListFile(file, 0); 
    free(file);
}
