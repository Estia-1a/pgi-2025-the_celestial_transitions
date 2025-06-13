
#include <stdio.h>
#include <stdlib.h>
#include "estia-image.h"
#include "features.h"
#include "utils.h"

void second_line(const char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) != 0) {
        print_error("Impossible de lire l'image.");
        return;
    }

    if (height < 2) {
        print_error("L'image doit avoir au moins 2 lignes.");
        free(data);
        return;
    }

    if (channels < 3) {
        print_error("L'image doit avoir au moins 3 canaux (R,G,B).");
        free(data);
        return;
    }

    int index = width * channels;
    int R = data[index];
    int G = data[index + 1];
    int B = data[index + 2];

    printf("second_line: %d, %d, %d\n", R, G, B);

    free(data);
}
