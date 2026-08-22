// Submission Timestamp: 2026-05-09 23:07:46

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int n;cin>>n;
  vector<int> p(n);
  for (int i = 0; i < 10; ++i)
  {
    string s(n,'0');
    for (int j = 0; j < n; j++) {
      if ((j>>i)&1) s[j] = '1';
    }
    cout << "? "<<s<<endl;
    string a;cin>>a;
    for (int j = 0; j < n; j++) {
      if (a[j] == '1') {
        p[j]|=(1<<i);
      }
    }
  }
  cout << "! ";
  for (int i = 0; i < n; ++i)
  {
    cout<<p[i]+1<<' ';
  }
  cout << endl;
}