#include <stdio.h>
#include "features.h"

int main() {
    if (rotate_image_90("image.bmp", "image_out.bmp") == 0) {
        printf("Image tournée avec succès.\n");
    } else {
        printf("Erreur lors de la rotation de l'image.\n");
    }
    return 0;
}
