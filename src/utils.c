#include <estia-image.h>

#include "utils.h"


pixelRGB* getPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (x >= width || y >= height) {
        return 0;
    }

    int index = (y * width + x) * n;

    pixelRGB* pixel = malloc(sizeof(pixelRGB));
    pixel->R = data[index];
    pixel->G = data[index + 1];
    pixel->B = data[index + 2];

    return pixel;
}


/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

