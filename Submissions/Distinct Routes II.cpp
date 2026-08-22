// Submission Timestamp: 2026-05-20 15:11:46

#include <bits/stdc++.h>
using namespace std;
#define o int
o INF = 1e9;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  o n, m, k;
  cin >> n >> m >> k;
  vector<array<o,4>> e(m*2);
  for (o i = 0; i < m; i++) {
    for (o j = 0; j < 2; j++) {
      cin >> e[i*2][j];
      e[i*2][j]--;
    }
    o x=i*2;
    e[x+1][0] = e[x][1];
    e[x+1][1] = e[x][0];
    e[x][2]=1;
    e[x+1][2] = 0;
    e[x][3]=1;
    e[x+1][3]=-1;
  }
  o a = 0;
  while (k--) {
    vector<o> d(n, INF);
    vector<o> f(n, -1);
    d[0] = 0;
    bool any = true;
    while (any) {
      any = false;
      for (o i = 0; i < m * 2; i++) {
        if (e[i][2] == 0) continue;
        if (d[e[i][0]] != INF && d[e[i][0]] + e[i][3] < d[e[i][1]]) {
          d[e[i][1]] = d[e[i][0]] + e[i][3];
          f[e[i][1]] = i;
          any = true;
        }
      }
    }
    if (d[n-1] == INF) {
      a = -1;
      break;
    }
    a += d[n-1];
    o nd = n-1;
    o el = k;
    while (nd) {
      e[f[nd]][2]--;
      e[f[nd]^1][2]++;
      nd = e[f[nd]][0];
    }
  }
  cout << a << '\n';
  if (a == -1) return 0;
  while (1) {
    o p = n - 1;
    vector<o> v;
    bool bb = true;
    while (p) {
      v.push_back(p);
      for (o i = 0; i < m; i++) {
        if (e[i*2][1] == p && e[i*2][2] == 0) {
          e[i*2][2]=1;
          p=e[i*2][0];
          break;
        }
      }
      if (v.back() == p) {
        bb=false;
        break;
      }
    }
    if (bb) {
      v.push_back(0);
      reverse(v.begin(), v.end());
      cout<<v.size()<<'\n';
      for (auto it : v) cout << it+1<<' ';cout<<'\n';
    } else break;
  }
}