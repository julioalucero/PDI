#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

CImg <unsigned char> centered_circle(int image_size, int background_color, int radio, unsigned char circle_color[]){

  CImg <unsigned char> centered_circle_img(image_size, image_size, 1, 3, background_color);
  centered_circle_img.draw_circle(image_size/2, image_size/2, radio, circle_color, 1);

  return centered_circle_img;
}


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

  // Black Image with a white centered circle
    int image_size;
    int radio;
    int background_color;

    cout << "Size of the image: ";
    cin >> image_size;
    cout << "background_color: ";
    cin >> background_color;
    cout << "radio: ";
    cin >> radio;

    unsigned char circle_color[]     = {255, 255, 255};    

    CImg <unsigned char> centered_circle_img;
    centered_circle_img = centered_circle(image_size, background_color, radio, circle_color);

  CImgDisplay centered_circle_windows(centered_circle_img, "Centered Circle on Image");
  while (!centered_circle_windows.is_closed()) {}
  return 0;
}
