// Submission Timestamp: 2026-05-18 16:06:29

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    if (i) a[i] += a[i-1];
  }
  for (int i = 0; i < n; ++i)
  {
    cin >> b[i];
    if (i) b[i] += b[i-1];
  }
  long double l = 0, r = 1000000000;
  long double eps = 1e-9;
  int ans1, ans2;
  while (l + eps < r) {
    long double m = (l + r)/2;
    pair<long double, int> maxel1 = {a[0]-m, 0};
    pair<long double, int> maxel2 = {b[0]-m, 0};
    for (int i = 1; i < n; i++) {
      maxel1 = max(maxel1, pair<long double, int>{a[i]-(i+1)*m,i});
      maxel2 = max(maxel2, pair<long double, int>{b[i]-(i+1)*m,i});
    }
    ans1 = maxel1.second;
    ans2 = maxel2.second;
    if (maxel1.first + maxel2.first >= 0) {
      l = m;
    } else r = m;
  }
  cout << ans1+1 << ' ' << ans2+1 << '\n';
}