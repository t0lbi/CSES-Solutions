// Submission Timestamp: 2026-04-05 17:54:44

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 2e6;
int say[MAXN<<2];
int val[MAXN<<2];
int mn[MAXN<<2];
void build(int l=0, int r=MAXN, int x=0) {
  say[x] = r - l + 1;
  if (l < r) {
    int m = l + r >> 1;
    build(l, m, x * 2 + 1);
    build(m+1, r, x * 2 + 2);
  }
}
void upd(int tl, int tr, int v, int l=0, int r=MAXN, int x=0) {
  if (l >= tl && r <= tr) {
    val[x] += v;
    mn[x] += v;
    return;
  }
  if (l > tr || r < tl) return;
  int m = l + r >> 1;
  if (tl <= m) upd(tl, tr, v, l, m, x * 2 + 1);
  if (m < tr) upd(tl, tr, v, m+1, r, x * 2 + 2);
  mn[x] = min(mn[x*2+1], mn[x*2+2])+val[x];
  if (mn[x*2+1] == mn[x*2+2]) say[x] = say[x*2+1]+say[x*2+2];
  else if (mn[x*2+1] < mn[x*2+2]) say[x] = say[x*2+1];
  else say[x] = say[x*2+2];
  //merge
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<array<int,4>> v;
  for (int i = 0; i < n; ++i)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    y1+=1e6;
    y2+=1e6;
    v.push_back({x1, y1, y2-1, 1});
    v.push_back({x2, y1, y2-1,-1});
  }
  build();
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i + 1 < v.size(); i++) {
    upd(v[i][1], v[i][2], v[i][3]);
    ans += (MAXN+1 - say[0])*(v[i+1][0]-v[i][0]);
  }
  cout << ans << '\n';
}