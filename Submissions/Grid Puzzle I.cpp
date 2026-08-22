// Submission Timestamp: 2026-05-31 19:20:19

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<vector<int>> graph(n*2+2);
  vector<array<int,3>> ed;
  int somma1 = 0;
  int somma2 = 0;
  for (int i = 0; i < n; i++) {
    int x;cin>>x;
    somma1 += x;
    graph[0].push_back(ed.size());
    ed.push_back({0,i+1,x});
    graph[i+1].push_back(ed.size());
    ed.push_back({i+1,0,0});
  }
  for (int i = 0; i < n; i++) {
    int x;cin>>x;
    somma2 += x;
    graph[n+1+i].push_back(ed.size());
    ed.push_back({n+1+i,n*2+1,x});
    graph[n*2+1].push_back(ed.size());
    ed.push_back({n*2+1,n+1+i,0});
  }
  if (somma1 != somma2) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i+1].push_back(ed.size());
      ed.push_back({i+1,j+n+1,1});
      graph[j+n+1].push_back(ed.size());
      ed.push_back({j+n+1,i+1,0});
    }
  }
  int max_flow = 0;
  while (true) {
    vector<int> from(n*2+2,-1);
    queue<int> q;
    q.push(0);
    from[0] = 23;
    while (q.size()) {
      int node = q.front();
      q.pop();
      for (auto it : graph[node]) {
        if (ed[it][2] > 0 && from[ed[it][1]] == -1) {
          from[ed[it][1]] = it;
          q.push(ed[it][1]);
        }
      }
    }
    if (from[n*2+1] == -1) break;
    max_flow++;
    int nd = n*2+1;
    while (nd > 0) {
      int i = from[nd];
      ed[i][2]--;
      ed[i^1][2]++;
      nd = ed[i][0];
    }
  }
  if (max_flow == somma1) {
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