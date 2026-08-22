// Submission Timestamp: 2022-10-14 13:21:29

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
vector<int> sz;
int find_par(int node){
	if (par[node]==node) return node;
	return par[node]=find_par(par[node]);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		par.resize(n);
		sz.resize(n,1);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i;
		}
		int ans=n;
		int lar = 1;
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			u=find_par(u-1);
			v=find_par(v-1);
			if (u!=v) {
				ans--;
				par[u]=v;
				sz[v]+=sz[u];
				lar=max(lar,sz[v]);
			}
			cout<<ans<<" "<<lar<<endl;
		}
	}
}