// Submission Timestamp: 2026-05-20 01:11:51

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int a, b, c;cin >> a >> b >> c;
    if (c > a || c < 0) {
      cout << "NO\n";
      continue;
    }
    int u = gcd(a, b);
    if (c % u != 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}