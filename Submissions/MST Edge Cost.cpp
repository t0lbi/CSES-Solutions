// Submission Timestamp: 2026-05-14 12:06:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[100000][20], ma[100000][20];
vector<int> par;
int find(int node) {
  if (par[node] == node) return node;
  return par[node] = find(par[node]);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<array<int,3>> ed(m);
  for (int i = 0; i < m; ++i)
  {
    cin>>ed[i][1]>>ed[i][2]>>ed[i][0];
    ed[i][1]--,ed[i][2]--;
  }
  vector<array<int,3>> orig_ed = ed;
  vector<vector<pair<int,int>>> tree(n);
  sort(ed.begin(), ed.end());
  par.resize(n);
  iota(par.begin(), par.end(), 0);
  int ans = 0;
  for (int i = 0; i < m; ++i)
  {
    int a = find(ed[i][1]);
    int b = find(ed[i][2]);
    if (a == b) continue;
    par[a] = b;
    ans += ed[i][0];
    tree[ed[i][1]].push_back({ed[i][2],ed[i][0]});
    tree[ed[i][2]].push_back({ed[i][1],ed[i][0]});
  }
  vector<int> dept(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      ma[i][j] = st[i][j] = -1;
    }
  }
  auto dfs = [&](int node, int lnode, auto &&dfs)->void{
    for (auto [c, w] : tree[node]) if (c != lnode) {
      st[c][0] = node;
      ma[c][0] = w;
      dept[c] = dept[node] + 1;
      dfs(c, node, dfs);
    }
  };
  dfs(0,-1,dfs);
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      if (st[i][j-1] == -1) continue;
      st[i][j] = st[st[i][j-1]][j-1];
      if (st[i][j] == -1) continue;
      ma[i][j] = max(ma[i][j-1], ma[st[i][j-1]][j-1]);
    }
  }

  auto kthpar = [&](int node, int k)->pair<int,int>{
    int ret = 0;
    for (int i = 19; i >= 0; i--) {
      if ((k>>i)&1) {
        ret = max(ret, ma[node][i]);
        node = st[node][i];
      }
    }
    return {node, ret};
  };
  auto lca = [&](int a, int b)->int{
    if (dept[a] > dept[b]) swap(a, b);
    auto cur = kthpar(b, dept[b] - dept[a]);
    b = cur.first;
    int ret = cur.second;
    if (a == b) return ret;
    for (int i = 19; i >= 0; i--) {
      if (st[a][i] == st[b][i]) continue;
      ret = max(ret, ma[a][i]);
      ret = max(ret, ma[b][i]);
      a = st[a][i];
      b = st[b][i];
    }
    ret = max(ret, ma[a][0]);
    ret = max(ret, ma[b][0]);
    return ret;
  };
  for (int i = 0; i < m; i++) {
    cout << ans + orig_ed[i][0] - lca(orig_ed[i][1],orig_ed[i][2]) << '\n';
  }
}