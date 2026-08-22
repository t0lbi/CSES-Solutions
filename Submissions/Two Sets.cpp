// Submission Timestamp: 2022-10-06 11:12:00

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
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		if ((n*(n+1)/2)%2){
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			int ulas = n*(n+1)/4;
			int lind = n;
			vector<int> v1;
			while (ulas>0){
				int al = min(ulas,lind);
				if (ulas==lind){
					v1.push_back(ulas-1);
					v1.push_back(1ll);
					break;
				}
				else v1.push_back(al),ulas-=al, lind=al-1;
			}
			rev(v1);
			cout<<v1.size()<<endl;
			coutarr(v1);
			int ind = 0;
			cout<<n-v1.size()<<endl;
			for (int i = 1; i <= n; i++){
				while (ind<v1.size() && v1[ind]<i) ind++;
				if (ind<v1.size() && v1[ind]==i) continue;
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
}