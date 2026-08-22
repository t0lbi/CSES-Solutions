// Submission Timestamp: 2022-10-17 16:54:03

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
	vector<int> arr(1000001,1);
	vector<bool> vis(1000001,false);
	for (int i = 2; i < arr.size(); i++){
		if (vis[i]) continue;
		for (int j = i; j < arr.size(); j+=i){
			vis[j]=true;
			int node = j;
			int hueh = 0;
			while (node%i==0) node/=i,hueh++;
			arr[j]*=(hueh+1);
		}
	}
	int t=0;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(x);
		cout<<arr[x]<<endl;
	}
}