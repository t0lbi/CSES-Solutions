// Submission Timestamp: 2026-05-31 04:51:53

#pragma GCC optimize("O3,unroll-loops")
//niye GEcMIyoN abI
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3005;
int fenwik[maxn];
long long ans[26];
short u1[maxn][maxn];
short a[maxn][maxn], b[maxn][maxn];
int head[maxn], nxt[maxn];
string v[maxn];

void upd(int x, int y) {
  for (;x<maxn;x|=x+1) fenwik[x]+=y;
}
int get(int x) {
  int ret = 0;
  for (;x>=0;x=(x&(x+1))-1) ret+=fenwik[x];
    return ret;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;cin>>n>>k;
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i && v[i-1][j] == v[i][j]) {
        u1[i][j]=u1[i-1][j]+1;
      } else u1[i][j]=0;
      if (j && v[i][j-1] == v[i][j]) {
        a[i][j]=a[i][j-1]+1;
      } else a[i][j]=0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j]=min(a[i][j],u1[i][j]);
    }
  }
  for (int i = n-1; i >= 0; --i) {
    for (int j = n-1; j >= 0; --j) {
      if (i<n-1 && v[i+1][j] == v[i][j]) {
        u1[i][j]=u1[i+1][j]+1;
      } else u1[i][j]=0;
      if (j<n-1 && v[i][j+1] == v[i][j]) {
        b[i][j]=b[i][j+1]+1;
      } else b[i][j]=0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j]=min(b[i][j],u1[i][j]);
    }
  }
  for (int _ = 0; _ < n * 2 - 1; _++) {
    int x, y;
    if (_ < n) x = n-_-1, y = 0;
    else x = 0, y = _-n+1;
    int len = min(n-x, n-y);
    for (int i = 0; i <= len; ++i) head[i] = -1;
    memset(fenwik,0,sizeof(fenwik));
    int tot = 0;
    int i = 0;
    for (;x<n&&y<n;x++,y++,i++) {
      for (int curr = head[i]; curr != -1; curr = nxt[curr]) {
        tot++;
        upd(curr,1);
      }
      int nx = i+b[x][y]+1;
      if (nx <= len) {
        nxt[i] = head[nx];
        head[nx] = i;
      }
      ans[v[x][y]-'A'] += a[x][y]+1;
      ans[v[x][y]-'A'] -= (tot-get(i-a[x][y]-1));
    }
  }
  for (int i = 0; i < k; ++i)
  {
    cout<<ans[i]<<'\n';
  }
}