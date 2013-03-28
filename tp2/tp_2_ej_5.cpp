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

// cimg_not
CImg<bool> cimg_not(CImg<unsigned char> img){
  CImg<bool> not_img(img.width(),img.height());

  cimg_forXY(img,x,y){
    not_img(x,y) = -1 * img(x,y) + 1;
  }

  return not_img;
} 

// cimg_or
CImg<bool> cimg_or(CImg<unsigned char> img_1, CImg<unsigned char> img_2){
  CImg<bool> or_img(img_1.width(),img_1.height());

  cimg_forXY(img_1,x,y){
    or_img(x,y) = img_1(x,y) || img_2(x,y);
  }

  return or_img;
} 

int main(int argc, char *argv[]) {
  CImg<unsigned char> huang2("../public/images/huang2.jpg");
 
  // 2.5.1 cimg_to_bin
  CImg<bool> huang2_binary = cimg_to_bin(huang2, 128, true);
  CImgDisplay ventana(huang2_binary, "Huang2 binary");

  // 2.5.2  NOT and OR
  CImg<bool> huang2_not = cimg_not(huang2_binary);
  CImgDisplay ventana_not(huang2_not, "Huang2 NOT");

  // TODO search an example
  CImg<bool> huang2_or = cimg_or(huang2_binary, huang2_binary);
  CImgDisplay ventana_or(huang2_or, "Huang2 OR");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
