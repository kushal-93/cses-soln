#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> entry;
    vector<int> ts;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        entry.insert(a);
        ts.push_back(a);
        ts.push_back(b);
    }

    sort(ts.begin(), ts.end());
    int ans = 0, c = 0; 
    for(int i=0; i<2*n; i++) {
        int t = ts[i];
        if (entry.find(t) != entry.end()) {
            c++;
        } else {
            c--;
        }
        ans = max(ans, c);
    }
    cout << ans;
}