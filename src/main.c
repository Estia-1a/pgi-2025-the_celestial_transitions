#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estia-image.h"
#include "getopt.h"

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
 
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  if ( strncmp( configuration.command, "dimension", 9) == 0){
    dimension(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "first_pixel", 11) == 0){
    first_pixel(configuration.filenames[0]);
  }
  

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    tenth_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "second_line", 11) == 0){
    second_line(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "print_pixel", 11) == 0){
    int x = atoi( configuration.arguments[0]);
    int y = atoi( configuration.arguments[1]);
    print_pixel(configuration.filenames[0], x, y);
  }

  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    min_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "max_pixel", 9) == 0) {
    max_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "max_component", 13 ) == 0) {
    char t = configuration.arguments[0][0] ;
    if (t != 'R' && t != 'G' && t != 'B') {
      fprintf(stderr, "Erreur : la composante doit etre R, G ou B (pas '%c')\n", t);
      return 0;
  }
    max_component( configuration.filenames[0], t);
  }

  if ( strncmp( configuration.command, "min_component", 13 ) == 0) {
    char t = configuration.arguments[0][0] ;
    if (t != 'R' && t != 'G' && t != 'B') {
      fprintf(stderr, "Erreur : la composante doit etre R, G ou B (pas '%c')\n", t);
      return 0;
  }
    min_component( configuration.filenames[0], t);
  }

  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ){
    color_red(configuration.filenames[0]);
  }

    if ( strncmp( configuration.command, "color_green", 9 ) == 0 ){
    color_green(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_gray", 11 )== 0){
    color_gray(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_gray_luminance", 11 )== 0){
    color_gray_luminance(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_invert", 13 )== 0){
    color_invert(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "color_blue", 10 )== 0){
    color_blue(configuration.filenames[0]);
  }
 
  if ( strncmp( configuration.command, "color_desaturate", 17 )== 0){
    color_desaturate(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "rotate_cw", 10 )== 0){
    rotate_cw(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "rotate_acw", 10 )== 0){
    rotate_acw(configuration.filenames[0]);
  }
  
  return 0;
}

  