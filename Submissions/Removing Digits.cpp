// Submission Timestamp: 2026-05-24 22:22:49

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int ans = 0;
  while (n > 0) {
    int uu = 0;
    int x = n;
    while (x) {
      uu = max(uu, x%10);
      x/=10;
    }
    n -= uu;
    ans++;
  }
  cout<<ans<<'\n';
}