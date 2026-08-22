// Submission Timestamp: 2026-05-19 19:05:25

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
typedef array<int,2> ROW;
typedef array<ROW,2> MAT;
MAT id;
MAT mul(MAT &a, MAT &b) {
  MAT c = MAT();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % MOD;
        if (c[i][j] >= MOD) c[i][j] -= MOD;
      }
    }
  }
  return c;
}
MAT pow(MAT base, int pow) {
  MAT rval = id;
  while (pow) {
    if (pow & 1) {
      rval = mul(rval, base);
    }
    pow >>= 1;
    base = mul(base, base);
  }
  return rval;
}
ROW mul(MAT a, ROW b) {
  int ret = 0;
  for (int i = 0; i < 2; i++) {
    int sum = 0;
    for (int j = 0; j < 2; j++) {
      sum += a[j][i];
      if (sum >= MOD) sum -= MOD;
    }
    b[i] = (b[i] * sum) % MOD;
  }
  return b;
}
int32_t main(){
  id[0][0] = id[1][1] = 1;
  id[0][1] = id[1][0] = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n, k;cin>>n>>k;
    vector<pair<int,int>> p;
    for (int i = 2; i * i <= k; i++) {
      if (k % i == 0) {
        p.push_back({i, 0});
        while (k % i == 0) {
          k /= i;
          p.back().second++;
        }
      }
    }
    if (k > 1) p.push_back({k, 1});
    int ans = 1;
    for (auto [_, w] : p) {
      MAT mt;
      mt[0][0] = 0;
      mt[0][1] = w;
      mt[1][0] = 1;
      mt[1][1] = 1;
      mt = pow(mt, n-1);
      ROW cur = {w, 1};
      cur = mul(mt, cur);
      ans = (ans * ((cur[0] + cur[1])%MOD))%MOD;
    }
    cout << ans << '\n';
  }
}