// Submission Timestamp: 2026-05-18 12:29:14

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5;
int seg[maxn<<1];
void update(int x, int y) {
  for (seg[x+=maxn]=y;x>1;x>>=1) seg[x>>1]=max(seg[x],seg[x^1]);
}
int query(int l, int r) {
  int ret = 0;
  for (l+=maxn,r+=maxn+1;l<r;l>>=1,r>>=1) {
    if (l&1) ret = max(ret, seg[l++]);
    if (r&1) ret = max(ret, seg[--r]);
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  int x = min(n, m);
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int y;cin>>y;
    if (y <= x) a.push_back(y);
  }
  vector<int> pos(x+1);
  for (int i = 0; i < m; i++) {
    int y;cin>>y;
    if (y <= x) {
      pos[y] = b.size();
      b.push_back(y);
    }
  }
  n = x;
  vector<int> ans(n);
  int max_ans = 0;
  for (int i = 0; i < n; i++) {
    a[i] = pos[a[i]];
    ans[i] = query(0,a[i]-1) + 1;
    max_ans = max(max_ans, ans[i]);
    update(a[i],ans[i]);
  }
  vector<int> fin;
  int cur = n + 1;
  for (int i = n-1; i >= 0; i--) {
    if (ans[i] == max_ans && a[i] < cur) {
      cur = a[i];
      max_ans--;
      fin.push_back(b[a[i]]);
    }
  }
  reverse(fin.begin(), fin.end());
  cout << fin.size() << '\n';
  for (auto it : fin) {
    cout << it << ' ';
  }
  cout << '\n';
}