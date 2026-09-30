#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> mts;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        mts.push_back({a, b});
    }

    sort(mts.begin(), mts.end(), comp);
    int rm = 0;
    pair<int, int> prev = mts[0];
    for (int i=1;i<n;i++) {
        pair<int, int> p = mts[i];
        if (prev.second > p.first) {
            rm++;
        } else {
            prev = p;
        }
    }
    cout << n-rm ;
}