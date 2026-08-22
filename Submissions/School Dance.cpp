// Submission Timestamp: 2022-10-28 19:59:03

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
vector<vector<int>> kul;
vector<vector<int>> arr;
vector<int> way;
vector<bool> vis;
int n,m;
bool dfs(int node){
	vis[node]=true;
	way.push_back(node);
	if (node<n){
		for (int i = 0; i < arr[node].size(); i++){
			if (kul[node][arr[node][i]]) continue;
			if (vis[arr[node][i]]) continue;
			if (dfs(arr[node][i])) return true;
		}
	}
	else {
		bool boolean = true;
		for (int i = 0; i < arr[node].size(); i++){
			if (!kul[node][arr[node][i]]) continue;
			boolean = false;
			if (vis[arr[node][i]]) continue;
			if (dfs(arr[node][i])) return true;
		}
		if (boolean) return true;
	}
	way.pop_back();
	return false;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>m;deci(k);
		arr.resize(n+m);
		kul.resize(n+m,vector<int>(n+m,0));
		for (int i = 0; i < k; i++){
			deci(u);deci(v);
			arr[u-1].push_back(n+v-1);
			arr[n+v-1].push_back(u-1);
		}
		for (int i = 0; i < n; i++){
			way.clear();
			vis.clear();
			vis.resize(n+m,false);
			dfs(i);
			for (int j = 1; j < way.size(); j++){
				if (j%2){
					kul[way[j]][way[j-1]]=true;
					kul[way[j-1]][way[j]]=true;
				}
				else {
					kul[way[j]][way[j-1]]=false;
					kul[way[j-1]][way[j]]=false;
				}
			}
		}
		vector<pair<int,int>> ansarr;
		for (int i = 0; i < n; i++){
			for (int j = n; j < n+m; j++){
				if (kul[i][j]){
					ansarr.push_back({i+1,j-n+1});
				}
			}
		}
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].first<<" "<<ansarr[i].second<<endl;
		}
	}
}