// Submission Timestamp: 2022-09-29 16:38:50

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		dp.resize(n+1,vector<int>(m+1,-1));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (i==j){
					dp[i][j]=0ll;
				}
				else {
					dp[i][j]=MOD;
					for (int z = 1; z<i; z++){
						dp[i][j]=min(dp[i][j],1ll+dp[z][j]+dp[i-z][j]);
					}
					for (int z = 1; z<j; z++){
						dp[i][j]=min(dp[i][j],1ll+dp[i][z]+dp[i][j-z]);
					}
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
}