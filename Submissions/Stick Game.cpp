// Submission Timestamp: 2022-11-21 09:44:55

#pragma optimize("Bismillahirrahmanirrahim")
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
		vint(arr(k));
		cinarr(arr);
		vector<bool> dp(n+1);
		vector<bool> dp2(n+1);
		dp[0]=false;
		dp2[0]=false;
		for (int i = 1; i <= n; i++){
			dp[i]=false;
			dp2[i]=false;
			for (int j = 0; j < k; j++){
				if (i-arr[j]<0) continue;
				else {
					if (dp[i-arr[j]]==false) dp2[i]=true;
					if (dp2[i-arr[j]]==false) dp[i]=true;
				}
			}
			if (dp[i]){
				cout<<"W";
			}
			else cout<<"L";
		}
		cout<<endl;
	}
}