// Submission Timestamp: 2026-06-02 16:29:33

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int LG = 20;
constexpr int maxn = 1e5;
int st[LG][maxn];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;cin>>n>>m>>q;
  vector<vector<int>> arr(n);
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    arr[u-1].push_back(v-1);
    arr[v-1].push_back(u-1);
  }
  vector<int> dept(n,-1);
  dept[0]=0;
  vector<int> dp(n);
  auto dfs = [&](int node, auto &&rec)->void{
    int child = 0;
    dp[node] = dept[node];
    for (auto it : arr[node]) {
      if (dept[it] == -1) {
        st[0][it] = node;
        dept[it] = dept[node] + 1;
        rec(it, rec);
        dp[node]=min(dp[node], dp[it]);
      } else {
        dp[node]=min(dp[node], dept[it]);
      }
    }
  };
  st[0][0] = -1;
  dfs(0,dfs);
  for (int i = 1; i < LG; i++) {
    for (int j = 0; j < n; j++) {
      st[i][j] = -1;
      if (st[i-1][j] == -1) continue;
      st[i][j] = st[i-1][st[i-1][j]];
    }
  }
  auto kthpar = [&](int node, int k)->int{
    for (int i = LG-1; i >= 0; i--) {
      if ((k>>i)&1) node = st[i][node];
    }
    return node;
  };
  while (q--) {
    int a, b, c;cin>>a>>b>>c;--a,--b,--c;
    if (a == c || b == c) {
      cout<<"NO\n";
      continue;
    }
    if (dept[a] > dept[c]) {
      a = kthpar(a, dept[a]-dept[c]-1);
    }
    if (dept[b] > dept[c]) {
      b = kthpar(b, dept[b]-dept[c]-1);
    }
    if (a == b) {
      cout<<"YES\n";
      continue;
    }
    if (st[0][a]==c && dp[a]==dept[c]) {
      cout<<"NO\n";
      continue;
    }
    if (st[0][b]==c && dp[b]==dept[c]) {
      cout<<"NO\n";
      continue;
    }
    cout<<"YES\n";
  }
}