#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cimg_library;
using namespace std;

bool outside(int x, int y, int w, int h){
  if (x < 0 or y < 0 or x >= w or y >= h){
    return true;
  }else{
    return false;
  }
}

vector<double> neighbors(CImg<double> img, int x, int y, int w, int h) {
  vector<double> result;

  for (int i=x-1; i <= x+1; i++) {
    for (int j=y-1; j <= y+1; j++) {
      if (not outside(i, j, w, h)) {
        result.push_back(img(i,j));
      }
    }
  }
  return result;
}

CImg<double> geometric_filter(CImg<double> image){
  CImg<double> result(image.width(), image.height(), image.depth(), image.spectrum());

  cimg_forXY(image, x, y){
    vector<double> pixels = neighbors(image, x, y, image.width(), image.height());

    double pixels_product = 1.0;

    for (int i=0; i < pixels.size(); i++){
      pixels_product *= pixels[i];
    }

    result(x,y) = pow(pixels_product, 1.0/ pixels.size());
    cout << result(x, y) << endl;
  }
  

  return result;
}

void show_matrix(CImg<double> image){
  cout << endl;

  for(int i=0; i< image.width(); i++){
    cout << endl;
    for(int j=0; j< image.height(); j++){
      cout << image[i, j] << " ";
    }
  }
  cout << endl;

}

int main(int argc, char *argv[]) {

  CImg<double> image("../public/images/sangre.jpg");

  CImg<double> noise_image;
  noise_image  = image.get_noise(20, 0);
  // noise_image += image.get_noise(20, 2);

  CImg<double> image_with_filter = geometric_filter(noise_image);

  CImgDisplay v1(image, "sangre");
  //CImgDisplay v2(noise_image, "Sangre with Gaussian and Impulsive Noise");
  CImgDisplay v3(image_with_filter, "Image With Filter");

  while (!v1.is_closed()) {}
  return 0;
}
