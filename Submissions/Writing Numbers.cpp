// Submission Timestamp: 2023-05-01 01:16:49

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
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> &pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X, typename Y> pair<X,Y> operator+(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first+b.first,c.second=a.second+b.second;return c;}
template<typename X, typename Y> pair<X,Y> operator-(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first-b.first,c.second=a.second-b.second;return c;}
template<typename X, typename Y> void operator+=(pair<X,Y> &a, pair<X,Y> &b){a.first+=b.first,a.second+=b.second;}
template<typename X, typename Y> void operator-=(pair<X,Y> &a, pair<X,Y> &b){a.first-=b.first,a.second-=b.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
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
int valid0(int num){
	int left = num;
	int right = 0;
	int crr = 0;
	int b = 1ll;
	while (left>=10){
		int bit = left%10;
		left/=10;
		crr+=b*(left-1)+right+1;
		right+=bit*b;
		b*=10;
	}
	return crr+1;
}
int valid1(int num){
	int left = num;
	int right = 0;
	int crr = 0;
	int b = 1ll;
	while (left>=10){
		int bit = left%10;
		left/=10;
		crr+=b*(left);
		if (bit==1) crr+=right+1;
		else if (bit>1) crr+=b;
		right+=bit*b;
		b*=10;
	}
	if (left==1){
		crr+=right+1;
	}
	else {
		crr+=b;
	}
	return crr;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		int l = 1, r = 1000000000000000000;
		while (l<r){
			int mid = l+(r-l+1)/2;
			if (valid0(mid)>n || valid1(mid)>n){
				r=mid-1;
			}
			else l=mid;
		}
		cout<<l<<endl;
	}
}