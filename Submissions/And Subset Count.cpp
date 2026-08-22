// Submission Timestamp: 2026-05-14 05:09:34

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5+5;
constexpr int bt = 20;
constexpr int MOD = 1e9+7;
int dp[maxn][bt];
int tw[maxn];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  tw[0]=1;
  for (int i = 0; i < n; ++i)
  {
    tw[i+1]=(tw[i]<<1)%MOD;
    int x;cin>>x;
    dp[x][bt-1]++;
  }
  for (int i = bt - 2; i >= 0; i--) {
    for (int j = 0; j <= n; j++) {
      dp[j][i] = dp[j][i+1];
      if (!((j>>i)&1) && (j|(1ll<<i)) <= n) {
        dp[j][i] += dp[j|(1ll<<i)][i+1];
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i][bt-1]=tw[dp[i][0]];
    dp[i][bt-1]--;
    if (dp[i][bt-1]<0)dp[i][bt-1]+=MOD;
    if (__builtin_popcountll(i)&1) {
      dp[i][bt-1]*=-1;
      if (dp[i][bt-1]<0)dp[i][bt-1]+=MOD;
    }
  }
  for (int i = bt - 2; i >= 0; i--) {
    for (int j = 0; j <= n; j++) {
      dp[j][i] = dp[j][i+1];
      if (!((j>>i)&1) && (j|(1ll<<i)) <= n) {
        dp[j][i] += dp[j|(1ll<<i)][i+1];
        if (dp[j][i] >= MOD) dp[j][i]-=MOD;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (__builtin_popcountll(i)&1) {
      dp[i][0]*=-1;
      if (dp[i][0]<0)dp[i][0]+=MOD;
    }
    cout << dp[i][0] << ' ';
  }
  cout << '\n';
}