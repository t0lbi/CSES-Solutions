// Submission Timestamp: 2022-10-24 15:08:34

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
int find(int n, int x, int crr=2, int cr=0){
	if(n==x) return 1;
	if (x<=n/2){
		return x*crr-cr;
	}
	return find(n/2,x-n/2,crr*2,cr*2+1);
}
int query(int n, int x){
		int hueh = n-tol(log2(n));
		if (x<=hueh){
			return x*2;
		}
		int node = find(n-hueh,x-hueh)+hueh*2;
		if (node>n){
			node%=n;
			node=node*2-1;
		}
		return node;
}
int32_t main(){
	ios;
	int t=0;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){

		deci(n);deci(x);
		cout<<query(n,x)<<endl;
	}
}