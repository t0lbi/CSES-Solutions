// Submission Timestamp: 2026-04-05 23:01:45

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<int> in(n);
  vector<vector<int>> arr(n);
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    in[u-1]++;
    arr[v-1].push_back(u-1);
  }
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i)
  {
    if (!in[i]) pq.push(i);
  }
  vector<int> ans;
  while (pq.size()) {
    int node = pq.top();
    pq.pop();
    ans.push_back(node+1);
    for (auto it : arr[node]) {
      in[it]--;
      if (!in[it]) pq.push(it);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}