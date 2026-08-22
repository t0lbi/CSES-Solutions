// Submission Timestamp: 2026-04-01 17:27:00

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  vector<int> primes;
  vector<bool> isnprime(1000001);
  for (int i = 2; i < 1000001; i++) {
    if (!isnprime[i]) primes.push_back(i);
    for (auto j : primes) {
      if (i * j > 1000000) break;
      isnprime[i * j] = true;
    }
  }
  if (cin>>t) {
    while (t--){
      int n;cin>>n;n++;
      mahmut:;
      for (auto it : primes) {
        if (n == it) break;
        if (n % it == 0) {
          n++;
          goto mahmut;
        }
      }
      cout << n << '\n';
    }
  }
}