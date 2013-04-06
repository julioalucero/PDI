#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {
  
  //  Exercise 3.3
  CImg<double> img("../public/images/huang2.jpg");                        

  CImg<double> filtro_1(3, 3);
  cimg_forXY(filtro_1,x,y) { filtro_1(x,y) = 1.0/9.0; }	

  CImg<double> filtro_2(5,5);
  cimg_forXY(filtro_2,x,y) { filtro_2(x,y) = 1.0/9.0; }

  CImg<double> filtro_3(10,10);
  cimg_forXY(filtro_3,x,y) { filtro_3(x,y) = 1.0/9.0; }
  
  CImg<double> img_filtrada_1 = img.get_convolve(filtro_1);
  CImg<double> img_filtrada_2 = img.get_convolve(filtro_2);
  CImg<double> img_filtrada_3 = img.get_convolve(filtro_3);
  
  CImgDisplay vent1, vent2, vent3, vent4;
  img.display(vent1);
  
  img_filtrada_1.display(vent2);// More like the original
  img_filtrada_2.display(vent3);// More Fuzzy
  img_filtrada_3.display(vent4);// More that more Fuzzy

  while(!vent1.is_closed()){}; 
            
  return 0;
}
