// Submission Timestamp: 2026-05-19 12:21:08

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n+1);
  vector<int> dp(n+1);
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }
  map<int,int> seen;
  dp[0] = 1;
  int l = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    l = max(l, seen[a[i]]);
    seen[a[i]] = i+1;
    if (l == 1) dp[i] = dp[i-1];
    else dp[i] = dp[i-1] - dp[l-2];
    if (dp[i] < 0) dp[i] += MOD;
    ans = dp[i];
    dp[i] += dp[i-1];
    if (dp[i] >= MOD) dp[i] -= MOD;
  }
  cout<<ans<<'\n';
}