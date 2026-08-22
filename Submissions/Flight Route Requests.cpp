// Submission Timestamp: 2026-05-19 03:25:23

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (par[node] == node) return node;
  return par[node] = find(par[node]);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<vector<int>> arr(n);
  vector<vector<int>> r_arr(n);
  par.resize(n);
  iota(par.begin(), par.end(), 0);
  for (int i = 0; i < m; ++i)
  {
    int a, b;cin>>a>>b;
    par[find(a-1)] = find(b-1);
    arr[a-1].push_back(b-1);
    r_arr[b-1].push_back(a-1);
  }

  vector<bool> vis(n, false);
  vector<int> eul;
  auto dfs = [&](int node, auto&&rec)->void{
    if (vis[node]) return;
    vis[node] = true;
    for (auto it : arr[node]) {
      rec(it, rec);
    }
    eul.push_back(node);
  };
  for (int i = 0; i < n; i++) {
    dfs(i, dfs);
  }
  vis.assign(n,false);
  int cur = 0;

  vector<int> scc(n);
  auto dfs2 = [&](int node, auto&&rec)->void{
    if (vis[node]) return;
    vis[node] = true;
    scc[node]=cur;
    for (auto it : r_arr[node]) {
      rec(it, rec);
    }
  };
  reverse(eul.begin(), eul.end());
  vector<int> uu;
  for (auto it : eul) {
    if (!vis[it]) {
      uu.push_back(it);
      dfs2(it, dfs2);
      cur++;
    }
  }
  int comp = 0;
  map<int,int> mp;
  for (int i = 0; i < n; ++i)
  {
    mp[scc[i]]++;
    if (find(i) == i) comp++;
  }
  set<int> st;
  for (auto it : mp) {
    if (it.second > 1) st.insert(find(uu[it.first]));
  }
  cout << n - comp + st.size() << '\n';
}