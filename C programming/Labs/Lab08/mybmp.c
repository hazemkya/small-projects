#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybmp.h"

Pixel** load_image(char* fname, FileHead* fh, ImageHead* ih){
  FILE* bmpf;
  int i, padding;
  Pixel** result = NULL;

  if ((bmpf = fopen(fname, "rb"))){
    fread(fh, sizeof(FileHead), 1, bmpf);
    fread(ih, sizeof(ImageHead), 1, bmpf);
    if (!(result = (Pixel**)malloc(ih->image_height*sizeof(Pixel*))))
      return NULL;
    *result = (Pixel*)malloc(ih->image_width*ih->image_height*sizeof(Pixel));

    for (i = ih->image_height - 1; i >= 0; i--){
      result[i] = (*result)+(i*ih->image_width);
      fread(result[i], sizeof(Pixel), ih->image_width, bmpf);
      fseek(bmpf, (4-((sizeof(Pixel)*ih->image_width)%4))%4, SEEK_CUR);      
    }      
    fclose(bmpf);
  }
  return result;
}


void make_grey(Pixel** pixels, int rows, int cols, Channel c){
  int i, j;
  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++)
      if (c == cRED) pixels[i][j].blue = pixels[i][j].green = pixels[i][j].red;
      else if (c == cGREEN) pixels[i][j].blue = pixels[i][j].red = pixels[i][j].green;
      else pixels[i][j].red = pixels[i][j].green = pixels[i][j].blue;
}

void redify(Pixel** pixels, int rows, int cols){
  int i, j;
  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++){
      pixels[i][j].blue /=2;
      pixels[i][j].green /=2;
      pixels[i][j].red += (255-pixels[i][j].red)/2;
    } 
}


void hmirror(Pixel** pixels, int rows, int cols){
  int i, j;
  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++){
      if (j>cols/2) break;
      Pixel temp = pixels[i][j];
      pixels[i][j] = pixels[i][cols-j];
      pixels[i][cols-j] = temp;
    } 
}


int save_image(char* fname, FileHead* fh, ImageHead* ih, Pixel** pixels){
  FILE* bmpf;
  int i, padding;

  if ((bmpf = fopen(fname, "wb"))){

    fwrite(fh, sizeof(FileHead), 1, bmpf);
    fwrite(ih, sizeof(ImageHead), 1, bmpf);

    for (i = ih->image_height - 1; i >= 0; i--){
      fwrite(pixels[i], sizeof(Pixel), ih->image_width, bmpf);
      fwrite(&padding, 1, (4-((sizeof(Pixel)*ih->image_width)%4))%4, bmpf);      
    }      
    
  } 
  return 1;
}