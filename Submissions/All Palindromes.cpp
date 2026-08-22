// Submission Timestamp: 2026-04-04 20:51:17

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> manacher(string s) {
  int n = s.length();
  vector<int> ret(n, 1);
  int l = -1;
  int r = -1;
  for (int i = 0; i < n; i++) {
    if (i >= l && i <= r) {
      ret[i] = min(ret[l+r-i], r-i+1);
    }
    while (i-ret[i]>=0 && i+ret[i] < n && s[i-ret[i]] == s[i+ret[i]]) ret[i]++;
    if (i + ret[i] - 1 > r) {
      r = i + ret[i] - 1;
      l = i - ret[i] + 1;
    }
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  int n = s.length();
  vector<int> odd = manacher(s);
  string s2 = "?";
  for (auto it : s) {
    s2.push_back(it);
    s2.push_back('?');
  }
  vector<int> even = manacher(s2);
  vector<int> ans(n);
  set<int> st;
  vector<array<int,2>> v;
  for (int i = 0; i < n; ++i)
  {
    v.push_back({i, i});
    v.push_back({i+odd[i], i});
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; ++i) {
    while (v.size() && v.back()[0] <= i) {
      if (st.find(v.back()[1]) == st.end()) {
        st.insert(v.back()[1]);
      } else st.erase(v.back()[1]);
      v.pop_back();
    }
    ans[i] = (i - (*st.begin())) * 2 + 1;
  }
  v.clear();
  for (int i = 2; i < n * 2 + 1; i += 2) {
    if (even[i] == 1) continue;
    int l = (i-even[i]+2)/2;
    int r = (i+even[i]-2)/2;
    int m = l + r >> 1;
    v.push_back({m+1, m});
    v.push_back({r+1, m});
  }
  st.clear();
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; ++i) {
    while (v.size() && v.back()[0] <= i) {
      if (st.find(v.back()[1]) == st.end()) {
        st.insert(v.back()[1]);
      } else st.erase(v.back()[1]);
      v.pop_back();
    }
    if (st.size()) {
      ans[i] = max(ans[i], (i - *st.begin()) * 2);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}