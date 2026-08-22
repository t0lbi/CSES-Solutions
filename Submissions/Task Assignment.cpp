// Submission Timestamp: 2026-05-09 22:26:01

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e15;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<array<int,4>> ed;
  for (int i = 0; i < n; ++i)
  {
    ed.push_back({0, i+1, 1, 0});
    ed.push_back({i+1, 0, 0, 0});

    ed.push_back({i+n+1, 2*n+1, 1, 0});
    ed.push_back({2*n+1, i+n+1, 0, 0});

    for (int j = 0; j < n; ++j) {
      int x;cin>>x;
      ed.push_back({i+1, j+n+1, 1, x});
      ed.push_back({j+n+1, i+1, 0, -x});
    }
  }
  int bn = n;
  vector<int> ns(n);
  n = n * 2 + 2;
  int m = ed.size()/2;
  int ans = 0;
  int k = bn;
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
      if (nd >= 1 && nd <= bn && ed[from[nd]][0] != 0) {
        ns[ed[from[nd]][0] - bn - 1] = nd-1;
      } else if (nd >= bn + 1 && nd <= 2 * bn && ed[from[nd]][0] != n - 1) {
        ns[nd-bn-1] = ed[from[nd]][0]-1;
      }
      ed[from[nd]][2]--;
      ed[from[nd]^1][2]++;
      nd = ed[from[nd]][0];
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < ns.size(); ++i)
  {
    cout << ns[i] + 1 << ' ' << i + 1 << endl;
  }
}