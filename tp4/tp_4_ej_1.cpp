#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  //Exercise 4.1.a
  CImg<double> img("../public/images/patron.tif");
  img.resize(256, 256);
  int N = img.width();
  int M = img.height();

  CImg <double> red_pattern(N, M);
  CImg <double> green_pattern(N, M);
  CImg <double> blue_pattern(N, M);

  cimg_forXY(img, x, y){
    red_pattern(x,y)   = img(x, y, 0, 0);
    green_pattern(x,y) = img(x, y, 0, 1);
    blue_pattern(x,y)  = img(x, y, 0, 2);
  }

  CImgDisplay vent_1(img, "RGB Patron");
  CImgDisplay vent_2(red_pattern, "Red Patron");
  CImgDisplay vent_3(green_pattern, "Green Patron");
  CImgDisplay vent_4(blue_pattern, "Blue Patron");

  while(!vent_1.is_closed()){}; 
  return 0;
}
