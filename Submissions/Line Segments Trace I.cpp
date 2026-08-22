// Submission Timestamp: 2026-04-04 21:42:21

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i].first >> a[i].second;
    a[i].second = (a[i].second - a[i].first) / m;
  }
  sort(a.begin(), a.end(), [&](pair<int,int> &x, pair<int,int> &y){
    return x.second < y.second;
  });
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
    while (v.size() >= 2) {
      pair<int,int> &p1 = v[v.size()-2];
      pair<int,int> &p2 = v[v.size()-1];
      int l = 0, r = m;
      while (l < r) {
        int mm = l + r >> 1;
        if (p1.first + p1.second * mm > p2.first + p2.second * mm) {
          l = mm + 1;
        } else r = mm;
      }
      if (a[i].first + a[i].second * l >= p2.first + p2.second * l) {
        v.pop_back();
      } else break;
    }
    if (v.size() == 0 || a[i].first + a[i].second * m > v.back().first + v.back().second * m) {
      v.push_back(a[i]);
    }
  }
  int pt = 0;
  for (int i = 0; i <= m; i++) {
    while (pt + 1 < v.size() && v[pt+1].first + v[pt+1].second * i > v[pt].first + v[pt].second * i) {
      pt++;
    }
    cout << v[pt].first + v[pt].second * i << ' ';
  }
  cout << '\n';
}