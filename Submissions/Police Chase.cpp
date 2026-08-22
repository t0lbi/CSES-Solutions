// Submission Timestamp: 2022-10-28 20:42:26

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
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
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
vector<vector<int>> arr;
vector<vector<int>> kul;
vector<int> par;
bool dfs(int node){
	if (node==arr.size()-1) return true;
	for (int i = 0; i < arr[node].size(); i++){
		if (par[arr[node][i]]!=-1) continue;
		if (!kul[node][arr[node][i]]) continue;
		par[arr[node][i]]=node;
		if (dfs(arr[node][i])) return true;
	}
	return false;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		if (n==1){
			cout<<0<<endl;
			continue;
		}
		arr.resize(n);
		kul.resize(n,vector<int>(n,0));
		par.resize(n);
		vector<pair<int,int>> parr(m);
		vector<pair<int,int>> ansarr;
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			parr[i]={u,v};
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
			kul[u-1][v-1]++;
			kul[v-1][u-1]++;
		}
		while (true){
			fill(par.begin(),par.end(),-1);
			par[0]=/*ahmet*/23;
			if (!dfs(0)) break;
			int node = n-1;
			while (node){
				kul[node][par[node]]++;
				kul[par[node]][node]--;
				node=par[node];
			}
		}
		fill(par.begin(),par.end(),-1);
		par[0]=37;
		dfs(0);
		for (int i = 0; i < m; ++i)
		{
			if ((par[parr[i].first-1]==-1)!=(par[parr[i].second-1]==-1)){
				ansarr.push_back(parr[i]);
			}
		}
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].first<<" "<<ansarr[i].second<<endl;
		}
	}
}