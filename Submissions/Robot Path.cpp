// Submission Timestamp: 2026-05-17 13:32:49

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 500000;
int fenwik[maxn];
void update(int x, int v) {
  for (; x < maxn; x = x | (x + 1)) fenwik[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) ret += fenwik[x];
    return ret;
}
int query(int l, int r) {
  return get(r) - get(l - 1);
}
int sgn(int x) {
  if (x == 0) return 0;
  if (x > 0) return 1;
  return -1;
}

struct Point{
  int x, y;
  Point(int x, int y):x(x),y(y){}
  Point():x(0),y(0){}
  friend ostream& operator<<(ostream& os, Point pt){return os<<'('<<pt.x<<','<<pt.y<<')';}
  const bool operator<(Point &ot)const{if (x==ot.x) return y<ot.y;return x<ot.x;}
};
int manhattan(Point a, Point b) {
  return abs(a.x-b.x) + abs(a.y-b.y);
}
vector<array<int,4>> same_hor;
vector<array<int,4>> same_ver;
bool solve1(int x) {
  int last = -1;
  for (int i = 0; i < same_hor.size(); i++) {
    if (same_hor[i][3] > x) continue;
    if (last == -1) {
      last = i;
      continue;
    }
    if (same_hor[i][0] == same_hor[last][0]) {
      if (same_hor[i][1] <= same_hor[last][2]) return true;
    }
    last = i;
  }
  last = -1;
  for (int i = 0; i < same_ver.size(); i++) {
    if (same_ver[i][3] > x) continue;
    if (last == -1) {
      last = i;
      continue;
    }
    if (same_ver[i][0] == same_ver[last][0]) {
      if (same_ver[i][1] <= same_ver[last][2]) return true;
    }
  }
  return false;
}
vector<int> compres;
vector<array<int,5>> upd;
bool solve2(int x) {
  bool bb = false;
  for (auto it : upd) {
    if (it[4] > x) continue;
    if (it[1] == 2) {
      it[2] = lower_bound(compres.begin(),compres.end(),it[2])-compres.begin();
      it[3] = lower_bound(compres.begin(),compres.end(),it[3])-compres.begin();
      if (query(it[2], it[3])) bb=true;
    } else {
      it[2] = lower_bound(compres.begin(),compres.end(),it[2])-compres.begin();
      update(it[2], it[3]);
    }
  }
  return bb;
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int x = 0, y = 0;
  vector<array<Point,2>> v(n);
  int ans1 = 0;
  char lst = '?';
  for (int i = 0; i < n; i++) {
    char ch;
    int d;
    cin >> ch >> d;
    v[i][0] = Point(x,y);
    if (ch == 'U') {
      if (lst == 'D') {
        lst = 'X';
      }
      y += d;
      if (i) v[i][0].y++;
    } else if (ch == 'D') {
      if (lst == 'U') {
        lst = 'X';
      }
      y -= d;
      if (i) v[i][0].y--;
    } else if (ch == 'L') {
      if (lst == 'R') {
        lst = 'X';
      }
      x -= d;
      if (i) v[i][0].x--;
    } else if (ch == 'R') {
      if (lst == 'L') {
        lst = 'X';
      }
      x += d;
      if (i) v[i][0].x++;
    }
    v[i][1] = Point(x,y);
    if (lst != 'X') {
      ans1 += manhattan(v[i][0], v[i][1]);
      if (i) ans1++;
      lst = ch;
    }
    compres.push_back(v[i][0].y);
    compres.push_back(v[i][1].y);
  }
  for (int i = 0; i < v.size(); i++) {
    array<Point,2> pt = v[i];
    if (pt[1] < pt[0]) swap(pt[0], pt[1]);
    if (pt[0].x == pt[1].x) {
      upd.push_back({pt[0].x, 2, pt[0].y, pt[1].y, i});
    } else {
      upd.push_back({pt[0].x, 1, pt[0].y, 1, i});
      upd.push_back({pt[1].x+1, -1, pt[0].y, -1, i});
    }
  }
  sort(upd.begin(), upd.end());
  for (int i = 0; i < v.size(); i++) {
    array<Point,2> pt = v[i];
    if (pt[1] < pt[0]) swap(pt[0], pt[1]);
    if (pt[0].x == pt[1].x) same_hor.push_back({pt[0].x, pt[0].y, pt[1].y, i});
    else same_ver.push_back({pt[0].y, pt[0].x, pt[1].x, i});
  }
  sort(same_hor.begin(), same_hor.end());
  sort(same_ver.begin(), same_ver.end());
  sort(compres.begin(), compres.end());
  compres.erase(unique(compres.begin(), compres.end()), compres.end());
  int ans_r = manhattan(v[0][0], v[0][1]);
  for (int i = 1; i < n; i++) {
    ans_r += manhattan(v[i][0], v[i][1]) + 1;
  }
  auto check = [&](int x)->bool{
    return solve1(x) || solve2(x);
  };
  if (!check(n-1)) {
    cout << ans1 << '\n';
    return 0;
  }
  int l = 1, r = n-1;
  while (l < r) {
    int m = l + r >> 1;
    if (check(m)) r = m;
    else l = m + 1;
  }
  ans_r = 0;
  for (int i = 0; i < l; i++) {
    ans_r += manhattan(v[i][0], v[i][1]) + 1;
  }
  int ek = manhattan(v[l][0], v[l][1]);
  bool swp = false;
  Point ptl1 = v[l][0];
  Point ptl2 = v[l][1];
  if (ptl1.x != ptl2.x) {
    swp = true;
    swap(ptl1.x, ptl1.y);
    swap(ptl2.x, ptl2.y);
  }
  for (int i = 0; i < l; i++) {
    Point pt1 = v[i][0];
    Point pt2 = v[i][1];
    if (swp) {
      swap(pt1.x, pt1.y);
      swap(pt2.x, pt2.y);
    }
    if (pt2 < pt1) swap(pt1, pt2);
    if (pt1.x == pt2.x) {
      if (pt1.x != ptl1.x) continue;
      int lma = max(min(ptl1.y, ptl2.y), pt1.y);
      int rmi = min(max(ptl1.y, ptl2.y), pt2.y);
      if (lma > rmi) continue;
      Point pt(pt1.x, lma);
      ek = min(ek, manhattan(pt, ptl1));
      pt.y = rmi;
      ek = min(ek, manhattan(pt, ptl1));
    } else {
      if (pt1.x <= ptl1.x && pt2.x >= ptl1.x) {
        if (min(ptl1.y, ptl2.y) <= pt1.y && pt1.y <= max(ptl1.y, ptl2.y)) {
          Point pt(ptl1.x, pt1.y);
          ek = min(ek, manhattan(pt, ptl1));
        }
      }
    }
  }
  cout << min(ans_r + ek, ans1) << '\n';
}