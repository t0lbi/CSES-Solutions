// Submission Timestamp: 2026-05-26 17:42:15

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
int fac[maxn+1], ifac[maxn+1];
int nCr(int n, int r) {
  return mul(fac[n], mul(ifac[r], ifac[n-r]));
}
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow & 1) {
      rval = mul(rval, base);
    }
    pow>>=1;
    base = mul(base, base);
  }
  return rval;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    fac[i] = mul(fac[i-1], i);
  }
  ifac[maxn] = fpow(fac[maxn], MOD-2);
  for (int i = maxn-1; i >= 1; i--) {
    ifac[i] = mul(ifac[i+1], i+1);
  }
  int n, k;cin>>n>>k;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int c = mul(fpow(i, n), nCr(k, i));
    if ((i^k)&1) c = MOD - c;
    ans = sum(ans, c);
  }
  cout << ans << '\n';
}