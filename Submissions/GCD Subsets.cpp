// Submission Timestamp: 2026-05-20 18:34:25

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> freq(n+1);
  for (int i = 0; i < n; i++) {
    int x;cin>>x;
    freq[x]++;
  }
  vector<int> dp(n+1);
  vector<int> fp(n+1);
  fp[0] = 1;
  for (int i = 1; i <= n; i++) {
    fp[i] = (fp[i-1]<<1) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * i <= n; j++) {
      dp[i] += freq[i*j];
    }
    dp[i] = fp[dp[i]];
    dp[i]--;
    if (dp[i] < 0) dp[i] += MOD;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 2; j * i <= n; j++) {
      dp[i] -= dp[j*i];
      if (dp[i] < 0) dp[i] += MOD;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
}