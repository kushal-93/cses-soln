#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int curr_sum = 0, max_sum = INT_MIN, min_sum = 0;
    
    for(int i=0; i<n; i++) {
        long long int a;
        cin >> a;
        curr_sum += a;
        max_sum = max(max_sum, curr_sum-min_sum);
        min_sum = min(min_sum, curr_sum);
    }
    cout << max_sum;
}