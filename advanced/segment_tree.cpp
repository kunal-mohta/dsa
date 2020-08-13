// Using segment tree for range sum query


#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;

// Utility
int smallest_power_2 (int x) {
	// smallest power of 2 that is greater than or equal to the given number
	int ans = 1;
	while (ans < x) ans = ans<<1;

	return ans;
}

// Segment tree functions

int merge (int a, int b) {
	return a + b;
}

// build tree for arr[lo..hi]
void build (vector<int> arr, int treeInd, int lo, int hi) {
	if (lo == hi) {
		tree[treeInd] = arr[lo];
		return;
	}

	int mid = lo + (hi - lo)/2;
	build (arr, 2*treeInd + 1, lo, mid);
	build (arr, 2*treeInd + 2, mid+1, hi);

	tree[treeInd] = merge(tree[2*treeInd+1], tree[2*treeInd+2]);
}

// get sum int range arr[i..j]
int query (int treeInd, int lo, int hi, int i, int j) {
	if (i <= lo && j >= hi) return tree[treeInd];
	if (i > hi || j < lo) return 0;

	int mid = lo + (hi - lo)/2;

	if (j <= mid) return query(2*treeInd+1, lo, mid, i, j);
	else if (i > mid) return query(2*treeInd+2, mid+1, hi, i, j);

	int leftq = query(2*treeInd+1, lo, mid, i, mid);
	int rightq = query(2*treeInd+2, mid+1, hi, mid+1, j);
	return merge(leftq, rightq);
}

void update (int treeInd, int lo, int hi, int arrInd, int val) {
	if (arrInd < lo || arrInd > hi) return;

	if (lo == hi) {
		if (lo == arrInd) tree[treeInd] = val;
		return;
	}

	int mid = lo + (hi-lo)/2;

	if (arrInd <= mid) update(2*treeInd+1, lo, mid, arrInd, val);
	else update(2*treeInd+2, mid+1, hi, arrInd, val);

	tree[treeInd] = merge(tree[2*treeInd+1], tree[2*treeInd+2]);
}

int main () {
	vector<int> arr = {18, 17, 13, 19, 15, 11, 20, 12, 33, 25}; // size = 10

	tree = vector<int>(2*smallest_power_2(arr.size()), 0);

	// Build
	build(arr, 0, 0, arr.size()-1);
	cout<<"Seg tree: "<<endl;
	for (int a : tree) {
		cout<<a<<" ";
	}
	cout<<endl;

	// Queries
	cout<<query(0, 0, arr.size()-1, 1, 3)<<endl;
	cout<<query(0, 0, arr.size()-1, 2, 8)<<endl;

	// Update
	/*
	 *cout<<query(0, 0, arr.size()-1, 1, 3)<<endl;
	 *update(0, 0, arr.size()-1, 2, 123);
	 *cout<<query(0, 0, arr.size()-1, 1, 3)<<endl;
	 */
	
	cout<<query(0, 0, arr.size()-1, 2, 8)<<endl;
	update(0, 0, arr.size()-1, 2, -1);
	cout<<query(0, 0, arr.size()-1, 2, 8)<<endl;
}
