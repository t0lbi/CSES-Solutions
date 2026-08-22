// Submission Timestamp: 2026-05-20 04:16:59

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
  int stk[3000];
  int gez[3000];
  int sz;
  int sz2;
  vector<int> mi(n);
  vector<int> ma(n);
  for (int ch = 'A'; ch <= 'A' + k - 1; ch++) {
    vector<int> h(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      sz2=0;
      for (int j = 0; j < n; j++) {
        if (s[i][j] == ch) h[j]++,gez[sz2++]=j,mi[j]=cur;
        else h[j] = 0,cur=j+1;
      }
      cur = n-1;
      for (int j = n-1; j >= 0; j--) {
        if (h[j]) ma[j]=cur;
        else cur=j-1;
      }
      sz=0;
      for (int _ = 0; _ < sz2; _++) {
        int j = gez[_];
        while (sz && h[stk[sz-1]] > h[j]) {
          sz--;
        }
        if (sz) mi[j] = max(mi[j],stk[sz-1]+1);
        stk[sz++]=j;
      }
      sz=0;
      for (int _ = sz2 - 1; _ >= 0; _--) {
        int j = gez[_];
        while (sz && h[stk[sz-1]] >= h[j]) {
          sz--;
        }
        if (sz) ma[j] = min(ma[j], stk[sz-1]-1);
        ans += h[j] * (ma[j]-j+1) * (j-mi[j]+1);
        stk[sz++]=j;
      }
    }
    cout<<ans<<'\n';
  }
}