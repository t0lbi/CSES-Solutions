// Submission Timestamp: 2025-06-25 16:01:59

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		int x;cin>>x;
		mp[x]++;
	}
	int ans = 1;
	for (auto it : mp){
		ans = (1ll * ans * (it.second+1))%MOD;
	}
	ans--;
	if (ans < 0) ans += MOD;
	cout<<ans<<'\n';
}