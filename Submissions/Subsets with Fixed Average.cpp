// Submission Timestamp: 2026-05-19 23:05:30

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int offset = 250005;
constexpr int sz = 500010;
constexpr int MOD = 1e9+7;
int dp[sz];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a;cin>>n>>a;
  dp[offset] = 1;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;x-=a;
    if (x < 0) {
      for (int j = 0; j < sz; j++) {
        if (j+x >= 0) {
          dp[j+x]+=dp[j];
          if (dp[j+x] >= MOD) dp[j+x] -= MOD;
        }
      }
    } else {
      for (int j = sz-1; j >= 0; j--) {
        if (j+x >= 0) {
          dp[j+x]+=dp[j];
          if (dp[j+x] >= MOD) dp[j+x] -= MOD;
        }
      }
    }
  }
  dp[offset]--;
  if (dp[offset]<0) dp[offset]+=MOD;
  cout << dp[offset] << '\n';
}