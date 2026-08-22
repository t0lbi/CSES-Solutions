// Submission Timestamp: 2023-04-20 13:44:57

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
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
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vector<int> pref(n);
		cinarr(pref);
		for (int i = 1; i < n; i++){
			pref[i]+=pref[i-1];
		}
		auto query = [&](int l, int r)->int{
			int hh = 0;
			if (l) hh = pref[l-1];
			return pref[r]-hh;
		};
		vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));
		for (int r = 0; r < n; r++){
			if (r) dp[r-1][r]={query(r-1,r),r-1};
			dp[r][r]={0,r};
		}
		for (int len = 3; len <= n; len++){
			for (int l = 0; l+len-1 < n; l++){
				int r = l+len-1;
				int opt = -1;
				int best = INF;
				for (int i = max(0ll,dp[l][r-1].second); i <= dp[l+1][r].second; i++){
					int crr = dp[l][i].first+dp[i+1][r].first;
					if (best>crr){
						best=crr;
						opt=i;
					}
				}
				if (best!=INF) best+=query(l,r);
				dp[l][r]={best,opt};
			}
		}
		cout<<dp[0][n-1].first<<endl;
	}
}

