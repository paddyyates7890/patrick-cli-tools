#ifndef _PASSWORDS
#define _PASSWORDS

void getPasswords();
void getPasswordsInput();
void goToPasswordsCommand(char command);

void getNewPasswordInput();
char* getWordyPassword();
char* getEnteredPassword();
void addPassword(char* password, char* application);

void showPasswords();

#endif
