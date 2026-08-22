// Submission Timestamp: 2026-06-05 21:56:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<char*> history;
void undo(int x) {
  while (history.size() > x) {
    *history.back() = '?';
    history.pop_back();
  }
}
pair<int,int> moves[4] = {
  pair<int,int>{-1, 0},
  pair<int,int>{1, 0},
  pair<int,int>{0, -1},
  pair<int,int>{0, 1}
};
char nxt[3] = {'B','C','A'};
char prv[3] = {'C','A','B'};
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  vector<string> ans(n,string(m,'?'));
  queue<pair<int,int>> q;
  auto bfs = [&](int x, int y)->bool{
    q.push({x,y});
    while (q.size()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (auto [dx, dy] : moves) {
        if (x+dx < 0 || x+dx >= n || y+dy < 0 || y+dy >= m) continue;
        if (ans[x+dx][y+dy] == '?') {
          if (ans[x][y] != s[x+dx][y+dy]) {
            char ch;
            if (ans[x][y] == prv[s[x+dx][y+dy]-'A']) {
              ch = nxt[s[x+dx][y+dy]-'A'];
            } else {
              ch = prv[s[x+dx][y+dy]-'A'];
            }
            history.push_back(&ans[x+dx][y+dy]);
            ans[x+dx][y+dy]=ch;
            q.push({x+dx,y+dy});
          }
        } else {
          if (ans[x+dx][y+dy] == ans[x][y]) {
            while (q.size()) q.pop();
            return false;
          }
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ans[i][j] != '?') continue;
      int u = history.size();
      history.push_back(&ans[i][j]);
      ans[i][j] = nxt[s[i][j]-'A'];
      if (!bfs(i,j)) {
        undo(u);
        ans[i][j] = prv[s[i][j]-'A'];
        if (!bfs(i,j)) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}