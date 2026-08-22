// Submission Timestamp: 2022-09-27 16:56:26

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
vector<vector<int>> arr;
vector<vector<int>> dp;
int n;
int f(int node, int flag){
	flag|=tol(node);
	if (dp[node][flag]!=-1) return dp[node][flag];
	if (node == n-1) {
		if (flag+1==tol(n)) return dp[node][flag]=1ll;
		return dp[node][flag]=0ll;
	}
	dp[node][flag]=0ll;
	for (int i = 0; i < arr[node].size(); i++){
		if (tol(arr[node][i])&flag) continue;
		dp[node][flag]+=f(arr[node][i],flag);
		dp[node][flag]%=MOD;
	}
	return dp[node][flag];
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;deci(m);
		arr.clear();
		arr.resize(n);
		dp.clear();
		dp.resize(n,vector<int>(tol(n),-1));
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
		}
		cout<<f(0,0)<<endl;
	}
}