// Submission Timestamp: 2026-06-06 03:44:44

#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> dp[19][10][10][10];
int max_digi(int x) {
  int r = 0;
  while (x) {
    r = max(r, x%10);
    x/=10;
  }
  return r;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int j = 0; j < 10; j++) {
    for (int k = 0; k < 10; k++) {
      for (int z = 0; z < 10; z++) {
        if (j == 0) {
          int ans = 0;
          int el = k * 10 + z;
          while (el > 0) {
            ans++;
            el -= max_digi(el);
          }
          dp[1][j][k][z]={ans,0};
        } else {
          int ans = 0;
          int el = k * 10 + z;
          while (el >= 0) {
            ans++;
            el -= max(max_digi(el), j);
          }
          dp[1][j][k][z]={ans,el+10};
        }
      }
    }
  }
  for (int i = 2; i < 19; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int z = 0; z < 10; z++) {
          int ans = 0;
          int el = z;
          for (int d = k; d >= 0; d--) {
            ans += dp[i-1][max(j,d)][9][el].first;
            el = dp[i-1][max(j,d)][9][el].second;
          }
          dp[i][j][k][z]={ans,el};
        }
      }
    }
  }
  int n;cin>>n;
  int digi = 1;
  int last = n%10;
  n/=10;
  int ans = 0;
  while (n) {
    int d = n%10;
    n/=10;
    ans += dp[digi][max_digi(n)][d][last].first;
    last=dp[digi][max_digi(n)][d][last].second;
    if (n > 0) {
      n--;
      if (n == 0) {
        ans += dp[digi][0][9][last].first;
        last = 0;
      }
    }
    digi++;
  }
  if (last) ans++;
  cout << ans << '\n';
}