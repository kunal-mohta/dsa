// Code for strongly connected components in a directed graph
// Solution for Codeforces 427C

#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define mod (ll)(1e9+7)

using namespace std;

ll n;
vector<vector<int>> graph, rgraph;
vector<ll> weight;
vector<bool> vis;
stack<ll> st;
unordered_map<ll, ll> ump;
ll curr_min;

void dfs (int u) {
  vis[u] = true;
  for (int v : graph[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
  st.push(u);
}

void dfs2 (int u) {
  vis[u] = true;
  curr_min = min(curr_min, weight[u]);
  ump[weight[u]]++;
  for (int v : rgraph[u]) {
    if (vis[v]) continue;
    dfs2(v);
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  weight = vector<ll>(n+1);
  graph = vector<vector<int>>(n+1);

  for (int i = 0; i < n; i++) {
    cin>>weight[i+1];
  }

  ll m;
  cin>>m;
  for (ll i = 0; i < m; i++) {
    int u, v;
    cin>>u>>v;
    graph[u].push_back(v);
  }

  // 1. DFS and store vertices in stack
  vis = vector<bool>(n+1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }

  // 2. transpose of the graph
  rgraph = vector<vector<int>>(n+1);
  for (int u = 1; u <= n; u++) {
    for (int v : graph[u]) {
      rgraph[v].push_back(u);
    }
  }

  // 3. DFS on transpose in order of stack
  ll ways = 1, cost = 0;
  vis = vector<bool>(n+1, false);
  while (!st.empty()) {
    curr_min = INT_MAX;
    ump = unordered_map<ll,ll>();
    int u = st.top();
    if (!vis[u]) {
      dfs2(u);
      cost = (cost + curr_min);
      ways = (ways * ump[curr_min]) % mod;
    }
    st.pop();
  }
  cout<<cost<<" "<<ways<<endl;
}
