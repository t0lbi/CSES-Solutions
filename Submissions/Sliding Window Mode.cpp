// Submission Timestamp: 2026-05-05 23:23:27

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
  priority_queue<pair<int,int>> pq;
  for (int i = 0; i < k; i++) {
    say[v[i]]++;
    pq.push({say[v[i]], -v[i]});
  }
  for (int i = 0; i + k - 1 < n; i++) {
    while (say[-pq.top().second] != pq.top().first) pq.pop();
    cout << s[-pq.top().second] << ' ';
    say[v[i]]--;
    pq.push({say[v[i]], -v[i]});
    if (i + k < n) {
      say[v[i+k]]++;
      pq.push({say[v[i+k]], -v[i+k]});
    }
  }
  cout << '\n';
}