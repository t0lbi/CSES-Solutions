// Submission Timestamp: 2026-08-07 22:22:04

#include <bits/stdc++.h>
using namespace std;
#define int long long
map<array<int,6>, string> mp;
int stage(int x) {
  if (x <= 3) return 3;
  if (x == 4 || x == 5) return 4;
  return 5;
}
bool anss = true;
string gen_path(int n, int m, int sy, int sx, int ty, int tx) {
  string path;
  string ans;
  bool ret = false;
  vector<vector<bool>> vis(m+1, vector<bool>(n+1, false));
  int cnt = n * m;
  auto dfs = [&](int x, int y, auto&& rec) -> void {
    if (ret) return;
    if (vis[x][y]) return;
    if (x == tx && y == ty) {
      if (cnt != 1) {
        return;
      }
      ans = path;
      ret = true;
      return;
    }
    cnt--;
    vis[x][y] = true;
    if (cnt > 0) {
      bool valid = true;
      for (int i = 1; i <= m && valid; ++i) {
        for (int j = 1; j <= n && valid; ++j) {
          if (!vis[i][j]) {
            int kom = 0;
            if (i-1 >= 1 && !vis[i-1][j]) kom++;
            if (i+1 <= m && !vis[i+1][j]) kom++;
            if (j-1 >= 1 && !vis[i][j-1]) kom++;
            if (j+1 <= n && !vis[i][j+1]) kom++;
            if (i == tx && j == ty) {
              if (kom < 1 && cnt > 1) valid = false;
            } else {
              int req = (abs(i-x) + abs(j-y) == 1) ? 1 : 2;
              if (kom < req) valid = false;
            }
          }
        }
      }
      if (!valid) {
        vis[x][y] = false;
        cnt++;
        return;
      }
      vector<vector<bool>> vis2(m+1, vector<bool>(n+1, false));
      int kal = 0;
      auto dfs2 = [&](int x, int y, auto&& rec) -> void {
        vis2[x][y] = true;
        kal++;
        if (x-1 >= 1 && !vis[x-1][y] && !vis2[x-1][y]) rec(x-1, y, rec);
        if (x+1 <= m && !vis[x+1][y] && !vis2[x+1][y]) rec(x+1, y, rec);
        if (y-1 >= 1 && !vis[x][y-1] && !vis2[x][y-1]) rec(x, y-1, rec);
        if (y+1 <= n && !vis[x][y+1] && !vis2[x][y+1]) rec(x, y+1, rec);
      };
      bool first = true;
      for (int i = 1; i <= m && first; i++) {
        for (int j = 1; j <= n && first; j++) {
          if (!vis[i][j]) {
            dfs2(i,j,dfs2);
            first = false;
            if (kal != cnt) {
              vis[x][y] = false;
              cnt++;
              return;
            }
            break;
          }
        }
      }
    }
    path.push_back('?');
    path.back() = 'R';
    if (x+1 <= m) rec(x+1, y, rec);
    path.back() = 'L';
    if (x-1 >= 1) rec(x-1, y, rec);
    path.back() = 'U';
    if (y-1 >= 1) rec(x, y-1, rec);
    path.back() = 'D';
    if (y+1 <= n) rec(x, y+1, rec);
    path.pop_back();
    vis[x][y] = false;
    cnt++;
  };
  dfs(sx, sy, dfs);
  return ans;
}
string solve(int n, int m, int sy, int sx, int ty, int tx) {
  if ((n*m)%2 == 0) {
    if ((tx+ty+sx+sy)%2==0) return "";
  } else {
    if ((tx+ty)%2) return "";
    if ((sx+sy)%2) return "";
  }
  if (stage(m) < stage(n)) {
    string ans = solve(m, n, sx, sy, tx, ty);
    for (auto &ch : ans) {
      if (ch == 'U') ch = 'L';
      else if (ch == 'D') ch = 'R';
      else if (ch == 'L') ch = 'U';
      else if (ch == 'R') ch = 'D';
    }
    return ans;
  }
  if (tx < sx) {
    string ans = solve(n, m, ty, tx, sy, sx);
    for (auto &ch : ans) {
      if (ch == 'U') ch = 'D';
      else if (ch == 'D') ch = 'U';
      else if (ch == 'L') ch = 'R';
      else if (ch == 'R') ch = 'L';
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  if (n == 1) {
    if (sx == 1 && tx == m) {
      return string(m-1,'R');
    } else return "";
  }
  else if (n == 2) {
    if (sx == tx) {
      if (sx == 1) {
        return string(m-1,'R')+(sy==1?'D':'U')+string(m-1,'L');
      } else if (sx == m) {
        return string(m-1,'L')+(sy==1?'D':'U')+string(m-1,'R');
      } else return "";
    }
    string ans = string(sx-1,'L')+(sy==1?'D':'U')+string(sx,'R');
    sy = 3 - sy;
    sx++;
    while (sx != tx) {
      if (sy == 1) ans.push_back('D');
      else ans.push_back('U');
      ans.push_back('R');
      sy = 3 - sy;
      sx++;
    }
    ans += string(m-tx, 'R');
    ans.push_back(sy==1?'D':'U');
    ans += string(m-tx, 'L');
    return ans;
  }
  else if (n == 3) {
    if (m <= 20) {
      return gen_path(n,m,sy,sx,ty,tx);
    }
  }
  else if (m <= 5) {
    return mp[{n,m,sy,sx,ty,tx}];
  }
  if (sx >= m-1) {
    string ans = solve(n, m, sy, m+1-sx, ty, m+1-tx);
    for (auto &ch : ans) {
      if (ch == 'L') ch = 'R';
      else if (ch == 'R') ch = 'L';
    }
    return ans;
  }
  if (tx >= m-1) {
    array<int,6> cand = {1,2,3,4,n-1,n};
    for (auto y : cand) {
      if (y > n || y < 1) continue;
      if (array<int,2>{y,1} == array<int,2>{ty,tx-m+2}) continue;
      if (array<int,2>{sy,sx} == array<int,2>{y,m-2}) continue;
      string cur = solve(n, 2, y, 1, ty, tx-m+2);
      if (cur == "") continue;
      return solve(n, m-2, sy, sx, y, m-2)+'R'+cur;
    }
    //assert(false);
    anss=false;
    return "";
  }
  auto ans = solve(n, m-2, sy, sx, ty, tx);
  int x = sx, y = sy;
  string ret;
  bool bb = true;
  for (int i = 0; i < ans.length(); i++) {
    char ch = ans[i];
    int oy = y;
    if (ch == 'U') y--;
    else if (ch == 'D') y++;
    else if (ch == 'L') x--;
    else x++;
    if (bb && x == m-2 && (y != oy)) {
      bb = false;
      ret.push_back('R');
      ret += solve(n, 2, oy, 1, y, 1);
      ret.push_back('L');
    } else ret.push_back(ch);
  }
  return ret;
}
void gen_pathes(int n, int m, int sy, int sx) {
  string path;
  vector<vector<bool>> vis(m+1, vector<bool>(n+1, false));
  int cnt = n * m;
  auto dfs = [&](int x, int y, auto&&rec)->void{
    if (vis[x][y]) return;
    cnt--;
    vis[x][y] = true;
    if (cnt == 0) {
      mp[{n,m,sy,sx,y,x}]=path;
      cnt++;
      vis[x][y]=false;
      return;
    }
    path.push_back('U');
    if (y-1>=1) rec(x,y-1,rec);
    path.back()='D';
    if (y+1<=n) rec(x,y+1,rec);
    path.back()='R';
    if (x+1<=m) rec(x+1,y,rec);
    path.back()='L';
    if (x-1>=1) rec(x-1,y,rec);
    path.pop_back();
    vis[x][y] = false;
    cnt++;
  };
  dfs(sx, sy, dfs);
}
int32_t main(){
  for (int n = 4; n <= 5; n++) {
    for (int m = 4; m <= 5; m++) {
      for (int sy = 1; sy <= n; sy++) {
        for (int sx = 1; sx <= m; sx++) {
          gen_pathes(n,m,sy,sx);
        }
      }
    }
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  if (cin>>t) {
    while (t--) {
      int n, m, sy, sx, ty, tx;
      cin>>n>>m>>sy>>sx>>ty>>tx;
      anss=true;
      auto ans = solve(n,m,sy,sx,ty,tx);
      if (!anss) ans="";
      if (ans == "") cout << "NO\n";
      else cout << "YES\n" << ans << '\n';
    }
  }
}