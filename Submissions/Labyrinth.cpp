// Submission Timestamp: 2022-10-11 10:56:00

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
#define endl '\n'
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
using namespace std;
vector<vector<int>> dp;
string ans="";
void dfs(int i, int j){
	if (dp[i][j]==0) return;
	int yuk = INT_MAX;
	if (i) yuk=dp[i-1][j];
	int as = INT_MAX;
	if (i<dp.size()-1) as=dp[i+1][j];
	int sag = INT_MAX;
	if (j<dp[0].size()-1) sag=dp[i][j+1];
	int sol = INT_MAX;
	if (j) sol = dp[i][j-1];
	int mivi = min(min(yuk,as),min(sag,sol));
	if (mivi==yuk){
		ans+="D";
		dfs(i-1,j);
	}
	else if (mivi==sag){
		ans+="L";
		dfs(i,j+1);
	}
	else if (mivi==sol){
		ans+="R";
		dfs(i,j-1);
	}
	else {
		ans+="U";
		dfs(i+1,j);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<string> arr(n);
		cinarr(arr);
		priority_queue<pair<int,int>> pq;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j]=='A') pq.push({0,i*m+j});
			}
		}
		dp.resize(n,vector<int>(m,INT_MAX));
		while (pq.size()){
			int w = -pq.top().first;
			int x = pq.top().second/m;
			int y = pq.top().second%m;
			pq.pop();
			if (dp[x][y]<=w) continue;
			dp[x][y]=w;
			if (x && arr[x-1][y]!='#' && dp[x-1][y]>w){
				pq.push({-(w+1),x*m+y-m});
			}
			if (x<n-1 && arr[x+1][y]!='#' && dp[x+1][y]>w){
				pq.push({-(w+1),x*m+y+m});
			}
			if (y && arr[x][y-1]!='#' && dp[x][y-1]>w){
				pq.push({-(w+1),x*m+y-1});
			}
			if (y<m-1 && arr[x][y+1]!='#' && dp[x][y+1]>w){
				pq.push({-(w+1),x*m+y+1});
			}
		}
		int xp , yp =-1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j){
				if (arr[i][j]=='B') xp=i,yp=j;
				if (yp+1) break;
			}
			if (yp+1) break;
		}
		if (dp[xp][yp]==INT_MAX){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<dp[xp][yp]<<endl;
		dfs(xp,yp);
		rev(ans);
		cout<<ans<<endl;
	}
}