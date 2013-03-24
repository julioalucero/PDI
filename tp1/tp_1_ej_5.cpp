#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  cimg_usage("Ejemplo Basico");
  const char* filename = cimg_option("-i", "../public/images/rmn.jpg", "Image file\n");
  CImg<unsigned char> rmn(filename);

  int width  = rmn.width() / 2;

  int height = rmn.height() / 2;

  CImg<unsigned char> rmn_subsampling = rmn.get_resize(width, height, 1, 1, 1);


  // see two images at the same time
  CImgDisplay ventana(rmn, "rmn"), ventana_2(rmn_subsampling, "rmn subsampling");

  while (!ventana.is_closed()) {}
  return 0;
}
