// Submission Timestamp: 2022-11-25 14:57:58

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
	vector<int> dp(2001,0);
	for (int i = 1; i < dp.size(); i++){
		vector<bool> v(5000,false);
		for (int j = 1; j < i; j++){
			if (j>=i-j) break;
			v[dp[i-j]^dp[j]]=true;
		}
		for (int j = 0; j < v.size(); j++){
			if (v[j]==false){
				dp[i]=j;
				break;
			}
		}
	}
	int t=0;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		if (n>=dp.size()){
			cout<<"first"<<endl;
		}
		else if (dp[n]){
			cout<<"first"<<endl;
		}
		else cout<<"second"<<endl;
	}
}