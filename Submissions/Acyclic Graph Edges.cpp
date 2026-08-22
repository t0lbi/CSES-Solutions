// Submission Timestamp: 2023-04-23 17:58:01

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
		vector<vector<int>> arr(n);
		vector<pair<int,int>> ed(m);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			ed[i]={u,v};
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		vector<int> vis(n,0);
		map<pair<int,int>,bool> mp;
		map<pair<int,int>,bool> vr;
		auto merge = [&](int a, int b)->void{
			int u = a, v = b;
			if (a>b) swap(a,b);
			if (mp[{a,b}]) return;
			mp[{a,b}]=true;
			vr[{u+1,v+1}]=true;
		};
		vector<int> gez;
		auto dfs = [&](int node, int lnode, auto dfs)->void{
			vis[node]=1;
			gez.push_back(node);
			for (int i = 0; i < arr[node].size(); i++){
				if (vis[arr[node][i]]==1){
					merge(arr[node][i],node);
				}
				else {
					merge(node,arr[node][i]);
				}
				if (!vis[arr[node][i]]) dfs(arr[node][i],node,dfs);
			}
		};
		for (int i = 0; i < n; i++){
			if (vis[i]) continue;
			dfs(i,-1,dfs);
			for (auto &it : gez) {
				vis[it]=2;
			}
			gez.clear();
		}
		for (int i = 0; i < m; i++){
			if (vr[ed[i]]) cout<<ed[i].first<<" "<<ed[i].second<<endl;
			else cout<<ed[i].second<<" "<<ed[i].first<<endl;
		}
	}
}