#ifndef _APP_RUNNING
#define _APP_RUNNING

void goToCommand(char command);
void homeInput();
void getBody();
void testColours();
void getCommands();

#define sizearr(A) sizeof(A)/sizeof(A[0]); 

// Output colours.
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\033[0;37m"

//overscore unicode
#define OVRSCR "‾"

#endif
