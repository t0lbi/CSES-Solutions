// Submission Timestamp: 2026-05-27 02:24:05

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 1005;
int mul(int a, int b) {
  return (a * b) % MOD;
}
int sum(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}
int dp[maxn][maxn][3];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  dp[1][1][2] = 1;
  for (int i = 1; i < n; i++) {
    for (int c = 1; c <= i; c++) {
      for (int f = 0; f < 3; f++) {
        dp[i+1][c+1][2] = sum(dp[i+1][c+1][2], dp[i][c][f]);
        dp[i+1][c][1] = sum(dp[i+1][c][1], mul(dp[i][c][f], c*2-f));
        if (c > 1) {
          if (f == 0) {
            dp[i+1][c-1][0] = sum(dp[i+1][c-1][0], mul(dp[i][c][f], c*(c-1)));
          }
          if (f == 1) {
            dp[i+1][c-1][0] = sum(dp[i+1][c-1][0], mul(dp[i][c][f], (c-1) * (c-1)));
          }
          if (f == 2) {
            dp[i+1][c-1][0] = sum(dp[i+1][c-1][0], mul(dp[i][c][f], (c-1)*(c-2)));
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans = sum(ans, dp[n][1][i]);
  }
  cout << ans << '\n';
}