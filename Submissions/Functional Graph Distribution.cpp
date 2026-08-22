// Submission Timestamp: 2026-06-05 19:10:54

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 5000;
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
  vector<vector<int>> S(n+1, vector<int>(n+1, 0));
  S[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    S[i][1] = fac[i-1];
    for (int j = 2; j <= i; j++) {
      S[i][j] = sum(S[i-1][j-1],mul(i-1,S[i-1][j]));
    }
  }
  int fp[maxn+1];
  fp[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    fp[i] = mul(n, fp[i-1]);
  }
  for (int k = 1; k <= n; k++) {
    int ans = S[n][k];
    for (int i = k; i < n; i++) {
      ans = sum(ans, mul(
        C(n,i),
        S[i][k],
        fp[n-i-1],
        i
      ));
    }
    cout << ans << '\n';
  }
}