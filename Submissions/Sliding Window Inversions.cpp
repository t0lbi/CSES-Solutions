// Submission Timestamp: 2026-05-06 14:17:22

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 200000;
int fenwik[N];
void upd(int x, int v) {
  for (; x < N; x |= x + 1) fenwik[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) ret += fenwik[x];
    return ret;
}
int query(int l, int r) {
  return get(r) - get(l - 1);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  vector<int> s = v;
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i = 0; i < n; i++) {
    v[i] = lower_bound(s.begin(), s.end(), v[i]) - s.begin();
  }
  int ans = 0;
  int lim = s.size()-1;
  for (int i = 0; i < k; i++) {
    ans += query(v[i]+1, lim);
    upd(v[i], 1);
  }
  for (int i = 0; i + k - 1 < n; i++) {
    cout << ans << ' ';
    ans -= query(0, v[i]-1);
    upd(v[i], -1);
    if (i + k < n) {
      upd(v[i+k], 1);
      ans += query(v[i+k]+1, lim);
    }
  }
  cout << '\n';
}