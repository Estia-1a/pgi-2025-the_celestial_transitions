

#ifndef FEATURES_H
#define FEATURES_H

void dimension(char* sourcepath);

void helloWorld();

void second_line(char* sourcepath);

void first_pixel(char* sourcepath);

void max_component(char* sourcepath, char t);

void tenth_pixel(char *source_path);

void second_line(char* sourcepath);

void print_pixel(char* sourcepath, int x, int y);

void min_pixel (char *source_path);

void max_pixel (char *source_path);

void min_component (char *source_path, char t);

void max_component (char *source_path, char t);

void color_red (char *source_path);

void color_green (char *source_path);

void color_blue (char *source_path);

void color_gray (char *source_path);

void color_gray_luminance (char *source_path);

void color_invert(char *source_path);

void color_desaturate (char *source_path);

void rotate_cw ( char *sourcepath);

void rotate_acw ( char *sourcepath);

void mirror_horizontal( char *source_path);

void mirror_vertical( char *source_path);

void mirror_total( char *source_path);

void scale_crop( char *sourcepath, int cx, int cy, int width, int height);

void scale_nearest( char *sourcepath, float scale);

void scale_bilinear( char *sourcepath, float scale);

#endif
