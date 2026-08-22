// Submission Timestamp: 2022-10-17 09:42:06

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
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
#define tol(bi) (1<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		int arr[200000][32];
		int LOG=32;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i][0];
			arr[i][0]--;
		} 
		for (int bit = 1; bit < LOG; bit++){
			for (int i = 0; i < n; ++i)
			{
				arr[i][bit]=arr[arr[i][bit-1]][bit-1];
			}
		}
		while (q--){
			deci(x);deci(k);
			x--;
			for (int bit = LOG-1; bit >= 0; bit--){
				if (tol(bit)&k){
					x=arr[x][bit];
				}
			}
			cout<<x+1<<'\n';
		}
	}
}