// Submission Timestamp: 2026-04-05 18:15:04

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int n, k;cin>>n>>k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  int ans = 0;
  deque<int> q;
  vector<int> v(n);
  v[0] = x;
  for (int i = 1; i < n; i++) {
    v[i] = (v[i-1] * a + b) % c;
  }
  for (int i = 0; i < n; i++) {
    while (q.size() && v[q.back()] >= v[i]) q.pop_back();
    q.push_back(i);
    while (q.front() <= i - k) q.pop_front();
    if (i >= k - 1) ans ^= v[q.front()];
  }
  cout << ans << '\n';
}