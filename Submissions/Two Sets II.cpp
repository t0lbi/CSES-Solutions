// Submission Timestamp: 2022-09-29 22:16:10

#define author tolbi
#pragma optimize("Bismillahirrahmanirrahim")
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
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<bi)
const int MOD = 1e9+7;
using namespace std;
int n, x;
vector<vector<int>> dp;
int fpow(int base, int pow){
	base%=MOD;
	if (!pow) return 1ll;
	if (pow&1) return (base*(fpow(base*base,pow/2)%MOD))%MOD;
	return fpow(base*base,pow/2)%MOD;
}
int f(int node, int val){
	if (val<0) return 0ll;
	if (val==0) return 1ll;
	if (node == 0) return 0ll;
	if (dp[node][val]+1) return dp[node][val];
	return dp[node][val]=(f(node-1,val)+f(node-1,val-node))%MOD;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;
		if ((n*(n+1))%4){
			cout<<0<<endl;
			continue;
		}
		x=(n*(n+1))/4;
		dp.clear();
		dp.resize(n+1,vector<int>(x+1,-1));
		cout<<(f(n,x)*fpow(2,MOD-2))%MOD<<endl;
	}
}