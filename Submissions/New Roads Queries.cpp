// Submission Timestamp: 2023-04-23 15:39:44

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
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
template<typename X, typename Y>istream& operator>>(istream& in, pair<X,Y> &pr){return in>>pr.first>>pr.second;}
template<typename X, typename Y>ostream& operator<<(ostream& out, pair<X,Y> &pr){return out<<"{"<<pr.first<<", "<<pr.second<<"}";}
template<typename T> istream& operator>>(istream& in, vector<T> &v){for (int i = 0; i < v.size(); i++) in>>v[i];return in;}
template<typename T> ostream& operator<<(ostream& out, vector<T> &v){for (int i = 0; i < v.size(); i++) out<<v[i];return out;}
struct DSU{
	vector<int> par;
	vector<int> sz;
	DSU(int n){
		par.resize(n);
		sz.resize(n,1ll);
		iota(par.begin(), par.end(), 0ll);
	}
	int find(int a){
		if (par[a]==a || a==-1 || a>=par.size()) return a;
		return par[a]=find(par[a]);
	}
	void merge(int a, int b){
		a=find(a);
		b=find(b);
		if (sz[a]>sz[b]) swap(a,b);
		sz[b]+=sz[a];
		par[a]=b;
	}
	void merge(pair<int,int> k){
		auto [a,b] = k;
		a=find(a);
		b=find(b);
		if (sz[a]>sz[b]) swap(a,b);
		sz[b]+=sz[a];
		par[a]=b;
	}
	bool same(int a, int b){
		a=find(a);
		b=find(b);
		return (a==b);
	}
	bool same(pair<int,int> k){
		auto [a, b] = k;
		a=find(a);
		b=find(b);
		return (a==b);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);deci(q);
		vector<pair<int,pair<int,int>>> ed(m);
		for (int i = 0; i < m; i++){
			ed[i].first=i+1;
			cin>>ed[i].second;
			ed[i].second.first--,ed[i].second.second--;
		}
		int LOG = log2(n)+3;
		vector<vector<pair<int,int>>> st(n,vector<pair<int,int>>(LOG,{-1,0}));
		vector<vector<pair<int,int>>> arr(n);
		DSU dsu(n);
		sortarr(ed);
		for (int i = 0; i < m; i++){
			if (dsu.same(ed[i].second)) continue;
			dsu.merge(ed[i].second);
			auto [u,v] = ed[i].second;
			arr[u].push_back({v,ed[i].first});
			arr[v].push_back({u,ed[i].first});
		}
		vector<bool> vis(n,false);
		vector<int> dept(n,0);
		auto dfs = [&](int node, int lnode, auto dfs)->void{
			vis[node]=true;
			if (lnode==-1) dept[node]=0ll;
			else dept[node]=dept[lnode]+1ll;
			for (auto [v,w] : arr[node]){
				if (v==lnode) continue;
				st[v][0]={node,w};
				dfs(v,node,dfs);
			}
		};
		for (int i = 0; i < n; i++){
			if (vis[i]) continue;
			dfs(i,-1,dfs);
		}
		for (int bit = 1; bit < LOG; bit++){
			for (int i = 0; i < n; i++){
				if (st[i][bit-1].first==-1) continue;
				st[i][bit].first=st[st[i][bit-1].first][bit-1].first;
				st[i][bit].second=max(st[i][bit-1].second,st[st[i][bit-1].first][bit-1].second);
			}
		}
		auto kthpar = [&](int node, int k)->pair<int,int>{
			pair<int,int> ans={node,0};
			for (int bit = LOG-1; bit >= 0; bit--){
				if (k&tol(bit)){
					ans.second=max(ans.second,st[ans.first][bit].second);
					ans.first=st[ans.first][bit].first;
				}
			}
			return ans;
		};
		auto query = [&](int a, int b)->int{
			if (dept[a]>dept[b]) swap(a,b);
			pair<int,int> rval = kthpar(b,dept[b]-dept[a]);
			b=rval.first;
			int ans = rval.second;
			if (a==b) return ans;
			for (int bit = LOG-1; bit >= 0; bit--){
				if (st[a][bit].first==st[b][bit].first) continue;
				ans=max(ans,max(st[a][bit].second,st[b][bit].second));
				a=st[a][bit].first;
				b=st[b][bit].first;
			}
			return max(ans,max(st[a][0].second,st[b][0].second));
		};
		while (q--){
			deci(a);deci(b);
			a--,b--;
			if (dsu.same(a,b)){
				cout<<query(a,b)<<endl;
			}
			else cout<<-1<<endl;
		}
	}
}