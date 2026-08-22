// Submission Timestamp: 2026-05-31 14:25:32

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5005;
constexpr int MOD = 1e9+7;
int mul(int a, int b) {
  return (1ll * a * b) % MOD;
}
int sum(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow & 1) rval = mul(rval, base);
    pow >>= 1;
    base = mul(base, base);
  }
  return rval;
}
int fac[maxn], ifac[maxn];
int dp[maxn][maxn];
int nCr(int n, int r) {
  return mul(fac[n], mul(ifac[r], ifac[n-r]));
}
int main(){
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = mul(fac[i-1], i);
    ifac[i] = fpow(fac[i], MOD - 2);
  }
  dp[2][1] = 1;
  for (int n = 3; n < maxn; n++) {
    for (int x = 1; x < n; x++) {
      dp[n][x] = sum(dp[n][x], mul(dp[n-1][x], x));
      if (x > 1) {
        dp[n][x] = sum(dp[n][x], mul(dp[n-1][x-1], n-x));
      }
      dp[n][x] = sum(dp[n][x], mul(n-1, dp[n-2][x-1]));
    }
  }
  dp[0][0] = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  if (cin>>t) {
    while (t--) {
      int n, a, b;
      cin >> n >> a >> b;
      if (n < a + b) {
        cout << 0 << '\n';
      } else {
        int c = n - a - b;
        cout << mul(mul(fac[n], nCr(n, c)), dp[a+b][a]) << '\n';
      }
    }
  }
}