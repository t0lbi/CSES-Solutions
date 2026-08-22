// Submission Timestamp: 2026-05-19 02:43:12

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> transpoze(vector<vector<int>> a) {
  vector<vector<int>> b(a[0].size(),vector<int>(a.size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      b[j][i] = a[i][j];
    }
  }
  return b;
}
vector<vector<int>> solve(int n, int m) {
  if (n == 9 && m == 5) {
    return {
      { 0, 0, 1, 2, 2},
      { 0, 1, 1, 3, 2},
      { 4, 5, 5, 3, 3},
      { 4, 4, 5, 6, 6},
      {10,10, 7, 7, 6},
      {10,11,11, 7, 8},
      {12,12,11, 8, 8},
      {12,13,14, 9, 9},
      {13,13,14,14, 9}
    };
  }
  vector<vector<int>> ret;
  if (n == 3) {
    ret.resize(n, vector<int>(m));
    assert(m % 2 == 0);
    for (int i = 0; i < m/2; i++) {
      ret[0][i*2]=i;
      ret[0][i*2+1]=i;
      ret[1][i*2]=i;
      ret[1][i*2+1]=i+m/2;
      ret[2][i*2]=i+m/2;
      ret[2][i*2+1]=i+m/2;
    }
  } else {
    if (m % 2 == 1) {
      ret = solve(n, m-3);
      int say = n * (m-3) / 3;
      for (int i = 0; i < 3; i++) {  
        ret[i*2].push_back(say);
        ret[i*2].push_back(say);
        ret[i*2].push_back(say+1);
        ret[i*2+1].push_back(say);
        ret[i*2+1].push_back(say+1);
        ret[i*2+1].push_back(say+1);
        say+=2;
      }
    } else {
      auto ret1 = solve(3, m);
      for (auto it : ret1) {
        ret.push_back(it);
      }
      for (auto it : ret1) {
        for (auto &it2 : it) it2 += m;
          ret.push_back(it);
      }
    }
  }
  return ret;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n, m;cin>>n>>m;
    vector<vector<int>> a;
    bool swp = false;
    if (n == 1 || m == 1 || (n*m) % 3 != 0) {
      cout << "NO\n";
      continue;
    }
    if (n % 3 != 0 || (m==3)) {
      swp = true;
      swap(n, m);
    }
    if (m % 2 == 0) {
      int say = 0;
      for (int i = 0; i < n / 3; i++) {
        auto v = solve(3, m);
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < m; k++) {
            v[j][k] += say;
          }
        }
        say += m;
        for (int j = 0; j < 3; j++) {
          a.push_back(v[j]);
        }
      }
    } else {
      if (n == 3) {
        cout << "NO\n";
        continue;
      } else if (n % 2 == 0) {
        int say = 0;
        for (int i = 0; i < n / 6; i++) {
          auto v = solve(6, m);
          for (int j = 0; j < 6; j++) {
            for (int k = 0; k < m; k++) {
              v[j][k] += say;
            }
          }
          say += m * 2;
          for (int j = 0; j < 6; j++) {
            a.push_back(v[j]);
          }
        }
      } else {
        a = solve(9, 5);
        int say = 15;
        for (int i = 0; i < (n-9)/6; i++) {
          auto v = solve(6, 5);
          for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 5; k++) {
              v[j][k] += say;
            }
          }
          say += 10;
          for (int j = 0; j < 6; j++) {
            a.push_back(v[j]);
          }
        }
        m -= 5;
        vector<vector<int>> b;
        for (int i = 0; i < n / 3; i++) {
          auto v = solve(3, m);
          for (int j = 0; j < 3; j++) {
            for (int k = 0; k < m; k++) {
              v[j][k] += say;
            }
          }
          say += m;
          for (int j = 0; j < 3; j++) {
            b.push_back(v[j]);
          }
        }
        for (int i = 0; i < a.size(); i++) {
          for (auto it : b[i]) {
            a[i].push_back(it);
          }
        }
      }
    }
    cout << "YES\n";
    if (swp) {
      a = transpoze(a);
    }
    n = a.size();
    m = a[0].size();
    vector<vector<int>> arr(n*m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i > 0) {
          arr[a[i][j]].push_back(a[i-1][j]);
        }
        if (j > 0) {
          arr[a[i][j]].push_back(a[i][j-1]);
        }
        if (i + 1 < n) {
          arr[a[i][j]].push_back(a[i+1][j]);
        }
        if (j + 1 < m) {
          arr[a[i][j]].push_back(a[i][j+1]);
        }
      }
    }
    vector<char> hh(n*m,'A');
    for (int i = 0; i < n * m; i++) {
      vector<bool> seen(26, false);
      for (auto it : arr[i]) {
        seen[hh[it]-'A']=true;
      }
      while (seen[hh[i]-'A']) hh[i]++;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << hh[a[i][j]];
      }
      cout << '\n';
    }
  }
}