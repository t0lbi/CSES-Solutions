// Submission Timestamp: 2026-05-09 22:37:55

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  for (int i = 20; i >= 0; i--) {
    if (((n-k)>>i)&1) {
      vector<int> b;
      for (int j = 0; j + (1<<i) < n; j++) {
        a[j]^=a[j+(1<<i)];
      }
      n -= (1<<i);
    }
  }
  for (int i = 0; i < k; ++i)
  {
    cout << a[i] << ' ';
  }
  cout << '\n';
}