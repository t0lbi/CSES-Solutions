// Submission Timestamp: 2026-06-05 14:40:54

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 5000;
int fac[maxn+1], ifac[maxn+1];
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
  for (int i = 1; i <= maxn; i++) {
    fac[i] = mul(i, fac[i-1]);
    ifac[i] = fpow(fac[i], MOD-2);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string S;cin>>S;
  int n = S.length();
  vector<int> freq(26);
  for (auto c : S) {
    freq[c-'a']++;
  }
  vector<int> dp(n+1,0);
  dp[0] = 1;
  int s = 0;
  for (auto c : freq) {
    if (c == 0) continue;
    vector<int> ndp(n+1,0);
    for (int y = 1; y <= c; y++) {
      for (int x = 0; x<=s && (s==0 || x <= s-1); x++) {
        if (s > 0 && x == s) continue;
        ndp[x+c-y] = sum(ndp[x+c-y],mul(
          C(s-x+y,y),
          C(c-1,c-y),
          dp[x]
        ));
      }
    }
    s += c;
    swap(dp, ndp);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = sum(ans, mul(dp[i], i&1?MOD-1:1));
  }
  cout<<ans<<'\n';
}