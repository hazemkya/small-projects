#include <stdlib.h>
#include <string.h>
#include "mybmp.h"

int main(){
  FileHead fh;
  ImageHead ih;
  Pixel **pixels, *tmp_pixels;


  pixels = load_image("image.bmp", &fh, &ih);
  tmp_pixels = (Pixel*)malloc(ih.image_height*
                              ih.image_width*
                              sizeof(Pixel));


  memcpy(tmp_pixels, *pixels, 
         ih.image_height * ih.image_width * sizeof(Pixel));


  make_grey(pixels, ih.image_height, ih.image_width, cGREEN);


  save_image("image-grey.bmp", &fh, &ih, pixels);


  memcpy(*pixels, tmp_pixels,
         ih.image_height * ih.image_width * sizeof(Pixel));


  redify(pixels, ih.image_height, ih.image_width);


  save_image("image-red.bmp", &fh, &ih, pixels);

  memcpy(*pixels, tmp_pixels,
         ih.image_height * ih.image_width * sizeof(Pixel));

  hmirror(pixels, ih.image_height, ih.image_width);


  save_image("image-hflip.bmp", &fh, &ih, pixels);


  return 0;
}