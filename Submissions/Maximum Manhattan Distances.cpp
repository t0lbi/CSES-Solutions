// Submission Timestamp: 2026-04-04 21:06:23

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;cin>>q;
  int x,y;
  cin>>x>>y;
  int max_xpy = x + y;
  int min_xpy = x + y;
  int max_xmy = x - y;
  int min_xmy = x - y;
  cout << 0 << '\n';
  while (--q) {
    cin >> x >> y;
    max_xpy = max(max_xpy, x + y);
    min_xpy = min(min_xpy, x + y);
    max_xmy = max(max_xmy, x - y);
    min_xmy = min(min_xmy, x - y);

    cout << max(max_xpy - min_xpy, max_xmy - min_xmy) << '\n';
  }
}