/*
 *Solution for finding Hamiltonian paths
 *using bitmasking DP
 *
 *This code is for Codeforces 329E - gives excess memory error, but correct answer
 */

#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define db double 
#define endl '\n'

using namespace std;

void solve(vector<vector<ll>> points, ll n) {
	ll dp[n][1<<n]; // [ending vertex, selected subset]
	int firstv[n][1<<n];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 1<<n; j++) {
			dp[i][j] = -1;
			firstv[i][j] = -1;
		}
	}

	for (ll i = 0; i < n; i++) {
		dp[i][1<<i] = 0;
		firstv[i][1<<i] = i;
	}

	for (ll i = 0; i < 1<<n; i++) { // all subsets
		for (int j = 0; j < n; j++) { // which vertex to remove
			// trying to find dp[j][i]
			//dp[j][i] = -1;
			if ((1<<j) & i) { // if jth bit is set
				for (int k = 0; k < n; k++) { // prev ending vertex of the path
					if (j != k // ending vertex not same as the vertex to remove
						&& ((1<<k) & i) // ending vertex is present in subset
						// should also check if there is edge from k to j
						// which in this case by default true
						&& dp[k][i^(1<<j)] != -1
					   ) {
						ll dist = abs(points[j][0] - points[k][0]) + abs(points[j][1] - points[k][1]);
						ll n = dp[k][i^(1<<j)] + dist;
						if (dp[j][i] < n) {
							dp[j][i] = n;
							firstv[j][i] = firstv[k][i^(1<<j)];
						}
					}
				}
			}
		}
	}
	ll ans = -1;
	for (int i = 0; i < n; i++) {
		if (firstv[i][(1<<n)-1] == -1) continue;
		ll d = abs(points[i][0] - points[firstv[i][(1<<n)-1]][0]) + abs(points[i][1] - points[firstv[i][(1<<n)-1]][1]);
		ans = max(ans, dp[i][(1<<n)-1] + d);
		 //ans = max(ans, dp[i][(1<<n)-1]);
	}
	cout<<ans<<endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  

	ll n;
	cin>>n;
	vector<vector<ll>> points(n, vector<ll>(2));
	for (int i = 0; i < n; i++) {
		cin>>points[i][0];
		cin>>points[i][1];
	}

	solve(points, n);
}
