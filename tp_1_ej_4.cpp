#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  // Random Gray Columns
  CImg <unsigned char> random_gray_columns(256, 256);

  for (int i=0; i<256; i++){
    int rand_gray = rand() % 256;
    for (int j=0; j<256; j++){
      random_gray_columns(i,j) = rand_gray;
    }
  }

  // Random Gray less than 100
  CImg <unsigned char> random_gray_column_less_100(100, 100);
  for (int i=0; i<100; i++){
    int rand_gray = rand() % 100;
    for (int j=0; j<100; j++){
      random_gray_column_less_100(i,j) = rand_gray;
    }
  }

  // white and black in each pixel
  CImg <unsigned char> black_white(100, 100);
  for (int i=0; i<100; i++){
    for (int j=0; j<100; j++){
      if (i%2 ==0) {
        black_white(i,j) = 0;
      } else {
        black_white(i,j) = 255;
      }
    }
  }

  CImgDisplay ventana_1(random_gray_columns, "Random Gray Columns"),
              ventana_2(random_gray_column_less_100, "Random Gray Columns less 100"),
              ventana_3(black_white, "Black and white in each pixel");




  while (!ventana_1.is_closed() && !ventana_1.is_keyQ()) {}
  return 0;
}
