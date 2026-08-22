// Submission Timestamp: 2023-05-03 01:34:40

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
		deci(n);
		vint(arr(n));
		cinarr(arr);
		const int LOG = 20;
		vector<int> freq(tol(LOG),0);
		vector<vector<int>> f(tol(LOG),vector<int>(LOG,0));
		vector<array<int,3>> ansarr(n,{-1,-1,-1});
		for (int i = 0; i < n; i++){
			freq[arr[i]]++;
		}
		for (int i = 0; i < tol(LOG); i++){
			if (i&1){
				f[i][0]=freq[i]+freq[i-1];
			}
			else {
				f[i][0]=freq[i];
			}
			for (int j = 1; j < LOG; j++){
				if (tol(j)&i){
					f[i][j]=f[i][j-1]+f[i^tol(j)][j-1];
				}
				else {
					f[i][j]=f[i][j-1];
				}
			}
		}
		int kk = tol(LOG)-1;
		for (int i = 0; i < n; ++i)
		{
			ansarr[i][0]=f[arr[i]][LOG-1];
			ansarr[i][2]=n-f[arr[i]^kk][LOG-1];
		}
		for (int i = 0; i < tol(LOG); i++){
			if (i&1){
				f[i][0]=freq[i^kk]+freq[(i-1)^kk];
			}
			else {
				f[i][0]=freq[i^kk];
			}
			for (int j = 1; j < LOG; j++){
				if (tol(j)&i){
					f[i][j]=f[i][j-1]+f[i^tol(j)][j-1];
				}
				else {
					f[i][j]=f[i][j-1];
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			ansarr[i][1]=f[arr[i]^kk][LOG-1];
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<ansarr[i]<<endl;
		}
	}
}