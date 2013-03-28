#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// Add images
CImg<unsigned char> cimg_add(CImg<unsigned char> img_1, CImg<unsigned char> img_2){
  CImg<unsigned char> result(img_1.width(), img_1.height(), img_1.depth(), img_1.spectrum());

  cimg_forXYC(img_1, x, y, v){
    result(x, y, 0, v) = (img_1(x, y, 0, v) + img_2(x, y, 0, v)) / 2;
  }
  return result;
} 

// s = 255 - r
CImg<unsigned char> cimg_negative(CImg<unsigned char> img){

  CImg<unsigned char> img_i(img.width(), img.height());

  cimg_forXY(img, x, y){
    img_i(x,y) = 255 - img(x,y);
  }

  return img_i;
} 

// cimg_displacement_x
CImg<unsigned char> cimg_displacement_x(CImg<unsigned char> img, int displacement){
  CImg<unsigned char> result(img.width(), img.height(), img.depth(), img.spectrum());

  cimg_forXYC(img, x, y ,v)
    result(x + displacement, y, 0, v) = img(x, y, 0, v);

  return result;
} 

// Emboss
// TODO test if the solution is correct
CImg<unsigned char> cimg_emboss(CImg<unsigned char> img, int displacement){
  CImg<unsigned char> img_negative = cimg_negative(img);
  CImg<unsigned char> img_negative_displacement;
  img_negative_displacement = cimg_displacement_x(img_negative, displacement);

  CImg<unsigned char> images_sum; 
  images_sum = cimg_add(img, img_negative_displacement);
  
  CImg<unsigned char> result(img.width()-displacement, img.height(), img.depth(), img.spectrum());
  cimg_forXYC(result, x, y ,v)
    result(x, y, 0, v) = images_sum(x+displacement, y, 0, v);
  

  return result;
} 

int main(int argc, char *argv[]) {
  CImg<unsigned char> huang2("../public/images/huang2.jpg");
  int displacement = 4;
  CImg<unsigned char> emboss_huang2 = cimg_emboss(huang2, displacement);

  CImgDisplay ventana(emboss_huang2, "Emboss Chairs");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
