// Submission Timestamp: 2026-05-20 01:23:48

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  map<int,vector<int>> mp;
  for (int i = 0; i < n; ++i)
  {
    mp[b[i]].push_back(i);
  }
  int ans = 0;
  for (int i = n-1; i >= 0; i--) {
    if (mp[a[i]].back() < i) {
      ans = max(ans, i - mp[a[i]].back());
    }
    mp[a[i]].pop_back();
  }
  cout << ans << '\n';
}