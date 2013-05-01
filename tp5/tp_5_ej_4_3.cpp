#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <complex>

using namespace cimg_library;
using namespace std;

#define cimg_use_fftw3

// D0 = Cut Frecuency
CImgList<double> gauss(int width, int height, int D0){
  CImgList<double> filter(2, width, height, 1, 1, 0);

  int center_x = width / 2;
  int center_y = height / 2;

  cimg_forXY(filter[0], x, y){
    double factor = sqrt((x-center_x)*(x-center_x) + (y-center_y)*(y - center_y));
    filter[0](x,y) = exp(-pow(factor, 2) / (2*pow(D0, 2)));
  }

  filter[0].shift(center_x, center_y, 0, 0, 2);

  return filter;
}

CImg<double> frequency_filter(CImg<double> img, CImgList<double> filter){
  CImgList<double> fft_img = img.get_FFT();
  CImgList<double> result(2, img.width(), img.height(), img.depth(), img.spectrum(), 0);

  cimg_forXY(img, u, v){
    complex <double>
      complex_img_fft(fft_img[0](u,v), fft_img[1](u,v)),
      complex_filter(  filter[0](u,v),  filter[1](u,v));
  
    // producto de binomios
    complex<double> complex_product = complex_img_fft * complex_filter;

    // real and imaginary
    result[0](u,v) = real(complex_product);
    result[1](u,v) = imag(complex_product);
  }

  return result.get_FFT(true)[0];
}

int main(int argc, char *argv[]) {

  // Exercise 5.4.3
  CImg<double> img("../public/images/huang2.jpg");
  int D0 = 80; // D0 = Cut Frecuency

  CImgList<double> filter = gauss(img.width(), img.height(), D0);

  CImg<double> img_filter = frequency_filter(img, filter);

  CImgDisplay vent_1(img, "Image");
  CImgDisplay vent_2(img_filter, "Image with Gauss Filter");

  while(!vent_1.is_closed()){}; 
  return 0;
}
