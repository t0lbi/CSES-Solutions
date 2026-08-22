// Submission Timestamp: 2022-10-24 12:35:28

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
struct pdiv{
	int base, pow;
};
int fpow(int base, int pow, int md=MOD){
	base%=md;
	if (pow==0) return 1ll;
	if (pow&1) return (base*fpow(base*base,pow/2))%md;
	return fpow(base*base,pow/2)%md;
}
using namespace std;
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vector<pdiv> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].base>>arr[i].pow;
		}
		int somma = 1;
		int cnt=1,sum=1,exp=1;
		for (int i = 0; i < n; ++i)
		{
			cnt*=arr[i].pow+1;
			cnt%=MOD;
			cnt+=MOD;
			cnt%=MOD;

			sum*=((fpow(arr[i].base,arr[i].pow+1)-1)*fpow(arr[i].base-1,MOD-2))%MOD;
			sum%=MOD;
			sum+=MOD;
			sum%=MOD;

			exp*=(fpow(exp,arr[i].pow)*fpow(fpow(arr[i].base,arr[i].pow*(arr[i].pow+1)/2),somma))%MOD;
			exp%=MOD;
			exp+=MOD;
			exp%=MOD;

			somma*=arr[i].pow+1;
			somma%=(MOD-1);
			somma+=(MOD-1);
			somma%=(MOD-1);
		}
		cout<<cnt<<" "<<sum<<" "<<exp<<endl;
	}
}