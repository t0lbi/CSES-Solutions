// Submission Timestamp: 2026-05-18 20:41:01

#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<pair<int&,int>> history;
void undo(int x) {
  while (history.size() > x) {
    history.back().first = history.back().second;
    history.pop_back();
  }
}
int find(int node) {
  if (par[node] < 0) return node;
  return par[node] = find(par[node]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (par[a] > par[b]) swap(a, b);
  history.push_back({par[a],par[a]});
  history.push_back({par[b],par[b]});
  par[a] += par[b];
  par[b] = a;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;cin>>n>>m>>q;
  par.resize(n, -1);
  vector<array<int,4>> ed(m);
  vector<array<int,3>> edg(m);
  for (int i = 0; i < m; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edg[i] = {w, u-1, v-1};
    ed[i] = {w, u-1, v-1, i};
  }
  vector<int> ans(q, true);
  sort(ed.begin(), ed.end());
  vector<vector<pair<vector<int>,int>>> qu(m);
  for (int i = 0; i < q; ++i)
  {
    int x;cin>>x;
    vector<int> v(x);
    for (int j = 0; j < x; j++) {
      cin >> v[j];
      v[j]--;
    }
    sort(v.begin(), v.end(), [&](int a, int b){
      return edg[a][0] < edg[b][0];
    });
    for (int j = 0; j < x; j++) {
      if (j == 0 || (edg[v[j]][0] != edg[v[j-1]][0])) {
        pair<vector<int>,int> c;
        for (int k = j; k < x && edg[v[j]][0] == edg[v[k]][0]; k++) {
          c.first.push_back(v[k]);
        }
        c.second = i;
        int lb = lower_bound(ed.begin(), ed.end(), array<int,4>{edg[v[j]][0], 0, 0, 0}) - ed.begin();
        qu[lb].push_back(c);
      }
    }
  }
  for (int i = 0; i < m; ++i)
  {
    for (auto [v, qq] : qu[i]) {
      int x = history.size();
      for (auto it : v) {
        if (find(edg[it][1]) == find(edg[it][2])) {
          ans[qq] = false;
        }
        merge(edg[it][1], edg[it][2]);
      }
      undo(x);
    }
    merge(ed[i][1], ed[i][2]);
  }
  for (int i = 0; i < q; ++i)
  {
    cout<<"NO\0YES"+3*ans[i]<<'\n';
  }
}