#include "runCliCommands.h"
#include <stdio.h>

void runCliCommand(char *command){
    FILE *commandOut = popen(command, "r");
    char result[128];
    while (fgets(result, sizeof(result), commandOut)) {
        printf("%s", result);
    }
    pclose(commandOut);

    getchar();
    printf("\n Press Enter To Continue");
    while(getchar() != '\n');
}
