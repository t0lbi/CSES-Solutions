// Submission Timestamp: 2022-09-29 10:52:04

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
vector<int> arr;
int n,m;
vector<vector<int>> dp;
int ab(int a){
	if (a<0) a=-a;
	return a;
}
int f(int node, int last){
	if (last>m || last<=0) return 0ll;
	if (node==n) return 1ll;
	if (dp[node][last]!=-1) return dp[node][last];
	if (arr[node]){
		if (ab(arr[node]-last)>1) return dp[node][last]=0ll;
		return dp[node][last]=f(node+1,arr[node]);
	}
	else {
		return dp[node][last]=(((f(node+1,last+1)+f(node+1,last-1))%MOD)+f(node+1,last))%MOD;
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>m;
		arr.resize(n);
		cinarr(arr);
		dp.resize(n,vector<int>(m+1,-1));
		int ans = 0;
		if (arr[0]){
			ans=f(0,arr[0]);
		}
		else {	
			for (int i = 1; i <= m; i++){
				ans+=f(1,i);
				ans%=MOD;
			}
		}
		cout<<ans<<endl;
	}
}