#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estia-image.h"
#include "getopt.h"

#include "features.h"
#include "utils.h"
#include "argsparse.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    second_line(argv[1]);
    return 0;
}
