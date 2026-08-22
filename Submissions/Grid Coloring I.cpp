// Submission Timestamp: 2025-06-25 15:52:08

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;cin>>n>>m;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (arr[i][j] <= 'B') arr[i][j] += 2;
			else arr[i][j] -= 2;
			if ((arr[i][j]&1) && ((i+j)&1)) arr[i][j]++;
			else if (!(arr[i][j]&1) && !((i+j)&1)) arr[i][j]--;
		}
		cout<<arr[i]<<'\n';
	}
}