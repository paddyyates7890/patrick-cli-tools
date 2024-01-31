#include "../cli/interface.h"
#include "../files/fileLib.h"
#include <stdio.h>
#include "test.h"
#include "../database/sqliteConn.h"
#include "sqlite3.h"

void runTests(){
    testColours();

    printf("%s \n", WHT);
    dbTest();
}


int dbTest(){
    sqlite3* db = openDB();
    char* testSql = "SELECT * FROM TESTING";
    sqlite3_stmt* res =  select_data(db, testSql);
    char* test;

    while(res){
        test = fieldC(res, 1);
        printf("%s \n", test);
        res = step_result(res);
    }

    char* testSql2 = "INSERT INTO TESTING(value) VALUES('this is a test');";
    update_data(db, testSql2);
    
    char* testSql3 = "UPDATE TESTING SET value = 'this is another test' WHERE id=2;";
    update_data(db, testSql3);

    closeDB(db, res);
    return 0;
}

