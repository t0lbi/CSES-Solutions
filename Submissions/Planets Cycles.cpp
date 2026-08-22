// Submission Timestamp: 2022-10-18 10:22:17

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
vector<int> comp;//ok component number
vector<int> uza;//ok component size
vector<int> arr;//ok graph
vector<bool> dong;//ok in cycle or not
vector<bool> vis;//ok not persistent
vector<pair<int,int>> dist;//neares cycle element and distance to it
int crr=0;
int dongdfs(int node, int dept){
	vis[node]=true;
	comp[node]=crr;
	if (!vis[arr[node]-1]) return uza[node]=dongdfs(arr[node]-1,dept+1);
	return uza[node]=dept+1;
}
void dfs(int node){
	if (dist[node].first!=-1) return;
	if (dong[node]){
		dist[node].first=node;
		dist[node].second=0;
	}
	else {
		dfs(arr[node]-1);
		comp[node]=comp[arr[node]-1];
		dist[node].first=dist[arr[node]-1].first;
		dist[node].second=dist[arr[node]-1].second+1;
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		comp.resize(n);
		uza.resize(n,-1);
		arr.resize(n);
		dong.resize(n,true);
		vis.resize(n,false);
		dist.resize(n,{-1,-1});
		cinarr(arr);
		vector<int> git(n,0);
		for (int i = 0; i < n; ++i)
		{
			git[arr[i]-1]++;
		}
		queue<int> q;
		for (int i = 0; i < n; ++i){
			if (!git[i]) q.push(i);
		}
		while (q.size()){
			int node = q.front();
			q.pop();
			dong[node]=false;
			git[arr[node]-1]--;
			if (!git[arr[node]-1]) q.push(arr[node]-1);
		}
		crr=0;
		for (int i = 0; i < n; i++){
			if (!vis[i] && dong[i]){
				dongdfs(i,0);
				crr++;
			}
		}
		for (int i = 0; i < n; i++){
			dfs(i);
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<dist[i].second+uza[dist[i].first]<<" ";
		}
		cout<<endl;
	}
}