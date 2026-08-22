// Submission Timestamp: 2022-11-05 21:45:29

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
		cout<<fixed<<setprecision(6);
		deci(n);deci(a);deci(b);
		vector<vector<double>> arr(6*n+1,vector<double>(n+1,0));
		arr[0][0]=1;
		for (int i = 1; i <= 6*n; i++){
			for (int j = 1; j <= n; j++){
				for (int k = i-1; k>=max(0ll,i-6); k--){
					arr[i][j]+=arr[k][j-1];
				}
				arr[i][j]/=6;
			}
		}
		double ans = 0;
		for (int i = a; i <= b; ++i)
		{
			ans+=arr[i][n];
		}
		cout<<ans<<endl;
	}
}