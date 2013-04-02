#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cimg_library;
using namespace std;

// Multiplicity images
CImg<unsigned char> cimg_mult(CImg<unsigned char> img, CImg<bool> binary_mask){
  CImg<unsigned char> result(img.width(), img.height(), img.depth(), img.spectrum());

  cimg_forXYC(img, x, y, v){
    result(x, y, 0, v) = img(x, y, 0, v) * binary_mask(x, y);
  }
  return result;
} 

// Mean of List of Images
CImg<float> cimg_mean(CImgList<float> list){
  CImg<float> img(list.at(0).width(), list.at(0).height(), list.at(0).depth(), list.at(0).spectrum() );

  CImg<float> result(img.width(), img.height(), img.depth(), img.spectrum(), 255);

  cimg_forXY(result, x, y){
    float pixel_x_y = 0;
    for(int i=0; i < list.size(); i++){
      pixel_x_y += list.atNXY(i,x,y);
    }
    result(x,y) = pixel_x_y / list.size();
  }

  return result;
} 

int main(int argc, char *argv[]) {

  CImg<unsigned char> a7v600_X("../public/images/a7v600-X.gif");
  CImg<unsigned char> a7v600_SE("../public/images/a7v600-SE.gif");

  int width  = a7v600_X.width();
  int height = a7v600_X.height();

  // Multiplicity each by a binary_mask
  CImg<bool> X_binary_mask( width, height, 1, 1, 0);
  CImg<bool> SE_binary_mask(width, height, 1, 1, 0);

  cimg_forXY(X_binary_mask, x, y){
    if (x > 195 && x < 245 && y > 100 && y < 150)
      X_binary_mask(x, y) = 1;
  }
  cimg_forXY(SE_binary_mask, x, y){
    if (x > 195 && x < 245 && y > 100 && y < 150)
      SE_binary_mask(x, y) = 1;
  }

  cout << "Mean of a7v600_X before mask: " <<  a7v600_X.mean() << endl;
  cout << "Mean of a7v600_SE before mask:  "<< a7v600_SE.mean() << endl;

  a7v600_X  = cimg_mult(a7v600_X,  X_binary_mask);
  a7v600_SE = cimg_mult(a7v600_SE, SE_binary_mask);

  CImgDisplay ventana(  a7v600_X,  "a7v600-x");
  CImgDisplay ventana_2(a7v600_SE, "a7v600-SE");


  cout << "Mean of a7v600_X: " <<  a7v600_X.mean() << endl;
  cout << "Mean of a7v600_SE: "<< a7v600_SE.mean() << endl;
  

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
