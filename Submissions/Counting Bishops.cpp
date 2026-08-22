// Submission Timestamp: 2026-05-26 17:27:34

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int mul(int a, int b) {
  return (a*b)%MOD;
}
int sum(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}
vector<vector<int>> build(vector<int> lengths, int k) {
  int m = lengths.size();
  vector<vector<int>> ret(m, vector<int>(k+1,0));
  ret[0][0] = 1;
  ret[0][1] = lengths[0];
  for (int i = 1; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      ret[i][j] = ret[i-1][j];
      if (j > 0) {
        int empty_slot = lengths[i-1] - (j-1);
        if (empty_slot < 0) continue;
        empty_slot += lengths[i] - lengths[i-1];
        ret[i][j] = sum(ret[i][j], mul(ret[i-1][j-1], empty_slot));
      }
    }
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  if (k > n * 2 - 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  vector<int> lengths;
  vector<bool> vis(n*n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j)&1) continue;
      if (vis[i*n+j]) continue;
      lengths.push_back(0);
      for (int k = 0; i+k < n && j-k >= 0; k++) {
        vis[(i+k)*n+(j-k)]=true;
        lengths.back()++;
      }
    }
  }
  sort(lengths.begin(), lengths.end());
  auto dp1 = build(lengths, k);
  lengths.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i*n+j]) continue;
      lengths.push_back(0);
      for (int k = 0; i+k < n && j-k >= 0; k++) {
        vis[(i+k)*n+(j-k)]=true;
        lengths.back()++;
      }
    }
  }
  sort(lengths.begin(), lengths.end());
  auto dp2 = build(lengths, k);
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = sum(ans, mul(dp1.back()[i], dp2.back()[k-i]));
  }
  cout << ans << '\n';
}