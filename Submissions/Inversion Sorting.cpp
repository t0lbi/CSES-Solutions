// Submission Timestamp: 2026-05-09 23:37:33

#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[10];
int nn;
int ask(int i, int j) {
  #ifdef tolbi
  for (int a=i,b=j;a<=b;a++,b--) swap(p[a],p[b]);
  int hh = 0;
  for (int a = 1; a <= nn; a++) {
    for (int b = a+1; b <= nn; b++) {
      if (p[a] > p[b]) hh++;
    }
  }
  if (hh == 0) exit(0);
  return hh;
  #endif
  cout << i << ' ' << j << endl;
  int x;cin>>x;
  if (x == 0) exit(0);
  return x;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  #ifdef tolbi
  nn=n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  #endif
  ask(1,1);
  for (int i = 2; i <= n; i++) {
    int y = ask(1, i) - ((i-1)*(i-2)/2);
    int x = ask(1, i);
    int ord = (y-x+1+i)/2;
    //cout<<"ORD BULDUM "<<i<<' '<<x<<' '<<y<<' '<<ord<<endl;
    if (ord < i) {
      ask(ord, i);
      ask(ord+1, i);
    }
    //for (int j = 1; j <= n; j++) cout << p[j] << ' ';cout<<'\n';
  }
}