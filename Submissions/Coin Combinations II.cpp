// Submission Timestamp: 2022-09-27 17:53:30

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(k);
		vint(arr(n));
		cinarr(arr);
		vector<vector<int>> dp(2,vector<int>(k+1,0));
		for (int i = 0; i < 2; ++i)
		{
			dp[i][k]=1ll;
		}
		sortrarr(arr);
		for (int i = 0; i < n; i++){
			for (int j = k-1; j>=0;j--){
				int huh = 0;
				int heh = 0;
				if (i>0) heh = dp[0][j];
				if (j+arr[i]<=k) huh = dp[1][j+arr[i]];
				dp[1][j]=heh+huh;
				dp[1][j]%=MOD;
			}
			swap(dp[1],dp[0]);
		}
		int ans = dp[0][0];
		if (ans>=INT_MAX) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}