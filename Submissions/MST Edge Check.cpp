// Submission Timestamp: 2026-04-05 23:34:01

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (par[node] == node) return node;
  return par[node] = find(par[node]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  par[a] = b;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  par.resize(n);
  iota(par.begin(), par.end(), 0);
  vector<array<int,4>> ed(m);
  for (int i = 0; i < m; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    ed[i] = {w, u-1, v-1, i};
  }
  sort(ed.begin(), ed.end());
  vector<bool> ans(m);
  for (int i = 0; i < m; ++i)
  {
    if (i == 0 || ed[i][0] != ed[i-1][0]) {
      for (int j = i; j < m && ed[i][0] == ed[j][0]; j++) {
        if (find(ed[j][1]) != find(ed[j][2])) {
          ans[ed[j][3]] = true;
        }
      }
    }
    merge(ed[i][1], ed[i][2]);
  }
  for (int i = 0; i < m; ++i)
  {
    cout<<"NO\0YES"+3*ans[i]<<'\n';
  }
}