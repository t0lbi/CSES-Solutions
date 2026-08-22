// Submission Timestamp: 2022-10-11 11:14:28

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(w);
		vint(arr(n));
		cinarr(arr);
		vector<pair<int,int>> dp(tol(n),{0,0});
		dp[tol(n)-1].first=1;
		for (int bit = tol(n)-1; bit >= 0; bit--){
			for (int i = 0; i < n; i++){
				if (tol(i)&bit) continue;
				int tur = dp[bit+tol(i)].first;
				int we = dp[bit+tol(i)].second+arr[i];				if (we>w) we=arr[i],tur++;
				if (dp[bit].first<tur){
					dp[bit].first=tur;
					dp[bit].second=we;
				}
				else if (dp[bit].first==tur && dp[bit].second>we){
					dp[bit].first=tur;
					dp[bit].second=we;
				}
			}
		}
		cout<<dp[0].first<<endl;
	}
}