// Submission Timestamp: 2026-06-05 19:48:22

#include <bits/stdc++.h>
using namespace std;
#define int long long
int sgn(int x) {
  if (x == 0) return 0;
  if (x > 0) return 1;
  return -1;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int ans = 0;
  vector<array<int,2>> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i][0];
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i][1];
  }
  int A = 0, B = 0;
  for (int i = 0; i < n; ++i)
  {
    int curA = a[i][0];
    int curB = a[i][1];
    if (curA == 0) curA = -1;
    else curA--;
    if (curB == 0) curB = -1;
    else curB--;
    if (sgn(A) != sgn(curA)) {
      int m = min(abs(A), abs(curA));
      A -= sgn(A) * m;
      curA -= sgn(curA) * m;
    }
    if (sgn(B) != sgn(curB)) {
      int m = min(abs(B), abs(curB));
      B -= sgn(B) * m;
      curB -= sgn(curB) * m;
    }
    A += curA;
    B += curB;
    if (sgn(A) != sgn(B)) {
      int m = min(abs(A), abs(B));
      A -= sgn(A) * m;
      B -= sgn(B) * m;
      ans += m;
    }
    ans += abs(A) + abs(B);
  }
  cout << ans << '\n';
}