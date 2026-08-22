// Submission Timestamp: 2026-04-01 17:36:19

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  int fac[21];
  fac[0] = 1;
  for (int i = 1; i <= 20; i++) {
    fac[i] = (fac[i-1] * i);
  }
  if (cin>>t) {
    while (t--){
      int ty, n;cin>>ty>>n;
      if (ty == 1) {
        int k;cin>>k;k--;
        vector<int> ans;
        auto solve = [&](int x, int y, auto&&rec)->void{
          if (x == 1) {
            ans.push_back(1);
            return;
          }
          rec(x-1, y % fac[x-1], rec);
          int pl = y / fac[x-1];
          for (auto &it : ans) {
            if (it >= pl + 1) it++;
          }
          ans.push_back(pl + 1);
        };
        solve(n, k, solve);
        reverse(ans.begin(), ans.end());
        for (auto it : ans) {
          cout << it << ' ';
        }
        cout << '\n';
      } else {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
        }
        int k = 0;
        for (int i = 0; i + 1 < n; ++i) {
          k += fac[n-i-1] * (a[i]-1);
          for (int j = i + 1; j < n; ++j) {
            if (a[j] >= a[i]) a[j]--;
          }
        }
        cout << k + 1 << '\n';
      }
    }
  }
}