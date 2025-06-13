#include "estia-image.h"


#include <stdio.h>
#include "utils.h"

int MAX_pixel_value(unsigned char *data, int size) {
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
