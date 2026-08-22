// Submission Timestamp: 2026-06-05 15:51:55

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int mul(int a) {
  return a;
}
template<typename ...T> int mul(int a, T... tail) {
return (a * mul(tail...)) % MOD;
}
int sum(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<vector<int>> dp(n+1,vector<int>(n+1));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = mul(dp[i-1][j], j+1);
      if (j>0) dp[i][j] = sum(dp[i][j], mul(dp[i-1][j-1], i-j+1));
    }
  }
  for (int i = 0; i < n; i++) {
    cout<<dp[n-1][i]<<'\n';
  }
}