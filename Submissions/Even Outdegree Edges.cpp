// Submission Timestamp: 2023-04-24 01:07:44

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
template<typename X, typename Y> pair<X,Y> operator+=(pair<X,Y> &a, pair<X,Y> &b){a.first+=b.first,a.second+=b.second;return a;}
template<typename X, typename Y> pair<X,Y> operator-=(pair<X,Y> &a, pair<X,Y> &b){a.first-=b.first,a.second-=b.second;return a;}
template<typename X, typename Y, typename Z> pair<X,Y> operator+(pair<X,Y> &a, initializer_list<Z> b) {pair<X,Y> c; auto it = b.begin(); c.first=a.first+*it;it++;c.second=a.second+*it;return c;}
template<typename X, typename Y, typename Z> pair<X,Y> operator-(pair<X,Y> &a, initializer_list<Z> b) {pair<X,Y> c; auto it = b.begin(); c.first=a.first-*it;it++;c.second=a.second-*it;return c;}
template<typename X, typename Y, typename Z> pair<X,Y> operator+=(pair<X,Y> &a, initializer_list<Z> b) {auto it = b.begin(); a.first+=*it;it++;a.second+=*it;return a;}
template<typename X, typename Y, typename Z> pair<X,Y> operator-=(pair<X,Y> &a, initializer_list<Z> b) {auto it = b.begin(); a.first-=*it;it++;a.second-=*it;return a;}
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
struct DSU{
	vector<int> par;
	vector<int> sz;
	int siz;
	DSU(int n){
		siz=n;
		par.resize(n);
		sz.resize(n,1ll);
		iota(par.begin(), par.end(), 0ll);
	}
	int find(int node){
		if (node<0 || node>=par.size() || par[node]==node) return node;
		return par[node]=find(par[node]);
	}
	void merge(int a, int b){
		a=find(a);
		b=find(b);
		if (a==b) return;
		if (sz[a]>sz[b]) swap(a,b);
		siz--;
		sz[b]+=sz[a];
		par[a]=b;
	}
	void merge(pair<int,int> pr){
		auto [a, b] = pr;
		a=find(a);
		b=find(b);
		if (a==b) return;
		siz--;
		if (sz[a]>sz[b]) swap(a,b);
		sz[b]+=sz[a];
		par[a]=b;
	}
	int size(){return siz;}
};//DSU
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<pair<int,int>> ed(m);
		cin>>ed;
		vector<vector<int>> arr(n);
		for (int i = 0; i < m; i++){
			ed[i]-={1,1};
			arr[ed[i].first].push_back(ed[i].second);
			arr[ed[i].second].push_back(ed[i].first);
			ed[i]+={1,1};
		}
		if (m%2){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		map<pair<int,int>,bool> kul;
		vector<int> ss(n,0);
		auto merge = [&](int a, int b)->void{
			a++,b++;
			if (kul.count({a,b}) || kul.count({b,a})) return;
			ss[a-1]++;
			kul[{a,b}]=true;
		};
		vector<bool> vis(n,false);
		auto dfs = [&](int node, int lnode, auto dfs)->void{
			vis[node]=true;
			for (int i = 0; i < arr[node].size(); i++){
				if (arr[node][i]==lnode) continue;
				if (vis[arr[node][i]]) {
					merge(node,arr[node][i]);
					continue;
				}
				dfs(arr[node][i],node,dfs);
				if (ss[arr[node][i]]%2){
					merge(arr[node][i],node);
				}
				else {
					merge(node,arr[node][i]);
				}
			}
		};
		for (int i = 0; i < n; i++){
			if (vis[i]) continue;
			dfs(i,-1,dfs);
		}
		bool boolean=true;
		for (int i = 0; i < n; i++){
			if (ss[i]%2) boolean=false;
		}
		if (!boolean){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		for (int i = 0; i < m; i++){
			if (!kul.count(ed[i])) swap(ed[i].first,ed[i].second);
			cout<<ed[i]<<endl;
		}
	}
}