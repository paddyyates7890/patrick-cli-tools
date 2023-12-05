#include "../cli/interface.h"
#include "help.h"
#include "../files/fileLib.h"
#include <stdio.h>

void getHelp(){
    linkedList *help = rFileList(HELP_FILE);
    char* helpLine = LLindex(help, 0);
    
    int listLen = LLcount(help);
    int count = 1;
    while (count < listLen) {
        getPadding(55);
        printf("%s", helpLine);
        helpLine = LLindex(help, count);
        count ++;
    }

    LLdestroy(help);
}
