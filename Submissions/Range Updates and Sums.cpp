// Submission Timestamp: 2022-10-21 10:50:09

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
#define endl '\n'
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
	vector<int> lazy;
	vector<int> val;
	vector<bool> isvalid;
	vector<int> sz;
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0);
		lazy.resize(segtree.size(),0);
		val.resize(segtree.size(),0);
		sz.resize(segtree.size(),0);
		isvalid.resize(segtree.size(),false);
		for (int i = 0; i < arr.size(); i++){
			segtree[i+segtree.size()/2]=arr[i];
			sz[i+sz.size()/2]=1ll;
		}
		for (int i = segtree.size()/2-1; i >= 0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
			sz[i]=sz[i*2+1]+sz[i*2+2];
		}
	}
	void dallan(int node){
		if (isvalid[node]){
			if (node*2+1<segtree.size()){
				lazy[node*2+1]=lazy[node*2+2]=lazy[node];
				val[node*2+1]=val[node*2+2]=val[node];
				isvalid[node*2+1]=isvalid[node*2+2]=true;
			}
			segtree[node]=(val[node]+lazy[node])*sz[node];
		}
		else {
			segtree[node]+=lazy[node]*sz[node];
			if (node*2+1<segtree.size()){
				lazy[node*2+1]+=lazy[node];
				lazy[node*2+2]+=lazy[node];
			}
		}
		lazy[node]=0;
		val[node]=0;
		isvalid[node]=false;
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>tarr || r<tarl) return 0ll;
		dallan(node);
		if (l>=tarl && r<=tarr) return segtree[node];
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void update(int tarl, int tarr, int x, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr){
			lazy[node]+=x;
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		dallan(node);
		update(tarl, tarr, x, l, mid, node*2+1);
		update(tarl, tarr, x, mid+1, r, node*2+2);
		dallan(node*2+1);
		dallan(node*2+2);
		segtree[node]=segtree[node*2+1]+segtree[node*2+2];
	}
	void set(int tarl, int tarr, int x, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr){
			val[node]=x;
			lazy[node]=0ll;
			isvalid[node]=true;
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		dallan(node);
		set(tarl, tarr, x, l, mid, node*2+1);
		set(tarl, tarr, x, mid+1, r, node*2+2);
		dallan(node*2+1);
		dallan(node*2+2);
		segtree[node]=segtree[node*2+1]+segtree[node*2+2];
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
		SegTree	segtree(arr);
		while (q--){
			deci(type);
			if (type==1){
				deci(l);deci(r);deci(x);
				segtree.update(l-1,r-1,x);
			}
			else if (type==2){
				deci(l);deci(r);deci(x);
				segtree.set(l-1,r-1,x);
			}
			else {
				deci(l);deci(r);
				cout<<segtree.query(l-1,r-1)<<endl;
			}
		}
	}
}