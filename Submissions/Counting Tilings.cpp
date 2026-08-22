// Submission Timestamp: 2022-10-11 11:49:26

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
//#define endl '\n'
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
		deci(n);deci(m);
		vector<vector<vector<int>>> dp(m,vector<vector<int>>(tol(n),vector<int>(n,0)));
		for (int i = 0; i < tol(n); i++){
			int lel = 0;
			bool boolean = true;
			for (int j = 0; j < n; ++j)
			{
				if (tol(j)&i) {
					if(lel%2) boolean=false;
					lel=0;
				}
				else lel++;
			}
			if (lel%2) boolean=false;
			dp[0][i][0]=boolean;
		}
		for (int i = 1; i < m; i++){
			for (int j = n-1; j >= 0; j--){
				for (int bit = tol(n)-1; bit >= 0; bit--){
					if (j==n-1){
						dp[i][bit][j]=dp[i-1][bit^(tol(n)-1)][0];
						dp[i][bit][j]%=MOD;
						continue;
					}
					if(tol(j)&bit) {
						dp[i][bit][j]=dp[i][bit][j+1];
						continue;
					}
					dp[i][bit][j]=dp[i][bit][j+1];
					if ((tol(j+1)&bit)==0){
						dp[i][bit][j]+=dp[i][bit+tol(j)+tol(j+1)][j];
					}
					dp[i][bit][j]%=MOD;
				}
			}
		}
		cout<<dp[m-1][0][0]<<endl;
	}
}