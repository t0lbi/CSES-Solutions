// Submission Timestamp: 2026-04-01 18:11:39

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int fpow(int base, int pow) {
  int rval = 1;
  while (pow) {
    if (pow & 1) rval = (rval * base) % MOD;
    base = (base * base) % MOD;
    pow >>= 1;
  }
  return rval;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<vector<int>> M(n, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m + 1; j++) {
      cin >> M[i][j];
    }
  }
  vector<vector<int>> row_echelon;
  for (auto row : M) {
    for (auto &it : row_echelon) {
      int row_fi = m;
      int it_fi = m;
      for (int i = m - 1; i >= 0; i--) {
        if (row[i] != 0) row_fi = i;
        if (it[i] != 0) it_fi = i;
      }
      if (row_fi < it_fi) {
        swap(row, it);
        continue;
      }
      if (row_fi == it_fi) {
        int fi = row_fi;
        int cons = (row[fi] * fpow(it[fi], MOD-2))%MOD;
        for (int i = 0; i <= m; i++) {
          row[i] -= (it[i] * cons)%MOD;
          if (row[i] < 0) row[i] += MOD;
        }
      }
    }
    row_echelon.push_back(row);
  }
  M = row_echelon;//reduced row echelon
  vector<int> ans(m);
  bool boolean = true;
  for (int i = n-1; i >= 0; i--) {
    int fi = -1;
    for (int j = m-1; j >= 0; j--) {
      if (M[i][j] != 0) fi = j;
    }
    if (fi == -1) {
      if (M[i][m] != 0) {
        boolean=false;
      }
      continue;
    }
    int fp = fpow(M[i][fi], MOD - 2);
    for (int j = 0; j <= m; j++) {
      M[i][j] = (M[i][j] * fp) % MOD;
    }
    int hh = M[i][m];
    ans[fi] = M[i][m];
    for (int j = 0; j < i; j++) {
      int cons = M[j][fi];
      for (int k = 0; k <= m; k++) {
        M[j][k] -= (M[i][k] * cons)%MOD;
        if (M[j][k] < 0) M[j][k] += MOD;
      }
    }
  }
  if (!boolean) {
    cout << -1 << '\n';
  } else { 
    for (int i = 0; i < m; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}