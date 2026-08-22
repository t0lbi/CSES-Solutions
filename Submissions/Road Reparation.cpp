// Submission Timestamp: 2022-10-14 13:16:05

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
vector<int> par;
int find_par(int node){
	if (par[node]==node) return node;
	return par[node]=find_par(par[node]);
}
struct edge{
	int u, v, c;
	friend inline bool operator<(const edge& a, const edge& b){
		return a.c<b.c;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		par.resize(n);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i;
		}
		deci(m);
		vector<edge> arr(m);
		for (int i = 0; i < m; ++i)
		{
			cin>>arr[i].u>>arr[i].v>>arr[i].c;
			arr[i].u--;
			arr[i].v--;
		}
		sortarr(arr);
		int ans = 0;
		for (int i = 0; i < m; i++){
			arr[i].u=find_par(arr[i].u);
			arr[i].v=find_par(arr[i].v);
			if (arr[i].u==arr[i].v) continue;
			ans+=arr[i].c;
			par[arr[i].u]=arr[i].v;
		}
		for (int i = 0; i < n; ++i)
		{
			find_par(i);
		}
		sortarr(par);
		if (par[0]==par[n-1]) cout<<ans<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
}