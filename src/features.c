
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

    printf("Dimension : %d, %d\n", width, height);
    printf("Dimension : %d, %d\n", width, height);
}

void helloWorld() {
    printf("Hello World !");
}

void first_pixel(char* sourcepath){
    unsigned char *data = NULL;

    int width = 0, height = 0,channels = 0;

    if (read_image_data(sourcepath, &data, &width, &height, &channels)) {
        unsigned char *data;
        if(read_image_data(sourcepath, &data, &width, &height, &channels)){
            printf("first_pixel: %d, %d, %d", data[0 * channels], data[0 * channels + 1], data[0 * channels + 2]);
    
        } else {
            printf("Erreur");
        }
        free(data);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", sourcepath);
    }
}

void tenth_pixel(char* sourcepath) {
    unsigned char *data = NULL;
   
    int width = 0;
    int height = 0;
    int channels = 0;

    if (read_image_data(sourcepath, &data, &width, &height, &channels)) {
        unsigned char *data;
        if(read_image_data(sourcepath, &data, &width, &height, &channels)){
            printf("tenth_pixel: %d, %d, %d", data[9 * channels], data[9 * channels + 1], data[9 * channels + 2]);
    
        } else {
            printf("Erreur");
        }
        free(data);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", sourcepath);
    }
}

void second_line(char* sourcepath) {
    unsigned char *data = NULL;

    int width = 0;
    int height = 0;
    int channels = 0;

    if (read_image_data(sourcepath, &data, &width, &height, &channels)) {
        if (height >= 2 && channels >= 3) {
            int index = (1 * width + 0) * channels; 
            printf("second_line : %d, %d, %d\n", data[index], data[index + 1], data[index + 2]);
        } else {
            printf("Image trop petite ou nombre de canaux insuffisant.\n");
        }

        free(data);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", sourcepath);
    }
}

void print_pixel(char* sourcepath,int x,int y){
    int width, height, channels, n;
    unsigned char *data;
    
    if (read_image_data(sourcepath, &data, &width, &height, &channels)){
        n = (width * channels*(y))+((x)*channels);
        printf ("print_pixel (%d,%d): %d, %d, %d", x, y, data[n], data[n+1], data[n+2]);

    } else {
        printf("Erreur d'éxécution");
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

void min_component(char *sourcepath, char t){
    int width, height, channel_count;
    int min = 255;
    int xmin = 0, ymin = 0;
    unsigned char *data;
    

    int result = read_image_data(sourcepath, &data, &width, &height, &channel_count);

    if (result) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                pixelRGB* pointeur = getPixel(data, width, height, channel_count, x, y);
                if (pointeur != NULL) {
                    int value = 256;
                    if (t == 'R') value = pointeur->R;
                    else if (t == 'G') value = pointeur->G;
                    else if (t == 'B') value = pointeur->B;

                    if (value < min) {
                        min = value;
                        xmin = x;
                        ymin = y;
                    }

                    free(pointeur);
                }
            }
        }
        printf("min_component %c (%d, %d): %d\n", t, xmin, ymin, min);
    } else {
        printf("Erreur dans la lecture, vérifier le fichier\n");
    }
}

void color_red(char *sourcepath){
    int width, height, channels, x, y;
    unsigned char *data;
    if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
        for (y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                int index = (y * width + x) * channels;
                data[index + 1] = 0; //COuleur Vert
                data[index + 2] = 0; //Couleur Bleu
            }
        }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
    } else {
        printf("Erreur!");
    }
}
void color_green(char *sourcepath){
    int width, height, channels, x, y;
    unsigned char *data;
    if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
        for (y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                int index = (y * width + x) * channels;
                data[index] = 0; //COuleur Rouge
                data[index + 2] = 0; //Couleur Bleu
            }
        }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
    } else {
        printf("Erreur!");
    }
}


void color_gray(char *sourcepath){
int width, height, channels, x, y;
unsigned char *data;
if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
    for (y = 0; y < height; y++){
        for(x = 0; x < width; x++){
            int index = (y * width + x) * channels;
            
            unsigned char r = data[index];
            unsigned char g = data[index + 1];
            unsigned char b = data[index + 2];
            unsigned char gris = (r + g + b) / 3;
            data[index] = gris;
            data[index + 1] = gris;
            data[index + 2] = gris;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
} else {
    printf("Erreur!");
}
}

void color_gray_luminance(char *sourcepath){
int width, height, channels, x, y;
unsigned char *data;
if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
    for (y = 0; y < height; y++){
        for(x = 0; x < width; x++){
            int index = (y * width + x) * channels;
            
            unsigned char r = data[index];
            unsigned char g = data[index + 1];
            unsigned char b = data[index + 2];
            unsigned char gris = (0.21 * r + 0.72 * g + 0.07 * b);
            data[index] = gris;
            data[index + 1] = gris;
            data[index + 2] = gris;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
} else {
    printf("Erreur!");
}
}

void color_invert(char *sourcepath){
    int width, height, channels, x, y;
    unsigned char *data;
    if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
        for (y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                int index = (y * width + x) * channels;
                
                unsigned char old_r = data[index];
                unsigned char old_g = data[index + 1];
                unsigned char old_b = data[index + 2];
                unsigned char new_r = 255 - old_r;
                unsigned char new_g = 255 - old_g;
                unsigned char new_b = 255 - old_b;
                data[index] = new_r;
                data[index + 1] = new_g;
                data[index + 2] = new_b;
            }
        }
        write_image_data("image_out.bmp", data, width, height);
        free(data);
    } else {
        printf("Erreur!");
    }
}

void max_pixel(char *source_path) {
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

void max_component(char *sourcepath, char t){
    int width, height, channels_count;
    int max = 0;
    int xmax = 0, ymax = 0;
    unsigned char *data;
   
 
    int result = read_image_data(sourcepath, &data, &width, &height, &channels_count);
 
    if (result) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                pixelRGB* pointeur = getPixel(data, width, height, channels_count, x, y);
                if (pointeur != NULL) {
                    int value = 256;
                    if (t == 'R') value = pointeur->R;
                    else if (t == 'G') value = pointeur->G;
                    else if (t == 'B') value = pointeur->B;
 
                    if (value > max) {
                        max = value;
                        xmax = x;
                        ymax = y;
                    }
 
                    free(pointeur);
                }
            }
        }
        printf("max_component %c (%d, %d): %d\n", t, xmax, ymax, max);
    } 
        else{
        printf("Erreur dans la lecture, vérifier le fichier\n");
    }
}
void color_blue(char *sourcepath){
    int width, height, channels, x, y;
    unsigned char *data;
    if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
        for (y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                int index = (y * width + x) * channels;
                data[index + 1] = 0; //COuleur Vert
                data[index] = 0; //Couleur Bleu
            }
        }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
    } else {
        printf("Erreur!");
    }
}

void color_desaturate(char *sourcepath){
    int width, height, channels, x, y;
    unsigned char *data;
    if ( read_image_data(sourcepath, &data, &width, &height, &channels)){
        for (y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                int index = (y * width + x) * channels;
                
                unsigned char r = data[index];
                unsigned char g = data[index + 1];
                unsigned char b = data[index + 2];
                unsigned char new_val = (min(r,g,b) + max(r,g,b)) / 2;
                data[index] = new_val;
                data[index + 1] = new_val;
                data[index + 2] = new_val;
            }
        }
        write_image_data("image_out.bmp", data, width, height);
        free(data);
    } else {
        printf("Erreur!");
    }
    }

void rotate_cw(char *sourcepath){
    int width, height, channels;
    unsigned char *data; 

    if ( !read_image_data(sourcepath, &data, &width, &height, &channels)){
        printf("Erreur de lecture Image");
        return;
    } 

    unsigned char *rotate = malloc(width * height * channels);
    if(!rotate) {
        printf("Erreur Memoire");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src = (y * width + x) * channels;
                
            int rot_x = height - 1 - y;
            int rot_y = x;
            int idx = (rot_y * height + rot_x) * channels;  
    
            for (int c = 0; c < channels; c++) {
                rotate[idx + c] = data[src + c];
            }
        }
    }
    write_image_data("image_out.bmp",rotate, height, width);

    free(data);
    free(rotate);
}

void rotate_acw(char *sourcepath){
        int width, height, channels;
        unsigned char *data;
 
        if ( !read_image_data(sourcepath, &data, &width, &height, &channels)){
            printf("Erreur de lecture Image");
            return;
        }
 
        unsigned char *rotate = malloc(width * height * channels);
        if(!rotate) {
            printf("Erreur Memoire");
            free(data);
            return;
        }
 
        for (int y = 0; y< height; y++){
            for (int x = 0; x< width; x++) {
                int src = (y * width + x) * channels;
                int rot_x = y;
                int rot_y = width - 1 - x;
                int idx = (rot_y * height + rot_x) * channels;
 
                for (int c = 0; c < channels; c++) {
                    rotate[idx + c] = data[src + c];
                }
            }
        }
        write_image_data("image_out.bmp",rotate, height, width);
 
        free(data);
        free(rotate);
    }

    void mirror_horizontal (char* source_path){
        int width, height, channels;
        unsigned char *data;
 
        if ( !read_image_data(source_path, &data, &width, &height, &channels)){
            printf("Erreur de lecture Image");
            return;
        }

            for (int y = 0; y < height; y++){
            for (int x = 0; x < width / 2; x++){
                int idx1 = (y * width + x)*channels;
                int idx2 = (y * width + (width - 1 - x))*channels;

                for (int c = 0; c < channels; c++){
                    unsigned char tmp = data[idx1 + c];
                    data[idx1 + c] = data[idx2 +c];
                    data[idx2 + c] = tmp;
                }
            }
        }
        write_image_data("image_out.bmp",data, height, width);

        free(data);
    }