#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {
  //Exercise 3.1
  
  // a
  CImg<unsigned char> img("../public/images/lenna.gif"),aux;
  CImg<unsigned char> hist(256,256);                 
  hist=img.get_histogram(256,0,255);        
  hist.display_graph();        
  aux=img.get_equalize(256);        
  (img,aux).display();
             
  // b
  CImg<unsigned char> histo_1("../public/images/histo1.tif");
  CImg<unsigned char> histo_2("../public/images/histo2.tif");
  CImg<unsigned char> histo_3("../public/images/histo3.tif");
  CImg<unsigned char> histo_4("../public/images/histo4.tif");
  CImg<unsigned char> histo_5("../public/images/histo5.tif");
          
  (histo_1,histo_2,histo_3,histo_4,histo_5).display();
  // cargar imagenes y corroborar orden : D, F, B, A, C
  return 0;
}
