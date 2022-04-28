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

void write_dataTIMSI(FILE * output, uint32_t timsi) {

    std::string strtimsi = std::to_string(timsi);

    fprintf(output, "%s;", strtimsi.c_str());
}

void save_dataTIMSI(char * file_imsi, uint32_t timsi) {
    FILE * fp;
    fp = fopen(file_imsi, "a");

    if (fp) {
        write_dataTIMSI(fp, timsi);
        fclose(fp);
    } else {
        perror("fopen");
    }
}