// Submission Timestamp: 2022-10-24 15:28:38

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
int n;
bool overf(__int128 a, __int128 b){
	
	if (a*b>n) {
		return true;
	}
	return false;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;deci(k);
		vint(arr(k));
		cinarr(arr);
		int ans = 0;
		for (int i = 1; i < tol(k); i++){
			int rval = -1;
			if (__builtin_popcount(i)&1) rval=1;
			int hehe = 1ll;
			bool boolean = true;
			for (int bit = 0; bit < k; bit++){
				if (tol(bit)&i) {
					if (overf(hehe,arr[bit])){
						boolean=false;break;
					}
					hehe*=arr[bit];
				}
			}
			if (!boolean) continue;
			ans+=rval*(n/hehe);
		}
		cout<<ans<<endl;
	}
}