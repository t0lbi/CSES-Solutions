// Submission Timestamp: 2026-05-20 01:31:26

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k > n - 1) k = n - 1;
  k++;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  priority_queue<int,vector<int>,greater<int>> pq;
  
  int ind = 0;
  for (int i = 0; i < n; i++) {
    while (pq.size() < k && ind < n && ind - i < k) {
      pq.push(a[ind++]);
    }
    cout << pq.top() << ' ';
    pq.pop();
  }
  cout << '\n';
}