// Submission Timestamp: 2026-04-05 17:38:43

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
bool issame(vector<vector<int>> &tree_1, vector<vector<int>> &tree_2, int root1, int root2) {
  int n = tree_1.size();
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
  hash(root1, -1, 0, tree_1, hash);
  swap(depth_sorted, depth_sorted_2);
  hash(root2, -1, 0, tree_2, hash);
  for (auto &it : depth_sorted) {
    sort(it.begin(), it.end());
  }
  for (auto &it : depth_sorted_2) {
    sort(it.begin(), it.end());
  }
  return depth_sorted == depth_sorted_2;
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

    auto get_centroids = [&](vector<vector<int>> &tree) ->vector<int>{
      vector<int> subsz(n);
      auto dfs = [&](int node, int lnode, vector<vector<int>> &tree, auto &&rec)->void{
        subsz[node] = 1;
        for (auto it : tree[node]) if (it != lnode) {
          rec(it, node, tree, rec);
          subsz[node] += subsz[it];
        }
      };
      dfs(0, -1, tree, dfs);
      int node = 0, lnode = -1;
      mahmut:;
      for (auto it : tree[node]) if (it != lnode) {
        if (subsz[it] * 2 == n) {
          return {node, it};
        }
        if (subsz[it] * 2 > n) {
          lnode = node;
          node = it;
          goto mahmut;
        }
      }
      return {node};
    };
    auto v1 = get_centroids(tree_1);
    auto v2 = get_centroids(tree_2);
    for (auto r1 : v1) {
      for (auto r2 : v2) {
        if (issame(tree_1, tree_2, r1, r2)) {
          cout << "YES\n";
          goto mahmut;
        }
      }
    }
    cout << "NO\n";
    mahmut:;
  }
}