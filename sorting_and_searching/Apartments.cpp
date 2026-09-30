#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int d,a,k;
  cin >> d >> a >> k;
  map<int, int> m;
  int out = 0;

  for(int i=0;i<d;i++) {
    int x = 0;
    cin >> x;
    auto it = m.find(x);
    if (it != m.end()) {
      int v = it->second+1;
      m[it->first] = v;
    } else {
      m[x] = 1;
    }
  }
  int apts[a];
  for(int j=0; j<a; j++) {
    int y;
    cin >> apts[j];
  }

  sort(apts, apts+a);

  for(int j=0; j<a; j++) {
    int y = apts[j];
    auto it = m.lower_bound(y-k);
    if (it != m.end()) {
      if (it->first <= y+k) {
        int v = it->second-1;
        if (v > 0) {
          m[it->first] = v;
        } else {
          m.erase(it->first);
        }
        out++;
      }
    }
  }

  cout << out;

}
