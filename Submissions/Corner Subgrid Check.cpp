// Submission Timestamp: 2026-04-05 16:54:47

#include <bits/stdc++.h>
using namespace std;
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  bitset<9100000> bs;
  for (char ch = 'A'; ch <= 'A'+m-1; ch++) {
    bs.reset();
    for (int i = 0; i < n; i++) {
      vector<int> poses;
      for (int j = 0; j < n; j++) {
        if (a[i][j] == ch) poses.push_back(j);
      }
      for (int j = 0; j < poses.size(); j++) {
        for (int k = 0; k < j; k++) {
          int hh = poses[j]*n + poses[k];
          if (bs.test(hh)) goto mahmut;
          bs.set(hh);
        }
      }
    }
    cout<<"NO"<<endl;
    continue;
    mahmut:;
    cout<<"YES"<<endl;
  }
}