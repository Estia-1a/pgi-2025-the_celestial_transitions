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
