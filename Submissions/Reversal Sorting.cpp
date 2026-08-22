// Submission Timestamp: 2026-05-31 19:37:07

#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct Treap{
  Treap *left, *right;
  int val, sz, sub, h;
  int tag;
  Treap(int x) {
    val = sub = x;
    sz = 1;
    tag = 0;
    h = ayahya();
    left = right = nullptr;
  }
};
void upd(Treap* nd) {
  nd->sub = nd->val;
  if (nd->left) nd->sub = min(nd->sub, nd->left->sub);
  if (nd->right) nd->sub = min(nd->sub, nd->right->sub);
  nd->sz = 1;
  if (nd->left) nd->sz += nd->left->sz;
  if (nd->right) nd->sz += nd->right->sz;
}
void push(Treap* nd) {
  if (nd->tag) {
    swap(nd->left, nd->right);
    nd->tag = 0;
    if (nd->left) nd->left->tag^=1;
    if (nd->right) nd->right->tag^=1;
  }
}
Treap* merge(Treap* a, Treap* b) {
  if (!a||!b) return a?a:b;
  push(a), push(b);
  if (a->h > b->h) {
    a->right = merge(a->right, b);
    return upd(a),a;
  } else {
    b->left = merge(a, b->left);
    return upd(b),b;
  }
}
pair<Treap*,Treap*> split(Treap *nd, int v){
  if (!nd) return {nullptr,nullptr};
  push(nd);
  if (nd->val == v) {
    Treap* x = nd->right;
    nd->right=nullptr;
    upd(nd);
    return {nd,x};
  }
  if (nd->left && nd->left->sub == v) {
    auto spl = split(nd->left, v);
    nd->left = spl.second;
    upd(nd);
    return {spl.first, nd};
  } else {
    auto spl = split(nd->right, v);
    nd->right = spl.first;
    upd(nd);
    return {nd, spl.second};
  }
}
Treap* remove_first(Treap* nd) {
  push(nd);
  if (nd->left) {
    nd->left = remove_first(nd->left);
    upd(nd);
    return nd;
  } else {
    return nd->right;
  }
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  Treap *treap = nullptr;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;
    treap = merge(treap, new Treap(x));
  }
  cout<<n<<'\n';
  for (int i = 1; i <= n; i++) {
    auto spl = split(treap, i);
    cout<<i<<' '<<i+spl.first->sz-1<<'\n';
    spl.first->tag = 1;
    spl.first = remove_first(spl.first);
    treap = merge(spl.first, spl.second);
  }
}