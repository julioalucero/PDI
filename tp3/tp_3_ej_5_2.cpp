#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// Exercise 3.5.2
// High Pass Filters with coefficients sum equal to 0
int main(int argc, char *argv[]) {

  CImg<double> img("../public/images/huang2.jpg");                        

  CImg<double> filtro_1(3,3);
  filtro_1.fill( 0, -1,  0,
                -1,  4, -1,
                 0, -1,  0);

  CImg<double> filtro_2(3,3);
  filtro_2.fill(-1, -1, -1,
                -1,  8, -1,
                -1, -1, -1);

  CImg<float> filtro_3(3,3);
  filtro_3.fill( 1, -2,  1,
                -2,  4, -2,
                 1, -2,  1);
  
  CImg<double> img_filtrada_1 = img.get_convolve(filtro_1);
  CImg<double> img_filtrada_2 = img.get_convolve(filtro_2);
  CImg<double> img_filtrada_3 = img.get_convolve(filtro_3);
  
  CImgDisplay ventana(img, "Huang2");
  CImgDisplay ventana_img_1(img_filtrada_1, "center: 4, side:  -1");
  CImgDisplay ventana_img_2(img_filtrada_2, "center: 8, other: -1");
  CImgDisplay ventana_img_3(img_filtrada_3, "center: 4, sides: -2, corners: 1");


  while(!ventana.is_closed()){};             
  return 0;
}
