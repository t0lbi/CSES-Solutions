// Submission Timestamp: 2026-05-20 03:29:12

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  for (int ch = 'A'; ch <= 'A' + k - 1; ch++) {
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
      for (int j = n-1; j >= 0; j--) {  
        if (s[i][j] != ch) {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
        ans += dp[i][j];
      }
    }
    cout << ans << '\n';
  }
}