// Submission Timestamp: 2026-05-27 02:33:00

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  vector<vector<int>> next(n, vector<int>(n, 1));
  for (int i = 0; i < n; ++i) {
    for (int j = n-2; j >= 0; --j) {
      if (s[i][j] == s[i][j+1]) {
        next[i][j] = next[i][j+1]+1;
      }
    }
  }
  vector<int> ans(k);
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      char cur = '?';
      int say = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i][l] != s[i][r]) {
          cur = '?';
        }
        if (s[i][l] != cur) {
          cur = s[i][l];
          say = 0;
        }
        if (next[i][l] >= r-l+1) {
          say++;
          ans[cur-'A'] += say;
        }
      }
    }
  }
  for (int i = 0; i < k; ++i)
  {
    cout<<ans[i]<<'\n';
  }
}