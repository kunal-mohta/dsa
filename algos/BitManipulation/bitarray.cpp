//each bit ON means a number => the array can have as many numbers as their are bits
//also, only non negative integers can be stored (directly at lease)

#include<iostream>

void addToBitArray (int num, int* array) {
  *array |= ( 1 << num );
}

void removeFromArray (int num, int* array) {
  *array &= ( ~( 1 << num ) );
}

bool isNumInArray (int num, int array) {
  if ( (array & ( 1 << num )) > 0 ) return true;
  else return false;
}

int main () {
  int bitArray = 0;

  addToBitArray(1, &bitArray);
  addToBitArray(2, &bitArray);
  std::cout<<bitArray<<std::endl;
  removeFromArray(2, &bitArray);
  std::cout<<bitArray<<std::endl;
  std::cout<<isNumInArray(3, bitArray)<<std::endl;
  std::cout<<isNumInArray(1, bitArray)<<std::endl;
}