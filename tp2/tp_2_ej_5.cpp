#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// cimg_to_bin
CImg<bool> cimg_to_bin(CImg<unsigned char> img, int umbral, bool inverse){
  CImg<bool> bin_img(img.width(),img.height());

  cimg_forXY(img,x,y){
    if(img(x,y) < umbral)
      bin_img(x,y) = inverse;
    else
      bin_img(x,y) = !inverse;
  }

  return bin_img;
} 


int main(int argc, char *argv[]) {
  CImg<unsigned char> huang2("../public/images/huang2.jpg");
  CImg<bool> huang2_binary = cimg_to_bin(huang2, 128, true);

  CImgDisplay ventana(huang2_binary, "Huang2 binary");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
