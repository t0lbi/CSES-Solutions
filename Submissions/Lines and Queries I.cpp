// Submission Timestamp: 2026-04-04 22:54:24

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 1e5;
typedef array<int,2> Line;
Line seg[MAXN<<2];
int f(Line &ln, int x) {
  return ln[0] * x + ln[1];
}
void upd(Line v, int l=0, int r=MAXN, int node=0) {
  int m = l + r >> 1;
  if (f(v, m) > f(seg[node], m)) {
    swap(v, seg[node]);
  }
  if (l < r) {
    if (seg[node][0] > v[0]) {
      upd(v, l, m, node * 2 + 1);
    } else upd(v, m+1, r, node * 2 + 2);
  }
}
int query(int x) {
  int l = 0, r = MAXN, node = 0;
  int ans = LONG_LONG_MIN;
  while (l < r) {
    int m = l + r >> 1;
    ans = max(ans, f(seg[node], x));
    if (x <= m) {
      r = m;
      node = node * 2 + 1;
    } else {
      l = m + 1;
      node = node * 2 + 2;
    }
  }
  return ans;
}
int32_t main(){
  for (int i = 0; i < (MAXN<<2); ++i) {
    seg[i] = {0, LONG_LONG_MIN};
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;cin>>q;
  while (q--) {
    int ty;cin>>ty;
    if (ty == 1) {
      int a, b;cin>>a>>b;
      upd({a, b});
    } else {
      int x;cin>>x;
      cout << query(x) << '\n';
    }
  }
}