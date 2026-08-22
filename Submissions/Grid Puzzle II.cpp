// Submission Timestamp: 2026-05-31 19:59:47

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e9;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<vector<int>> graph(n*2+2);
  vector<array<int,4>> ed;
  int somma1 = 0;
  int somma2 = 0;
  for (int i = 0; i < n; i++) {
    int x;cin>>x;
    somma1 += x;
    graph[0].push_back(ed.size());
    ed.push_back({0,i+1,x,0});
    graph[i+1].push_back(ed.size());
    ed.push_back({i+1,0,0,0});
  }
  for (int i = 0; i < n; i++) {
    int x;cin>>x;
    somma2 += x;
    graph[n+1+i].push_back(ed.size());
    ed.push_back({n+1+i,n*2+1,x,0});
    graph[n*2+1].push_back(ed.size());
    ed.push_back({n*2+1,n+1+i,0,0});
  }
  if (somma1 != somma2) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;cin>>x;
      graph[i+1].push_back(ed.size());
      ed.push_back({i+1,j+n+1,1,x});
      graph[j+n+1].push_back(ed.size());
      ed.push_back({j+n+1,i+1,0,-x});
    }
  }
  int max_flow = 0;
  int fin = 0;
  while (true) {
    vector<pair<int,int>> minel(n*2+2,{-INF,-1});
    minel[0]={0,-1};
    while (true) {
      bool chg = false;
      for (int i = 0; i < ed.size(); i++) {
        if (ed[i][2] > 0) {
          if (minel[ed[i][0]].first != -INF) {
            if (minel[ed[i][0]].first + ed[i][3] > minel[ed[i][1]].first) {
              chg = true;
              minel[ed[i][1]] = {minel[ed[i][0]].first+ed[i][3], i};
            }
          }
        }
      }
      if (!chg) break;
    }
    if (minel[n*2+1].first == -INF) break;
    fin += minel[n*2+1].first;
    max_flow++;
    int nd = n*2+1;
    while (nd > 0) {
      int i = minel[nd].second;
      ed[i][2]--;
      ed[i^1][2]++;
      nd = ed[i][0];
    }
  }
  if (max_flow == somma1) {
    cout << fin << '\n';
    vector<string> ans = vector<string>(n,string(n,'.'));
    while (max_flow--) {
      int node = n*2+1;
      while (node > 0) {
        for (auto it : graph[node]) if ((it&1) && ed[it][2] > 0) {
          ed[it][2]--;
          if (ed[it][1] <= n && ed[it][0] > n) {
            ans[ed[it][1]-1][ed[it][0]-n-1]='X';
          }
          node = ed[it][1];
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i)
    {
      cout<<ans[i]<<'\n';
    }
  } else {
    cout << -1 << '\n';
  }
}