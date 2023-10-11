#ifndef _INTERFACE_ACTIVE
#define _INTERFACE_ACTIVE

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

// TESTING
void testColours();

// INTERFACE FUNCTIONS
int getWindow();
void getPadding(int ammount);

void drawLine(int length);
void getBody();
void getHeader();

#endif 
