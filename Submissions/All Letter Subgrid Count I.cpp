// Submission Timestamp: 2026-05-20 04:39:11

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, c;cin>>n>>c;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> s[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(c,3000000));
  vector<vector<int>> odp(n+1, vector<int>(c,3000000));
  int ans = 0;
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      int maxel = 0;
      for (int k = 0; k < c; k++) {
        if (s[i][j]==('A'+k)){
          dp[j][k]=0;
        } else {
          dp[j][k]=30000000;
          dp[j][k]=min({dp[j][k],dp[j+1][k]+1,odp[j][k]+1,odp[j+1][k]+1});
        }
        maxel=max(maxel,dp[j][k]);
      }
      ans += max(0ll,n-max(i,j)-maxel);
    }
    swap(dp, odp);
  }
  cout<<ans<<'\n';
}