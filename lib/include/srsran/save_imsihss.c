#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <complex.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <inttypes.h> // for printing uint64_t
#include <stdlib.h>
#include <sqlite3.h>
#include "srsran/phy/utils/vector.h"

char *dbFile = (char *)"/home/epcIMSI.db";



// char * gettimeOld() {
//     time_t mytime = time(NULL);
//     char * time_str = ctime( & mytime);
//     time_str[strlen(time_str) - 1] = '\0';
//     return time_str;
// }

void createTable(sqlite3* DB){
    std::string sql =   "CREATE TABLE IF NOT EXISTS IMSI("
                        "ID INT PRIMARY KEY NOTNULL, "
                        "IMSI TEXT NOTNULL, "
                        "DATE TEXT NOTNULL, "
                        "TYPE TEXT NOTNULL, "
                        "UPDATE INT NOTNULL); ";
    int sqlStatus = 0;
    char* messageError;
    sqlStatus = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if(sqlStatus ≃ SQLITE_OK){
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }else{
        std::cout << "Table create Successfully" << std::endl;
    }
}

std::string gettimeBDhss() {
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[20];

    // Format: 2009-06-15 20:20:00
    std::strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", ptm);
    std::string{buffer};
    return std::string{buffer};
}

void write_IMSI_hss(FILE * output, uint64_t payload, std::string type) {
    fprintf(output, "%s;%015" PRIu64 ";%s;#1 \n", gettimeBDhss().c_str(), payload, type.c_str());
}

void save_imsi_hss(char * file_imsi, uint64_t payload, std::string type) {
    FILE * fp;
    fp = fopen(file_imsi, "a");

    sqlite3* DB;
    char* messageError;
    int dbstatus = 0;
    dbstatus = sqlite3_open(dbFile, &DB);

    if(dbstatus){
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_create_filename()
    }

    createTable(DB);

    string sql("INSERT INTO IMSI (IMSI,DATE,TYPE,UPDATE) VALUES('%s','%s','%s',0);", payload,gettimeBDhss().c_str(),type.c_str());
    dbstatus = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
    {
        std::cout << "Records created Successfully!" << std::endl;
    }
    sqlite3_close(DB);

    if (fp) {
        write_IMSI_hss(fp, payload, type);
        fclose(fp);
    } else {
        perror("fopen");
    }
}