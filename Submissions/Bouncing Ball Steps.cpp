// Submission Timestamp: 2026-05-23 01:01:20

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  if (cin>>t) {
    while (t--) {
      int n, m, x;
      cin >> n >> m >> x;
      int a = x/(n-1);
      int b = x/(m-1);
      if (a % 2 == 0) {
        cout << 1 + (x % (n-1)) << ' ';
      } else {
        cout << n - (x % (n-1)) << ' ';
      }
      if (b % 2 == 0) {
        cout << 1 + (x % (m-1)) << ' ';
      } else {
        cout << m - (x % (m-1)) << ' ';
      }
      int c = a + b;
      int lcm = (n-1) * (m-1) / gcd(n-1, m-1);
      c -= x / lcm;
      cout << c << '\n';
    }
  }
}