// Submission Timestamp: 2026-06-02 05:18:23

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;cin>>n>>m;
  vector<vector<int>> arr(n);
  vector<vector<int>> r_arr(n);
  vector<int> scc(n);
  for (int i = 0; i < m; ++i)
  {
    int u, v;cin>>u>>v;
    arr[u-1].push_back(v-1);
    r_arr[v-1].push_back(u-1);
  }
  vector<int> eul;
  auto dfs = [&](int node, auto &&rec)->void{
    if (scc[node] == 1) return;
    scc[node]=1;
    for (auto it : arr[node]) {
      rec(it, rec);
    }
    eul.push_back(node);
  };
  for (int i = 0; i < n; ++i)
  {
    dfs(i,dfs);
  }
  reverse(eul.begin(),eul.end());
  int cur = 0;
  scc.assign(n,-1);
  queue<int> q;
  vector<int> rep;
  for (auto x : eul) {
    if (scc[x] == -1) {
      q.push(x);
      while (q.size()) {
        int node = q.front();
        q.pop();
        if (scc[node] != -1) continue;
        scc[node] = cur;
        for (auto it : r_arr[node]) {
          q.push(it);
        }
      }
      cur++;
      rep.push_back(x+1);
    }
  }
  if (cur == 1) {
    cout << "0\n";
    return 0;
  }
  vector<vector<int>> tree(cur);
  vector<vector<int>> r_tree(cur);
  vector<int> in(cur);
  vector<int> out(cur);
  for (int i = 0; i < n; ++i)
  {
    for (auto j : arr[i]) {
      if (scc[i] == scc[j]) continue;
      tree[scc[i]].push_back(scc[j]);
      r_tree[scc[j]].push_back(scc[i]);
      out[scc[i]]++;
      in[scc[j]]++;
    }
  }
  bool swp = false;
  if (count(in.begin(),in.end(),0) > count(out.begin(),out.end(),0)) {
    swap(in,out);
    swap(tree,r_tree);
    swp = true;
  }
  vector<int> S;
  vector<int> T;
  for (int i = 0; i < cur; ++i)
  {
    if (in[i] == 0) S.push_back(i);
  }
  for (int i = 0; i < cur; ++i)
  {
    if (out[i] == 0) T.push_back(i);
  }
  vector<int> dp(cur,-1);
  for (int i = 0; i < out.size(); ++i)
  {
    if (out[i] == 0) {
      dp[i]=i;
      q.push(i);
    }
  }
  while (q.size()) {
    int node = q.front();
    q.pop();
    for (auto it : r_tree[node]) {
      out[it]--;
      if (out[it] == 0) {
        dp[it] = dp[node];
        q.push(it);
      }
    }
  }
  vector<pair<int,int>> ans;
  vector<bool> tS(cur);
  vector<bool> tT(cur);
  for (auto it : S) {
    if (!tT[dp[it]]) {
      tS[it]=tT[dp[it]]=true;
      ans.push_back({dp[it],it});
      continue;
    }
    for (auto it2 : tree[it]) {
      if (!tT[dp[it2]]) {
        tS[it]=tT[dp[it2]]=true;
        ans.push_back({dp[it2],it});
        break;
      }
    }
  }
  int fi = ans[0].second;
  for (int i = 0; i+1 < ans.size(); ++i)
  {
    ans[i].second=ans[i+1].second;
  }
  ans.back().second = fi;
  while (S.size() && T.size()) {
    if (tS[S.back()]) {
      S.pop_back();
    } else if (tT[T.back()]) {
      T.pop_back();
    } else {
      ans.push_back({T.back(),S.back()});
      S.pop_back();
      T.pop_back();
    }
  }
  for (auto it : T) {
    if (!tT[it]) ans.push_back({it, ans[0].second});
  }
 
  if (swp) {
    for (auto &it : ans) {
      swap(it.first, it.second);
    }
  }
  cout<<ans.size()<<'\n';
  for (auto [a1, a2] : ans) {
    cout<<rep[a1]<<' '<<rep[a2]<<'\n';
  }
}