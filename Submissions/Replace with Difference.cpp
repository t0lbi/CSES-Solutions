// Submission Timestamp: 2026-05-20 17:02:24

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MX = 1000001;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> v(n+1);
  vector<bitset<MX>> bs(n+1);
  bs[0].set(0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    bs[i] = (bs[i-1]<<v[i])|(bs[i-1]>>v[i]);
    for (int j = 0; j <= v[i]; j++) {
      if (bs[i-1][j]) {
        bs[i].set(v[i]-j);
      }
    }
  }
  if (!bs[n][0]) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> sgn(n+1,1);
  int cur_sgn = 1;
  int node = 0;
  for (int i = n; i >= 1; i--) {
    if (node+v[i]<MX && bs[i-1][node+v[i]]) {
      node+=v[i];
      sgn[i] = -cur_sgn;
    } else if (node-v[i] >= 0 && bs[i-1][node-v[i]]) {
      node-=v[i];
      sgn[i]=cur_sgn;
    } else {
      sgn[i]=cur_sgn;
      node=v[i]-node;
      cur_sgn *= -1;
    }
  }
  vector<int> pos;
  vector<int> neg;
  for (int i = 1; i <= n; i++) {
    if (sgn[i] == 1) pos.push_back(v[i]);
    else neg.push_back(v[i]);
  }
  while (pos.size() && neg.size()) {
    int a = pos.back();
    int b = neg.back();
    pos.pop_back();
    neg.pop_back();
    cout << a << ' ' << b << '\n';
    if (a >= b) {
      pos.push_back(a-b);
    } else neg.push_back(b-a);
  }
}