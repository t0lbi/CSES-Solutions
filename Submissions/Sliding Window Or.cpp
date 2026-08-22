// Submission Timestamp: 2026-05-05 23:17:30

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  vector<int> pref(n), suff(n);
  pref[0] = suff[0] = x;
  for (int i = 1; i < n; ++i) {
    pref[i] = suff[i] = (pref[i-1] * a + b)%c;
  }
  for (int i = 0; i < n; ++i) {
    if (i % k) pref[i] |= pref[i-1];
  }
  for (int i = n-1; i >= 0; --i) {
    if (i % k) suff[i] |= suff[i+1];
  }
  int ans = 0;
  for (int i = 0; i + k - 1 < n; i++) {
    ans ^= suff[i] | pref[i + k - 1];
  }
  cout << ans << '\n';
}