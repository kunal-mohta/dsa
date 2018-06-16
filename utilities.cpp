void swapInt (int *a, int *b) {
  if (*a == *b) return;
  else {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
  }
}