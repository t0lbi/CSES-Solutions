// Submission Timestamp: 2022-10-12 21:12:27

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
struct SegTree{
	vector<int> segtree;
	vector<int> arr;
	vector<int> lazy;
	SegTree(vector<int> inarr){
		arr=inarr;
		segtree.resize(-1+tol(ceil(log2(arr.size())+1)),0);
		lazy.resize(segtree.size(),0);
		for (int i = 1; i < arr.size(); i++){
			arr[i]+=arr[i-1];
		}
		for (int i = 0; i < arr.size(); i++){
			segtree[segtree.size()/2+i]=arr[i];
		}
		for (int i = segtree.size()/2-1; i >= 0; i--){
			segtree[i]=max(segtree[i*2+1],segtree[i*2+2]);
		}
		arr=inarr;
	}
	void dallan(int node){
		segtree[node]+=lazy[node];
		if (node*2+1<segtree.size()){
			lazy[node*2+1]+=lazy[node];
			lazy[node*2+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		dallan(node);
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return -INF;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode, rnode);
	}
	int q(int l, int r){
		if (l) return max(0ll,query(l,r)-query(l-1,l-1));
		return max(0ll,query(l,r));
	}
	void lazyupdate(int tarl, int tarr, int val, int l = 0, int r = -1, int node = 0){
		if (r==-1) r=segtree.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr) {
			lazy[node]+=val;
			dallan(node);
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		lazyupdate(tarl, tarr, val, l, mid, node*2+1);
		lazyupdate(tarl, tarr, val, mid+1, r, node*2+2);
		segtree[node]=max(segtree[node*2+1],segtree[node*2+2]);
	}
	void update(int pos, int val){
		val -= arr[pos];
		arr[pos]+=val;
		lazyupdate(pos, arr.size()-1, val);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		vint(arr(n));
		cinarr(arr);
		SegTree segtree(arr);
		while (q--){
			deci(type);
			if (type==1){
				deci(node);deci(val);
				segtree.update(node-1,val);		
			}
			else {
				deci(l);deci(r);
				cout<<segtree.q(l-1, r-1)<<endl;
			}
		}
	}
}