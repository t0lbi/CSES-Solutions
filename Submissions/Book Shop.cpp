// Submission Timestamp: 2022-09-28 09:46:00

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
		vector<pair<int,int>> arr(n);
		for (auto &it : arr) cin>>it.first;
		for (auto &it : arr) cin>>it.second;
		vector<vector<int>> dp(2,vector<int>(k+1));
		for (int j = n; j >= 0; j--){
			for (int i = 0; i <= k; i++){
				int hehe = 0ll;
				if (j<n-1 && i-arr[j].first>=0) hehe = dp[1][i-arr[j].first]+arr[j].second;
				else if (j==n-1 && i-arr[j].first>=0) hehe = arr[j].second;
				int huhu = 0ll;
				if (j<n-1) huhu = dp[1][i];
				dp[0][i]=max(huhu,hehe);
			}
			swap(dp[0],dp[1]);
		}
		cout<<dp[1][k]<<endl;
	}
}
