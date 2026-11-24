#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    long long val = 1;
    for (int i=0;i<n;i++) {
        if (arr[i] > val) {
            break;
        } 
        val += arr[i];
    }

    cout << val;

}