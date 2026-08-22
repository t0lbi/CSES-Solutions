// Submission Timestamp: 2026-05-14 21:21:16

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e5;
constexpr int mx = 1e7;
typedef array<int,2> Line;
Line lc[mx];
int lnode[mx], rnode[mx];
int ind;
int create(){
  lc[ind] = {0, LONG_LONG_MIN};
  lnode[ind] = rnode[ind] = -1;
  return ind++;
}
int f(Line &ln, int x) {
  return ln[0] * x + ln[1];
}
struct LiChao{
  int root;
  LiChao(){
    root = create();
  }
  void upd(Line v, int l=0, int r=maxn, int node=-1) {
    if (node == -1) node = root;
    int m = l + r >> 1;
    if (f(v, m) > f(lc[node], m)) {
      swap(v, lc[node]);
    }
    if (f(v, l) <= f(lc[node], l) && f(v, r) <= f(lc[node], r)) return;
    if (l < r) {
      if (lc[node][0] > v[0]) {
        if (lnode[node] == -1) lnode[node] = create();
        upd(v, l, m, lnode[node]);
      } else {
        if (rnode[node] == -1) rnode[node] = create();
        upd(v, m+1, r, rnode[node]);
      }
    }
  }
  int query(int x) {
    int l = 0, r = maxn, node = root;
    int ans = LONG_LONG_MIN;
    while (l < r) {
      if (node == -1) break;
      int m = l + r >> 1;
      ans = max(ans, f(lc[node], x));
      if (x <= m) {
        r = m;
        node = lnode[node];
      } else {
        l = m + 1;
        node = rnode[node];
      }
    }
    return ans;
  }
};
vector<LiChao> seg;
void upd(int tl, int tr, Line f, int l, int r, int x) {
  if (l >= tl && r <= tr) {
    seg[x].upd(f);
    return;
  }
  if (l > tr || r < tl) return;
  int m = l + r >> 1;
  upd(tl, tr, f, l, m, x * 2 + 1);
  upd(tl, tr, f, m+1, r, x * 2 + 2);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  seg.resize((maxn<<2) + 10);
  int n;cin>>n;
  while (n--) {
    int ty;cin>>ty;
    if (ty == 1) {
      int a, b, l, r;cin>>a>>b>>l>>r;
      upd(l,r,{a,b},0,maxn,0);
    } else {
      int x;cin>>x;
      int l = 0, r = maxn;
      int v = 0;
      int ans = LONG_LONG_MIN;
      while (l < r) {
        int m = l + r >> 1;
        ans = max(ans, seg[v].query(x));
        if (x <= m) {
          r = m;
          v = v * 2 + 1;
        } else {
          l = m + 1;
          v = v * 2 + 2;
        }
      }
      ans = max(ans, seg[v].query(x));
      if (ans == LONG_LONG_MIN) {
        cout << "NO\n";
      } else cout << ans << '\n';
    }
  }
}