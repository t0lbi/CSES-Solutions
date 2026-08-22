// Submission Timestamp: 2022-10-18 11:17:48

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
vector<vector<int>> revarr;
vector<int> stak;
vector<int> component;
vector<bool> vis;
int crr = 1;
void dfs(int node){
	vis[node]=true;
	for (int i = 0; i < arr[node].size(); i++){
		if (vis[arr[node][i]]) continue;
		dfs(arr[node][i]);
	}
	stak.push_back(node);
}
void dfs2(int node){
	vis[node]=true;
	component[node]=crr;
	for (int i = 0; i < revarr[node].size(); i++){
		if (vis[revarr[node][i]]) continue;
		dfs2(revarr[node][i]);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		revarr.resize(n);
		component.resize(n);
		vis.resize(n,false);
		crr=1;
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			revarr[v-1].push_back(u-1);
		}
		for (int i = 0; i < n; i++){
			if (vis[i]) continue;
			dfs(i);
		}
		vis.clear();
		vis.resize(n,false);
		while (stak.size()){
			int node = stak[stak.size()-1];
			stak.pop_back();
			if (vis[node]) continue;
			dfs2(node);
			crr++;
		}
		cout<<crr-1<<endl;
		coutarr(component);
	}
}