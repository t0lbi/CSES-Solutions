// Submission Timestamp: 2023-05-01 23:36:05

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
		deci(n);deci(k);
		vint(arr(n));
		cinarr(arr);
		int sum = 0ll;
		for (int i = 0; i < n; i++){
			sum+=arr[i];
		}
		if(sum<=k){
			cout<<1<<endl;
			continue;
		}
		int LOG = log2(n)+4;
		vector<vector<int>> st(n,vector<int>(LOG,-1));
		int r = 0;
		sum = arr[0];
		vector<int> nex(n);
		for (int i = 0; i < n; i++){
			while (sum+arr[(r+1)%n]<=k){
				r++;
				r%=n;
				sum+=arr[r];
			}
			st[i][0]=r+1;
			st[i][0]%=n;
			if ((r+1)%n<i) st[i][0]=-1;
			nex[i]=r;
			sum-=arr[i];
		}
		for (int bit = 1ll; bit < LOG; bit++){
			for (int i = 0; i < n; i++){
				if (st[i][bit-1]==-1) continue;
				st[i][bit]=st[st[i][bit-1]][bit-1];
			}
		}
		int ans = n;
		for (int i = 0; i < n; i++){
			int crr = 0ll;
			int pl = i;
			for (int bit = LOG-1; bit >= 0; bit--){
				if (st[pl][bit]==-1) continue;
				pl=st[pl][bit];
				crr+=tol(bit);
			}
			crr++;
			pl=nex[pl]+1;
			pl%=n;
			if (pl<i){
				for (int bit = LOG-1; bit >= 0; bit--){
					if (st[pl][bit]==-1 || st[pl][bit]>i){
						continue;
					}
					pl=st[pl][bit];
					crr+=tol(bit);
				}
				crr++;
			}
			ans=min(ans,crr);
		}
		cout<<ans<<endl;
	}
}