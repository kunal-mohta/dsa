void swapInt (int *a, int *b) {
  if (*a == *b) return;
  else {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
  }
} // O(1)

void printIntArray (int arr[], int startIndex, int endIndex) {
  for (int i = startIndex; i <= endIndex; i++) {
    cout<<arr[i]<<endl;
  }
}