#include "passwords.h"
#include "../cli/interface.h"
#include "../cli/othertoolcli/passwordinterface.h"
#include "../app/othertool.h"
#include "../database/sqliteConn.h"
#include <stdio.h>
#include <ctype.h>

void getPasswords(){
    getPasswordMenu();
    getPasswordsInput();
}

void getPasswordsInput(){
    char command;
    printf("\n\n");

    printf("%s(PASSWORDS)%s Enter Command: ", MAG, WHT);
    scanf(" %c", &command);

    goToPasswordsCommand(command);
}

void goToPasswordsCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        getOtherTools();
    }else if (command == 'A'){
        printf("not implemented");
        getPasswords();
    }else if (command == 'S'){
        printf("not implemented");
        getPasswords();
    }else {
        printf("That was not a command");
        getPasswordsInput();
    }
}

void getNewPasswordInput(){
    
}

void addPassword(char* password, char* application){
   char* sql = "insert into pass_manage(password, application) values(%s, %s)";
   int res = param(1, sql, password, application);

   printf("Password Has been added");
}

void showPasswords(){
    
}
