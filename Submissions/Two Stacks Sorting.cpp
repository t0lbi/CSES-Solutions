// Submission Timestamp: 2026-06-07 01:04:22

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par;
vector<int> sgn;
pair<int,int> find(int node) {
  if (par[node] == node) {
    return {node, 1};
  }
  auto ret = find(par[node]);
  par[node] = ret.first;
  sgn[node] = ret.second * sgn[node];
  return {par[node], sgn[node]};
}
bool connect(int x, int y, int c) {
  auto a = find(x);
  auto b = find(y);
  if (a.first == b.first) {
    return a.second * b.second == c;
  }
  par[a.first] = b.first;
  sgn[a.first] = a.second * b.second * c;
  return 1;
}
bool valid = 1;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct Treap {
  Treap *left, *right;
  int tag, val, el, h;
  Treap(pair<int,int> x) {
    left = right = NULL;
    tag = 0;
    val = x.first;
    el = x.second;
    h = ayahya();
  }
};
void push(Treap* x) {
  if (x->tag) {
    x->tag = 0;
    if (x->left) {
      x->left->tag = 1;
      valid &= connect(x->el, x->left->el, 1);
    }
    if (x->right) {
      x->right->tag = 1;
      valid &= connect(x->el, x->right->el, 1);
    }
  }
}
Treap* merge(Treap* a, Treap* b) {
  if (!a||!b) return a?a:b;
  if (a->h > b->h) {
    push(a);
    a->right = merge(a->right, b);
    return a;
  } else {
    push(b);
    b->left = merge(a, b->left);
    return b;
  }
}
pair<Treap*,Treap*> split(Treap* x, int y) {
  if (x == NULL) return {NULL, NULL};
  push(x);
  if (x->val > y) {
    auto spl = split(x->left, y);
    x->left = spl.second;
    return {spl.first, x};
  } else {
    auto spl = split(x->right, y);
    x->right = spl.first;
    return {x, spl.second};
  }
}
void gg(Treap* nd) {
  if (nd == NULL) return;
  push(nd);
  gg(nd->left);
  gg(nd->right);
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  par.resize(n);
  sgn.resize(n,0);
  iota(par.begin(), par.end(), 0);
  vector<int> v(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
    v[i]--;
    p[v[i]]=i;
  }
  vector<bool> vis(n+1,0);
  int cur = 0;
  vector<pair<int,int>> seg(n,{-1,-1});
  int tin = 0;
  vector<pair<int,int>> nx(2*n,{-1,-1});
  for (int i = 0; i < n; ++i)
  {
    seg[v[i]].first = tin++;
    vis[v[i]] = 1;
    while (vis[cur]) {
      seg[cur].second = tin++;
      nx[seg[cur].first] = {seg[cur].second, cur};
      cur++;
    }
  }
  Treap *treap = NULL;
  for (int i = 0; i < 2*n; ++i)
  {
    if (nx[i].first != -1) {
      auto p = split(treap, i);
      gg(p.first);
      treap = p.second;
      p = split(treap, nx[i].first);
      if (p.first != NULL) {
        p.first->tag=1;
        valid &= connect(p.first->el, nx[i].second, -1);
      }
      Treap *x = new Treap(nx[i]);
      treap = merge(p.first, x);
      treap = merge(treap, p.second);
    }
  }
  gg(treap);
  if (valid) {
    for (int i = 0; i < n; ++i)
    {
      int ans = find(v[i]).second;
      if (ans == -1) ans = 2;
      cout<<ans<<' ';
    }
    cout<<'\n';
  } else cout << "IMPOSSIBLE\n";
}