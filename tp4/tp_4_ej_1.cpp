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

  red_pattern   = img.get_channel(0);
  green_pattern = img.get_channel(1);
  blue_pattern  = img.get_channel(2);

  CImgDisplay vent_1(img, "RGB Patron");
  CImgDisplay vent_2(red_pattern, "Red Patron");
  CImgDisplay vent_3(green_pattern, "Green Patron");
  CImgDisplay vent_4(blue_pattern, "Blue Patron");

  CImg<double> img_hsi = img.get_RGBtoHSI();

  CImg <double> h_pattern(N, M);
  CImg <double> s_pattern(N, M);
  CImg <double> i_pattern(N, M);

  h_pattern = img_hsi.get_channel(0);
  s_pattern = img_hsi.get_channel(0);
  i_pattern = img_hsi.get_channel(0);

  CImgDisplay vent_5(img_hsi, "HSI Patron");
  CImgDisplay vent_6(h_pattern, "H Patron");
  CImgDisplay vent_7(s_pattern, "S Patron");
  CImgDisplay vent_8(i_pattern, "I Patron");

  //Exercise 4.1.b
  cimg_forXY(img_hsi, x, y){
    double hue = 180 + img_hsi(x, y, 0, 0);
    img_hsi(x, y, 0, 0) = (hue > 360) ? hue - 360 : hue;
  }
 
  img_hsi.get_channel(0).display("Channel h of hsi");
  img_hsi.HSItoRGB();
  img_hsi.display("Nueva HSI");
  
  while(!vent_1.is_closed()){}; 
  return 0;
}
