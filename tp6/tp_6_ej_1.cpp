#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  CImg<unsigned char> image("../public/images/futbol.jpg");

  CImgDisplay ventana(image, "futbol");
   
  // Type of additive noise (can be 0=gaussian, 1=uniform, 2=Salt and Pepper, 3=Poisson or 4=Rician). 

  CImgDisplay gaussian(image.get_noise(20,0), "Gaussian Noise");
  CImgDisplay  Uniform(image.get_noise(20,1), "Uniform Noise");
  CImgDisplay    SaltP(image.get_noise(20,2), "Salt and Pepper Noise");
  CImgDisplay  Poisson(image.get_noise(20,3), "Poisson Noise");
  CImgDisplay   Rician(image.get_noise(20,4), "Rician Noise");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}
  return 0;
}
