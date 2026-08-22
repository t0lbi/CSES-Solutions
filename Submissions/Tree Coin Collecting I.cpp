// Submission Timestamp: 2026-05-19 01:30:45

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 200000;
int st[20][maxn];
int mi[20][maxn];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;cin>>n>>q;
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> c[i];
    c[i]--;
  }
  vector<vector<int>> arr(n);
  for (int i = 0; i < n-1; ++i)
  {
    int u, v;cin>>u>>v;
    arr[u-1].push_back(v-1);
    arr[v-1].push_back(u-1);
  }
  auto dfs = [&](int node, int lnode, auto&&rec)->void{
    for (auto it : arr[node]) if (it != lnode) {
      rec(it, node, rec);
      if (c[it] != -1) {
        if (c[node] == -1) c[node] = c[it]+1;
        c[node] = min(c[node], c[it]+1);
      }
    }
  };
  dfs(0,-1,dfs);
  vector<int> dept(n);
  auto dfs2 = [&](int node, int lnode, int x, auto&&rec)->void{
    st[0][node] = lnode;
    if (node) dept[node] = dept[lnode] + 1;
    if (x != -1) {
      if (c[node] == -1) c[node] = x;
      c[node] = min(c[node], x);
    }
    if (c[node] != -1) x = c[node];
    if (x != -1) x++;
    vector<int> v;
    for (auto it : arr[node]) if (it != lnode) {
      if (c[it] != -1) v.push_back(c[it]);
    }
    sort(v.rbegin(), v.rend());
    for (auto it : arr[node]) if (it != lnode) {
      int el = -1;
      if (v.size() > 0 && v[0] != c[it]) el = 0;
      else if (v.size() > 1) el = 1;
      int y = -1;
      if (x != -1) y = x;
      if (el != -1) {
        if (y == -1) y = v[el]+2;
        y = min(y, v[el]+2);
      }
      rec(it, node, y, rec);
    }
  };

  dfs2(0,-1,-1,dfs2);
  for (int i = 0; i < n; ++i)
  {
    mi[0][i] = c[i];
  }

  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < n; ++j) {
      st[i][j] = -1;
      if (st[i-1][j] == -1) {
        continue;
      }
      st[i][j] = st[i-1][st[i-1][j]];
      if (st[i][j] == -1) continue;
      mi[i][j] = min(mi[i-1][j], mi[i-1][st[i-1][j]]);
    }
  }


  auto kthpar = [&](int node, int k)->pair<int,int>{
    int ans = n;
    for (int i = 19; i >= 0; i--) {
      if ((k>>i)&1) {
        ans = min(ans, mi[i][node]);
        node = st[i][node];
      }
    }
    return {node, ans};
  };
  auto lca = [&](int a, int b)->int{
    if (dept[a] < dept[b]) swap(a, b);
    int k = dept[a] - dept[b];
    auto pr = kthpar(a, k);
    a = pr.first;
    int ans = pr.second;
    if (a == b) return min(ans, mi[0][a]) * 2 + k;
    for (int i = 19; i >= 0; i--) {
      if (st[i][a] == st[i][b]) continue;
      k += 2<<i;
      ans = min(ans, mi[i][a]);
      ans = min(ans, mi[i][b]);
      a = st[i][a];
      b = st[i][b];
    }
    return k+2+min({ans, mi[0][a], mi[0][b], mi[0][st[0][a]]})*2;
  };
  while (q--) {
    int a, b;cin>>a>>b;
    cout << lca(a-1, b-1) << '\n';
  }
}