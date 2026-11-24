#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
  if (visited[u]) {
    return;
  }
  visited[u] = true;
  for (int v : adj[u]) {
    dfs(adj, v, visited);
  }
  return;
}


int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> adj(m);

  for (int i=0;i<n;i++) {
    int u, v;
    cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }

  vector<bool> visited (m);
  vector<int> comps;

  for (int i=0; i<m; i++) {
    if (!visited[i]) {
      dfs(adj, i, visited);
      comps.push_back(i+1);
    }
  }

  cout << comps.size()-1 << "\n";
  for(int i=1;i<comps.size(); i++) {
    cout << comps[i-1] << " " << comps[i] << "\n";
  }
}