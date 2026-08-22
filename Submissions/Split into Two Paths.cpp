// Submission Timestamp: 2026-06-02 21:44:35

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> relabel(int n, vector<vector<int>> &a, vector<int> &topo) {
  vector<vector<int>> ret(n);
  vector<int> where(n);
  for (int i = 0; i < n; ++i)
  {
    where[topo[i]] = i;
  }
  for (int i = 0; i < n; ++i)
  {
    for (auto it : a[i]) {
      ret[where[i]].push_back(where[it]);
    }
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<vector<int>> a(n);
  vector<int> in(n);
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    a[u-1].push_back(v-1);
    in[v-1]++;
  }
  queue<int> q;
  for (int i = 0; i < n; ++i)
  {
    if (in[i] == 0) q.push(i);
  }
  vector<int> topo;
  while (q.size()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for (auto it : a[node]) {
      in[it]--;
      if (in[it] == 0) q.push(it);
    }
  }
  a = relabel(n, a, topo);
  vector<int> dp(n+1,-1);
  vector<int> toleft(n);
  for (int i = 0; i+1 < n; ++i)
  {
    toleft[i+1]=i+1;
    for (auto it : a[i]) {
      if (it == i+1){
        toleft[i+1]=toleft[i];
        break;
      }
    }
  }
  dp[0] = -2;
  for (int i = 1; i < n; i++) {
    if (toleft[i-1] == 0) dp[i] = -2;
  }
  for (int i = 1; i+1 < n; i++) {
    if (dp[i] != -1) {
      for (auto it : a[i-1]) {
        if (it != i) {
          if (toleft[it-1] <= i) {
            dp[it] = i-1;
          }
        }
      }
    }
  }
  if (toleft[n-1] == 0) dp[n] = -2;
  for (int i = 1; i < n; i++) {
    if (toleft[n-1] <= i && dp[i] != -1) {
      dp[n] = i-1;
    }
  }
  if (dp[n] == -1) {
    cout<<"NO\n";
    return 0;
  }
  vector<int> ans1;
  vector<int> ans2;
  int x = n;
  while (true) {
    if (dp[x] == -2) {
      for (int i = x-1; i >= 0; i--) {
        ans2.push_back(i);
      }
      break;
    } else {
      for (int i = x-1; i >= dp[x]+1; i--) {
        ans2.push_back(i);
      }
      swap(ans1, ans2);
      x = dp[x]+1;
    }
  }
  cout<<"YES\n";
  reverse(ans1.begin(), ans1.end());
  reverse(ans2.begin(), ans2.end());
  cout << ans1.size() << ' ';
  for (auto it : ans1) cout << topo[it]+1 << ' ';
  cout << '\n';
  cout << ans2.size() << ' ';
  for (auto it : ans2) cout << topo[it]+1 << ' ';
  cout << '\n';
}