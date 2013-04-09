#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  // Exercise 3.4.1
//  CImg<double> img("../public/images/huang2.jpg");                        
//
//  CImg<double> filtro_1(3,3);
//  cimg_forXY(filtro_1,x,y){filtro_1(x,y)=1.0/9.0;}	
//
//  CImg<double> filtro_2(5,5);
//  cimg_forXY(filtro_2,x,y){filtro_2(x,y)=1.0/9.0;}
//
//  CImg<double> filtro_3(10,10);
//  cimg_forXY(filtro_3,x,y){filtro_3(x,y)=1.0/9.0;}
//
//  
//  CImg<double> img_filtrada_1=img.get_convolve(filtro_1);
//  CImg<double> img_filtrada_2=img.get_convolve(filtro_2);
//  CImg<double> img_filtrada_3=img.get_convolve(filtro_3);
  
  //CImgDisplay vent1,vent2,vent3,vent4;
  //img.display(vent1);
  //
  //img_filtrada_1.display(vent2);
  //img_filtrada_2.display(vent3);
  //img_filtrada_3.display(vent4);

  // Exercise 3.4.2
  CImg<double> hubble("../public/images/hubble.tif");                        

  CImg<double> filtro_1_hubble(3,3);
  cimg_forXY(filtro_1_hubble,x,y){filtro_1_hubble(x,y)=1.0/9.0;}	

  CImg<double> filtro_2_hubble(5,5);
  cimg_forXY(filtro_2_hubble,x,y){filtro_2_hubble(x,y)=1.0/9.0;}

  CImg<double> filtro_3_hubble(10,10);
  cimg_forXY(filtro_3_hubble,x,y){filtro_3_hubble(x,y)=1.0/9.0;}

  
  CImg<double> img_filtrada_hubble_1 = hubble.get_convolve(filtro_1_hubble);
  CImg<double> img_filtrada_hubble_2 = hubble.get_convolve(filtro_2_hubble);
  CImg<double> img_filtrada_hubble_3 = hubble.get_convolve(filtro_3_hubble);
  
  CImgDisplay vent_hubble(hubble, "Hubble");
  CImgDisplay vent_hubble1(img_filtrada_hubble_1, "Hubble 1 - size: 3x3");
  CImgDisplay vent_hubble2(img_filtrada_hubble_2, "Hubble 2 - size: 5x5");
  CImgDisplay vent_hubble3(img_filtrada_hubble_3, "Hubble 3 - size: 10x10");

  while(!vent_hubble.is_closed()){};             
  return 0;
}
