#include "interface.h"
#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

// testing
void testColours(){
    printf("%s RED\n", RED);
    
    printf("%s GRN\n", GRN);
    
    printf("%s YEL\n", YEL);
    
    printf("%s BLU\n", BLU);
    
    printf("%s MAG\n", MAG);
    
    printf("%s CYN\n", CYN);
    
    printf("%s WHT\n", WHT);
}

// interface functions
int getWindow(){
    struct winsize w;
    ioctl(0,TIOCGWINSZ,&w);

    return w.ws_col / 2;
}

void drawLine(){
    int length = getWindow();

    for (int i = 0; i < length+1; i++) {
        printf("_");
    }

    printf("\n");
}

void getCommands(){
    
    
    printf("%s(O) other tools ", MAG);
    printf("%s(S) Scripts ", YEL);
    printf("%s(D) Development Tools ", CYN);
    printf("%s(H) Help ", GRN);
    printf("%s(X) Exit ", RED); // DO NOT REMOVE !!!!
    printf("%s(T) Test ", WHT);
}

void getBody(){
    getCommands();
}

void getHeader(){
    char *thisLine;
    for (int i = 0; i < 50; i++) {
        printf("%s_", BLU)  ;
    }

    printf("\n");

    for (int j = 0; j < 3; j++) {
        if (j == 1) {
            char *part1 =  "|                   ";
            char *part2 = "CLI TOOLS";
            char *part3 = "                    |";
        }else {
            thisLine =  "|                                                |";
            printf("%s%s\n",thisLine,BLU);
        }
    }
    
    for (int k = 0; k < 50; k++) {
        printf("%s%s",BLU, OVRSCR)  ;
    }
    
    printf("%s\n", WHT);
}
