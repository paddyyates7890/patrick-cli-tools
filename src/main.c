#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "cli/interface.h"

int main(int argc, char *argv[])
{
    int running = 1;
    int first = 1;

    system("clear"); 
    getHeader();
    getBody();
    homeInput();    
    return 0;
}
