#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ll[n];
    for (int i=0;i<n; i++) {
        cin >> ll[i];
    }

    sort(ll, ll + n);
    int mid = ll[n/2];
    long long cost = 0;

    for (int i=0;i<n;i++) {
        cost += abs(ll[i]-mid);
    }
    cout << cost;
}