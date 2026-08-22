// Submission Timestamp: 2022-11-22 12:24:16

#pragma optimize("Bismillahirrahmanirrahim")
//Allahuekber
//ahmet23 orz...
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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);deci(q);
		vector<vector<int>> arr(n);
		vector<vector<int>> revarr(n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			revarr[v-1].push_back(u-1);
		}
		vector<bool> vis(n,false);
		vector<int> stak;
		auto dfs = [&](int node, auto dfs) -> void{
			vis[node]=true;
			for (int i = 0; i < arr[node].size(); i++){
				if (vis[arr[node][i]]) continue;
				dfs(arr[node][i],dfs);
			}
			stak.push_back(node);
		};
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i]){
				dfs(i,dfs);
			}
		}
		int hueh = 0;
		vector<int> indi(n);
		vis.clear();
		vis.resize(n,false);
		auto dfs2=[&](int node, auto dfs2)->void{
			vis[node]=true;
			indi[node]=hueh;
			for (int i = 0; i < revarr[node].size(); i++){
				if (vis[revarr[node][i]]) continue;
				dfs2(revarr[node][i],dfs2);
			}
		};
		while (stak.size()){
			int crr = stak.back();
			stak.pop_back();
			if (vis[crr]) continue;
			dfs2(crr,dfs2);
			hueh++;
		}
		vector<vector<int>> hh(hueh);
		vector<vector<int>> revhh(hueh);
		vector<int> sz(hueh);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < arr[i].size(); j++){
				if (indi[i]==indi[arr[i][j]]) continue;
				hh[indi[i]].push_back(indi[arr[i][j]]);
				revhh[indi[arr[i][j]]].push_back(indi[i]);
				sz[indi[i]]++;
			}
		}
		queue<int> qu;
		for (int i = 0; i < hueh; i++){
			if (!sz[i]) qu.push(i);
		}
		vector<int> topo;
		while (qu.size()){
			int node = qu.front();
			topo.push_back(node);
			qu.pop();
			for (int i = 0; i < revhh[node].size(); i++){
				sz[revhh[node][i]]--;
				if (!sz[revhh[node][i]]) qu.push(revhh[node][i]);
			}
		}
		vector<bitset<50000>> ansarr(hueh);
		for (int i = 0; i < hueh; ++i)
		{
			ansarr[i].set(i,true);
		}
		for (int j = 0; j < topo.size(); j++){
			int node = topo[j];
			for (int i = 0; i < hh[node].size(); i++){
				ansarr[node]|=ansarr[hh[node][i]];
			}
		}
		int qn = 0;
		while (q--){
			deci(a);deci(b);
			if (ansarr[indi[a-1]][indi[b-1]]){
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
}