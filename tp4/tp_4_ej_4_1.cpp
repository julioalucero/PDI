#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include "../src/PDI_functions.h"

using namespace cimg_library;
using namespace std;

// TODO review if is OK the rgb equalized method
int main(int argc, char *argv[]) {

  // Exercise 4.4.1
  CImg<double> chairs("../public/images/chairs.jpg");
  CImg<double> chairs_oscura("../public/images/chairs_oscura.jpg");
  CImg<double> chairs_eq = chairs_oscura.get_equalize(256);
  CImg<double> chairs_hsi = chairs_oscura.get_RGBtoHSI();

  // equalize the Intensiti channel
  chairs_hsi.get_shared_channel(2).equalize(256);

  chairs_hsi.HSItoRGB();

  CImgDisplay vent_1(chairs, "Chairs");
  CImgDisplay vent_2(chairs_oscura, "Chairs Oscura");
  CImgDisplay vent_3(chairs_eq, "Chairs Equalized");
  CImgDisplay vent_4(chairs_hsi, "Chairs HSI Equalized");

  while(!vent_1.is_closed()){}; 
  return 0;
}
