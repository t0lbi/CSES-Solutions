// Submission Timestamp: 2025-06-28 22:06:57

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;cin>>n>>q;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int LOG = 30;
	vector<vector<int>> st(n, vector<int>(LOG,n));
	vector<int> stk(1, n);
	for (int i = n-1; i >= 0; i--){
		while (stk.size() > 1 && arr[i] >= arr[stk.back()]) stk.pop_back();
		st[i][0] = stk.back();
		stk.push_back(i);
	}
	for (int j = 1; j < LOG; j++){
		for (int i = 0; i < n; i++){
			if (st[i][j-1] == n) continue;
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}

	while (q--){
		int l, r;cin>>l>>r;l--,r--;
		int ans = 0;
		for (int i = LOG-1; i >= 0; i--){
			if (st[l][i] <= r){
				l = st[l][i];
				ans += (1<<i);
			}
		}
		cout<<ans+1<<'\n';
	}
}