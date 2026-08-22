// Submission Timestamp: 2022-10-26 15:02:54

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
int fpow(int base, int pow=MOD-2){
	base%=MOD;
	if (!pow) return 1ll;
	if (pow&1) return (base*fpow(base*base,pow/2))%MOD;
	return fpow(base*base, pow/2)%MOD;
}
vector<int> fac,invfac;
int C(int n, int r){
	return (((fac[n]*invfac[r])%MOD)*invfac[n-r])%MOD;
}
int32_t main(){
	ios;
	fac.resize(2e6,1);
	invfac.resize(2e6,1);
	for (int i = 2; i < fac.size(); ++i)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
		fac[i]+=MOD;
		fac[i]%=MOD;
		invfac[i]=fpow(fac[i],MOD-2);
	}
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		if (n&1) cout<<0<<endl;
		else {
			n/=2;
			cout<<(((C(2*n,n)-C(2*n,n-1))%MOD)+MOD)%MOD<<endl;
		}
	}
}