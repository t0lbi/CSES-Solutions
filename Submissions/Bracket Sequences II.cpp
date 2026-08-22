// Submission Timestamp: 2022-11-21 09:07:28

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
int fpow(int base, int pow){
	base%=MOD;
	if (pow==0) return 1ll;
	if (pow%2) return (base*fpow(base*base, pow/2))%MOD;
	return fpow(base*base, pow/2)%MOD;
}
int C(int n, int r){
	int ans = 1;
	for (int i = 1; i <= r; i++){
		ans*=n-i+1;
		ans%=MOD;
		ans*=fpow(i,MOD-2);
		ans%=MOD;
	}
	return ans;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		decstr(str);
		if (n%2){
			cout<<0<<endl;
			continue;
		}
		int op = 0;
		bool boolean = true;
		int crr = 0;
		for (int i = 0; i < (int)str.length(); i++){
			if (str[i]=='(') op++,crr++;
			else crr--,op--;
			if (crr<0){
				boolean=false;
				break;
			}
		}
		n=(n-(int)str.length()-op)/2;
		if (n<0){
			cout<<0<<endl;
			continue;
		}
		if (!boolean){
			cout<<0<<endl;
			continue;
		}
		cout<<(((C(n*2+op,n)*(op+1))%MOD)*fpow(n+op+1,MOD-2))%MOD<<endl;
	}
}