// Submission Timestamp: 2026-04-01 17:41:47

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
  vector<bool> vis(n, false);
  vector<int> ans;
  for (int i = 0; i < n; ++i)
  {
    if (vis[i]) continue;
    int node = i;
    int sz = 0;
    while (vis[node] == false) {
      sz++;
      vis[node] = true;
      node = a[node] - 1;
    }
    ans.push_back(sz);
  }
  vector<int> say(n+1);
  for (auto it : ans) {
    for (int j = 2; j * j <= it; j++) {
      if (it % j == 0) {
        int hh = 0;
        while (it % j == 0) it /= j, hh++;
        say[j] = max(say[j], hh);
      }
    }
    if (it > 1) say[it] = max(say[it], 1ll);
  }
  int fin = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < say[i]; j++) fin = (fin * i) % (1000000007);
  }
  cout << fin << '\n';
}