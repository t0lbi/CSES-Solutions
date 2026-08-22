// Submission Timestamp: 2026-06-05 14:18:29

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
constexpr int maxn = 500;
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
  int n;cin>>n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  vector<int> p(n, -1), q(n, -1);
  vector<int> v1(n, -1), v2(n, -1);
  int s1 = 0, s2 = 0, c1 = 0, c2 = 0, f1 = 0, f2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'A') p[i] = j, v1[j]=i;
      if (a[i][j] == 'B') q[i] = j, v2[j]=i;
    }
    if (p[i] == -1) c1++;
    if (q[i] == -1) c2++;
  }
  for (int i = 0; i < n; ++i)
  {
    if (v1[i] == -1 && v2[i] == -1) s1++;
    if (p[i] == -1 && q[i] == -1) s2++;
  }
  for (int i = 0; i < n; i++) {
    if (v2[i]!=-1 && v1[i]==-1 && p[v2[i]]==-1) f1++;
    if (v1[i]!=-1 && v2[i]==-1 && q[v1[i]]==-1) f2++;
  }
  vector<int> dp(n+1, 0);
  for (int x = 0; x <= min(s1,s2); x++) {
    for (int y = 0; y <= f1; y++) {
      for (int z = 0; z <= f2; z++) {
        dp[x+y+z]=sum(dp[x+y+z],mul(
          C(s1,x),
          P(s2,x),
          C(f1,y),
          C(f2,z),
          fac[c1-x-y],
          fac[c2-x-z]
        ));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = sum(ans, mul(dp[i], i&1?MOD-1:1));
  }
  cout << ans << '\n';
}