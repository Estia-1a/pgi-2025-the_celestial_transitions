#include <estia-image.h>
#include <stdlib.h>

#include <stdio.h>
#include "utils.h"


pixelRGB* getPixel(unsigned char* data, int width, int height, int channels, int x, int y) {
    if (!data || x >= width || y >= height || x < 0 || y < 0) return NULL;

    int index = (y * width + x) * channels;
    pixelRGB* px = malloc(sizeof(pixelRGB));

    px->R = data[index];
    px->G = channels >= 2 ? data[index + 1] : 0;
    px->B = channels >= 3 ? data[index + 2] : 0;

    return px;
}

int min (int a, int b, int c) {
    int min = a;
    if (b<min){
        min = b;
    }
    if (c<min){
        min = c;
    }
    return min;
}

int max (int a, int b, int c) {
    int max = a;
    if (b<max){
        max = b;
    }
    if (c<max){
        max = c;
    }
    return max;
}
