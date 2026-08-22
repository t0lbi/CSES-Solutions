// Submission Timestamp: 2026-05-09 22:02:41

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e15;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int,4>> ed(m * 2);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> ed[i*2][j];
      if (j < 2) ed[i*2][j]--;
    }
    ed[i*2+1][0] = ed[i*2][1];
    ed[i*2+1][1] = ed[i*2][0];
    ed[i*2+1][2] = 0;
    ed[i*2+1][3] = -ed[i*2][3];
  }
  int ans = 0;
  while (k--) {
    vector<int> dp(n, INF);
    vector<int> from(n, -1);
    dp[0] = 0;
    bool any = true;
    while (any) {
      any = false;
      for (int i = 0; i < m * 2; i++) {
        if (ed[i][2] == 0) continue;
        if (dp[ed[i][0]] != INF && dp[ed[i][0]] + ed[i][3] < dp[ed[i][1]]) {
          dp[ed[i][1]] = dp[ed[i][0]] + ed[i][3];
          from[ed[i][1]] = i;
          any = true;
        }
      }
    }
    if (dp[n-1] == INF) {
      ans = -1;
      break;
    }
    ans += dp[n-1];
    int nd = n-1;
    while (nd) {
      ed[from[nd]][2]--;
      ed[from[nd]^1][2]++;
      nd = ed[from[nd]][0];
    }
  }
  cout << ans << '\n';
}