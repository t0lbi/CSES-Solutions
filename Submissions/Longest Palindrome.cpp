// Submission Timestamp: 2026-04-04 20:35:56

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
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, odd[i] * 2 - 1);
  }
  for (int i = 2; i < n * 2 + 1; i += 2){
    ans = max(ans, even[i] - 1);
  }
  if (ans % 2 == 0) {
    for (int i = 2; i < n * 2 + 1; i += 2) {
      if (ans == even[i] - 1) {
        for (int j = i-even[i]+2; j <= i+even[i]-1; j+=2) {
          cout << s2[j];
        }
        cout << '\n';
        break;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (ans == odd[i] * 2 - 1) {
        for (int j = i-odd[i]+1; j <= i+odd[i]-1; j++) {
          cout << s[j];
        }
        cout << '\n';
        break;
      }
    }
  }
}