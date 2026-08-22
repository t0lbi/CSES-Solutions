// Submission Timestamp: 2023-05-01 22:02:31

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
		deci(n);deci(m);
		vector<string> arr(n);
		cin>>arr;
		vector<vector<int>> dp(n,vector<int>(m,0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j]=='.'){
					dp[i][j]=1ll;
					if (i) dp[i][j]+=dp[i-1][j];
				}
				else {
					dp[i][j]=0ll;
				}
			}
		}
		int ans = 0ll;
		vector<int> left(m);
		vector<int> right(m);
		vector<pair<int,int>> stak;
		for (int i = 0; i < n; i++){
			stak.clear();
			stak.push_back({-1,-1});
			for (int j = 0; j < m; j++){
				while (stak.back().first>=dp[i][j]){
					stak.pop_back();
				}
				left[j]=stak.back().second+1;
				stak.push_back({dp[i][j],j});
			}
			stak.clear();
			stak.push_back({-1,m});
			for (int j = m-1; j >= 0; j--){
				while (stak.back().first>=dp[i][j]){
					stak.pop_back();
				}
				right[j]=stak.back().second-1;
				stak.push_back({dp[i][j],j});
			}
			for (int j = 0; j < m; j++){
				ans=max(ans,(right[j]-left[j]+1)*dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
}