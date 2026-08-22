// Submission Timestamp: 2026-05-17 18:16:55

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5;
constexpr int mx = 2e7;
typedef array<int,2> Line;
Line lc[maxn<<2];
vector<pair<int,Line>> history;
void undo(int x) {
  while (history.size() > x) {
    lc[history.back().first] = history.back().second;
    history.pop_back();
  }
}
int ind;
int f(Line &ln, int x) {
  return ln[0] * x + ln[1];
}
void update(Line v, int l=0, int r=maxn, int node=0) {
  int m = l + r >> 1;
  if (f(v, m) > f(lc[node], m)) {
    history.push_back({node,lc[node]});
    swap(v, lc[node]);
  }
  if (f(v, l) <= f(lc[node], l) && f(v, r) <= f(lc[node], r)) return;
  if (l < r) {
    if (lc[node][0] > v[0]) {
      update(v, l, m, node * 2 + 1);
    } else {
      update(v, m+1, r, node * 2 + 2);
    }
  }
}
int query(int x) {
  int l = 0, r = maxn, node = 0;
  int ans = LONG_LONG_MIN;
  while (l < r) {
    if (node == -1) break;
    int m = l + r >> 1;
    ans = max(ans, f(lc[node], x));
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
vector<Line> seg[maxn<<2];
void upd(int tl, int tr, Line &f, int l, int r, int x) {
  if (l >= tl && r <= tr) {
    seg[x].push_back(f);
    return;
  }
  if (l > tr || r < tl) return;
  int m = l + r >> 1;
  upd(tl, tr, f, l, m, x * 2 + 1);
  upd(tl, tr, f, m+1, r, x * 2 + 2);
}
vector<int> solve(vector<array<int,4>> &v, int n) {
  for (auto it : v) {
    array<int,2> vv = {it[2],it[3]};
    upd(it[0], it[1], vv, 0, n-1, 0);
  }
  vector<int> ret;
  auto rec = [&](int l, int r, int x, auto&&rec)->void{
    int sz = history.size();
    for (auto it : seg[x]) {
      update(it);
    }
    if (l == r) {
      ret.push_back(query(l));
    } else {
      int m = l + r >> 1;
      rec(l, m, x * 2 + 1, rec);
      rec(m+1, r, x * 2 + 2, rec);
    }
    undo(sz);
  };
  rec(0,n-1,0,rec);
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<int> a(n);
  vector<pair<int,int>> p(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    p[i] = {a[i], i};
  }
  set<int> st;
  for (int i = -1; i <= n; i++) {
    st.insert(i);
  }
  sort(p.rbegin(), p.rend());
  vector<array<int,4>> v;
  vector<pair<int,int>> u;
  for (auto [w, i] : p) {
    st.erase(st.find(i));
    auto lb = st.lower_bound(i);
    int r = *lb - 1;
    lb--;
    int l = *lb + 1;
    int fl = min(k, r-l+1);
    int bos = k - fl;
    int lp = l - bos;
    int rp = r - fl + 1;
    if (lp < 0) lp = 0;
    u.push_back({lp, fl*w});
    u.push_back({rp+1,-fl*w});
    v.push_back({rp, n-1, -w, fl*w+rp*w});
    v.push_back({0, lp, w, fl*w-lp*w});
  }
  vector<int> ans = solve(v, n - k + 1);
  sort(u.begin(), u.end());
  priority_queue<int> pq;
  priority_queue<int> sil;
  int ind = 0;
  for (int i = 0; i < n - k + 1; i++) {
    while (ind < u.size() && u[ind].first <= i) {
      if (u[ind].second > 0) {
        pq.push(u[ind].second);
      } else {
        sil.push(-u[ind].second);
      }
      ind++;
    }
    while (pq.size() && sil.size() && pq.top() == sil.top()) {
      pq.pop();
      sil.pop();
    }
    if (pq.size()) ans[i] = max(ans[i], pq.top());
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}