// Submission Timestamp: 2026-04-05 22:53:29

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;cin>>n>>m>>k;
  vector<int> dp(n, -1);
  vector<int> where(n, -1);
  vector<vector<int>> arr(n);
  queue<array<int,3>> q;
  vector<bool> shop(n);
  for (int i = 0; i < k; ++i)
  {
    int x;cin>>x;
    shop[x-1]=true;
    q.push({x-1,0,x-1});
  }
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    arr[u-1].push_back(v-1);
    arr[v-1].push_back(u-1);
  }
  while (q.size()) {
    int node = q.front()[0];
    int w = q.front()[1];
    int src = q.front()[2];
    q.pop();
    if (dp[node] != -1) continue;
    dp[node] = w;
    where[node]=src;
    for (auto it : arr[node]) {
      q.push({it, w+1,src});
    }
  }
  vector<int> ans = dp;
  for (int i = 0; i < n; i++) if (shop[i]) ans[i] = n * 5 + 10;
  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) continue;
    for (auto it : arr[i]) if (dp[it] != -1 && where[it] != where[i]) {
      ans[where[it]] = min(ans[where[it]], dp[it]+dp[i]+1);
      ans[where[i]] = min(ans[where[i]], dp[it]+dp[i]+1);
    }
  }
  dp = ans;
  for (int i = 0; i < n; i++) if (dp[i] == n*5 + 10) dp[i] = -1;
  for (auto it : dp) cout << it << ' ';cout << '\n';
}