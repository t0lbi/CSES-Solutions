// Submission Timestamp: 2025-06-25 15:41:31

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<int>> row(n, vector<int>(2*n+2));
	vector<vector<int>> col(n, vector<int>(2*n+2));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < 2*n+2; k++){
				if (row[i][k] || col[j][k]) continue;
				cout<<k<<" ";
				row[i][k]=col[j][k]=true;
				break;
			}
		}
		cout<<'\n';
	}
}