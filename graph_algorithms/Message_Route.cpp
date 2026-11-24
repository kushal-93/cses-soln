#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print(vector<int>& parent, int m) {
  vector<int> path;
  while(m != 0) {
    path.push_back(m);
    m = parent[m];
  }
  reverse(path.begin(), path.end());
  cout << path.size() << "\n";
  for (int e : path) {
    cout << e << " ";
  }
  cout << "\n";
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

  vector<bool> visited (m+1);
  queue<int> q;
  vector<int> parent (m+1);

  q.push(1);
  visited[1]= true;

  while(!q.empty()) {
    int ll = q.size();
    while(ll > 0) {
      int u = q.front();
      q.pop();
      if (u == m) {
        print(parent, u);
        return 0;
      }

      for (int v : adj[u]) {
        if (!visited[v]) {
          parent[v] = u;
          q.push(v);
          visited[v] = true;
        }
      }

      ll--;
    }
  }
  cout << "IMPOSSIBLE\n"; 

}