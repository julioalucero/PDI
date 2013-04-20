#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include "../src/PDI_functions.h"

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  // Exercise 4.4.2
  CImg<double> camino("../public/images/camino.tif");
  CImg<double> filter_camino("../public/images/camino.tif");
  CImg<double> camino_hsi = camino.get_RGBtoHSI();

  CImg<double> filtro_1(3,3);
  filtro_1.fill( 0, -1,  0,
                -1,  5, -1,
                 0, -1,  0);

  // RGB filter
  filter_camino.get_shared_channel(0) = camino.get_channel(0).get_convolve(filtro_1);
  filter_camino.get_shared_channel(1) = camino.get_channel(1).get_convolve(filtro_1);
  filter_camino.get_shared_channel(2) = camino.get_channel(2).get_convolve(filtro_1);

  // HSI filter
  camino_hsi.get_shared_channel(2) = camino_hsi.get_channel(2).get_convolve(filtro_1);
  camino_hsi.HSItoRGB();

  CImgDisplay vent_1(camino, "camino");
  CImgDisplay vent_2(filter_camino , "RGB - high filter - Camino");
  CImgDisplay vent_3(camino_hsi, "HSI - hihg filter - camino");

  while(!vent_1.is_closed()){}; 
  return 0;
}
