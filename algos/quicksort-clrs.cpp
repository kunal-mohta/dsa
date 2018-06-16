/* CLRS algo for quick sort */

#include<iostream>
#include<vector>

#include "../utilities.cpp"

using namespace std;

int partition(vector <int> &arr, int p, int r) {
  int pivot = arr[r];

  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (arr[j] <= pivot) {
      i++;
      swapInt(&arr[i], &arr[j]);
    }
  }
  swapInt(&arr[i+1], &arr[r]);
  
  return i + 1;
}

void quicksort(vector <int> &arr, int p, int r) {
  if (p < r) {
    int q = partition(arr, p, r);
    quicksort(arr, p , q - 1);
    quicksort(arr, q + 1, r);
  }
}

int main () {
  vector <int> arr = { NULL, 2, 7, 8, 1, 5, 6, 4, 3};
  int n = arr.size() - 1;
  quicksort(arr, 1, n);
  
  for (int i = 1; i < arr.size(); i++) {
    cout<<arr[i]<<endl;
  }
}