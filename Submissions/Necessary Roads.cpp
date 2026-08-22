// Submission Timestamp: 2022-11-25 12:43:23

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
vector<vector<bool>> back;
vector<vector<int>> arr;
vector<int> dep;
vector<bool> vis;
void dfscom(int node, int lnode = -1){
	if (lnode==-1) dep[node]=0ll;
	else dep[node]=dep[lnode]+1ll;
	vis[node]=true;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		if (vis[arr[node][i]]) continue;
		back[node][i]=false;
		dfscom(arr[node][i],node);
	}
}
vector<pair<int,int>> ansarr;
int dfs(int node, int lnode=-1){
	int rval = INF;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		if (back[node][i]){
			rval=min(rval,dep[arr[node][i]]);
		}
		else {
			int b = dfs(arr[node][i],node);
			rval=min(rval,b);
			if (b>dep[node]){
				ansarr.push_back({node,arr[node][i]});
			}
		}
	}
	return rval;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		dep.resize(n);
		vis.resize(n,false);
		back.resize(n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
			back[u-1].push_back(true);
			back[v-1].push_back(true);
		}
		dfscom(0);
		dfs(0);
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].first+1<<" "<<ansarr[i].second+1<<endl;
		}
	}
}