// Submission Timestamp: 2025-06-25 15:45:49

#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[1000][1000];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	queue<array<int,3>> q;
	q.push({0,0,0});
	while (q.size()){
		auto [x,y,w] = q.front();
		q.pop();
		if (min(x, y) < 0 || max(x, y) >= n) continue;
		if (ans[x][y]) continue;
		ans[x][y] = w+1;
		for (int i = -1; i <= 2; i += 2){
			for (int j = -1; j <= 1; j += 2){
				q.push({x+2*i, y+j, w+1});
				q.push({x+i, y+2*j, w+1});
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j){
			cout<<ans[i][j]-1<<" ";
		}
		cout<<'\n';
	}
}