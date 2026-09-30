#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int need = x - a;
        auto it = mp.find(need);
        if (it != mp.end()) {
            cout << it->second << " " << i + 1;
            return 0;
        }
        mp[a] = i + 1;
    }

    cout << "IMPOSSIBLE";
}