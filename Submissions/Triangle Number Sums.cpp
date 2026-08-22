// Submission Timestamp: 2026-04-04 20:06:13

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int cur = 0;
  vector<int> v;
  for (int i = 1; i <= 2000000; i++) {
    cur += i;
    if (cur > 1000000000000ll) break;
    v.push_back(cur);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    int ans = 3;
    int ptr = v.size() - 1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > n) break;
      if (v[i] == n) {
        ans = 1;
        break;
      }
      while (ptr >= 0 && v[i] + v[ptr] > n) ptr--;
      if (ptr >= 0 && v[i] + v[ptr] == n) ans = 2;
    }
    cout << ans << '\n';
  }
}