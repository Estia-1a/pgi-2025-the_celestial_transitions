
#include <stdio.h>
#include <stdlib.h>
#include "estia-image.h"
#include "features.h"
#include "utils.h"

void max_pixel(const char *source_path) {
    int width, height, channels;
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channels);

    int max_value = 0;
    int max_x = 0;
    int max_y = 0;
    int max_r = 0;
    int max_g = 0;
    int max_b = 0;

    if (result) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (y * width + x) * channels;
                int r = data[index];
                int g = data[index + 1];
                int b = data[index + 2];
                int sum_rgb = r + g + b;

                if (sum_rgb > max_value) {
                    max_value = sum_rgb;
                    max_x = x;
                    max_y = y;
                    max_r = r;
                    max_g = g;
                    max_b = b;
                }
            }
        }
        printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
    } else {
        printf("Error reading image\n");
    }
}
