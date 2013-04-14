#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;


// Exercise 3.7.1
// Fussy Mask Filter
// fussy_mask_img = img - img_high_filter * B
int main(int argc, char *argv[]) {

  CImg<double> img("../public/images/cuadros.tif");                        
  CImg<double> equalize_img;
  CImg<unsigned char> hist(256,256);                 
  CImg<unsigned char> equalize_hist(256,256);                 
  CImg<double> filtro_1(7,7);

  // (  -1, -1, -1, -1, -1, -1, -1,
  //    -1, -1, -1, -1, -1, -1, -1,
  //    -1, -1,  4,  4,  4, -1, -1,
  //    -1, -1,  4,  8,  4, -1, -1,
  //    -1, -1,  4,  4,  4, -1, -1,
  //    -1, -1, -1, -1, -1, -1, -1,
  //    -1, -1, -1, -1, -1, -1, -1);

  cimg_forXY(filtro_1, x, y)
    filtro_1(x,y) = -1;

  filtro_1(3,3) = 8;

  filtro_1(2,2) = 4;
  filtro_1(2,3) = 4;
  filtro_1(2,4) = 4;

  filtro_1(3,2) = 4;
  filtro_1(3,4) = 4;

  filtro_1(4,2) = 4;
  filtro_1(4,3) = 4;
  filtro_1(4,4) = 4;

  hist = img.get_histogram(256,0,255);        
  equalize_img = img.get_equalize(256);        
  equalize_hist = equalize_img.get_equalize(256);        
  CImg<double> img_filtrada_1 = img.get_convolve(filtro_1);

  CImgDisplay ventana(equalize_img, "Equalize Cuadros.tif");
  CImgDisplay ventana_img_1(img_filtrada_1, "center: 5, side: 1");

  while(!ventana.is_closed()){};             
  return 0;
}
