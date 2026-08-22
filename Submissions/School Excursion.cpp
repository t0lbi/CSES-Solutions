// Submission Timestamp: 2026-05-20 18:47:05

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (par[node] < 0) return node;
  return par[node] = find(par[node]);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<int> a(n);
  par.assign(n,-1);
  for (int i = 0; i < m; i++) {
    int u, v;cin>>u>>v;
    u--, v--;
    u = find(u);
    v = find(v);
    if (u != v) {
      par[u] += par[v];
      par[v] = u;
    }
  }
  bitset<100001> sz;
  sz[0] = 1;
  for (int i = 0; i < n; i++) {
    if (par[i] < 0) {
      sz |= sz << (-par[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout<<sz[n-i-1];
  }
  cout<<'\n';
}