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

char * gettime() {
    time_t mytime = time(NULL);
    char * time_str = ctime( & mytime);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

char * gettimeBD() {
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", ptm);  
    return buffer;
}

void write_IMSI(FILE * output, uint64_t payload) {
    fprintf(output, "%s; IMSI: %015" PRIu64 ";#1 \n", gettimeBD(), payload);
}

void save_imsi(char * file_imsi, uint64_t payload) {
    FILE * fp;
    // if((file = fopen(file_imsi,"r"))!=NULL)
    // {
    //     fclose(file);


    // }
    fp = fopen(file_imsi, "a");

    if (fp) {
        write_IMSI(fp, payload);
        fclose(fp);
    } else {
        perror("fopen");
    }
}