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

char * returnArray(char *arr, int size) {
    char *new_arr = malloc(sizeof(arr) * size);
    for(int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

char * gettimeBD() {
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[20];

    // Format: 2009-06-15 20:20:00
    std::strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", ptm);
    char *new_arr = returnArray(buffer, 20);
    return new_arr;
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