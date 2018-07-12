#include<iostream>

bool isBitOnAt (int num, int position) {
  int i = position - 1;

  if ( (num & ( 1 << i)) > 0 ) return true;
  else return false;
};

void setBitOnAt (int* num, int position) {
  int val = *num;
  int i = position - 1;

  *num = ( val | ( 1 << i ) );
}

void setBitOffAt (int* num, int position) {
  int val = *num;
  int i = position - 1;

  *num = ( val & ( ~( 1 << i ) ) );
}

int main () {
  std::cout<<isBitOnAt(8, 4)<<std::endl;

  int x = 0;
  setBitOnAt(&x, 3);
  std::cout<<x<<std::endl;

  int y = 3;
  setBitOffAt(&y, 2);
  std::cout<<y<<std::endl;
}