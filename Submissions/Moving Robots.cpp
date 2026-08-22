// Submission Timestamp: 2022-11-19 00:31:42

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
		deci(n);
		auto va = [](int i, int j) -> double{
			if (i==7 && j==7) return 1.0/2;
			if (i==0 && j==0) return 1.0/2;
			if (i==0 && j==7) return 1.0/2;
			if (i==7 && j==0) return 1.0/2;
			if (i==0) return 1.0/3;
			if (i==7) return 1.0/3;
			if (j==0) return 1.0/3;
			if (j==7) return 1.0/3;
			return 1.0/4;
		};
		vector<vector<vector<double>>> dp(8,vector<vector<double>>(8,vector<double>(n+1)));
		vector<vector<double>> hueh(8,vector<double>(8,1));
		for (int x = 0; x < 8; x++){
			for (int y = 0; y < 8; y++){
				for (int i = 0; i < 8; ++i){
					for (int j = 0; j < 8; j++){
						for (int k = 0; k <= n; k++){
							dp[i][j][k]=0;
						}
					}
				}
				dp[x][y][0]=1;
				for (int k = 1; k <= n; k++) {
					for (int i = 0; i < 8; ++i) {
						for (int j = 0; j < 8; ++j) {
							double sa=0;
							if (i<7) sa=va(i+1,j)*dp[i+1][j][k-1];
							double so=0;
							if (i>0) so=va(i-1,j)*dp[i-1][j][k-1];
							double us=0;
							if (j<7) us=va(i,j+1)*dp[i][j+1][k-1];
							double al=0;
							if (j>0) al=va(i,j-1)*dp[i][j-1][k-1];
							dp[i][j][k]=sa+so+us+al;
						}
					}
				}
				for (int i = 0; i < 8; ++i){
					for (int j = 0; j < 8; ++j){
						hueh[i][j]*=(1-dp[i][j][n]);
					}
				}
			}
		}
		double ans = 0;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				ans+=hueh[i][j];
			}
		}
		cout<<fixed<<setprecision(6);
		cout<<ans<<endl;
	}
}