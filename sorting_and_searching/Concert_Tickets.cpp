#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> pset;

    for(int i=0; i<n; i++) {
        int p;
        cin >> p;
        pset.insert(p);
    }

    for(int i=0; i<m; i++) {
        int c;
        cin >> c;
        auto ubit = pset.upper_bound(c);
        if (ubit == pset.begin()) {
            cout << "-1\n" ;
        } else {
            cout << *prev(ubit) << "\n";
            pset.erase(prev(ubit));
        }
    }
}