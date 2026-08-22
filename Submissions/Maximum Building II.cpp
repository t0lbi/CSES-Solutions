// Submission Timestamp: 2026-05-20 23:22:48

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DSU{
  vector<int> left;
  vector<int> right;
  int n;
  DSU(int n):n(n){
    left.resize(n);
    iota(left.begin(),left.end(),0);
    right = left;
  }
  void remove(int x) {
    left[x] = x-1;
    right[x] = x+1;
  }
  int next(int x) {
    if (x<0 || x>=n || right[x] == x) return x;
    return right[x] = next(right[x]);
  }
  int prev(int x) {
    if (x<0 || x>=n || left[x] == x) return x;
    return left[x] = prev(left[x]);
  }
};
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> s[i];
  }
  vector<vector<int>> ans(n+2, vector<int>(m+2));
  vector<int> h(m);
  vector<vector<int>> pos(n+1);
  for (int i = n-1; i >= 0; i--) {
    DSU dsu(m);
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') h[j] = 0;
      else h[j]++;
      if (h[j] > 0) pos[h[j]].push_back(j);
    }
    int cur = m * (m+1) / 2;
    for (int sz = n; sz >= 1; sz--) {
      while (pos[sz].size()) {
        int x = pos[sz].back();
        pos[sz].pop_back();
        dsu.remove(x);
        int l = dsu.prev(x)+1;
        int r = dsu.next(x)-1;
        ans[sz][r-l+1]++;
        if (l < x) ans[sz][x-l]--;
        if (x < r) ans[sz][r-x]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    int coef = 0;
    for (int j = m; j >= 1; j--) {
      sum += coef;
      coef += ans[i][j];
      ans[i][j] += sum;
      sum = ans[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      ans[i][j] += ans[i+1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}