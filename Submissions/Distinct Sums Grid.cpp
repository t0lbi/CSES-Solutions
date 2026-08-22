// Submission Timestamp: 2026-05-22 01:28:33

#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int get(int l, int r){
  return l+ayahya()%(r-l+1);
}
int freq[1000001]={};
int cur;
int n;
vector<int> s_x;
vector<int> s_y;
int check(vector<vector<int>> &arr) {
  int ret = 0;
  s_x.clear();
  s_y.clear();
  cur++;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    int sum2 = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[i][j];
      sum2 += arr[j][i];
    }
    if (freq[sum] != cur) {
      freq[sum]=cur;
      ret++;
    } else {
      s_x.push_back(i);
    }
    if (freq[sum2] != cur) {
      freq[sum2]=cur;
      ret++;
    } else {
      s_y.push_back(i);
    }
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  if (n <= 3) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> cur;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      cur.push_back(i);
    }
  }
  vector<vector<int>> ans(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = get(0,cur.size()-1);
      ans[i][j]=cur[x];
      swap(cur[x],cur.back());
      cur.pop_back();
    }
  }
  int cnt = 0;
  while (true) {
    int old = check(ans);
    int a = get(0,n-1);
    int c = get(0,n-1);
    if (s_x.size() && get(0,100) > 70) {
      a = s_x[get(0,s_x.size()-1)];
    } 
    if (s_x.size() && get(0,100) > 70) {
      c = s_x[get(0,s_x.size()-1)];
    } 
    int b = get(0,n-1);
    int d = get(0,n-1);
    if (s_y.size() && get(0,100) > 70) {
      b = s_y[get(0,s_y.size()-1)];
    } 
    if (s_y.size() && get(0,100) > 70) {
      d = s_y[get(0,s_y.size()-1)];
    }
    swap(ans[a][b],ans[c][d]);
    int nw = check(ans);
    if (nw < old) {
      swap(ans[a][b], ans[c][d]);
    }
    if (nw == 2 * n) break;
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j) {
      cout<<ans[i][j]<<' ';
    }
    cout<<'\n';
  }
}