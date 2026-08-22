// Submission Timestamp: 2026-05-19 19:22:41

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
int32_t main(){
  vector<int> prime(5001, -2);
  int cur = 0;
  prime[0] = prime[1] = -1;
  for (int i = 2; i <= 5000; i++) {
    if (prime[i] == -1) continue;
    prime[i] = cur++;
    for (int j = 2; i*j <= 5000; j++) {
      prime[i*j] = -1;
    }
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int ans = 1;
  vector<bitset<669>> bs;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;
    if (x == 1) {
      ans *= 2;
      if (ans >= MOD) ans -= MOD;
      continue;
    }
    bitset<669> cur;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int c = 0;
        while (x % j == 0) {
          x /= j;
          c++;
        }
        if (c & 1) {
          cur.set(prime[j]);
        }
      }
    }
    if (x > 1) cur.set(prime[x]);
    for (int j = 0; j <= bs.size(); j++) {
      int a;
      if (j == bs.size()) a = 670;
      else a = bs[j]._Find_first();
      int b = cur._Find_first();
      if (a == b) {
        cur ^= bs[j];
        if (cur.count() == 0) break;
      } else if (b < a) {
        bs.insert(bs.begin()+j,cur);
        break;
      }
    }
    if (cur.count() == 0) {
      ans *= 2;
      if (ans >= MOD) ans -= MOD;
    }
  }
  cout << ans << '\n';
}