// Submission Timestamp: 2025-06-25 15:56:19

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	map<int,int> mp;
	int ma = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int x;cin>>x;
		ma = max(ma, mp[x]);
		mp[x] = i;
		ans += i-ma;
	}
	cout<<ans<<'\n';
}