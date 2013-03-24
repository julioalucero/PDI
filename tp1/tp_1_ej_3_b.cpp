#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace cimg_library;
using namespace std;

int main(int argc, char *argv[]) {

  const unsigned char red[]  = {255,   0,   0},
                     green[] = {  0, 255,   0},
                     blue[]  = {  0,   0, 255};
  
  const char* filename = cimg_option("-i", "../public/images/cameraman.tif", "Image file\n");
  CImg <unsigned char> img(filename), perfil(256, 256, 1, 1, 0);  

  // see it
  CImgDisplay ventana(img, "intensity", 0), perfil_window(perfil, "", 0); // 0 == without normalization


  // see the intensity of the image
  int y;
  int pos;
  while (!ventana.is_closed()){
    ventana.wait(); // TODO
    if (ventana.button()){ // TODO
      pos = ventana.mouse_y(); // TODO
      perfil.fill(0); // Convert all image to 0 (black)
      perfil.draw_graph(
        img.get_crop(0, pos, 0,  0, img.width()-1, pos,  0, 0),
        red, 1, 1, 0, 255, 0);

      perfil.display(perfil_window);
    }
  }
  while (!ventana.is_closed() && !ventana.is_keyQ()) {}
  return 0;
}
