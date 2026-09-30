#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int w[n];

    for (int i=0;i<n;i++) {
        cin >> w[i];
    }

    sort(w, w+n);
    int l = 0, r = n-1, ans = 0;
    while (l <= r) {
        if (w[l]+w[r] <= s) {
            l++;
            r--;
        } else {
            r--;
        }
        ans++;
    }
    cout << ans;
}