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

// Subraction images
CImg<unsigned char> cimg_sub(CImg<unsigned char> img_1, CImg<unsigned char> img_2){
  CImg<unsigned char> result(img_1.width(), img_1.height(), img_1.depth(), img_1.spectrum());

  cimg_forXYC(img_1, x, y, v){
    result(x, y, 0, v) = img_1(x, y, 0, v) - img_2(x, y, 0, v);
  }
  return result;
} 

// Multiplicity images
CImg<unsigned char> cimg_mult(CImg<unsigned char> img, CImg<bool> binary_mask){
  CImg<unsigned char> result(img.width(), img.height(), img.depth(), img.spectrum());

  cimg_forXYC(img, x, y, v){
    result(x, y, 0, v) = img(x, y, 0, v) * binary_mask(x, y);
  }
  return result;
} 

CImg<unsigned char> cimg_inverse(CImg<unsigned char> img){
  CImg<unsigned char> result(img.width(), img.height(), img.depth(), img.spectrum());

  cimg_forXYC(img, x, y, v){
    result(x, y, 0, v) = 1 / 255 * img(x, y, 0, v);
  }
  return result;
} 

CImg<unsigned char> cimg_division(CImg<unsigned char> img, CImg<bool> binary_mask){
  return cimg_mult(img, cimg_inverse(binary_mask));
} 


int main(int argc, char *argv[]) {
  CImg<unsigned char> cameraman("../public/images/rmn.jpg");
  CImg<unsigned char> img("../public/images/huang2.jpg");

  // Add
  CImg<unsigned char> sum_images = cimg_add(img, cameraman);
  CImgDisplay ventana(sum_images, "Sum of Images");

  // Subtraction
  CImg<unsigned char> sub_images = cimg_sub(img, cameraman);
  CImgDisplay ventana_1(sub_images, "Subtraction of Images");

  // Multiplicity
  CImg<bool> binary_mask(256, 256, 1, 1, 0);
  cimg_forXY(binary_mask, x, y){
    if (x > 100 && x < 200 && y > 100 && y < 200)
      binary_mask(x, y) = 1;
  }
  CImg<unsigned char> multiplicity = cimg_mult(cameraman, binary_mask);
  CImgDisplay ventana_2(multiplicity, "Multiplication");

  // Division
  CImg<unsigned char> division = cimg_division(cameraman, binary_mask);
  CImgDisplay ventana_3(division, "Division");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
