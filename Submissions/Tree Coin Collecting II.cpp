// Submission Timestamp: 2026-06-03 23:42:40

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int LG = 20;
constexpr int maxn = 2e5;
int st[LG][maxn];
int st1[LG][maxn];
int val[LG][maxn];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;cin>>n>>q;
  vector<int> dp(n);
  vector<int> subdp(n);
  vector<int> subcnt(n);
  vector<int> dept(n);
  vector<vector<int>> a(n);
  vector<int> c(n);
  int tot = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> c[i];
    tot += c[i];
  }
  for (int i = 0; i < n-1; ++i)
  {
    int u, v;cin>>u>>v;
    a[u-1].push_back(v-1);
    a[v-1].push_back(u-1);
  }
  auto dfs1 = [&](int node, int lnode, auto&&rec)->void{
    st[0][node] = lnode;
    if (c[node] == 1) subcnt[node]=1;
    for (auto it : a[node]) if (it != lnode) {
      dept[it] = dept[node] + 1;
      rec(it, node, rec);
      subcnt[node] += subcnt[it];
      subdp[node] += subdp[it] + (subcnt[it] != 0) * 2;
    }
  };
  dfs1(0,-1,dfs1);
  auto dfs2 = [&](int node, int lnode, auto&&rec)->void{
    if (tot == subcnt[node]) {
      dp[node] = dp[lnode] - 2;
    } else if (subcnt[node] == 0){
      dp[node] = dp[lnode] + 2;
    } else {
      dp[node] = dp[lnode];
    }
    for (auto it : a[node]) if (it != lnode) {
      rec(it, node, rec);
    }
  };
  dp[0]=subdp[0];
  for (auto it : a[0]) {
    dfs2(it,0,dfs2);
  }
  for (int i = 0; i < n; i++) {
    val[0][i] = subdp[i];
    st1[0][i] = i;
  }
  for (int i = 1; i < LG; i++) {
    for (int j = 0; j < n; j++) {
      st[i][j] = -1;
      if (st1[i-1][j] != -1) {
        st1[i][j] = st[i-1][st1[i-1][j]];
      } else st1[i][j] = -1;
      if (st[i-1][j] == -1) continue;
      st[i][j] = st[i-1][st[i-1][j]];
      if (st[i][j] == -1) continue;
      val[i][j] = val[i-1][j] + val[i-1][st[i-1][j]];
      val[i][j] -= subdp[st1[i-1][j]] + (subcnt[st1[i-1][j]] != 0)*2;
    }
  }
  auto kthpar = [&](int node, int k)->pair<int,int>{
    int ret = 0;
    for (int i = LG-1; i >= 0; i--) {
      if ((k>>i)&1) {
        ret += val[i][node];
        int last = st1[i][node];
        ret -= subdp[last] + (subcnt[last] != 0) * 2;
        node = st[i][node];
      }
    }
    return {node, ret};
  };
  auto lca = [&](int a, int b)->int{
    if (dept[a] < dept[b]) swap(a, b);
    a = kthpar(a,dept[a]-dept[b]).first;
    if (a == b) return a;
    for (int i = LG-1; i >= 0; i--) {
      if (st[i][a] != st[i][b]) {
        a = st[i][a];
        b = st[i][b];
      }
    }
    return st[0][a];
  };
  while (q--) {
    int a, b;cin>>a>>b;a--,b--;
    int c = lca(a, b);
    int ans = dp[c];
    if (a != c) {
      ans += kthpar(a, dept[a]-dept[c]).second;
    }
    if (b != c) {
      ans += kthpar(b, dept[b]-dept[c]).second;
    }
    cout << ans + dept[a] + dept[b] - 2 * dept[c] << '\n';
  }
}