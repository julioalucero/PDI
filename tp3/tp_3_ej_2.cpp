#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {
  // Exercise 3.2
  CImg<unsigned char> familia_a("../public/images/FAMILIA_a.jpg");
  CImg<unsigned char> familia_b("../public/images/FAMILIA_b.jpg");
  CImg<unsigned char> familia_c("../public/images/FAMILIA_c.jpg");
  
  CImg<unsigned char> hist1(256,256), hist2(256,256), hist3(256,256);
  int x1 = 1412; int x2 = 1512;
  int y1 =  157; int y2 =  257;

  hist1=familia_a.crop(x1,y1,x2,y2).get_histogram(256,0,255);
  hist2=familia_b.crop(x1,y1,x2,y2).get_histogram(256,0,255);
  hist3=familia_c.crop(x1,y1,x2,y2).get_histogram(256,0,255);
  
  hist1.display_graph();
  hist2.display_graph(); // ruido gausseano.. ?? puede ser?
  hist3.display_graph(); // presenta ruido impulsivo blanco y negro        
  
  return 0;
}
