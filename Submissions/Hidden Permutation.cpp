// Submission Timestamp: 2026-05-06 20:23:35

#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  string x;cin>>x;
  return x == "YES";
}
vector<int> merge_sort(vector<int> a) {
  int n = a.size();
  if (n <= 1) return a;
  vector<int> left, right;
  for (int i = 0; i < n; i++) {
    if (i < n / 2) left.push_back(a[i]);
    else right.push_back(a[i]);
  }
  left = merge_sort(left);
  right = merge_sort(right);
  int l = 0, r = 0;
  a.clear();
  while (l < left.size() && r < right.size()) {
    if (comp(left[l], right[r])) {
      a.push_back(left[l++]);
    } else {
      a.push_back(right[r++]);
    }
  }
  while (l < left.size()) {
    a.push_back(left[l++]);
  }
  while (r < right.size()) {
    a.push_back(right[r++]);
  }
  return a;
}
int32_t main(){
  int n;cin>>n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  vector<int> v = merge_sort(a);
  vector<int> ans(n);
  for (int i = 0; i < n; ++i)
  {
    ans[v[i] - 1] = i + 1;
  }
  cout << "! ";
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << endl;
}