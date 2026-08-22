// Submission Timestamp: 2026-05-24 21:51:03

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  vector<vector<int>> arr(n);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'o') arr[i].push_back(j);
    }
  }
  vector<int> mt(n,-1);
  vector<bool> vis;
  auto dfs = [&](int node, auto&rec)->int{
    if (vis[node]) return false;
    vis[node] = true;
    if (node >= n) {
      node -= n;
      if (mt[node] == -1) return true;
      bool ret = rec(mt[node], rec);
      if (ret) {
        mt[node] = -1;
      }
      return ret;
    } else {
      for (auto it : arr[node]) {
        if (rec(n+it, rec)) {
          mt[it] = node;
          return true;
        }
      }
      return false;
    }
  };
  for (int i = 0; i < n; ++i) {
    for (auto it : arr[i]) {
      vis.assign(2*n,false);
      if (dfs(n+it,dfs)) {
        mt[it] = i;
        break;
      }
    }
  }
  vis.assign(2*n,false);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    bool bb = false;
    for (auto it : arr[i]) if (mt[it] == i) bb = true;
    if (!bb) q.push(i);
  }
  while (q.size()) {
    int node = q.front();
    q.pop();
    if (vis[node]) continue;
    vis[node] = true;
    if (node >= n && mt[node-n] != -1) q.push(mt[node-n]);
    else {
      for (auto it : arr[node]) {
        if (mt[it] != node) q.push(it+n);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (mt[i] != -1) ans++;
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (mt[i] != -1 && vis[i+n]) cout << "2 " << i + 1 << '\n';
    bool bb = false;
    for (auto it : arr[i]) if (mt[it] == i) bb = true;
    if (bb && !vis[i]) cout << "1 " << i+1 << '\n';
  }
}