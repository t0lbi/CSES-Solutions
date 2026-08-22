// Submission Timestamp: 2026-04-05 17:20:57

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M = 3;
typedef array<int,M> Hash;
constexpr Hash base = {23, 31, 37};
constexpr Hash base2 = {31, 37, 23};
constexpr int mod = 998244353;
Hash add(Hash a, Hash b) {
  for (int i = 0; i < M; i++) {
    a[i] += b[i];
    if (a[i] >= mod) a[i] -= mod;
  }
  return a;
}
Hash mul(Hash a, Hash b) {
  for (int i = 0; i < M; i++) {
    a[i] = (1ll * a[i] * b[i]) % mod;
  }
  return a;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<vector<int>> tree_1(n);
    vector<vector<int>> tree_2(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;cin>>u>>v;
      tree_1[u-1].push_back(v-1);
      tree_1[v-1].push_back(u-1);
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;cin>>u>>v;
      tree_2[u-1].push_back(v-1);
      tree_2[v-1].push_back(u-1);
    }
    vector<vector<Hash>> depth_sorted(n);
    vector<vector<Hash>> depth_sorted_2(n);
    auto hash = [&](int node, int lnode, int depth, vector<vector<int>> &tree, auto &&rec)->Hash{
      vector<Hash> hashes;
      for (auto it : tree[node]) if (it != lnode) {
        hashes.push_back(rec(it, node, depth + 1, tree, rec));
      }
      sort(hashes.begin(), hashes.end());
      Hash ret;
      Hash cont;
      for (int i = 0; i < M; i++) {
        ret[i] = 1;
        cont[i] = 1;
      }
      for (auto it : hashes) {
        cont = mul(cont, base);
        ret = add(ret, mul(cont, it));
      }
      depth_sorted[depth].push_back(ret);
      return mul(ret, base2);
    };
    hash(0, -1, 0, tree_1, hash);
    swap(depth_sorted, depth_sorted_2);
    hash(0, -1, 0, tree_2, hash);
    for (auto &it : depth_sorted) {
      sort(it.begin(), it.end());
    }
    for (auto &it : depth_sorted_2) {
      sort(it.begin(), it.end());
    }
    if (depth_sorted == depth_sorted_2) {
      cout << "YES\n";
    } else cout << "NO\n";
  }
}