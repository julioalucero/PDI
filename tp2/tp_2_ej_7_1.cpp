#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>

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

int main(int argc, char *argv[]) {
  CImg<float> earth("../public/images/earth.bmp");

  // Exercise a
  CImg<float> earth_log;
  earth_log = cimg_log(earth, 0.2);

  CImgDisplay ventana(earth, "Earth");
  CImgDisplay ventana_2(earth_log, "Earth Log");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
