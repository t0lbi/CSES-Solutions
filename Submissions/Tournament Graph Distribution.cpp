// Submission Timestamp: 2026-06-05 15:13:10

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 500;
int fac[maxn+1], ifac[maxn+1];
int fp[maxn*maxn+1];
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
int P(int n, int r) {
  return mul(fac[n], ifac[n-r]);
}
int C(int n, int r) {
  return mul(fac[n], ifac[r], ifac[n-r]);
}
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow&1) rval = mul(rval, base);
    base = mul(base, base);
    pow>>=1;
  }
  return rval;
}
int32_t main(){
  fac[0] = ifac[0] = 1;
  fp[0] = 1;
  for (int i = 1; i <= maxn*maxn; i++) {
    fp[i] = mul(fp[i-1], 2);
  }
  for (int i = 1; i <= maxn; i++) {
    fac[i] = mul(i, fac[i-1]);
    ifac[i] = fpow(fac[i], MOD-2);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][1]=fp[i*(i-1)/2];
    for (int j = 1; j < i; j++) {
      for (int k = 1; k <= i-j; k++) {
        dp[i][k+1] = sum(dp[i][k+1], mul(
          C(i,j),
          dp[j][1],
          dp[i-j][k]
          ));
      }
    }
    for (int j = 2; j <= i; j++) {
      dp[i][1] = sum(dp[i][1], mul(dp[i][j], MOD-1));
    }
  }
  for (int i = 1; i <= n; i++) {
    cout<<dp[n][i]<<'\n';
  }
}