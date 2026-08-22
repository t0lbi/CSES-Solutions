// Submission Timestamp: 2026-04-04 21:02:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  vector<int> p(n+2, -1);
  for (int i = 0; i < n; ++i)
  {
    p[v[i]] = i;
  }
  char ch = 'a';
  string s(n, '?');
  s[v[0]-1] = 'a';
  for (int i = 1; i < n; ++i) {
    //{s[v[i]-1], p[v[i]+1]} < {s[v[i+1]-1], p[v[i+1]+1]} olmali
    //p[v[i]+1] > p[v[i+1]+1] ise kucuk olmak zorunda, hop olcak
    if (p[v[i-1]+1] > p[v[i]+1]) {
      if (ch == 'z') {
        s = "-1";
        break;
      }
      ch++;
    }
    s[v[i]-1] = ch;
  }
  cout << s << '\n';
}