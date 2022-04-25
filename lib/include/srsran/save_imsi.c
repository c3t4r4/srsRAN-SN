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

std::string gettimeBD() {
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[20];

    // Format: 2009-06-15 20:20:00
    std::strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", ptm);
    std::string{buffer};
    return std::string{buffer};
}

void write_IMSI(FILE * output, uint64_t payload) {
    std::string datatime = gettimeBD();
    fprintf(output, "%x; IMSI: %015" PRIu64 ";#1 \n", datatime, payload);
}

void save_imsi(char * file_imsi, uint64_t payload) {
    FILE * fp;
    // if((file = fopen(file_imsi,"r"))!=NULL)
    // {
    //     fclose(file);
    //     rename(file_imsi, "readme.txt");
    // }
    fp = fopen(file_imsi, "a");

    if (fp) {
        write_IMSI(fp, payload);
        fclose(fp);
    } else {
        perror("fopen");
    }
}