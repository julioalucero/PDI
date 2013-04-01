#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

// Add images
CImg<unsigned char> cimg_add(CImg<unsigned char> img_1, CImg<unsigned char> img_2){
  CImg<unsigned char> result(img_1.width(), img_1.height(), img_1.depth(), img_1.spectrum());

  cimg_forXYC(img_1, x, y, v){
    result(x, y, 0, v) = (img_1(x, y, 0, v) + img_2(x, y, 0, v)) / 2;
  }
  return result;
} 

// Mean List of images images
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

CImgList<float> cimg_noise(CImg<float> img, int size, int radium){
  CImgList <float> list;

  for(int i=0; i<size; i++){
    CImg<float> noise_img;
    noise_img = img.get_noise(rand() % radium);
    list.push_back(noise_img);
  }

  return list;
} 

int main(int argc, char *argv[]) {
  CImg<float> img("../public/images/huang2.jpg");

  CImgList <float> list;
  list = cimg_noise(img, 5, 70);

  CImg<float> img_mean_noise = cimg_mean(list);

  CImgDisplay ventana(img, "Hunag2 Images");
  CImgDisplay ventana_1(img_mean_noise, "Hunag2 Mean Noise");

  cout << endl;
  cout << "Mean of f(x,y) (" << img.mean() << ") == ";
  cout << "Mean of E(g(x,y)) (" << img_mean_noise.mean() << ")";
  cout << endl;

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}

  return 0;
}
