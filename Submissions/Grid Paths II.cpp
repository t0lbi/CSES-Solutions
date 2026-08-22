// Submission Timestamp: 2026-05-26 18:13:17

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 2e6;
int mul(int a, int b) {
  return (a * b) % MOD;
}
int sum(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}
int sub(int a, int b) {
  if (a < b) return a - b + MOD;
  return a - b;
}
int fac[maxn+1], ifac[maxn+1];
int nCr(int n, int r) {
  if (n < 0 || r < 0 || r > n) return 0;
  return mul(fac[n], mul(ifac[r], ifac[n-r]));
}
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow & 1) {
      rval = mul(rval, base);
    }
    pow >>= 1;
    base = mul(base, base);
  }
  return rval;
}
int32_t main(){
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    fac[i] = mul(fac[i-1], i);
  }
  ifac[maxn] = fpow(fac[maxn], MOD-2);
  for (int i = maxn-1; i >= 1; i--) {
    ifac[i] = mul(ifac[i+1], i+1);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<array<int,2>> pts(m);
  for (int i = 0; i < m; ++i)
  {
    cin >> pts[i][0] >> pts[i][1];
  }
  sort(pts.begin(), pts.end());
  vector<int> dp(m);
  int ans = nCr(n*2-2, n-1);
  for (int i = 0; i < m; i++) {
    dp[i] = nCr(pts[i][0]+pts[i][1]-2, pts[i][0]-1);
    for (int j = 0; j < i; j++) {
      int cur = mul(
        dp[j],
        nCr(pts[i][0]-pts[j][0]+pts[i][1]-pts[j][1], pts[i][0] - pts[j][0])
      );
      dp[i] = sub(dp[i], cur);
    }
    ans = sub(ans, mul(
      dp[i],
      nCr(n*2-pts[i][0]-pts[i][1],n-pts[i][0])
    ));
  }
  cout << ans << '\n';
}