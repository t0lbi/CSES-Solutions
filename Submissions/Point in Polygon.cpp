// Submission Timestamp: 2026-02-26 03:24:55

#include <bits/stdc++.h>
using namespace std;
#define int long long
int cross(pair<int,int> &a, pair<int,int> &b) {
  __int128 ret = (__int128)a.first * b.second - (__int128)a.second * b.first;
  if (ret > 0) return 1;
  if (ret < 0) return -1;
  return 0;
}
int cross(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
  a.first -= c.first;
  a.second -= c.second;
  b.first -= c.first;
  b.second -= c.second;
  return cross(a, b);
}
bool clamp(int a, int b, int c) {
  if (b > c) swap(b, c);
  return a >= b && a <= c;
}
bool clash(pair<int,int> a, pair<int,int> b, pair<int,int> c, pair<int,int> d) {
  return (cross(b, c, a) != cross(b, d, a) && cross(d, a, c) != cross(d, b, c));
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;cin>>n>>m;
  vector<pair<int,int>> v(n);
  pair<int,int> far = {5e9, 8e9+1};
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i].first>>v[i].second;
  }
  while (m--) {
    pair<int,int> pts;
    cin >> pts.first >> pts.second;
    int clash_cnt = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == pts) {
        cout << "BOUNDARY\n";
        goto mahmut;
      }
      if (cross(v[(i+1)%n], pts, v[i]) == 0) {
        if (clamp(pts.first, v[i].first, v[(i+1)%n].first) && clamp(pts.second, v[i].second, v[(i+1)%n].second)) {
          cout << "BOUNDARY\n";
          goto mahmut;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      clash_cnt += clash(pts, far, v[i], v[(i+1)%n]);
    }
    if (clash_cnt % 2 == 0) cout << "OUTSIDE\n";
    else cout << "INSIDE\n";
    mahmut:;
  }
}