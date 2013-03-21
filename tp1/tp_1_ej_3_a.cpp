#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  const char* filename = cimg_option("-i", "public/images/cameraman.tif", "Image file\n");
  CImg <unsigned char> img(filename), perfil(256, 256, 1, 1, 0);  

  // see it
  CImgDisplay ventana(img, "intensity", 0), perfil_window(perfil, "", 0); // 0 == without normalization

  // intensity on the pointer TODO does not work
  int y;
  int pos;
  while(!ventana.is_closed()){
    ventana.wait(); // TODO
    pos = ventana.mouse_y();
    perfil.fill(0); // TODO
    perfil.draw_graph( img.get_line(pos), "white", 1, 1, 255, 0).display(perfil_window);
  }	

  while (!ventana.is_closed() && !ventana.is_keyQ()) {}
  return 0;
}
