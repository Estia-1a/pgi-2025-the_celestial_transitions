#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */
void dimension (char* sourcepath){
    unsigned char *data = NULL;
    int width, height, channel_count;
    
    read_image_data(sourcepath, &data, &width, &height, &channel_count);

    printf("Dimension : %d %d\n", width, height);
}

void helloWorld() {
    printf("Hello World !");
}
void print_pixel(char* sourcepath){
    unsigned char *data = NULL;
   
    int width = 0;
    int height = 0;
    int channels = 0;

    if (read_image_data(sourcepath, &data, &width, &height, &channels)) {
        printf("Image : %d x %d, channels: %d\n", width, height, channels);

        pixelRGB* px = getPixel(data, width, height, channels, 0, 0);
        if (px != NULL) {
            printf("First Pixel : R=%d G=%d B=%d\n", px->R, px->G, px->B);
            free(px);
        } else {
            printf("Erreur lors de l'accès au pixel (0,0).\n");
        }

        free(data);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", sourcepath);
    }
}

void second_line(char *source_path) {
    unsigned char *image_data;
    int width, height, channels;

    if (read_image_data(source_path, &image_data, &width, &height, &channels) != 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    if (width <= 1 || height < 2) {
        fprintf(stderr, "Image trop petite pour accéder au pixel (1, 0).\n");
        return;
    }

    int x = 1;
    int y = 0;  // ligne du haut
    int index = (y * width + x) * channels;

    // On suppose que l'image est RGB ou RGBA — on prend les 3 premiers canaux
    unsigned char r = image_data[index + 0];
    unsigned char g = image_data[index + 1];
    unsigned char b = image_data[index + 2];

    printf("second_line: %d, %d, %d\n", r, g, b);

}

void first_pixel(char*source_path) {
    unsigned char *image_data;
    int width, height, channel;

    typedef struct _pixelRGB {
    unsigned char R ;
    unsigned char G ;
    unsigned char B ;
}   pixelRGB ;

    int read_image_data(const char *filename, unsigned char **data, int *width, int *height, int *channel_count);
}