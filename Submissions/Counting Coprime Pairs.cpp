// Submission Timestamp: 2022-10-31 09:20:38

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
		deci(n);
		vector<int> vis(1e6+5,0);
		for (int i = 0; i < n; ++i)
		{
			deci(x);
			vis[x]++;
		}
		vector<int> hueh(1e6+5,0);
		for (int i = hueh.size()-1; i > 0; i--){
			for (int j = i; j < hueh.size(); j+=i){
				hueh[i]+=vis[j];
			}
			hueh[i]=hueh[i]*(hueh[i]-1)/2;
			for (int j = i*2; j < hueh.size(); j+=i){
				hueh[i]-=hueh[j];
			}
		}
		cout<<hueh[1]<<endl;
	}
}