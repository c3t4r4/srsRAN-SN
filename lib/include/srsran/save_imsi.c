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
#include "srsran/phy/utils/vector.h"
//#include "sqlite/sqlite3.h"

//sqlite3* db;
//sqlite3_stmt * stmt;

char * gettime() {
    time_t mytime = time(NULL);
    char * time_str = ctime( & mytime);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

void write_IMSI(FILE * output, uint64_t payload) {
    fprintf(output, "%s; IMSI: %015" PRIu64 " \n", gettime(), payload);
}

// void save_IMSI_BD(){
//     sqlite3_open("imsi.db", &db);
// }



void save_imsi(char * file_imsi, uint64_t payload) {
    FILE * fp;
    fp = fopen(file_imsi, "a");

    if (fp) {
        write_IMSI(fp, payload);
        fclose(fp);
    } else {
        perror("fopen");
    }
}