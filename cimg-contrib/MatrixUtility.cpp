#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>

namespace matrix_utility {
using namespace cimg_library;

void show_matrix(CImg<double> image){
  std::cout << std::endl;

  for(int i=0; i< image.width(); i++){
    std::cout << std::endl;
    for(int j=0; j< image.height(); j++){
      std::cout << image[i, j] << " ";
    }
  }
  std::cout << std::endl;
}

}
