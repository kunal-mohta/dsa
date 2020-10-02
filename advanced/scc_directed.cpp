// KOSARAJU'S algo to find strongly connected components in a directed graph

// SOME LEMMAS:-
//
// -> If we considered each scc as a vertex and make edges between these 
// if there is edge between any two vertices from each component, then
// we get a DAG - call it condensed graph.
//
// -> If there is edge from C1->C2 in condensed graph then DFS of on
// orig graph means that finish time of all vertices in C1 component
// is greater than C2.
//
// -> Transpose of orig graph and then DFS in order of decreasing finish
// time would mean that all the vertices in the a given componenet are only visited.
// 

#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define db double 
#define endl '\n'

using namespace std;
vector<vector<int>> graph, revgraph;
vector<bool> vis1, vis2;
stack<int> st;
vector<int> comp;

void dfs (int u) {
	vis1[u] = true;
	for (int v : graph[u]) {
		if (!vis1[v]) {
			dfs(v);
		}
	}
	st.push(u);
}

void dfsutil (int u) {
	comp.push_back(u);
	vis2[u] = true;
	for (int v : revgraph[u]) {
		if (!vis2[v]) {
			dfsutil(v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
	int n, m, k;
	cin>>n>>m>>k;

	graph = vector<vector<int>> (n+1, vector<int>());
	revgraph = vector<vector<int>> (n+1, vector<int>());
	vis1 = vector<bool>(n+1, false);
	vis2 = vector<bool>(n+1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
	}

	// Kosaraju's algo
	
	// 1st DFS
	for (int i = 1; i <= n; i++) {
		if (!vis1[i]) {
			dfs(i);
		}
	}

	// TRANSPOSE OF GRAPH
	for (int i = 1; i <= n; i++) {
		vector<int> adj = graph[i];
		for (int dest : adj)
			revgraph[dest].push_back(i);
	}

	vector<vector<int>> scc;
	// 2nd DFS
	while (!st.empty()) {
		int u = st.top();
		st.pop();
		comp = vector<int>();
		if (!vis2[u]) {
			dfsutil(u);
			scc.push_back(comp);
		}
	}

	// SCCs
	for (vector<int> comp : scc) {
		for (int v : comp)
			cout<<v<<" ";
		cout<<endl;
	}
}
