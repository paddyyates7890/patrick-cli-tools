#include "../linked-list/linkedList.h"

#ifndef _DEVTOOL_ACTIVE
#define _DEVTOOL_ACTIVE

void getDevTools();
void goToDevCommand(char command);
void devtoolInput();
linkedList* getToolList();
void runDevTool(char* devtoolstr);
#endif // !_DEVTOOL_ACTIVE
