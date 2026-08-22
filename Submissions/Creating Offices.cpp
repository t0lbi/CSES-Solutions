// Submission Timestamp: 2026-05-21 01:01:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[400000][20];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,d;cin>>n>>d;
  vector<vector<int>> arr(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;cin>>u>>v;
    arr[u-1].push_back(v-1);
    arr[v-1].push_back(u-1);
  }
  vector<int> dept(n);
  vector<int> ans;
  auto dfs = [&](int node, int lnode, auto &&rec)->int{
    vector<int> c;
    for (auto it : arr[node]) if (it != lnode) {
      dept[it]=dept[node]+1;
      c.push_back(rec(it, node, rec));
    }
    sort(c.begin(), c.end(), [&](int a, int b){
      return dept[a] > dept[b];
    });
    bool bb = false;
    for (auto it : c) {
      if (dept[it] < dept[node]+d) {
        bb=true;
        break;
      }
    }
    if (!bb) {
      for (auto it : c) {
        ans.push_back(it);
      }
      return node;
    }
    for (int i = 1; i < c.size(); i++) {
      if (dept[c[i-1]]+dept[c[i]]-2*dept[node] >= d) {
        ans.push_back(c[i-1]);
      } else return c[i-1];
    }
    return c.back();
  };
  ans.push_back(dfs(0,-1,dfs));
  sort(ans.begin(),ans.end());
  cout << ans.size() << '\n';
  for (auto it : ans) {
    cout << it + 1 << ' ';
  }
  cout << '\n';
}