// Submission Timestamp: 2022-10-18 15:52:16

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
vector<int> ansarr;
vector<vector<int>> arr;
map<int,bool> vis;
void dfs(int node){
	while (arr[node].size()){
		int next = arr[node][arr[node].size()-1];
		arr[node].pop_back();
		if (vis[node*1000000+next]) continue;
		vis[node*1000000+next]=true;
		vis[next*1000000+node]=true;
		dfs(next);
	}
	ansarr.push_back(node+1);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		deci(m);
		arr.resize(n);
		vector<int> gir(n,0);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
			gir[u-1]++;
			gir[v-1]++;
		}
		bool boolean = true;
		for (int i = 0; i < n; i++){
			if (gir[i]%2){
				boolean=false;
				break;
			}
		}
		if (!boolean){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		ansarr.clear();
		dfs(0);
		if (ansarr.size()!=m+1 || (ansarr[0]!=1) || ansarr[ansarr.size()-1]!=1){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		coutarr(ansarr);
	}
}
