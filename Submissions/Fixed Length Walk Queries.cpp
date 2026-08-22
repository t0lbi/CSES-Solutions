// Submission Timestamp: 2026-05-18 19:52:47

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e9;
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
  array<vector<vector<int>>,2> dp;
  dp[0]=dp[1]=vector<vector<int>>(n,vector<int>(n,INF));
  for (int src = 0; src < n; src++) {
    queue<pair<int,int>> q;
    q.push({src,0});
    dp[0][src][src]=0;
    while (q.size()) {
      int node = q.front().first;
      int w = q.front().second;
      q.pop();
      for (auto it : arr[node]) {
        if (w+1 < dp[(w+1)&1][src][it]) {
          q.push({it,w+1});
          dp[(w+1)&1][src][it]=w+1;
        }
      }
    }
  }
  while (q--) {
    int a, b, c;cin>>a>>b>>c;
    int d = dp[c&1][a-1][b-1];
    if (d == -1 || d > c) cout << "NO\n";
    else cout << "YES\n";
  }
}