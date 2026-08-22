// Submission Timestamp: 2023-06-12 13:26:16

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
int n, l, r;
vector<vector<int>> arr;
int ans;
vector<deque<int>> pref;
void dfs(int node, int lnode){
	pref[node]={0,1};
	for (int pp = 0; pp < arr[node].size(); pp++){
		int nex = arr[node][pp];
		if (nex==lnode) continue;
		dfs(nex,node);
		pref[nex].push_front(pref[nex].front());
		if (pref[nex].size()>pref[node].size()) swap(pref[nex],pref[node]);
		for (int i = 1; i < pref[nex].size(); i++){
			int say = pref[nex][i]-pref[nex][i-1];
			int lv = l-i+1;
			int rv = r-i+1;
			lv=max(lv,0ll);
			rv=min(rv,(int)pref[node].size()-2);
			if (lv>rv) continue;
			ans+=say*(pref[node][rv+1]-pref[node][lv]);
		}
		int lel = pref[node][pref[nex].size()-1];
		for (int i = pref[nex].size()-2; i >= 0; i--){
			int crlel = pref[node][i];
			pref[node][i]=pref[node][i+1]-(pref[nex][i+1]-pref[nex][i]+lel-pref[node][i]);
			lel=crlel;
		}
		pref[nex].clear();
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>l>>r;
		arr.resize(n);
		pref.resize(n);
		for (int i = 0; i < n-1; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		dfs(0,-1);
		cout<<ans<<endl;
	}
}