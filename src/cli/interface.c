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

void getPadding(int ammount){
    int window = getWindow();
    window = window - ammount;
    printf("%*s", window, ""); 
}

void drawLine(int length){
    for (int i = 0; i < length+1; i++) {
        printf("_");
    }

    printf("\n");
}

void getCommands(){
    getPadding(50);
    
    printf("%s(D) Development Tools ", CYN);
    printf("%s(H) Help ", GRN);
    printf("%s(X) Exit", RED); // DO NOT REMOVE !!!!
}

void getBody(){
    getCommands();
}

void getHeader(){

    int padding = 0;
    char *thisLine;
    
    padding = getWindow() - 25;
    printf("%*s",padding,"");
    for (int i = 0; i < 50; i++) {
        printf("%s_", BLU)  ;
    }

    printf("\n");

    for (int j = 0; j < 3; j++) {
        if (j == 1) {
            char *part1 =  "|                   ";
            char *part2 = "CLI TOOLS";
            char *part3 = "                    |";
            printf("%*s%s%s%s%s%s%s\n",padding,"",BLU,part1,GRN,part2,BLU,part3);
        }else {
            thisLine =  "|                                                |";
            printf("%*s%s%s\n",padding,"",thisLine,BLU);
        }
    }
    
    
    printf("%*s",padding,"");
    for (int k = 0; k < 50; k++) {
        printf("%s%s",BLU, OVRSCR)  ;
    }
    
    printf("%s\n", WHT);
    
    getPadding(50);
    drawLine(100);
}
