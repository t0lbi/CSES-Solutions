// Submission Timestamp: 2026-05-31 18:43:34

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
int find(int node) {
  if (node < 0 || node >= par.size() || par[node]==node) return node;
  return par[node] = find(par[node]);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i+1 < n; ++i) {
    a[i] = a[i+1]-a[i];
  }
  a.pop_back();
  n--;
  priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
  par.resize(n);
  iota(par.begin(), par.end(), 0);
  vector<int> l = par;
  vector<int> r = par;
  vector<int> pref = a;
  for (int i = 2; i < n; i++) {
    pref[i] += pref[i-2];
  }
  for (int i = 0; i < n; ++i)
  {
    pq.push({a[i], i});
  }
  int ans = 0;
  auto query = [&](int l, int r)->int{
    int ret = pref[r];
    if (l >= 2) ret -= pref[l-2];
    return ret;
  };
  while (pq.size()) {
    int w = pq.top()[0];
    int node = pq.top()[1];
    pq.pop();
    if (find(node) != node) continue;
    ans += w;
    cout << ans << ' ';
    l[node]--;
    r[node]++;
    if (l[node] >= 0) {
      int L = find(l[node]);
      par[L] = node;
      l[node] = l[L];
    }
    if (r[node] < n) {
      int R = find(r[node]);
      par[R] = node;
      r[node] = r[R];
    }
    if (l[node] >= 0 && r[node] < n) {
      pq.push({query(l[node],r[node])-query(l[node]+1,r[node]-1),node});
    }
  }
  cout << '\n';
}