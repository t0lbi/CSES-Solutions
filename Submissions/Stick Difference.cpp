// Submission Timestamp: 2026-07-21 07:15:20

#include <bits/stdc++.h>
using namespace std;
#define int long long
int revbs(vector<int> &a, int x) {
  if (a[0] < x) return -1;
  if (a.back() >= x) return a.size()-1;
  int l = 0, r = a.size()-1;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if (a[m] >= x) l = m;
    else r = m - 1;
  }
  return l;
}
int bs(vector<int> &R, int x, int y) {
  int l = 0, r = R.size()-1;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if ((y+R[m]-1)/R[m] <= x) l = m;
    else r=m-1;
  }
  return l;
}
int solveF(int x, vector<int> &a) {
  int ret = 0;
  for (auto it : a) {
    ret += it / x;
  }
  return ret;
}
int solveC(int x, vector<int> &a) {
  int ret = 0;
  for (auto it : a) {
    ret += (it + x - 1) / x;
  }
  return ret;
}
bool valid(int L, int R, vector<int> &a) {
  for (auto it : a) {
    if (it/L > (it+R-1)/R) return false;
  }
  return true;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  int somma = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
    somma += a[i];
  }
  vector<int> L, R;
  vector<int> fL, cR;
  L.push_back(*min_element(a.begin(), a.end()));
  R.push_back(*max_element(a.begin(), a.end()));
  priority_queue<array<int,3>> pq;

  priority_queue<array<int,2>> event;
  int ceilsum = 0;
  for (int i = 0; i < n; ++i)
  {
    pq.push({a[i],a[i],1});
    int t = (a[i]+R.back()-1)/R.back();
    ceilsum += t;
    if (a[i]>1&&R.back()>1)event.push({(a[i]-1)/t,i});
  }
  cR.push_back(ceilsum);
  int M = n + m + 5;
  while (pq.size() && M--) {
    int cur = pq.top()[0];
    int cng = pq.top()[1];
    int dnm = pq.top()[2];
    pq.pop();
    if (cur < R.back()) {
      while (event.size() && event.top()[0] >= cur) {
        int i = event.top()[1];
        event.pop();
        int t = (a[i]+cur-1)/cur;
        ceilsum -= (a[i]+R.back()-1)/R.back();
        ceilsum += t;
        if (cur > 1) event.push({(a[i]-1)/t,i});
      }
      R.push_back(cur);
      cR.push_back(ceilsum);
    }
    if (R.size() != cR.size()) cR.push_back(ceilsum);
    if (dnm == cng) continue;
    dnm++;
    pq.push({(cng+dnm-1)/dnm,cng,dnm});
  }
  while (pq.size()) pq.pop();
  while (event.size()) event.pop();
  int floorsum = 0;
  vector<int> say(R.size());
  for (int i = 0; i < n; ++i) {
    if (a[i] > 1) pq.push({a[i]/2,a[i],1});
    int t = a[i]/L.back();
    floorsum += t;
    if(a[i]>1&&L.back()>1)event.push({a[i]/(t+1),i});
    say[bs(R, t, a[i])]++;
  }
  int ptr = 0;
  while (say[ptr]==0) ptr++;
  vector<int> nxt;
  nxt.push_back(R.size()-ptr-1);
  fL.push_back(floorsum);
  M = n + m + 5;
  while (pq.size() && M--) {
    int cur = pq.top()[0];
    int cng = pq.top()[1];
    int dnm = pq.top()[2];
    pq.pop();
    if (cur < L.back()) {
      while (event.size() && event.top()[0] >= cur) {
        int i = event.top()[1];
        event.pop();
        int t = a[i]/cur;
        say[bs(R,a[i]/L.back(),a[i])]--;
        floorsum -= a[i]/L.back();
        say[bs(R,t,a[i])]++;
        floorsum += t;
        if (cur>1) event.push({a[i]/(t+1),i});
      }
      while (say[ptr]==0) ptr++;
      nxt.push_back(R.size()-ptr-1);
      L.push_back(cur);
      fL.push_back(floorsum);
    }
    if (dnm+1 == cng) continue;
    dnm++;
    pq.push({cng/(dnm+1),cng,dnm});
  }
  reverse(L.begin(),L.end());
  reverse(fL.begin(),fL.end());
  reverse(R.begin(),R.end());
  reverse(cR.begin(),cR.end());
  reverse(nxt.begin(), nxt.end());
  vector<array<int,3>> qu;
  for (int op = n+1; op <= n+m; op++) {
    int maxL = revbs(fL,op);
    int minR = revbs(cR,op+1)+1;
    qu.push_back({maxL, minR, op-n-1});
  }
  sort(qu.begin(), qu.end(), [&](array<int,3> &a, array<int,3>&b){
    return a[1]>b[1];
  });
  vector<int> ans(m, 1000000000);
  set<int> deactive;
  for (int i = -1; i < (int)L.size(); i++) {
    deactive.insert(i);
  }
  set<pair<int,int>> active;
  vector<pair<int,int>> nxt_s;
  for (int i = 0; i < nxt.size(); ++i)
  {
    nxt_s.push_back({nxt[i],i});
  }
  sort(nxt_s.rbegin(), nxt_s.rend());
  int ind = 0;
  for (auto [l, r, x] : qu) {
    while (ind < nxt_s.size() && nxt_s[ind].first >= r) {
      deactive.erase(nxt_s[ind].second);
      int x = nxt_s[ind].second;
      int y = R[nxt[x]] - L[x];
      ind++;
      auto lb = active.lower_bound({x,0});
      if (lb != active.begin() && prev(lb)->second < y) continue;
      vector<pair<int,int>> sil;
      while (lb != active.end() && lb->second > y) {
        sil.push_back(*lb);
        lb++;
      }
      for (auto it : sil) active.erase(it);
      active.insert({x,y});
    }
    int dd = *prev(deactive.lower_bound(l+1));
    if (dd != -1) ans[x] = min(ans[x], R[r]-L[dd]);
    auto lb = active.lower_bound({l+1,0});
    if (lb != active.begin()) {
      lb--;
      ans[x] = min(ans[x], lb->second);
    }
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout<<'\n';
}