// Submission Timestamp: 2026-06-01 01:22:51

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
  sort(a.begin(),a.end());
  priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>> pq;
  int sum = 0;
  pq.push({0,0,0,0});
  for (int i = 0; i < n; i++) {
    sum += a[i];
    pq.push({sum,i,i,n});
  }
  while (pq.size() && k--) {
    auto state = pq.top();
    pq.pop();
    cout << state[0] << ' ';
    if (state[2]+1<state[3]) {
      pq.push({state[0]+a[state[2]+1]-a[state[2]],state[1],state[2]+1,state[3]});
    }
    if (state[1] > 0 && state[2] > state[1]) {
      pq.push({state[0]+a[state[1]]-a[state[1]-1],state[1]-1,state[1],state[2]});
    }
  }
  cout << '\n';
}