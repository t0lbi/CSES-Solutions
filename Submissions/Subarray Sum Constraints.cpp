// Submission Timestamp: 2026-05-19 22:52:13

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<int> pref(n+1);
  vector<bool> vis(n+1);
  vector<vector<pair<int,int>>> arr(n+1);
  for (int i = 0; i < m; ++i)
  {
    int l, r, s;
    cin >> l >> r >> s;
    arr[l-1].push_back({r, s});
    arr[r].push_back({l-1,-s});
  }
  bool bb = true;
  auto dfs = [&](int node, int val, auto&&rec)->void{
    if (vis[node]) {
      if (val != pref[node]) {
        bb = false;
      }
      return;
    }
    vis[node] = true;
    pref[node] = val;
    for (auto [it, w] : arr[node]) {
      rec(it, val+w, rec);
    }
  };
  for (int i = 0; i <= n; ++i)
  {
    if (vis[i]) continue;
    dfs(i, 0, dfs);
  }
  if (bb) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << pref[i] - pref[i-1] << ' ';
    }
    cout << '\n';
  } else cout << "NO\n";
}