#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include "../src/PDI_functions.h"

using namespace cimg_library;
using namespace std;

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

  // Exercise 4.3
  CImg<double> rio("../public/images/rio.jpg");
  CImg<double> rio_color(rio.width(), rio.height(), rio.depth(), 3);
  unsigned char max_gray_water = 33;

  rio.get_histogram(256).display_graph("Rio Histogram");        

  cimg_forXY(rio_color, x, y){
    if (rio(x,y) <= max_gray_water){
      rio_color(x, y, 0) = 255;
      rio_color(x, y, 1) = 255;
      rio_color(x, y, 2) = 0;
    } else {
      rio_color(x, y, 0) = rio(x,y);
      rio_color(x, y, 1) = rio(x,y);
      rio_color(x, y, 2) = rio(x,y);
    }
  }

  CImgDisplay vent_1(rio_color, "Rio");

  while(!vent_1.is_closed()){}; 
  return 0;
}
