// Submission Timestamp: 2026-05-07 23:40:42

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define coutarr(x) for (auto it : x) cout << it << ' ';cout<<'\n';
constexpr int MOD = 1e9+7;
constexpr int i2 = 5e8+4;
vector<int> mul(vector<int> a, vector<int> b) {
  int n = a.size() / 2;
  if (n == 0) return {(a[0]*b[0])%MOD};
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; ++i)
  {
    l[i] = a[i] + a[i+n];
    if (l[i] >= MOD) l[i] -= MOD;
    r[i] = b[i] + b[i+n];
    if (r[i] >= MOD) r[i] -= MOD;
  }
  vector<int> d0 = mul(l, r);
  for (int i = 0; i < n; ++i) {
    l[i] = a[i] - a[i+n];
    if (l[i] < 0) l[i] += MOD;
    r[i] = b[i] - b[i+n];
    if (r[i] < 0) r[i] += MOD;
  }
  vector<int> d1 = mul(l, r);
  vector<int> ret(n * 2);
  for (int i = 0; i < n; i++) {
    ret[i] = ((d0[i] + d1[i]) * i2)%MOD;
    ret[i+n] = d0[i] - ret[i];
    if (ret[i+n] < 0) ret[i+n] += MOD;
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(1<<20, 0);
  int x = 0;
  a[x]++;
  for (int i = 0; i < n; i++) {
    int y;cin>>y;
    x ^= y;
    a[x]++;
  }
  vector<int> ans = mul(a, a);
  ans[0] -= n + 1;
  vector<int> pr;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i]) pr.push_back(i);
  }
  cout << pr.size() << '\n';
  coutarr(pr);
}