// Submission Timestamp: 2026-05-18 20:56:52

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  vector<int> isprime(200001, true);
  isprime[1] = false;
  for (int i = 2; i <= 200000; i++) {
    if (isprime[i]) { 
      for (int j = 2; j * i <= 200000; j++) {
        isprime[i*j]=false;
      }
    }
  }
  vector<int> dp(100001, -1);
  dp[0] = 0;
  for (int i = 1; i <= 100000; i++) {
    for (int j = 1; j <= i; j++) {
      if (isprime[j+i] && dp[j-1] != -1) {
        dp[i] = j;
        break;
      }
    }
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  if (dp[n] == -1) {
    cout<<"IMPOSSIBLE\n";
  } else {
    for (int i = n; i >= 1; i--) {
      cout << i << ' ';
    }
    cout<<'\n';
    while (n) {
      for (int j = dp[n]; j <= n; j++) {
        cout << j << ' ';
      }
      n = dp[n]-1;
    }
    cout<<'\n';
  }
}