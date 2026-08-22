// Submission Timestamp: 2023-04-29 20:52:08

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
	vector<int> mava;
	vector<int> miva;
	vector<int> lazy;
	SegTree(int n){
		mava.resize(tol(ceil(log2(n))+1)-1,0ll);
		miva.resize(mava.size(), 0ll);
		lazy.resize(miva.size(), 0ll);
	}
	void dallan(int node){
		mava[node]+=lazy[node];
		miva[node]+=lazy[node];
		if (node*2+1<mava.size()){
			lazy[node*2+1]+=lazy[node];
			lazy[node*2+2]+=lazy[node];
		}
		lazy[node]=0ll;
	}
	void update(int tarl, int tarr, int val, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = mava.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr) {
			lazy[node]+=val;
			dallan(node);
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		update(tarl, tarr, val, l, mid, node*2+1);
		update(tarl, tarr, val, mid+1, r, node*2+2);
		mava[node]=max(mava[node*2+1],mava[node*2+2]);
		miva[node]=min(miva[node*2+1],miva[node*2+2]);
	}
	int minq(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = miva.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr) return miva[node];
		if (l>tarr || r<tarl) return INF;
		int mid = l+(r-l)/2;
		int lnode = minq(tarl, tarr, l, mid, node*2+1);
		int rnode = minq(tarl, tarr, mid+1, r, node*2+2);
		return min(lnode, rnode);
	}
	int maxq(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = mava.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr) return mava[node];
		if (l>tarr || r<tarl) return -INF;
		int mid = l+(r-l)/2;
		int lnode = maxq(tarl, tarr, l, mid, node*2+1);
		int rnode = maxq(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode, rnode);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(q);
		SegTree segtree(q);
		int n = q;
		while (q--){
			deci(x);deci(hy);
			if (hy==2) hy = -1;
			segtree.update(0,x-1,hy);
			int miva = segtree.minq(0,n-1);
			int mava = segtree.maxq(0,n-1);
			if (miva<0 && mava>0){
				cout<<"?"<<endl;
			}
			else if (miva<0){
				cout<<"<"<<endl;
			}
			else cout<<">"<<endl;
		}
	}
}