#include "../cli/interface.h"
#include "help.h"
#include <stdio.h>

void getHomeCommandHelp(){
    printf("\n");
    getPadding(50);
    printf("O   other tools: other tools that will be useful\n");
    getPadding(50);
    printf("S   A list of scripts that can be run from inside the tools\n");
    getPadding(50);
    printf("D   development tools is a set of tools specifically to help development\n");
    getPadding(50);
    printf("H   this menue, the help menu (Kind of the manual)\n");
    getPadding(50);
    printf("X   exit it will exit eny set of tools that you are currently in or exit the app if you are in the home menu\n");
    getPadding(50);
    printf("T   testing runs the tests that are writen for this application\n");
}

void getHelp(){ // Home help
    getPadding(50);
    printf("%sWELCOME TO THE HOME HELP\n", WHT);
    getPadding(50);
    printf("Commands:");
    getHomeCommandHelp();
}
