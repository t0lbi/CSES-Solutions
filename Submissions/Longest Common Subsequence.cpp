// Submission Timestamp: 2025-06-28 13:13:50

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			dp[i][j] = max({dp[i+1][j+1]+(a[i]==b[j]),dp[i][j+1],dp[i+1][j]});
		}
	}
	cout<<dp[0][0]<<'\n';
	int x=0,y=0;
	while (x < n && y < n){
		if (dp[x+1][y+1]+(a[x]==b[y]) == dp[x][y]){
			if (a[x]==b[y]) cout<<a[x]<<" ";
			x++,y++;
		}
		else if (dp[x][y+1] == dp[x][y]) y++;
		else x++;
	}
	cout<<'\n';
}