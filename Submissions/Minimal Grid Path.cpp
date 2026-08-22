// Submission Timestamp: 2025-06-28 13:24:55

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<string> s(n);
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	vector<pair<int,int>> cand;
	cand.push_back({0,0});
	string ans(1,s[0][0]);
	for (int _ = 0; _ < 2 * n - 2; _++){
		char mn = 'Z';
		vector<pair<int,int>> n_cand;
		for (auto [x,y] : cand){
			if (x+1 < n && !vis[x+1][y]){
				vis[x+1][y]=true;
				if (s[x+1][y] < mn){
					mn = s[x+1][y];
					n_cand.clear();
				}
				if (s[x+1][y] == mn){
					n_cand.push_back({x+1,y});
				}
			}
			if (y+1 < n && !vis[x][y+1]){
				vis[x][y+1]=true;
				if (s[x][y+1] < mn){
					mn = s[x][y+1];
					n_cand.clear();
				}
				if (s[x][y+1] == mn){
					n_cand.push_back({x,y+1});
				}
			}
		}
		swap(cand,n_cand);
		ans.push_back(mn);
	}
	cout<<ans<<'\n';
}