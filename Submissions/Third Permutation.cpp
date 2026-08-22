// Submission Timestamp: 2026-05-18 12:12:11

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  if (n == 2) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> a(n);
  vector<int> b(n);
  vector<int> pos(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = b[pos[b[i]]];
  }
  vector<bool> vis(n, false);
  vector<pair<int,int>> grup;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    grup.push_back({i, pos[b[i]]});
    int x = i;
    while (!vis[x]) {
      vis[x] = true;
      x = pos[b[x]];
    }
  }
  int g = grup.size();
  if (grup.size() > 1) {
    vector<int> nc = c;
    for (int i = 0; i < grup.size(); i++) {
      c[grup[i].first] = nc[grup[(i+1)%g].first];
      c[grup[i].second] = nc[grup[(i+1)%g].second];
    }
  }
  for (auto it : c) {
    cout << it << ' ';
  }
  cout << '\n';
}