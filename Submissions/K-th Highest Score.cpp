// Submission Timestamp: 2026-05-09 23:03:58

#include <bits/stdc++.h>
using namespace std;
#define int long long
int hf[100001];
int hs[100001];
int F(int x) {
  if (!hf[x]) {
    cout << "F " << x << endl;
    cin >> hf[x];
  }
  return hf[x];
}
int S(int x) {
  if (!hs[x]) {
    cout << "S " << x << endl;
    cin >> hs[x];
  }
  return hs[x];
}
void answer(int x) {
  cout << "! " << x << endl;
  exit(0);
}
int32_t main(){
  int n, k;cin>>n>>k;
  if (k <= n) {
    if (F(k) > S(1)) {
      answer(F(k));
    }
    if (S(k) > F(1)) {
      answer(S(k));
    }
  }
  int l = max(1ll, k-n), r = min(n, k-1);
  while (l < r) {
    int m = l + r >> 1;
    if (F(m+1) > S(k-m)) {
      l = m + 1;
    } else r = m;
  }
  if (F(l) > S(k-l)) answer(S(k-l));
  else answer(F(l));
}