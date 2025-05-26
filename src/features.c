#include <stdio.h>
#include <stdlib.h>
#include "features.h"

unsigned char header[54];

int rotate_image_90(const char *input_filename, const char *output_filename) {
    FILE *f_in = fopen(input_filename, "rb");
    FILE *f_out = fopen(output_filename, "wb");

    if (!f_in || !f_out) {
        printf("Erreur d'ouverture des fichiers.\n");
        return 1;
    }

    fread(header, sizeof(unsigned char), 54, f_in);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int row_padded = (width * 3 + 3) & (~3);
    unsigned char* data = malloc(row_padded * height);
    fread(data, sizeof(unsigned char), row_padded * height, f_in);
    fclose(f_in);

    int new_row_padded = (height * 3 + 3) & (~3);
    unsigned char* rotated = calloc(new_row_padded * width, sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = y * row_padded + x * 3;
            int dst_x = height - y - 1;
            int dst_y = x;
            int dst_index = dst_y * new_row_padded + dst_x * 3;

            rotated[dst_index]     = data[src_index];
            rotated[dst_index + 1] = data[src_index + 1];
            rotated[dst_index + 2] = data[src_index + 2];
        }
    }

    *(int*)&header[18] = height;
    *(int*)&header[22] = width;
    *(int*)&header[34] = new_row_padded * width;

    fwrite(header, sizeof(unsigned char), 54, f_out);
    fwrite(rotated, sizeof(unsigned char), new_row_padded * width, f_out);

    fclose(f_out);
    free(data);
    free(rotated);

    return 0;
}
