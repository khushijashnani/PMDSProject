#include <stdio.h>
#include <string.h>
#include <C:\Users\Naik\Desktop\c_assignment\EmployeeDB\sqlite3.h>
#include "employee.h"

static int callback2(void* data, int argc, char** argv, char** azColName)
{
    id = atoi(argv[0]);
    return 0;
}

int main(int argc, char** argv)
{
	sqlite3* DB;
	int input;
	char* messaggeError;
	int exit = sqlite3_open("employee2.db", &DB);
	/*char * sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY      NOT NULL, "
                      "NAME           TEXT     NOT NULL, "
                      "SURNAME        TEXT     NOT NULL, "
                      "AGE            INT      NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL     NOT NULL,"
                      "PF             REAL     NOT NULL,"
                      "MEDICAL ALL    REAL     NOT NULL,"
                      "TRAVEL ALL     REAL     NOT NULL,"
                      "TAX            REAL     NOT NULL,"
                      "GROSS          REAL     NOT NULL,"
                      "NET            REAL     NOT NULL);";

    exit = sqlite3_exec(DB, sql, NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Error Creating TABLE!");
        sqlite3_free(messaggeError);
    }
    else fprintf(stdout, "Table Created Successfully!");*/
	sqlite3_exec(DB, "SELECT MAX(ID) FROM PERSON;", callback2, NULL, NULL); //To get Latest ID
	while(1)
    {
        printf("Press 1 to display records\nPress 2 to add employee\nPress 3 to delete record\nPress 0 to exit\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1: displayRecord(DB, messaggeError);
                break;

            case 2: createRecord(DB, messaggeError);
                break;

            case 3: deleteRecord(DB, messaggeError);
                break;

            default : break;
        }
        if(input==0)
            break;
    }
	return (0);
}
	/*char * sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";

    exit = sqlite3_exec(DB, sql, NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Error Creating TABLE!");
        sqlite3_free(messaggeError);
    }
    else fprintf(stdout, "Table Created Successfully!");*/
