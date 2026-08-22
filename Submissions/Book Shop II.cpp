// Submission Timestamp: 2026-05-22 02:15:58

#include <bits/stdc++.h>
using namespace std;
#define int long long
int window[1010][1010];
int l[1010];
int r[1010];
constexpr int mx = 1005;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;cin>>n>>x;
  vector<int> dp(x+1);
  vector<int> odp(x+1);
  vector<int> H(n);
  vector<int> S(n);
  vector<int> K(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>H[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>S[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>K[i];
  }
  for (int i = 0; i < n; i++) {
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    int h = H[i];
    int s = S[i];
    int k = K[i];
    for (int j = 0; j <= x; j++) {
      while (true) {
        int i1 = r[j%h] - 1;
        if (i1 < 0) i1 = mx-1;
        if (l[j%h] != r[j%h] && dp[j] >= dp[window[j%h][i1]]+s*(j-window[j%h][i1])/h) {
          r[j%h]--;
          if (r[j%h] < 0) r[j%h] = mx-1;
        } else break;
      }
      window[j%h][r[j%h]++]=j;
      if (r[j%h] == mx) r[j%h] = 0;
      while (window[j%h][l[j%h]] < j-h*k) {
        if (l[j%h] == r[j%h]) {
          r[j%h]++;
          if (r[j%h] == mx) r[j%h] = 0;
        }
        l[j%h]++;
        if (l[j%h] == mx) l[j%h] = 0;
      }
      odp[j] = dp[window[j%h][l[j%h]]] + s * (j-window[j%h][l[j%h]]) / h;
    }
    swap(dp,odp);
  }
  cout<<dp[x]<<'\n';
}