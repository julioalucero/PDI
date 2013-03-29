#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cimg_library;
using namespace std;

//dec a binario hasta 256 niveles
vector<bool> dec_to_bin(int value){
  vector<bool> bin_val;

  if (value == 0) {
    for(int i=0; i<8; i++)
      bin_val.push_back(0);
    return bin_val;
  }
  
  int dividendo = value;
  bool resto = 0;
  	
  while (dividendo != 0){
    resto = dividendo % 2;
    dividendo = dividendo / 2;
    bin_val.insert(bin_val.begin(),resto);
  }
  
  if (bin_val.size()!=8)
    while (bin_val.size() != 8) {
      bin_val.insert(bin_val.begin(),0);
    }

  return bin_val;
}

int main(int argc, char *argv[]) {
  CImg<unsigned char> img("../public/images/huang2.jpg");
  CImg<bool> bpl7(img.width(),img.height());
  CImg<bool> bpl6(img.width(),img.height());
  CImg<bool> bpl5(img.width(),img.height());
  CImg<bool> bpl4(img.width(),img.height());
  CImg<bool> bpl3(img.width(),img.height());
  CImg<bool> bpl2(img.width(),img.height());
  CImg<bool> bpl1(img.width(),img.height());
  CImg<bool> bpl0(img.width(),img.height());

  img.quantize(256);

  vector <bool> bin_output(8);

  cimg_forXY(img, x, y){
    bin_output = dec_to_bin(img(x,y));
    
    bpl7(x,y) =  bin_output[0];
    bpl6(x,y) =  bin_output[1];
    bpl5(x,y) =  bin_output[2];
    bpl4(x,y) =  bin_output[3];
    bpl3(x,y) =  bin_output[4];
    bpl2(x,y) =  bin_output[5];
    bpl1(x,y) =  bin_output[6];
    bpl0(x,y) =  bin_output[7];
    bin_output.clear();
  }

  CImgList<bool> list;
  list.insert(bpl7);
  list.insert(bpl6);
  list.insert(bpl5);
  list.insert(bpl4);
  list.insert(bpl3);
  list.insert(bpl2);
  list.insert(bpl1);
  list.insert(bpl0);

  list.display();

  return 0;
}
