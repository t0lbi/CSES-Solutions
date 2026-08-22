// Submission Timestamp: 2026-05-06 14:06:24

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
    if (v[i] > n) v[i] = n;
  }
  vector<int> say(n+1);
  priority_queue<int,vector<int>,greater<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(i);
  }
  for (int i = 0; i < k; i++) {
    say[v[i]]++;
  }
  for (int i = 0; i + k - 1 < n; i++) {
    while (pq.size() && say[pq.top()] > 0) pq.pop();
    cout << pq.top() << ' ';
    say[v[i]]--;
    pq.push(v[i]);
    if (i + k < n) {
      say[v[i+k]]++;
    }
  }
  cout << '\n';
}