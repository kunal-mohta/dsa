// Code for Fenwick tree (or Binary Indexed tree) for range sum query (LC 307)

#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

int n;
vector<int> arr, BIT, arr2;

// change ith element to val
void update (int i, int val) {
  int d = val - arr2[i];
  arr2[i] = val;
  i++;
  for (; i <= n; i += (i&-i)) {
    BIT[i] += d;
  }
}

// query over range [0,r]
int query1 (int r) {
  r++;
  int ans = 0;
  for (int i = r; i > 0; i -= (i&-i)) {
    ans += BIT[i];
  }
  return ans;
}
// query over range [l,r] indices
int query (int l, int r) {
  return query1(r) - query1(l-1);
}

int main () {
  arr = {1,3,5};
  n = arr.size();

  // constructing BIT
  BIT = vector<int>(n+1, 0);
  arr2 = vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    update(i, arr[i]);
  }

  // queries and updates
  cout<<query(0, 2)<<endl;
  update(1, 2);
  cout<<query(0, 2)<<endl;

}