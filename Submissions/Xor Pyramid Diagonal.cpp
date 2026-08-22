// Submission Timestamp: 2026-05-08 00:10:58

#include <bits/stdc++.h>
using namespace std;
#define coutarr(x) for (auto it : x) cout << it << ' ';cout<<endl;
#define int long long
vector<int> solve(vector<int> v) {
  int n = v.size();
  if (n == 1) return v;
  vector<int> l(v.begin(),v.begin()+n/2);
  vector<int> r(v.begin()+n/2,v.end());
  l = solve(l);
  r = solve(r);
  for (int i = 0; i < n/2; ++i)
  {
    l.push_back(l[i]^r[i]);
  }
  return l;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  vector<int> ans;
  for (int x = 20; x >= 0; x--) {
    if ((n>>x)&1) {
      vector<int> cur(v.begin(),v.begin()+(1<<x));
      for (auto it : solve(cur)) ans.push_back(it);
      cur.clear();
      for (int i = 0; i + (1<<x) < n; i++) {
        cur.push_back(v[i]^v[i+(1<<x)]);
      }
      swap(v, cur);
      n -= 1 << x;
    }
  }
  coutarr(ans);
  cout << '\n';
}