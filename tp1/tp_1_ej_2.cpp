#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {
  cimg_usage("Ejemplo Basico");

  // Gray Image
  CImg<unsigned char> gray_image(256, 256, 1, 1);
  for (int i=0; i < 256; i++){
    for (int j=0; j < 256; j++){
      gray_image(i, j) = i;
    }
  }
  gray_image.save("public/images/gray_image.bmp");

  gray_image.print("gray image", true);
  gray_image.stats();

  return 0;
}
