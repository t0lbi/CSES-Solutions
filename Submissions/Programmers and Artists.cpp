// Submission Timestamp: 2026-05-20 17:13:03

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, n;cin>>a>>b>>n;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i].first>>v[i].second;
  }
  sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
    return a.second-a.first < b.second-b.first;
  });
  vector<int> pref(n), suff(n);
  int cur = 0;
  priority_queue<int,vector<int>,greater<int>> pq;
  for (int i = 0; i < n; i++) {
    cur += v[i].first;
    pq.push(v[i].first);
    if (pq.size() > a) {
      cur -= pq.top();
      pq.pop();
    }
    pref[i] = cur;
  }
  cur = 0;
  while (pq.size()) pq.pop();
  for (int i = n-1; i >= 0; i--) {
    cur += v[i].second;
    pq.push(v[i].second);
    if (pq.size() > b) {
      cur -= pq.top();
      pq.pop();
    }
    suff[i] = cur;
  }
  int ans = 0;
  for (int i = a-1; i+b < n; i++) {
    ans = max(ans, pref[i] + suff[i+1]);
  }
  if (a == 0 && b == 0) ans = 0;
  else if (a == 0) ans = suff[0];
  else if (b == 0) ans = pref[n-1];
  cout << ans << '\n';
}