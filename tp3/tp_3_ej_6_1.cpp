#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;


// Exercise 3.6
// Fussy Mask Filter
// fussy_mask_img = img - img_high_filter * B
int main(int argc, char *argv[]) {

  CImg<double> img("../public/images/huang2.jpg");                        

  CImg<double> filtro_1(3,3);
  filtro_1.fill(0, 1, 0,
                1, 5, 1,
                0, 1, 0);
  cimg_forXY(filtro_1, x, y)
    filtro_1(x,y) = filtro_1(x,y) / 5;

  CImg<double> img_high_filter = img.get_convolve(filtro_1);


  double B = 1;
  CImg<double> fussy_mask_img(img); 

  cimg_forXY(img, x, y)
    fussy_mask_img(x,y) = img(x,y) - B * img_high_filter(x,y);
  
  CImgDisplay ventana(img, "Huang2");
  CImgDisplay ventana_1(fussy_mask_img, "Image with Fussy Mask");


  while(!ventana.is_closed()){};             
  return 0;
}
