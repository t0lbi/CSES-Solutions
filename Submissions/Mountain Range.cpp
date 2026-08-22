// Submission Timestamp: 2025-06-28 13:58:10

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	vector<pair<int,int>> topo(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		topo[i] = {a[i], i};
	}
	vector<int> left(n), right(n);
	vector<int> stk(n,-1);
	for (int i = n-1; i >= 0; i--){
		while (stk.size()>1 && a[i] >= a[stk.back()]) stk.pop_back();
		right[i] = stk.back();
		stk.push_back(i);
	}
	while (stk.size() > 1) stk.pop_back();
	for (int i = 0; i < n; i++){
		while (stk.size() > 1 && a[i] >= a[stk.back()]) stk.pop_back();
		left[i] = stk.back();
		stk.push_back(i);
	}
	vector<int> dp(n);
	sort(topo.rbegin(), topo.rend());
	for (auto [_,i] : topo){
		dp[i] = 1;
		if (left[i] != -1) dp[i] = max(dp[i], dp[left[i]]+1);
		if (right[i] != -1) dp[i] = max(dp[i], dp[right[i]]+1);
	}
	cout<<*max_element(dp.begin(), dp.end())<<'\n';
}