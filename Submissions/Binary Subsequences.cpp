// Submission Timestamp: 2026-05-24 22:09:17

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF = 1e9;
int _gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  int ara = (b-a)/(a+1)+1;
  if (b-ara*(a+1)<0) return INF;
  return _gcd(b-ara*(a+1),a)+ara;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int a = 0;
  for (int i = 0; i < n-i; i++) {
    if (_gcd(i,n-i) < _gcd(a,n-a)) a = i;
  }
  int b = n-a;
  int swp = 0;
  while (a && b) {
    if (a > b) {
      swap(a,b);
      swp^=1;
    }
    b-=a+1;
    cout<<(swp^1);
  }
  for (int i = 0; i < a; i++) {
    cout << swp;
  }
  for (int i = 0; i < b; i++) {
    cout << (swp^1);
  }
}