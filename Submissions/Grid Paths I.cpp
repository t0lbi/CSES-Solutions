// Submission Timestamp: 2022-09-26 08:56:52

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
vector<vector<int>> dp;
vector<string> arr;
int n;
int f(int x, int y){
	if (x>=n || y>=n) return 0ll;
	if (dp[x][y]!=-1) return dp[x][y];
	if (arr[x][y]=='*') return dp[x][y]=0ll;
	if (x==n-1 && y==n-1) return dp[x][y]=1ll;
	return dp[x][y]=(f(x+1,y)+f(x,y+1))%MOD;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;
		dp.resize(n,vector<int>(n,-1));
		arr.resize(n);
		cinarr(arr);
		cout<<f(0,0)<<endl;
	}
}