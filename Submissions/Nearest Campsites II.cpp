// Submission Timestamp: 2026-05-19 16:36:19

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e9;
constexpr int maxn = 1e6;
constexpr int sz = (maxn<<1)+10;
int seg[sz];
void upd(int x, int y) {
  x+=maxn;
  for (seg[x]=min(seg[x],y);x;x>>=1){
    seg[x>>1]=min(seg[x],seg[x^1]);
  }
}
int query(int l, int r) {
  int ret = INF;
  for (l+=maxn,r+=maxn+1;l<r;l>>=1,r>>=1){
    if (l&1) ret=min(ret,seg[l++]);
    if (r&1) ret=min(ret,seg[--r]);
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<array<int,3>> v(n+m);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i][0]>>v[i][1];
    v[i][2]=-1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> v[i+n][0]>>v[i+n][1];
    v[i+n][2]=i;
  }
  vector<int> ans(m, INF);
  sort(v.begin(), v.end());
  fill(seg,seg+sz,INF);
  for (int i = 0; i < v.size(); i++) {
    if (v[i][2] == -1) {
      upd(v[i][1], -v[i][0]-v[i][1]);
    } else {
      ans[v[i][2]] = min(ans[v[i][2]], v[i][0]+v[i][1]+query(0,v[i][1]));
    }
  }
  fill(seg,seg+sz,INF);
  for (int i = 0; i < v.size(); i++) {
    if (v[i][2] == -1) {
      upd(v[i][1], v[i][1]-v[i][0]);
    } else {
      ans[v[i][2]] = min(ans[v[i][2]], v[i][0]-v[i][1]+query(v[i][1],maxn));
    }
  }
  fill(seg,seg+sz,INF);
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i][2] == -1) {
      upd(v[i][1], v[i][0]-v[i][1]);
    } else {
      ans[v[i][2]] = min(ans[v[i][2]], -v[i][0]+v[i][1]+query(0,v[i][1]));
    }
  }
  fill(seg,seg+sz,INF);
  for (int i = 0; i < v.size(); i++) {
    if (v[i][2] == -1) {
      upd(v[i][1], v[i][1]+v[i][0]);
    } else {
      ans[v[i][2]] = min(ans[v[i][2]], -v[i][0]-v[i][1]+query(v[i][1],maxn));
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}