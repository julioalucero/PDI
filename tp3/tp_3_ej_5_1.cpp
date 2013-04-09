#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// Exercise 3.5.1
// High Pass Filters with coefficients sum equal to 1 
int main(int argc, char *argv[]) {

  CImg<double> img("../public/images/huang2.jpg");                        

  CImg<double> filtro_1(3,3);
  filtro_1.fill( 0, -1,  0,
                -1,  5, -1,
                 0, -1,  0);

  CImg<double> filtro_2(3,3);
  filtro_2.fill(-1, -1, -1,
                -1,  9, -1,
                -1, -1, -1);

  CImg<float> filtro_3(3,3);
  filtro_3.fill( 1, -2,  1,
                -2,  5, -2,
                 1, -2,  1);
  
  CImg<double> img_filtrada_1 = img.get_convolve(filtro_1);
  CImg<double> img_filtrada_2 = img.get_convolve(filtro_2);
  CImg<double> img_filtrada_3 = img.get_convolve(filtro_3);
  
  CImgDisplay ventana(img, "Huang2");
  CImgDisplay ventana_img_1(img_filtrada_1, "center: 5, side: 1");
  CImgDisplay ventana_img_2(img_filtrada_2, "center: 9, other: -1");
  CImgDisplay ventana_img_3(img_filtrada_3, "center: 5, sides: -2, corners: 1");


  while(!ventana.is_closed()){};             
  return 0;
}
