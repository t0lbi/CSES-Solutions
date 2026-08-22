// Submission Timestamp: 2026-05-07 22:28:29

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int LIM = 10000;
constexpr int MOD = 1000000007;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;cin>>n>>x;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  vector<array<int,LIM+1>> dp(n);
  vector<array<int,LIM+1>> ndp(n);
  dp[0][0]=1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fill(ndp[j].begin(), ndp[j].end(), 0);
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= LIM; k++) {
        if (dp[j][k] == 0 || k - v[i] * j > x) continue;
        if (j + 1 < n && k + v[i] <= LIM) {
          ndp[j+1][k+v[i]]+=dp[j][k];
          if (ndp[j+1][k+v[i]] >= MOD) ndp[j+1][k+v[i]] -= MOD;
        }
        ndp[j][k] += (dp[j][k]*(j+1))%MOD;
        if (ndp[j][k] >= MOD) ndp[j][k] -= MOD;
        if (j > 0 && k - v[i] >= 0) {
          ndp[j-1][k-v[i]] += (dp[j][k] * j)%MOD;
          if (ndp[j-1][k-v[i]] >= MOD) ndp[j-1][k-v[i]] -= MOD;
        }
      }
    }
    swap(dp,ndp);
  }
  int ans = 0;
  for (int i = 0; i <= x; i++) {
    ans += dp[0][i];
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
}