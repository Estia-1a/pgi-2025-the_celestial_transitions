#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estia-image.h"
#include "getopt.h"

#include "features.h"
#include "utils.h"
#include "argsparse.h"

void main(void){
    if ( strncmp( configuration.command, "max_pixel", 9 ) == 0 ) {
    max_pixel( configuration.filenames[0] );
    }
}