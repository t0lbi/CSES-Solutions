// Submission Timestamp: 2026-05-19 12:30:45

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  } else if (n <= 3) {
    cout << "NO SOLUTION\n";
    return 0;
  } else if (n == 4) {
    cout << "2 4 1 3\n";
    return 0;
  }
  vector<int> ans;
  for (int i = 1; i + 4 <= n; i += 5) {
    ans.push_back(i);
    ans.push_back(i+2);
    ans.push_back(i+4);
    ans.push_back(i+1);
    ans.push_back(i+3);
  }
  int a = n % 5;
  int l = (n-a)+1;
  if (a == 4) {
    //13526 8479
    ans.push_back(l+1);
    ans.push_back(l+3);
    ans.push_back(l);
    ans.push_back(l+2);
  } else if (a == 3) {
    //13526 847
    ans.back()=l;
    ans.push_back(l+2);
    ans.push_back(l-2);
    ans.push_back(l+1);
  } else if (a == 2) {
    //13526 47
    ans.back()=l;
    ans.push_back(l-2);
    ans.push_back(l+1);
  } else if (a == 1) {
    ans.push_back(l);
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}