// Submission Timestamp: 2026-05-20 14:16:06

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  vector<array<int,26>> h(n+1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      h[i][j] = n;
    }
  }
  int ans = 0;
  array<int,26> ch;
  int sz = 0;
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      h[j][s[i][j]-'A'] = i;
    }
    for (int l = 0; l < n; l++) {
      array<int,26> cur = h[n];
      sz = k;
      for (int i = 0; i < k; ++i)
      {
        ch[i]=i;
      }
      for (int r = l; r < n; r++) {
        int maxel = i;
        bool bb = false;
        for (int _ = 0; _ < sz; _++) {
          int c = ch[_];
          cur[c] = min(cur[c], h[r][c]);
          maxel = max(maxel, cur[c]);
          if (cur[c] == i) bb = true;
        }
        if (bb) {
          sz = 0;
          for (int c = 0; c < k; c++) {
            if (cur[c] > i) ch[sz++]=c;
          }
        }
        ans += n-maxel;
      }
    }
  }
  cout<<ans<<'\n';
}