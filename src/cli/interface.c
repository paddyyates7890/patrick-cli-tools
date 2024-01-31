#include "interface.h"
#include <asm-generic/ioctls.h>
#include <stdio.h>
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
    printf("https://github.com/paddyyates7890/patrick-cli-tools/issues\nPlease add any possible improvements or bugs here :) \n\n");

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
