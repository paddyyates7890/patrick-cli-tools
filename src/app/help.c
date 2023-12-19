#include "help.h"
#include "../files/fileLib.h"
#include <stdio.h>

void getHelp(){
    linkedList *help = rFileList(HELP_FILE);
    char* helpLine = LLindex(help, 0);
    
    int listLen = LLcount(help);
    int i;
    for (i = 1; i <= listLen; i++){
        printf("%s", helpLine);
        helpLine = LLindex(help, i);
    }
    LLdestroy(help);
}
