#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& teams, int tt) {
  if (visited[u]) {
    if (tt != teams[u]) {
      return false;
    }
    return true;
  }
  visited[u] = true;
  teams[u] = tt;
  if (tt == 1) {
    tt = 2;
  } else {
    tt = 1;
  }
  for (int v : adj[u]) {
    if (!dfs(adj, v, visited, teams, tt)) {
      return false;
    }
  }
  return true;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> adj(m+1);

  for (int i=0;i<n;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> teams (m+1);
  vector<bool> visited (m+1);

  for (int i=1;i<=m;i++) {
    if (!visited[i]) {
      if (!dfs(adj, i, visited, teams, 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  for(int i=1;i<=m;i++) {
    cout << teams[i] << " ";
  }
  cout << "\n";

}