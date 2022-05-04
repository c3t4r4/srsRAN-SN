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
#include <iostream>
#include "srsran/phy/utils/vector.h"

std::string gettimeDB() {
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[20];

    // Format: 2009-06-15 20:20:00
    std::strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", ptm);
    std::string{buffer};
    return std::string{buffer};
}

void write_data(FILE * output, uint64_t payload) {
    std::string strdata = std::to_string(payload);
    fprintf(output, "%s;%s;#1", strdata.c_str(), gettimeDB().c_str());
}

void save_dataDB(char * file_imsi, uint64_t payload) {
    FILE * fp;
    fp = fopen(file_imsi, "a");

    if (fp) {
        write_data(fp, payload);
        fclose(fp);
    } else {
        perror("fopen");
    }
}