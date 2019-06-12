/*
Solving this, basically, in a similar way a person
would draw the spiral,
starting from the last number first
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

pair<int,int> moveUp (int i, int j, int n_times) {
  return make_pair(i - n_times, j);
}

pair<int,int> moveDown (int i, int j, int n_times) {
  return make_pair(i + n_times, j);
}

pair<int,int> moveLeft (int i, int j, int n_times) {
  return make_pair(i, j - n_times);
}

pair<int,int> moveRight (int i, int j, int n_times) {
  return make_pair(i, j + n_times);
}

pair<int,int> makeMove (int i, int j, int n_times, int direction) {
  pair<int,int> move;
  switch (direction) {
    case 0: move = moveLeft(i, j, n_times);
            break;
    case 1: move = moveUp(i, j, n_times);
            break;
    case 2: move = moveRight(i, j, n_times);
            break;
    case 3: move = moveDown(i, j, n_times);
            break;
  }
  return move;
}

int next_dir (int dir) {
  dir++;
  if (dir >= 4) {
    dir = 0;
  }

  return dir;
}

int main () {
  int n = 4;

  int spiral[n][n];

  int dir = 0;
  int row = n - 1;
  int col = n - 1;
  int counter = n * n;
  for (int i = n - 1; i > 0; i--) {
    int j = 2;
    if (i == n - 1) j = 3;
    while (j > 0) {
      int z = i;
      while (z > 0) {
        spiral[row][col] = counter;
        counter--;
        pair<int,int> next_pair = makeMove(row, col, 1, dir);
        row = next_pair.first;
        col = next_pair.second;
        z--;
      }
      dir = next_dir(dir);
      j--;
    }
  }
  spiral[row][col] = counter;

  for (int m = 0; m < n; m++) {
    for (int l = 0; l < n; l++) {
      cout<<spiral[m][l]<<" ";
    }
    cout<<endl;
  }
}