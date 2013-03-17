#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  cimg_usage("Ejemplo Basico");
  const char* filename = cimg_option("-i", "public/images/cameraman.tif", "Image file\n");
  CImg<unsigned char> cameramm_image(filename);

  // Cut and copy on sub_image;
  CImg<unsigned char> sub_image(cameramm_image);
  cameramm_image.crop(100, 50, 150, 100);

  // calculate sub_image size (54 of head)
  // TODO something is wrong on the size calculation
  float size = 0;
  size = 50 * 50 * 3 + 54;
  cout << "Size of the image: " << size << " bytes" << endl;

  sub_image.save("public/images/sub_cameraman.bmp");
  // see two images at the same time
  CImgDisplay ventana(cameramm_image, "cameramm"), 
    sub_ventana(sub_image, "cameramm");

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}
  return 0;
}
