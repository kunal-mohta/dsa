/* CLRS algo for heaps ds */
/* TODO -
 *  minheaps
 */

// This file's functions are included in dsa/algos/heapsort-clrs.cpp
//No problem in keeping the header files as they won't be read twice (I think, as preprocessing gives the same number of lines when including the header files more than once)

#include<iostream>
#include<vector>

#include "../../utilities.cpp"

using namespace std;

int leftChild (int index) {
  return (index * 2);
}

int rightChild (int index) {
  return (index * 2 + 1);
}

void maxHeapify (vector <int> &arr, int index) {
  int l = leftChild(index), r = rightChild(index);
  int indexOfLargest;
  
  if (l < arr.size() && arr[l] > arr[index]) indexOfLargest = l;
  else indexOfLargest = index;

  if (r < arr.size() && arr[r] > arr[indexOfLargest]) indexOfLargest = r;
  
  if (indexOfLargest != index) {
    swapInt(&arr[index], &arr[indexOfLargest]);
    maxHeapify(arr, indexOfLargest);
  }
}

void buildMaxHeap (vector <int> &arr) {
  int heapSize = arr.size() - 1;

  int indexToStartHeapifing = heapSize / 2;

  for (int i = indexToStartHeapifing; i >= 1; i--) {
    maxHeapify(arr, i);
  }
}

// int main () {
//   vector <int> arr = { NULL, 1, 2, 3, 4, 5, 6, 7};
//   buildMaxHeap(arr);

//   for (int i = 1; i < arr.size(); i++) cout<<arr[i]<<endl;
// }
