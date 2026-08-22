// Submission Timestamp: 2026-05-19 12:06:09

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  map<int,vector<int>> mp;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;
    mp[x].push_back(i);
  }
  int ans = 0;
  for (auto [_, v] : mp) {
    ans += n * (n+1) / 2;
    ans -= v[0] * (v[0]+1) / 2;
    ans -= (n-v.back()-1) * (n-v.back()) / 2;
    for (int i = 0; i + 1 < v.size(); i++) {
      ans -= (v[i+1]-v[i]-1) * (v[i+1]-v[i]) / 2;
    }
  }
  cout << ans << '\n';
}