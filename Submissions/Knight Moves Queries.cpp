// Submission Timestamp: 2026-05-21 16:27:15

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e3;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> dp(maxn+10,vector<int>(maxn+10,-1));
  array<int,2> moves[8] = {
    {-2,-1},
    {-2,1},
    {-1,-2},
    {-1,2},
    {1,-2},
    {1,2},
    {2,-1},
    {2,1}
  };
  queue<array<int,3>> q;
  q.push({0,0,0});
  while (q.size()) {
    auto pr = q.front();
    q.pop();
    if (pr[0] < 0 || pr[1] < 0 || pr[0] > maxn+7 || pr[1] > maxn+7) continue;
    if (dp[pr[0]][pr[1]] != -1) continue;
    dp[pr[0]][pr[1]]=pr[2];
    for (auto [dx,dy] : moves) {
      q.push({pr[0]+dx,pr[1]+dy,pr[2]+1});
    }
  }
  int t;cin>>t;
  while (t--) {
    int x,y;cin>>x>>y;
    x--,y--;
    if (x > y) swap(x, y);
    int ans = 0;
    if (y >= maxn) {
      int ara = (y - maxn + 1)/2;
      if (y - x > ara) { 
        y -= ara * 2;
        x -= ara;
        if (x < 0) x = (x & 1);
        ans = ara;
      } else {
        ans = (y-x);
        y -= ans * 2;
        x -= ans;
        if (y >= maxn) {
          ans += ((y-maxn+4)/3)*2;
          x -= ((y-maxn+4)/3)*3;
          y -= ((y-maxn+4)/3)*3;
        }
      }
    }
    cout << dp[x][y] + ans << '\n';
  }
}