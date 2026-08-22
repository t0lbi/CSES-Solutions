// Submission Timestamp: 2023-05-01 22:24:46

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
struct SegTree{
	vector<int> segtree;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]=val;
		while (node){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
};
struct MSegTree{
	vector<int> segtree;
	MSegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]=val;
		while (node){
			node=(node-1)/2;
			segtree[node]=max(segtree[node*2+1],segtree[node*2+2]);
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode,rnode);
	}
};
struct DSU{
	vector<int> par;
	int sz;
	DSU(int n){
		par.resize(n);
		sz=n;
		iota(par.begin(), par.end(), 0ll);
	}
	int find(int a){
		if (par[a]==a) return a;
		return par[a]=find(par[a]);
	}
	void merge(int a, int b){
		a=find(a);
		b=find(b);
		if (a!=b) sz--;
		if (ayahya()&1) swap(a,b);
		par[a]=b;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vint(arr(n));
		SegTree segtree(n);
		MSegTree lis(n);
		DSU dsu(n);
		cin>>arr;
		int a = 0;
		int b = 0;
		int c = n;
		int d = n;
		int crr = n;
		for (int i = 0; i < n; ++i)
		{
			dsu.merge(i,arr[i]-1);
		}
		b=n-dsu.sz;
		for (int i = n-1; i >= 0; i--){
			if (arr[i]==crr){
				crr--,d--;
			}
		}
		for (int i = 0; i < n; i++){
			a+=segtree.query(arr[i]-1,n-1);
			segtree.update(arr[i]-1,1ll);
		}
		for (int i = 0; i < n; i++){
			int crr = lis.query(0,arr[i]-1)+1;
			c=min(c,n-crr);
			lis.update(arr[i]-1,crr);
		}
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	}
}