// Submission Timestamp: 2023-04-25 03:21:40

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		const int M = 1e6;
		const int LOG = log2(M)+3;
		vector<vector<int>> st(M+1,vector<int>(LOG,-1));
		for (int i = 0; i < n; ++i)
		{
			deci(a);deci(b);
			if (st[a][0]==-1) st[a][0]=b;
			else st[a][0]=min(st[a][0],b);
		}
		int lel = -1;
		for (int i = M; i >= 1; i--){
			if (st[i][0]==-1){
				st[i][0]=lel;
				continue;
			}
			if (lel==-1) lel=st[i][0];
			else lel=min(lel,st[i][0]);
			st[i][0]=lel;
		}
		for (int bit = 1; bit < LOG; bit++){
			for (int i = 1; i <= M; i++){
				if (st[i][bit-1]==-1) continue;
				st[i][bit]=st[st[i][bit-1]][bit-1];
			}
		}
		while (q--){
			deci(a);deci(b);
			int ans = 0ll;
			for (int bit = LOG-1; bit >= 0; bit--){
				if (st[a][bit]==-1) continue;
				if (st[a][bit]>b) continue;
				a=st[a][bit];
				ans+=tol(bit);
			}
			cout<<ans<<endl;
		}
	}
}