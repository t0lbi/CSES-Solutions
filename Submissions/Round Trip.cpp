// Submission Timestamp: 2022-10-12 09:12:00

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
vector<vector<int>> arr;
vector<bool> vis;
vector<int> ans;
vector<int> crr;
int snode=-1;
void find(int node, int lnode = -1){
	vis[node]=true;
	if (snode!=-1) return;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		if (snode!=-1) return;
		if (vis[arr[node][i]]){
			snode=arr[node][i];
			break;
		}
		if (snode!=-1) return;
		find(arr[node][i],node);
	}
}
void dfs(int node, int lnode=-1){
	vis[node]=true;
	crr.push_back(node+1);
	for (int i = 0; i < arr[node].size(); i++){
		if (ans.size()) return;
		if (arr[node][i]==lnode) continue;
		if (arr[node][i]==snode){
			crr.push_back(snode+1);
			ans=crr;
			return;
		}
		if (vis[arr[node][i]]) continue;
		dfs(arr[node][i],node);
	}
	crr.pop_back();
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		vis.resize(n,false);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i]) find(i);
			if (snode+1) break;
		}
		if (snode==-1){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		vis.clear();
		vis.resize(n,false);
		dfs(snode);
		cout<<ans.size()<<endl;
		coutarr(ans);
	}
}