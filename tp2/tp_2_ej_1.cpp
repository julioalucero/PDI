#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// s = a r + c
CImg<int> lut(CImg<int> r, float a, float c){
  CImg<int> s(256,1,1);

  cimg_forXY(r, x, y){
    s(x, y) = a* r(x, y) + c; 

    if(r(x,y) < 0) 
      s(x,y) = 0;
    else if (r(x,y) > 255)
      s(x,y) = 255;
  }
  
  return s;
} 

// s = 255 - r
CImg<unsigned char> negative(CImg<unsigned char> img){

  CImg<unsigned char> img_i(img.width(), img.height());

  cimg_forXY(img, x, y){
    img_i(x,y) = 255 - img(x,y);
  }

  return img_i;
} 

int main(int argc, char *argv[]) {
/*  
  CImg<unsigned char> img("../public/images/cameraman.tif");

  CImg<unsigned char> img_i=negative(img);
  // see two images at the same time
  CImgDisplay ventana(img, "inverse cameramm"),
              ventana_2(img_i, "inverse cameramm");

*/
  CImg<bool> img(256, 256);

  cimg_forXY(img, x, y){
    if (x == 255 - y)
      img(x,y) = 1;
  }

  CImgDisplay ventana(img, "inverse cameramm");

  int x1, y1, x2, y2;
  int clicks = 0;
  while (!ventana.is_closed()){
    ventana.wait(); // TODO
    if (ventana.button() && (clicks == 0)){ // TODO
      x1 = ventana.mouse_x(); // TODO
      y1 = ventana.mouse_y(); // TODO
      clicks++;
    }
    else if (ventana.button() && (clicks == 1)){ // TODO
      x2 = ventana.mouse_x(); // TODO
      y2 = ventana.mouse_y(); // TODO
    }
  }

  cout << endl << x1 << "  " << y1;
  cout << endl << x2 << "  " << y2;
  cout << endl;


  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
