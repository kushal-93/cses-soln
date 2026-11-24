#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string getPath(vector<vector<char>>& building, int x, int y) {
    string path = "";
    while(building[x][y] != 'A') {
        if (building[x][y] == 'D') {
            path+='U';
            x+=1;
        } else if (building[x][y] == 'U') {
            path+='D';
            x-=1;
        } else if (building[x][y] == 'L') {
            path+='R';
            y-=1;
        } else if (building[x][y] == 'R') {
            path+='L';
            y+=1;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> building(m, vector<char>(n));
    int xa, ya, xb, yb;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> building[i][j];
            if (building[i][j] == 'A') {
                xa = i;
                ya = j;
            }
            if (building[i][j] == 'B') {
                xb = i;
                yb = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({xa, ya});
    //building[xa][ya] = '*';
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    char dirs[4] = {'D', 'U', 'R', 'L'};

    while (!q.empty())
    {
        int len = q.size();
        while (len > 0)
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == xb && y == yb) {
                cout << "YES" << "\n";
                string s = getPath(building, x, y);
                cout << s.length() << "\n";
                cout << s << "\n";
                return 0;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + moves[k][0], ny = y + moves[k][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (building[nx][ny] == '.' || building[nx][ny] == 'B') {
                    building[nx][ny] = dirs[k];
                    q.push({nx, ny});   
                } else {
                    continue;
                }
                
            }
            len--;
        }
    }
    cout << "NO" << "\n";
    return 0;
}
