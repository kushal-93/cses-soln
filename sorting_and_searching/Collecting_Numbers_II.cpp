#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int pos[n+1], nums[n+1];
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        pos[num] = i;
        nums[i] = num;  
    }

    int rounds = 1, prevpos = -1;

    for (int num = 1; num <= n; num++) {
        if (pos[num] < prevpos) {
            rounds++;
        }
        prevpos = pos[num];
    }

    for (int i=0; i<m; i++) {
        int a, b, l, r;
        cin >> a >> b;
        a--;
        b--;
        if (a < b) {
            l = a;
            r = b;
        } else {
            l = b;
            r = a;
        }

        int x = nums[l], y = nums[r];
        
        // cout << l << " " << r << endl;
        // cout << x << " " << y << endl;

        if (pos[x+1] > l && pos[x+1] < r) rounds++;
        if (pos[x-1] > l && pos[x-1] < r) rounds--;
        if (pos[y+1] > l && pos[y+1] < r) rounds--;
        if (pos[y-1] > l && pos[y-1] < r) rounds++;

        if (y == x+1) rounds++;
        if (y == x-1) rounds--;
        pos[x] = r;
        pos[y] = l;
        nums[r] = x;
        nums[l] = y;
        cout << rounds << "\n";
    }
}