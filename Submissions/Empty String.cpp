// Submission Timestamp: 2026-05-20 01:53:56

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int fac[500], ifac[500];
int nCr(int n, int r) {
  return (fac[n]*((ifac[r]*ifac[n-r])%MOD))%MOD;
}
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow & 1) {
      rval = (rval * base) % MOD;
    }
    pow >>= 1;
    base = (base * base) % MOD;
  }
  return rval;
}
int32_t main(){
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < 500; i++) {
    fac[i] = (fac[i-1] * i) % MOD;
    ifac[i] = fpow(fac[i], MOD - 2);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  int n = s.length();
  vector<vector<int>> dp(n,vector<int>(n,0));
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == s[i+1]) dp[i][i+1] = 1;
  }
  for (int sz = 3; sz <= n; sz++) {
    for (int l=0,r=sz-1; r < n; l++,r++) {
      for (int m = l+1; m <= r; m+=2) {
        if (s[l] != s[m]) continue;
        int cur = 1;
        int ham1 = ((m-1)-(l+1)+1)/2+1;
        int ham2 = (r-(m+1)+1)/2;
        if (m-1 >= l+1) cur = dp[l+1][m-1];
        else ham1 = 1;
        if (m+1 <= r) cur = (cur * dp[m+1][r])%MOD;
        else ham2 = 0;
        if (cur == 0) continue;
        cur = (cur * nCr(ham1+ham2,ham1)) % MOD;
        dp[l][r] += cur;
        if (dp[l][r] >= MOD) dp[l][r] -= MOD;
      }
    }
  }
  cout << dp[0][n-1] << '\n';
}