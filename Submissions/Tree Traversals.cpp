// Submission Timestamp: 2023-04-25 04:20:40

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
vector<int> pre;
vector<int> in;
vector<int> post;
vector<int> plpre;
vector<int> plin;
struct SegTree{
	vector<int> segtree;
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]=val;
		while (node){
			node=(node-1)/2;
			segtree[node]=min(segtree[node*2+1],segtree[node*2+2]);
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return INF;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return min(lnode, rnode);
	}
	void resize(int n){
		segtree.resize(tol(ceil(log2(n))+1)-1,0ll);
	}
};
int n;
SegTree segtree;
void calc(int l1, int r1, int l2, int r2){
	int root = pre[l1];
	int pl = plin[root];
	if (l1==r1){
		post.push_back(root);
		return;
	}
	if (pl == l2){
		calc(l1+1,r1,l2+1,r2);
		post.push_back(root);
	}
	else if (pl == r2){
		calc(l1+1,r1,l2,r2-1);
		post.push_back(root);
	}
	else {
		int rig = segtree.query(pl+1,r2);
		calc(l1+1,rig-1,l2,pl-1);
		calc(rig,r1,pl+1,r2);
		post.push_back(root);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		segtree.resize(n);
		pre.resize(n);
		plpre.resize(n+1);
		plin.resize(n+1);
		in.resize(n);
		cinarr(pre);
		cinarr(in);
		for (int i = 0; i < n; ++i)
		{
			plpre[pre[i]]=i;
			plin[in[i]]=i;
		}
		for (int i = 0; i < n; ++i)
		{
			segtree.update(i,plpre[in[i]]);
		}
		calc(0,n-1,0,n-1);
		coutarr(post);
	}
}