// Submission Timestamp: 2022-09-29 12:04:32

#define author tolbi
#pragma optimize("Bismillahirrahmanirrahim")//atilla sattı ab :(
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
vector<vector<int>> dp(1000001,vector<int>(2,-1));
int f(int node,int flag){
	if (dp[node][flag]!=-1) return dp[node][flag];
	if (!flag){
		dp[node][0]=0ll;
		return dp[node][0]=(f(node-1,1)+4*f(node-1,0))%MOD;
	}
	else {
		return dp[node][1]=(f(node-1,0)+2*f(node-1,1))%MOD;
	}
}
int32_t main(){
	ios;
	int t=0;
	int tno = 0;
	dp[1][0]=1ll;
	dp[1][1]=1ll;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		cout<<(f(n,0)+f(n,1))%MOD<<endl;
	}
}