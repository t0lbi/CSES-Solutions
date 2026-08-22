// Submission Timestamp: 2026-05-05 23:20:40

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  vector<int> s = v;
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i = 0; i < n; i++) {
    v[i] = lower_bound(s.begin(), s.end(), v[i]) - s.begin();
  }
  vector<int> say(n);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    say[v[i]]++;
    if (say[v[i]] == 1) ans++;
  }
  for (int i = 0; i + k - 1 < n; i++) {
    cout << ans << ' ';
    say[v[i]]--;
    if (say[v[i]] == 0) ans--;
    if (i + k < n) {
      say[v[i+k]]++;
      if (say[v[i+k]] == 1) ans++;
    }
  }
  cout << '\n';
}