// Submission Timestamp: 2026-05-18 20:09:06

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (par[node] < 0) return node;
  return par[node]=find(par[node]);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<array<int,3>> ed(n-1);
  for (int i = 0; i < n-1; ++i)
  {
    cin >> ed[i][1] >> ed[i][2] >> ed[i][0];
    ed[i][1]--,ed[i][2]--;
  }
  sort(ed.rbegin(), ed.rend());
  par.resize(n, -1);
  int ans = 0;
  for (auto [w, a, b] : ed) {
    a = find(a);
    b = find(b);
    ans += w * par[a] * par[b];
    par[b] += par[a];
    par[a] = b;
  }
  cout << ans << '\n';
}