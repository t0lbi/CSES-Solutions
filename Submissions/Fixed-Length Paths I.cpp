// Submission Timestamp: 2022-11-02 10:55:56

#pragma optimize("Bismillahirrahmanirrahim")
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
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
vector<int> sz;
long long ans;
int n,k;
void find_sz(int node, int lnode = -1){
	sz[node]=1ll;
	for (int i = 0; i < (int)arr[node].size(); i++){
		if (arr[node][i]==lnode || vis[arr[node][i]]) continue;
		find_sz(arr[node][i],node);
		sz[node]+=sz[arr[node][i]];
	}
}
int find_centroid(int des, int node, int lnode=-1){
	for (int i = 0; i < (int)arr[node].size(); i++){
		if (arr[node][i]==lnode || vis[arr[node][i]]) continue;
		if (sz[arr[node][i]]>des) return find_centroid(des,arr[node][i],node);
	}
	return node;
}
vector<long long> ka;
int md = 0;
void dfs(int node, bool inc, int lnode = -1, int dept = 1){
	if (dept==k) {
		if (inc) return;
		ans++;
		return;
	}
	if (inc) ans+=ka[k-dept];
	else ka[dept]++;
	md = max(md,dept);
	for (int i = 0; i < (int)arr[node].size(); i++){
		if (vis[arr[node][i]] || arr[node][i]==lnode) continue;
		dfs(arr[node][i],inc,node,dept+1);
	}
}
void centroid_decomp(int node){
	find_sz(node);
	if (sz[node]==1) return;
	node = find_centroid(sz[node]/2,node);
	vis[node]=true;
	for (int i = 0; i < (int)arr[node].size(); i++){
		if (vis[arr[node][i]]) continue;
		dfs(arr[node][i],true);
		dfs(arr[node][i],false);
	}
	fill(ka.begin(),ka.begin()+md+1,0);
	md=0;
	for (int i = 0; i < (int)arr[node].size(); ++i){
		if (vis[arr[node][i]]) continue;
		centroid_decomp(arr[node][i]);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>k;
		arr.resize(n);
		vis.resize(n,false);
		sz.resize(n);
		ka.resize(k,0);
		for (int i = 0; i < n-1; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		centroid_decomp(0);
		cout<<ans<<endl;
	}
}