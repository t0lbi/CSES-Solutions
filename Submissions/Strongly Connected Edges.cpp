// Submission Timestamp: 2023-04-23 22:35:18

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
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
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<int> par(n);
		iota(par.begin(), par.end(), 0ll);
		auto find = [&](int node, auto find)->int{
			if (par[node]==node) return node;
			return par[node]=find(par[node],find);
		};
		vector<pair<int,int>> ed(m);
		vector<vector<int>> arr(n);
		for (int i = 0; i < m; i++){
			cin>>ed[i].first>>ed[i].second;
			auto [u,v] = ed[i];
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
			u=find(u-1,find);
			v=find(v-1,find);
			if (u<v) swap(u,v);
			par[u]=v;
		}
		vector<int> dept(n,-1);
		dept[0]=0;
		map<pair<int,int>,bool> mp;
		auto merge = [&](int a, int b)->void{
			a++,b++;
			if (mp.count({a,b}) || mp.count({b,a})) return;
			mp[{a,b}]=true;
		};
		bool boolean=true;
		auto dfs = [&](int node, int lnode, auto dfs)->int{
			int hh = INF;
			for (int i = 0; i < arr[node].size(); i++){
				if (arr[node][i]==lnode) continue;
				if (dept[arr[node][i]]==-1){
					dept[arr[node][i]]=dept[node]+1ll;
					merge(node,arr[node][i]);
					int crr = dfs(arr[node][i],node,dfs);
					hh=min(hh,crr);
					if (crr>dept[node]){
						boolean=false;
					}
				}
				else {
					hh=min(hh,dept[arr[node][i]]);
					merge(node,arr[node][i]);
				}
			}
			return hh;
		};
		for (int i = 0; i < par.size(); i++){
			par[i]=find(par[i],find);
			if (par[i]) {boolean=false;break;}
		}
		dfs(0,-1,dfs);
		if (boolean){
			for (int i = 0; i < m; i++){
				if (mp[ed[i]]) cout<<ed[i].first<<" "<<ed[i].second<<endl;
				else cout<<ed[i].second<<" "<<ed[i].first<<endl;
			}
		}
		else cout<<"IMPOSSIBLE"<<endl;
	}
}