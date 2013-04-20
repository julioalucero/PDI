#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include "../src//PDI_functions.h"

using namespace cimg_library;
using namespace std;

CImg<double> grays_image(int N, int M) {
  CImg<double> grays(N, M);

  // Gray Image
  for (int i=0; i < 256; i++){
    for (int j=0; j < 256; j++){
      grays(i, j) = i;
    }
  }

  return grays;
}

// Mapea una imagen con una paleta (paso imagen y la direccion de la paleta)
CImg<double> get_image_from_pallete(CImg<double> img, const char * filename = "../public/paletas/gray.pal" ) {

  CImg<double> paleta(cargar_paleta(filename)),
    result(img.width(), img.height(), img.depth(), 3);

  img.normalize(0, 255);

  // result with 3 channels (RGB)
  cimg_forXYC(result, x, y, c) {
    result(x, y, c) = paleta(0, img(x,y), c);
  }

  return result;
}

int main(int argc, char *argv[]) {

  // Exercise 4.2.a
  CImg<double> grays = grays_image(256, 256);

  (grays,
    get_image_from_pallete(grays, "../public/paletas/bone.pal"),
    get_image_from_pallete(grays, "../public/paletas/cool.pal"),
    get_image_from_pallete(grays, "../public/paletas/copper.pal"),
    get_image_from_pallete(grays, "../public/paletas/gray.pal"),
    get_image_from_pallete(grays, "../public/paletas/hot.pal"),
    get_image_from_pallete(grays, "../public/paletas/hsv.pal"),
    get_image_from_pallete(grays, "../public/paletas/jet.pal"),
    get_image_from_pallete(grays, "../public/paletas/pink.pal"))
    .display("Base, paletas (bone, cool, copper, gray, hot, hsv, jet, pink)", 0);

  return 0;
}
