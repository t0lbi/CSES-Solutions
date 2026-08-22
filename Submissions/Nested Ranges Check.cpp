// Submission Timestamp: 2025-06-25 20:29:48

#include <bits/stdc++.h>
using namespace std;
#define coutarr(x) for (auto it : x) cout<<it<<" ";cout<<'\n';
#define int long long
const int MOD = 1e9+7;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<array<int,3>> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2] = i;
	}
	sort(arr.begin(), arr.end(), [&](array<int,3> &a, array<int,3> &b){
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});
	int ma = 0;
	vector<int> ans1(n), ans2(n);
	for (int i = 0; i < n; i++){
		if (ma >= arr[i][1]) ans2[arr[i][2]] = 1;
		ma = max(ma, arr[i][1]);
	}
	int mi = 1000000023;
	for (int i = n-1; i >= 0; i--){
		if (mi <= arr[i][1]) ans1[arr[i][2]] = 1;
		mi = min(mi, arr[i][1]);
	}
	coutarr(ans1);
	coutarr(ans2);
}