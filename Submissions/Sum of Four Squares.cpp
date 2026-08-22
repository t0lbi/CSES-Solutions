// Submission Timestamp: 2026-04-01 18:21:15

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<array<int,3>> pos;
  for (int i = 0; i <= 3162; i++) {
    for (int j = 0; j <= i; j++) {
      pos.push_back({i*i+j*j,i,j});
    }
  }
  sort(pos.begin(), pos.end());
  int t;
  if (cin>>t) {
    while (t--){
      int n;cin>>n;
      for (int i = 0; i < pos.size() && n >= pos[i][0]; i++) {
        auto bb = lower_bound(pos.begin(), pos.end(), array<int,3>{n-pos[i][0],0,0});
        if (bb != pos.end() && (*bb)[0] == n - pos[i][0]) {
          cout << pos[i][1] << ' ' << pos[i][2] << ' '<< (*bb)[1] << ' ' << (*bb)[2] << '\n';
          break;
        }
      }
    }
  }
}