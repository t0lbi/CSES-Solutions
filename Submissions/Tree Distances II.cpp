// Submission Timestamp: 2022-10-06 18:15:03

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
vector<int> g;
vector<int> f;
vector<int> sz;
vector<int> ansarr;
vector<vector<int>> arr;
void dfs(int node, int lnode){
	g[node]+=f[node];
	sz[node]=1;
	f[node]=0;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs(arr[node][i],node);
		f[node]+=sz[arr[node][i]]+f[arr[node][i]];
		sz[node]+=sz[arr[node][i]];
	}
}
void dfs2(int node, int lnode){
	if (lnode+1){
		g[node]=arr.size()-sz[node]+g[lnode]+f[lnode]-sz[node]-f[node];
	}
	else g[node]=0ll;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs2(arr[node][i],node);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		g.resize(n);
		f.resize(n);
		arr.resize(n);
		sz.resize(n);
		for (int i = 0; i < n-1; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		ansarr.resize(n);
		dfs(0,-1);
		dfs2(0,-1);
		for (int i = 0; i < n; ++i)
		{
			ansarr[i]=f[i]+g[i];
		}
		coutarr(ansarr);
	}
}