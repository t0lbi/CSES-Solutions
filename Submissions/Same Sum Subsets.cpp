// Submission Timestamp: 2026-06-06 02:50:09

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,2>> solve(vector<int> &v) {
  int n = v.size();
  vector<array<int,2>> ret;
  vector<int> somma(1<<n);
  ret.reserve(1<<n);
  for (int i = 1; i < (1<<n); i++) {
    int j = __builtin_ctz(i);
    somma[i]=somma[i^(1<<j)]+v[j];
    ret.push_back({somma[i], i});
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> l;
  vector<int> r;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for (int i = 0; i < n; ++i)
  {
    int x = v[i];
    if (i < n/2) l.push_back(x);
    else r.push_back(x);
  }
  vector<array<int,2>> L = solve(l);
  vector<array<int,2>> R = solve(r);
  int vl = 1, vr = (1ll<<n)-2;
  while (vl < vr) {
    int vm = vl + vr >> 1;
    int id = 0;
    while (id < R.size() && R[id][0]<=vm) {
      id++;
    }
    int say = id;
    if (id == R.size()) id--;
    for (int i = 0; i < L.size() && L[i][0] <= vm; i++) {
      while (id >= 0 && L[i][0]+R[id][0] > vm) {
        id--;
      }
      say += id+2;
    }
    if (say > vm) {
      vr=vm;
    } else {
      vl=vm+1;
    }
  }
  int p1=-1,q1=-1,p2=-1,q2=-1;
  int id = R.size()-1;
  for (int i = 0; i < R.size(); ++i)
  {
    if (R[i][0] == vl) {
      if (p1==-1){
        p1=0;
        q1=R[i][1]<<(int)l.size();
      } else {
        p2=0;
        q2=R[i][1]<<(int)l.size();
        break;
      }
    }
  }
  for (int i = 0; i < L.size(); i++) {
    while (id >= 0 && L[i][0]+R[id][0] > vl) id--;
    if (id == -1 && L[i][0]==vl) {
      if (p1==-1){
        p1=L[i][1];
        q1=0;
      } else {
        p2=L[i][1];
        q2=0;
        break;
      }
    } else if (L[i][0]+R[id][0] == vl) {
      if (p1==-1){
        p1=L[i][1];
        q1=R[id][1]<<(int)l.size();
      } else {
        p2=L[i][1];
        q2=R[id][1]<<(int)l.size();
        break;
      }
    }
  }
  p1|=q1,p2|=q2;
  int s = p1&p2;
  p1^=s,p2^=s;
  cout<<__builtin_popcountll(p1)<<'\n';
  for (int i = 0; i < n; ++i)
  {
    if((p1>>i)&1) cout<<v[i]<<' ';
  }
  cout<<'\n';
  cout<<__builtin_popcountll(p2)<<'\n';
  for (int i = 0; i < n; ++i)
  {
    if((p2>>i)&1) cout<<v[i]<<' ';
  }
  cout<<'\n';
}