// Submission Timestamp: 2026-04-05 18:12:18

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int n, k;cin>>n>>k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  int ans = 0;
  int somma = 0;
  vector<int> v(n);
  v[0] = x;
  for (int i = 1; i < n; i++) {
    v[i] = (v[i-1] * a + b) % c;
  }
  for (int i = 0; i < n; i++) {
    somma += v[i];
    if (i - k >= 0) somma -= v[i-k];
    if (i >= k - 1) ans ^= somma;
  }
  cout << ans << '\n';
}