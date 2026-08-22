// Submission Timestamp: 2026-04-05 23:36:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int basis[30] = {};
  while (n--) {
    int x;cin>>x;
    for (int i = 29; i >= 0; i--) {
      if ((x>>i)&1) {
        if (basis[i] == 0) {
          basis[i] = x;
          break;
        }
        x ^= basis[i];
      }
    }
  }
  int ans = 0;
  for (int i = 29; i >= 0; i--) {
    if (basis[i]) {
      if ((ans>>i)&1) continue;
      ans ^= basis[i];
    }
  }
  cout << ans << '\n';
}