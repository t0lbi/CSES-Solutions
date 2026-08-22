// Submission Timestamp: 2026-05-09 23:18:20

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  int n;cin>>n;
  cout<<"? "<<1<<endl;
  char a, b;
  cin>>a;
  cout<<"? "<<n<<endl;
  cin>>b;
  if (a == b) {
    cout<<"! "<<n<<endl;
    return 0;
  }
  int l = 2, r = n-1;
  char x;
  while (l < r) {
    int m = l + r >> 1;
    cout<<"? "<<m<<endl;
    cin>>x;
    if ((m%2 != l%2) == (x == a)) {
      l=m+1;
      a=x;
    } else {
      r=m-1;
      b=x;
    }
  }
  cout<<"? "<<l<<endl;
  cin>>x;
  if (x == a) {
    l--;
  }
  cout<<"! "<<l<<endl;
}