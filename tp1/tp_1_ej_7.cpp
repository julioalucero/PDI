#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

CImg <bool> halftonic(CImg<unsigned char> img){
  bool gray_scale[10][3][3] = {
    {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
    {{1, 0, 1}, {1, 1, 1}, {1, 1, 1}},
    {{0, 0, 1}, {1, 1, 1}, {1, 1, 0}},
    {{0, 0, 1}, {1, 1, 1}, {1, 1, 0}},
    {{0, 0, 1}, {1, 1, 1}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 1}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 0}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  };

  int width  = img.width()  * 3;
  int height = img.height() * 3;

  CImg<bool> halftonic_image(width, height);

  float factor = 255 / 9;

  cimg_forXY(img, x, y){
    unsigned int halftonic_class = 9 - img(x,y) / factor;

    for(int m=0; m<3; m++){
      for(int n=0; n<3; n++){
        halftonic_image(x * 3 + m, y * 3 + n) = gray_scale[halftonic_class][n][m];
      }
    }
  }

  return halftonic_image;
}

int main(int argc, char *argv[]) {

  cimg_usage("Ejemplo Basico");
  const char* filename = cimg_option("-i", "../public/images/huang2.jpg", "Image file\n");
  CImg<unsigned char> huang2(filename);

  // image to test halftonic
  // CImg<unsigned char> test_image(256, 256);
  // cimg_forXY(huang2, x, y){
  //   test_image(x, y) = x;
  // }
  // huang2 = test_image;

  CImg<bool> halftonic_image = halftonic(huang2);

  CImgDisplay ventana(huang2, ""), ventana_2(halftonic_image, "");
  
  while (!ventana.is_closed()) {}
  return 0;
}
