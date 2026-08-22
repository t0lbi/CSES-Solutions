// Submission Timestamp: 2026-05-06 20:14:30

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int l = 1, r = 1000000000;
  while (l < r) {
    int m = l + r >> 1;
    cout << "? " << m << endl;
    string x;cin>>x;
    if (x == "YES") {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << "! " << l << endl;
}