#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

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

int main(int argc, char *argv[]) {

  CImg<unsigned char> blister_completo("../public/images/blister_completo.jpg");
  CImg<unsigned char> blister_incompleto("../public/images/blister_incompleto_2.jpg");

  // Multiplicity each by a binary_mask
  CImg<bool> mask(blister_completo.width(), blister_completo.height(), 1, 1, 0);
 // CImg<bool> SE_binary_mask(width, height, 1, 1, 0);


  int positions[10][4] = {
    {38,  39,  68, 69},
    {87,  39, 117, 69},
    {138, 39, 168, 69},
    {188, 39, 218, 69},
    {237, 39, 267, 69},// 5
    {38,  86,  68, 116},
    {87,  86, 117, 116},
    {138, 86, 168, 116},
    {188, 86, 218, 116},
    {237, 86, 267, 116}
  };

  float mean = 0;
 // float tolerance = 0;
  for(int i=0; i<10; i++){
    CImg<unsigned char> aux = blister_completo;
    aux.crop(positions[i][0],positions[i][1],positions[i][2],positions[i][3]);
    mean += aux.mean();
    //tolerance += sqrt(aux.variance());
  }
  mean /= 10; 
  // tolerance /= 10;

  float tolerance = 20;
  vector<int> pos_sin_pastillas;
  for(int i=0; i<10; i++){
    CImg<unsigned char> aux = blister_incompleto;
    aux.crop(positions[i][0],positions[i][1],positions[i][2],positions[i][3]);
    float current_mean = aux.mean();
    if(abs(mean - current_mean) > tolerance )
      pos_sin_pastillas.push_back(i);
  }

  for(int i=0; i < pos_sin_pastillas.size(); i++){
    cout << endl;
    cout << "There is not 'pastilla' on: " << pos_sin_pastillas[i];
    cout << endl;
  }

  CImgDisplay ventana(blister_completo,  "Blister Completo");
  CImgDisplay ventana_2(blister_incompleto,  "Blister Incompleto");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
