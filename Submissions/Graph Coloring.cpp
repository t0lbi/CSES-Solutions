// Submission Timestamp: 2026-05-14 12:41:11

#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[16][16];
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    arr[u-1][v-1] = arr[v-1][u-1] = 1;
  }
  vector<int> grup((1<<n), n);
  grup[0] = 0;
  for (int i = 1; i < (1<<n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i>>j)&1) {
        for (int k = j+1; k < n; k++) {
          if ((i>>k)&1) {
            if (arr[j][k]) {
              goto mahmut;
            }
          }
        }
      }
    }
    grup[i] = 1;
    mahmut:;
  }
  for (int i = 1; i < (1<<n); i++) {
    for (int j = i; j; j = (j - 1) & i) {
      if (grup[j] == 1) {
        grup[i] = min(grup[i], grup[i^j] + 1);
      }
    }
  }
  vector<int> ans(n);
  int cur = 0;
  int nd = (1<<n)-1;
  while (nd > 0) {
    cur++;
    for (int i = nd; i; i = (i - 1) & nd) {
      if (grup[i] == 1 && grup[nd^i] == grup[nd] - 1) {
        for (int j = 0; j < n; j++) {
          if ((i>>j)&1) {
            ans[j] = cur;
          }
        }
        nd ^= i;
        break;
      }
    }
  }
  cout << grup[(1<<n)-1] << '\n';
  for (auto it : ans) cout << it << ' ';cout << '\n';
}