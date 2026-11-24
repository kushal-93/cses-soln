#include<bits/stdc++.h>
#include <iostream>

using namespace std;

void dfs(int m, int n, vector<vector<char>>& building, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }
    if (building[i][j] != '.') {
        return;
    }

    building[i][j] = '*';
    int dirs[4][2] = {{-1, 0},{1,0},{0,-1},{0,1}};

    for (auto dir : dirs) {
        dfs(m, n, building, i+dir[0], j+dir[1]);
    }
    return;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> building(m, vector<char>(n));

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            char c;
            cin >> c;
            building[i][j] = c;
        }
    }
    int ans = 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (building[i][j] == '.') {
                dfs(m, n, building, i, j);
                ans++;
            }
        }
    }
    cout << ans;
}


