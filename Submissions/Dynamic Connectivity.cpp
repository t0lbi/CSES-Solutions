// Submission Timestamp: 2023-04-23 16:21:49

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
struct DSURB{
	vector<int> par;
	vector<int> ham;
	vector<int> sz;
	int comp;
	DSURB(){}
	DSURB(int n){
		par.resize(n);
		sz.resize(n,1);
		iota(par.begin(), par.end(), 0ll);
		comp=n;
	}
	void resize(int n){
		par.resize(n);
		sz.resize(n,1);
		iota(par.begin(), par.end(), 0ll);
		comp=n;
	}
	int find(int node){
		if (par[node]==node || node<0 || node>=par.size()) return node;
		return find(par[node]);
	}
	void merge(int a, int b){
		a=find(a);
		b=find(b);
		if (sz[a]>sz[b]) swap(a,b);
		if (a!=b) {
			sz[b]+=sz[a];
			comp--;
		}
		par[a]=b;
		ham.push_back(a);
	}
	void merge(pair<int,int> k){
		auto [a,b] = k;
		a=find(a);
		b=find(b);
		if (sz[a]>sz[b]) swap(a,b);
		if (a!=b) {
			sz[b]+=sz[a];
			comp--;
		}
		par[a]=b;
		ham.push_back(a);
	}
	void undo(){
		if (!ham.size()) return;
		int node = ham.back();
		ham.pop_back();
		if (par[node]==node){
			return;
		}
		comp++;
		sz[par[node]]-=sz[node];
		par[node]=node;
	}
};//DSU with rollback
struct SegTree{
	vector<vector<pair<int,int>>> segtree;
	DSURB dsu;
	int nn;
	SegTree(int n, int m){
		nn=n;
		segtree.resize(tol(ceil(log2(n)+1))-1);
		dsu.resize(m);
	}
	void update(int tarl, int tarr, pair<int,int> val, int l = 0, int r = -1, int node = 0){
		if (r==-1) {
			r = segtree.size()/2;
		}
		if (l>=tarl && r<=tarr){
			segtree[node].push_back(val);
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		update(tarl, tarr, val, l, mid, node*2+1);
		update(tarl, tarr, val, mid+1, r, node*2+2);
	}
	vector<int> ansarr;
	void init(int node = 0){
		for (int i = 0; i < segtree[node].size(); i++){
			dsu.merge(segtree[node][i]);
		}
		if (node*2+1<segtree.size()){
			init(node*2+1);
			init(node*2+2);
		}
		else if (node-segtree.size()/2<nn) ansarr.push_back(dsu.comp);
		for (int i = 0; i < segtree[node].size(); i++){
			dsu.undo();
		}
	}
};//Segment Tree
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);deci(q);
		map<pair<int,int>,int> mp;
		SegTree segtree(q+1,n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			u--,v--;
			if (u>v) swap(u,v);
			mp[{u,v}]=0;
		}
		for (int i = 0; i < q; i++){
			deci(ty);deci(u);deci(v);
			u--,v--;
			if (u>v) swap(u,v);
			if (ty==2){
				segtree.update(mp[{u,v}],i,{u,v});
				mp.erase({u,v});
			}
			else mp[{u,v}]=i+1;
		}
		for (auto it : mp){
			segtree.update(it.second,q,it.first);
		}
		segtree.init();
		coutarr(segtree.ansarr);
	}
}