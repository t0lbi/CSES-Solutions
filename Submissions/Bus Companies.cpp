// Submission Timestamp: 2026-05-20 18:55:47

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<int> c(m);
  for (int i = 0; i < m; ++i)
  {
    cin >> c[i];
  }
  vector<vector<pair<int,int>>> arr(n+m);
  for (int i = 0; i < m; ++i)
  {
    int k;cin>>k;
    for (int j = 0; j < k; ++j) {
      int x;cin>>x;
      arr[x-1].push_back({i+n,c[i]});
      arr[i+n].push_back({x-1,0});
    }
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> dp(n+m, -1);
  pq.push({0,0});
  while (pq.size()) {
    int node = pq.top().second;
    int w = pq.top().first;
    pq.pop();
    if (dp[node] != -1) continue;
    dp[node] = w;
    for (auto [it,iw] : arr[node]) {
      pq.push({w+iw,it});
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
}