// Submission Timestamp: 2022-11-19 01:07:04

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
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
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(k);
		vector<vector<double>> dp(n,vector<double>(k+1,0));
		for (int i = 1; i <= k; ++i)
		{
			dp[0][i]=1.0/k;
		}
		for (int i = 1; i < n; i++){
			for (int j = 1; j <= k; j++){
				dp[i][j]=dp[i-1][j]*(((double)j)/k);
				for (int l = 1; l < j; l++){
					dp[i][j]+=dp[i-1][l]*(1.0/k);
				}
			}
		}
		double ans = 0;
		double tot = 0;
		for (int i = 1; i <= k; i++){
			ans+=dp[n-1][i]*i;
			tot+=dp[n-1][i];
		}
		cout<<fixed<<setprecision(6)<<ans/tot<<endl;
	}
}