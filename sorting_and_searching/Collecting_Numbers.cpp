#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int pos[n+1];
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        pos[num] = i;    
    }

    int ans = 1, prevpos = -1;

    for (int num = 1; num <= n; num++) {
        if (pos[num] < prevpos) {
            ans++;
        }
        prevpos = pos[num];
    }

    cout << ans;

}