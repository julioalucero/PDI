#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  CImg <unsigned char> img(256, 256);

  for (int i=0; i<256; i++){
    int rand_gray = rand() % 256;
    for (int j=0; j<256; j++){
      img(i,j) = rand_gray;
    }
  }

  
  CImgDisplay ventana(img, "Random Gray Columns");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}
  return 0;
}
