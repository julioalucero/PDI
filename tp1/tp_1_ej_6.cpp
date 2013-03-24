#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  cimg_usage("Ejemplo Basico");
  const char* filename = cimg_option("-i", "../public/images/huang2.jpg", "Image file\n");
  CImg<unsigned char> huang2(filename);

  CImgList<unsigned char> cimg_list;
  cimg_list.push_back(huang2);

  for(int i=0; i<8; i++){
    CImg<unsigned char> hunag2_quantize = huang2.get_quantize(i+1);
    cimg_list.push_back(hunag2_quantize ); 
  }

  CImgDisplay ventana(cimg_list);

  while (!ventana.is_closed()) {}
  return 0;
}
