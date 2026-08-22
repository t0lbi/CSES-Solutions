// Submission Timestamp: 2026-05-20 01:04:05

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e9;
int32_t main(){
  ios_base::sync_with_stdio(false);
  string str[6] = {
    "FILL A",
    "FILL B",
    "EMPTY A",
    "EMPTY B",
    "MOVE A B",
    "MOVE B A"
  };
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c < 0 || c > a) {
    cout << -1 << '\n';
    return 0;
  }
  function<array<int,3>(int,int)> f[6] = {
    [&](int x, int y){return array<int,3>{a,y,a-x};},
    [&](int x, int y){return array<int,3>{x,b,b-y};},
    [&](int x, int y){return array<int,3>{0,y,x};},
    [&](int x, int y){return array<int,3>{x,0,y};},
    [&](int x, int y){
      int c = min(x, b-y);
      return array<int,3>{x-c,y+c,c};
    },
    [&](int x, int y){
      int c = min(a-x, y);
      return array<int,3>{x+c,y-c,c};
    },
  };
  vector<vector<array<int,3>>> from(a+1, vector<array<int,3>>(b+1, {-1,-1,-1}));
  vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
  vector<vector<bool>> vis(a+1, vector<bool>(b+1, false));
  priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
  pq.push({0,0,0});
  dp[0][0] = 0;
  while (pq.size()) {
    int w = pq.top()[0];
    int x = pq.top()[1];
    int y = pq.top()[2];
    pq.pop();
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 6; i++) {
      auto v = f[i](x,y);
      int nx = v[0];
      int ny = v[1];
      int nw = v[2] + w;
      int ham = i;
      if (nw < dp[nx][ny]) {
        dp[nx][ny] = nw;
        from[nx][ny] = {x, y, ham};
        pq.push({nw,nx,ny});
      } 
    }
  }
  int ans = -1;
  for (int i = 0; i <= b; i++) {
    if (vis[c][i]) {
      if (ans == -1) ans = i;
      else if (dp[c][i] < dp[c][ans]) ans = i;
    }
  }
  if (ans == -1) cout << -1 << '\n';
  else {
    vector<int> v;
    int x = c, y = ans;
    while (x != 0 || y != 0) {
      auto p = from[x][y];
      v.push_back(p[2]);
      x = p[0];
      y = p[1];
    }
    reverse(v.begin(), v.end());
    cout << v.size() << ' ' << dp[c][ans] << '\n';
    for (auto it : v) {
      cout << str[it] << '\n';
    }
  }
}