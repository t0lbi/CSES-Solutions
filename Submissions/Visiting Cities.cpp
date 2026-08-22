// Submission Timestamp: 2026-05-20 02:51:26

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e17;
constexpr int M = 4;
constexpr int MOD[M] = {998244353, 1000000007, 998244853, 1837837};
typedef array<int,M> Hash;
vector<pair<int,Hash>> bfs(int n, vector<vector<pair<int,int>>> &arr, int src) {
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<pair<int,Hash>> dp(n, {INF, {0,0,0}});
  dp[src].first = 0;
  for (int i = 0; i < M; i++) dp[src].second[i] = 1;
  pq.push({0,src});
  vector<bool> vis(n, false);
  while (pq.size()) {
    int w = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (vis[node]) continue;
    vis[node] = true;
    for (auto [it, iw] : arr[node]) {
      if (w + iw > dp[it].first) continue;
      if (w + iw < dp[it].first) {
        dp[it] = {w + iw, {0,0,0}};
      }
      if (w + iw == dp[it].first) {
        for (int i = 0; i < M; i++) {
          dp[it].second[i] += dp[node].second[i];
          if (dp[it].second[i] >= MOD[i]) dp[it].second[i] -= MOD[i];
        }
        pq.push({w+iw,it});
      }
    }
  }
  return dp;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<vector<pair<int,int>>> arr(n);
  vector<vector<pair<int,int>>> r_arr(n);
  for (int i = 0; i < m; ++i)
  {
    int u, v, w;cin>>u>>v>>w;
    arr[u-1].push_back({v-1,w});
    r_arr[v-1].push_back({u-1,w});
  }
 
  auto dp = bfs(n, arr, 0);
  auto rdp = bfs(n, r_arr, n-1);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (dp[i].first + rdp[i].first == dp[n-1].first) {
      for (int j = 0; j < M; j++) {
        if (dp[n-1].second[j] != (dp[i].second[j] * rdp[i].second[j])%MOD[j]) {
          goto mahmut;
        }
      }
      ans.push_back(i+1);
      mahmut:;
    }
  }
 
  cout << ans.size() << '\n';
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}