// Submission Timestamp: 2022-10-19 13:16:05

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
int fpow(int base, int pow, int mod){
	base%=mod;
	if (pow==0) return 1ll;
	int rval = 1ll;
	if (pow&1) rval=base;
	return (fpow(base*base,pow/2,mod)*rval)%mod;
}
int32_t main(){
	ios;
	int t=0;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(a);deci(b);deci(c);
		cout<<fpow(a,fpow(b,c,MOD-1),MOD)<<endl;
	}
}