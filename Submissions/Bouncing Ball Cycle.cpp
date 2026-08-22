// Submission Timestamp: 2026-06-05 20:54:04

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  if (cin>>t) {
    while (t--) {
      int a, b;cin>>a>>b;
      cout << (a*2-2) * (b*2-2) / gcd(a*2-2,b*2-2) << ' ';
      int l = gcd(a-1, b-1);
      if (l == 1) {
        cout << a * b / 2 << '\n';
      } else {
        int h = (a-1)/l;
        int w = (b-1)/l;
        if (w % 2 == 1) swap(h, w);
        cout << w * h * (l-1) + (h+1)/2 * (w+1) << '\n';
      }
    }
  }
}