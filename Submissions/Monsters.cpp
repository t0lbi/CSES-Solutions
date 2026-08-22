// Submission Timestamp: 2022-10-13 11:41:09

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
/*
#define endl '\n'
*/
using namespace std;
int n,m;
vector<string> arr;
vector<vector<int>> dp;
vector<vector<int>> dp2;
vector<vector<bool>> vis;
string ans = "NO";
int target;
string crr;
void dfs(int x, int y){
	vis[x][y]=true;
	if (x*m+y==target){
		ans=crr;
		rev(ans);
		return;
	}
	if (x && dp2[x-1][y]<dp[x-1][y] && !vis[x-1][y]){
		crr+='D';
		dfs(x-1,y);
		crr.pop_back();
	}
	if (x<n-1 && dp2[x+1][y]<dp[x+1][y] && !vis[x+1][y]){
		crr+='U';
		dfs(x+1,y);
		crr.pop_back();
	}
	if (y && dp2[x][y-1]<dp[x][y-1] && !vis[x][y-1]){
		crr+='R';
		dfs(x,y-1);
		crr.pop_back();
	}
	if (y<m-1 && dp2[x][y+1]<dp[x][y+1] && !vis[x][y+1]){
		crr+='L';
		dfs(x,y+1);
		crr.pop_back();
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>m;
		arr.resize(n);
		cinarr(arr);
		dp.resize(n,vector<int>(m,MOD));
		dp2.resize(n,vector<int>(m,MOD));
		vis.resize(n,vector<bool>(m,false));
		vector<int> hehe;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j]=='M') hehe.push_back(i*m+j);
				if (arr[i][j]=='A') target=i*m+j;
			}
		}
		int ind = 0;
		while (hehe.size()>0){
			vector<int> narr;
			while (hehe.size()){
				int x = hehe[hehe.size()-1]/m;
				int y = hehe[hehe.size()-1]%m;
				hehe.pop_back();
				if (dp[x][y]!=MOD) continue;
				dp[x][y]=ind;
				if (x && arr[x-1][y]!='#' && dp[x-1][y]==MOD){
					narr.push_back(x*m+y-m);
				}
				if (x<n-1 && arr[x+1][y]!='#' && dp[x+1][y]==MOD){
					narr.push_back(x*m+y+m);
				}
				if (y && arr[x][y-1]!='#' && dp[x][y-1]==MOD){
					narr.push_back(x*m+y-1);
				}
				if (y<m-1 && arr[x][y+1]!='#' && dp[x][y+1]==MOD){
					narr.push_back(x*m+y+1);
				}
			}
			ind++;
			hehe=narr;
		}
		ind=0;
		hehe.push_back(target);
		while (hehe.size()>0){
			vector<int> narr;
			while (hehe.size()){
				int x = hehe[hehe.size()-1]/m;
				int y = hehe[hehe.size()-1]%m;
				hehe.pop_back();
				if (dp2[x][y]!=MOD) continue;
				dp2[x][y]=ind;
				if (x && arr[x-1][y]!='#' && dp2[x-1][y]==MOD){
					narr.push_back(x*m+y-m);
				}
				if (x<n-1 && arr[x+1][y]!='#' && dp2[x+1][y]==MOD){
					narr.push_back(x*m+y+m);
				}
				if (y && arr[x][y-1]!='#' && dp2[x][y-1]==MOD){
					narr.push_back(x*m+y-1);
				}
				if (y<m-1 && arr[x][y+1]!='#' && dp2[x][y+1]==MOD){
					narr.push_back(x*m+y+1);
				}
			}
			ind++;
			hehe=narr;
		}
		ans = "NO";
		for (int i = 0; i < n; ++i)
		{
			if (ans!="NO") break;
			if (!vis[i][0] && dp2[i][0]<dp[i][0]){
				dfs(i,0);
			}
			if (ans!="NO") break;
			if (!vis[i][m-1] && dp2[i][m-1]<dp[i][m-1]){
				dfs(i,m-1);
			}
			if (ans!="NO") break;
		}
		for (int i = 0; i < m; ++i)
		{
			if (ans!="NO") break;
			if(!vis[0][i] && dp2[0][i]<dp[0][i]){
				dfs(0,i);
			}
			if (ans!="NO") break;
			if (!vis[n-1][i] && dp2[n-1][i]<dp[n-1][i]){
				dfs(n-1,i);
			}
			if (ans!="NO") break;
		}
		if (ans=="NO") cout<<ans<<endl;
		else {
			cout<<"YES"<<endl;
			cout<<ans.size()<<endl;
			cout<<ans<<endl;
		}
	}
}