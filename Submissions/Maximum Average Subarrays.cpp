// Submission Timestamp: 2026-05-20 00:29:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n+1);
  a[0] = 0;
  vector<int> stk;
  vector<pair<int,int>> f(n+1);
  f[0] = {0,0};
  stk.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i-1];
    f[i] = {-a[i], i};
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = stk.size()-1;
    while (l < r) {
      int m = l + r >> 1;
      if ((a[i] - a[stk[m+1]]) * (i - stk[m]) > (a[i] - a[stk[m]]) * (i-stk[m+1])) {
        l = m + 1;
      } else r = m;
    }
    cout << i - stk[l] << ' ';
    int a0 = f[i].first;
    int b0 = f[i].second; 
    while (stk.size() > 1) {
      int a1 = f[stk[stk.size()-1]].first;
      int b1 = f[stk[stk.size()-1]].second;
      int a2 = f[stk[stk.size()-2]].first;
      int b2 = f[stk[stk.size()-2]].second;
      if ((a2-a1)*(b1-b0) <= (a0-a1)*(b1-b2)) stk.pop_back();
      else break;
    }
    stk.push_back(i);
  }
  cout << '\n';
}