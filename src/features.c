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

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    int width, height, nbr_channel;
    unsigned char *data;
    int verif = read_image_data(source_path, &data, &width, & height, &nbr_channel);
    
    if (verif){
        printf("dimension: %d, %d \n",width, height);
    } else {
        printf("Erreur dans la verification");
    }
}

void first_pixel(char* sourcepath) {
    unsigned char *data = NULL;
   
    int width = 0;
    int height = 0;
    int channels = 0;

    if (read_image_data(sourcepath, &data, &width, &height, &channels)) {
        unsigned char *data;
        if(read_image_data(sourcepath, &data, &width, &height, &channels)){
            printf("first_pixel: %d, %d, %d", data[0], data[1], data[2]);
    
        } else {
            printf("Erreur");
        }
        free(data);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", sourcepath);
    }
}

void min_pixel(char *source_path){
    int width, height, channel_count, min = 255*3, xmin = 0, ymin = 0, rmin = 0, gmin = 0, bmin = 0, x , y;
    unsigned char *data;
    if(read_image_data(source_path, &data, &width, &height, &channel_count)){
        for (y=0; y < height; y++){
            for (x = 0; x< width; x++){
                pixelRGB* pointeur = getPixel(data, width, height, channel_count, x, y);
                if (pointeur != NULL) {
                    int RGB = pointeur->R + pointeur->G + pointeur->B;
                    if (RGB < min) {
                        min = RGB;
                        xmin = x;
                        ymin = y;
                        rmin = pointeur->R; 
                        gmin = pointeur->G;
                        bmin = pointeur->B;
                    }

                }
            }
        }
        printf("min_pixel (%d, %d): %d, %d, %d", xmin, ymin, rmin, gmin, bmin);
    } else {
        printf("Error");
    }    
}