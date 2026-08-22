// Submission Timestamp: 2026-05-07 22:37:54

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (par[node] == node) return node;
  return par[node] = find(par[node]);
}
bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return false;
  par[a] = b;
  return true;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;cin>>n>>m>>k;
  vector<array<int,3>> ed(m);
  map<pair<int,int>,int> mp;
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    if (u > v) swap(u, v);
    ed[i] = {m,u-1,v-1};
    mp[{u-1,v-1}]=i;
  }
  for (int i = 0; i < k; ++i) {
    int u, v;cin>>u>>v;
    if (u > v) swap(u, v);
    ed[mp[{u-1,v-1}]][0]=i;
  }
  sort(ed.rbegin(), ed.rend());
  vector<int> ans(m);
  par.resize(n);
  iota(par.begin(), par.end(), 0);
  int cur = n;
  for (int i = 0; i < m; i++) {
    ans[i] = cur;
    cur -= merge(ed[i][1], ed[i][2]);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < k; ++i)
  {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}