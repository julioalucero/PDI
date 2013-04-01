#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// s = c * log(1+r)
CImg<float> cimg_log(CImg<float> r, float c){
  CImg<float> s(r.width(), r.height(), r.depth(), r.spectrum());

  cimg_forXYC(r, x, y, v){
    s(x, y, 0, v) = c * log( 1 + r(x, y, 0, v)); 
    if ( s(x, y, 0, v) > 1 )
       s(x, y, 0, v) = 1; 
    else if ( s(x, y, 0, v) < 0 )
       s(x, y, 0, v) = 0; 
  }
  return s;
} 

// s = c * r^&
CImg<unsigned char> cimg_power(CImg<unsigned char> r, float c, float gamma){
  CImg<unsigned char> r_normalize = r.get_normalize(0,1);
  CImg<unsigned char> s(r.width(), r.height(), r.depth(), r.spectrum());

  cimg_forXYC(r_normalize, x, y, v){
    s(x, y, 0, v) = c * pow(r_normalize(x, y, 0, v), gamma); 
    if ( s(x, y, 0, v) > 1 )
       s(x, y, 0, v) = 1; 
    else if ( s(x, y, 0, v) < 0 )
       s(x, y, 0, v) = 0; 
  }

  return s;
} 

int main(int argc, char *argv[]) {
  CImg<unsigned char> img("../public/images/huang2.jpg");

   float gamma = 1;
   CImg<unsigned char> log = cimg_log(img, 2);
   CImg<unsigned char> power = cimg_power(img, 1, gamma);

  CImgDisplay ventana(img, "Image Original");
  CImgDisplay ventana_2(log, "log");
  CImgDisplay ventana_3(power, "power");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
