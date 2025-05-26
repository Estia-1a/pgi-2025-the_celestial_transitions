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