// Submission Timestamp: 2026-02-26 05:40:11

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int BL = 400;
constexpr int N = 2e5;
int32_t main(){
  int blok[N+BL+1]={},mini[N+BL+1]={},bl[N+BL+1]={};
  auto get = [&](int x)->int{
    if (x >= BL) return mini[x] + blok[x/BL-1];
    return mini[x];
  };
  auto query = [&](int l, int r)->int{
    if (l) return get(r) - get(l-1);
    return get(r);
  };
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;cin>>n>>q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  vector<int> u = a;
  vector<pair<int,int>> pr(q);
  for (int i = 0; i < q; ++i)
  {
    cin >> pr[i].first >> pr[i].second;
    pr[i].first--, pr[i].second--;
  }
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  int m = u.size();
  vector<int> ans(q);
  vector<vector<int>> cur(m+1);
  for (int i = 0; i < q; ++i)
  {
    cur[0].push_back(i);
  }
  vector<vector<int>> poses(m);
  for (int i = 0; i < n; ++i)
  {
    poses[lower_bound(u.begin(),u.end(),a[i])-u.begin()].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    for (auto it : cur[i]) {
      int somma = query(pr[it].first, pr[it].second);
      if (somma + 1 < u[i]) {
        ans[it] = somma + 1;
      } else {
        cur[lower_bound(u.begin(), u.end(), somma+2)-u.begin()].push_back(it);
      }
    }
    for (auto it : poses[i]) {
      bl[it/BL]+=u[i];
      for (int _i = it; _i / BL == it / BL; _i++) {
        mini[_i]+=u[i];
      }
    }
    blok[0] = bl[0];
    for (int j = 1; j < N/BL; j++) {
      blok[j] = bl[j] + blok[j-1];
    }
  }
  for (auto it : cur[m]) {
    ans[it] = query(pr[it].first, pr[it].second) + 1;
  }
  for (auto it : ans) cout << it << '\n';
}