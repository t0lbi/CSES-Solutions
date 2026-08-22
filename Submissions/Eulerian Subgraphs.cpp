// Submission Timestamp: 2022-11-28 20:40:29

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
int fpow(int base, int pow){
	if (pow==0) return 1ll;
	base%=MOD;
	if (pow&1) return (base*fpow(base*base, pow/2))%MOD;
	return fpow(base*base, pow/2)%MOD;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<vector<int>> arr(n);
		vector<int> vis(n,0ll);
		vector<int> nods;
		auto dfs = [&](int node, auto dfs, int lnode = -1)->int64_t{
			int rval = 0ll;
			vis[node]=1ll;
			nods.push_back(node);
			for (int i = 0; i < arr[node].size(); i++){
				if (arr[node][i]==lnode) continue;
				if (vis[arr[node][i]]==2) continue;
				if (vis[arr[node][i]]==1) rval++;
				else rval+=dfs(arr[node][i], dfs, node);
			}
			return rval;
		};
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		int ans = 1;
		for (int i = 0; i < n; ++i)
		{
			if (vis[i]) continue;
			ans*=fpow(2,dfs(i,dfs)/2);
			ans%=MOD;
			while (nods.size()){
				vis[nods.back()]=2ll;
				nods.pop_back();
			}
		}
		cout<<ans<<endl;
	}
}