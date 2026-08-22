// Submission Timestamp: 2026-04-04 22:27:28

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 1e5;
typedef array<int,2> Line;
Line seg[MAXN<<2];
vector<pair<Line&, Line>> history;
int f(Line &ln, int x) {
  return ln[0] * x + ln[1];
}
void upd(Line v, int l=0, int r=MAXN, int node=0) {
  int m = l + r >> 1;
  if (f(v, m) > f(seg[node], m)) {
    history.push_back({seg[node], seg[node]});
    Line c = v;
    v = seg[node];
    seg[node] = c;
  }
  if (l < r) {
    if (seg[node][0] > v[0]) {
      upd(v, l, m, node * 2 + 1);
    } else upd(v, m+1, r, node * 2 + 2);
  }
}
int query(int x) {
  int l = 0, r = MAXN, node = 0;
  int ans = -1;
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
 
 
vector<Line> events[MAXN<<2];
void push_event(int tl, int tr, Line event, int l, int r, int node) {
  if (l >= tl && r <= tr) {
    events[node].push_back(event);
    return;
  }
  if (l > tr || r < tl) return;
  int m = l + r >> 1;
  push_event(tl, tr, event, l, m, node * 2 + 1);
  push_event(tl, tr, event, m+1, r, node * 2 + 2);
}
vector<int> ans;
void solve(int l, int r, int node = 0) {
  int sz = history.size();
  for (auto ev : events[node]) {
    upd(ev);
  }
  if (l == r) {
    ans.push_back(query(l));
  } else {
    int m = l + r >> 1;
    solve(l, m, node * 2 + 1);
    solve(m+1, r, node * 2 + 2);
  }
  while (history.size() > sz) {
    history.back().first = history.back().second;
    history.pop_back();
  }
}
int32_t main(){
  for (int i = 0; i < (MAXN<<2); ++i) {
    seg[i] = {0, -1};
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  for (int i = 0; i < n; ++i)
  {
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    Line cur = {(y2-y1)/(x2-x1), 0};
    cur[1] = y1-f(cur, x1);
    push_event(x1, x2, cur, 0, m, 0);
  }
  solve(0, m, 0);
  for (auto it : ans) cout << it << ' ';
  cout << '\n';
}