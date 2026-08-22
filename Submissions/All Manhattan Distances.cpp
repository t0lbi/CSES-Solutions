// Submission Timestamp: 2026-04-04 21:17:19

#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;cin>>x;
  return x;
}
#define int __int128
int solve(vector<int> v) {
  int n = v.size();
  sort(v.begin(), v.end());
  int ret = 0;
  for (int i = 0; i < n; ++i)
  {
    ret += v[i] * (i - (n-i-1));
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = in();
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
  {
    a[i] = in();
    b[i] = in();
  }
  int ans = solve(a) + solve(b);
  if (ans == 0) {
    cout << 0 << '\n';
  } else {
    string s;
    while (ans > 0) {
      s.push_back((ans%10)+'0');
      ans /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
  }
}