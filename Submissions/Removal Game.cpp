// Submission Timestamp: 2025-06-28 13:35:07

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	vector<vector<int>> dp(n+2, vector<int>(n+2,0));
	for (int l = n; l >= 1; l--){
		for (int r = l; r <= n; r++){
			int turn = n-(r-l+1);
			if (turn & 1){
				dp[l][r] = min({dp[l+1][r],dp[l][r-1]});
			}
			else {
				dp[l][r] = max({dp[l+1][r]+a[l],dp[l][r-1]+a[r]});
			}
		}
	}
	cout<<dp[1][n]<<'\n';
}