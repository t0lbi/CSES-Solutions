// Submission Timestamp: 2023-12-04 08:33:52

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
using namespace std;
template<typename X, typename Y> istream& operator>>(istream& in, pair<X,Y> &pr) {return in>>pr.first>>pr.second;}
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> arr) {for(auto &it : arr) os<<it<<" "; return os;}
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(x);
		vint(arr(n));
		cinarr(arr);
		vector<int> hh;
		for (int i = 0; i < tol(n/2); i++){
			int somma = 0;
			for (int j = 0; j < n/2; j++){
				if (tol(j)&i) somma+=arr[j];
				if (somma>x) break;
			}
			if (somma>x) continue;
			hh.push_back(somma);
		}
		sortarr(hh);
		int ways = 0;
		for (int i = 0; i < tol((n-n/2)); i++){
			int somma = 0;
			for (int j = 0; j < n-n/2; j++){
				int el = n-j-1;
				if (tol(j)&i) somma+=arr[n-j-1];
				if (somma>x) break;
			}
			if (somma>x) continue;
			ways += (upper_bound(hh.begin(), hh.end(), x-somma)-lower_bound(hh.begin(), hh.end(), x-somma));
		}
		cout<<ways<<endl;
	}
}