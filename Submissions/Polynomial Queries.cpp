// Submission Timestamp: 2022-10-06 11:48:49

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
	vector<pair<int,int>> lazy;
	vector<int> sz;
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0);
		lazy.resize(segtree.size(),{0,0});
		sz.resize(segtree.size(),1);
		for (int i = 0; i < arr.size(); i++){
			segtree[segtree.size()/2+i]=arr[i];
		}
		for (int i = segtree.size()/2-1; i>=0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
			sz[i]=sz[i*2+1]+sz[i*2+2];
		}
	}
	void dallan(int node){
		segtree[node]+=lazy[node].first*sz[node]+((sz[node])*(sz[node]-1)/2)*lazy[node].second;
		if (node*2+1<segtree.size()){
			lazy[node*2+1].first+=lazy[node].first;
			lazy[node*2+1].second+=lazy[node].second;
			lazy[node*2+2].first+=lazy[node].first+(sz[node*2+1]*lazy[node].second);
			lazy[node*2+2].second+=lazy[node].second;
		}
		lazy[node]={0,0};
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode + rnode;
	}
	int adj(int l, int r){
		return r*(r+1)/2-l*(l-1)/2;
	}
	void update(int tarl, int tarr, int l = 0, int r = -1, int node = 0){ 
		if (r==-1) r = segtree.size()/2;
		dallan(node);
		if (l>=tarl && r<=tarr){
			lazy[node].first = l-tarl+1;
			lazy[node].second = 1ll;
			return;
		}
		if (l>tarr || r<tarl) return;
		int il = max(l,tarl);
		int ir = min(r,tarr);
		il-=tarl-1,ir-=tarl-1;
		segtree[node]+=adj(il,ir);
		int mid = l+(r-l)/2;
		update(tarl, tarr, l, mid, node*2+1);
		update(tarl, tarr, mid+1, r, node*2+2);
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
			deci(ty);
			deci(l);deci(r);
			if (ty==1){
				segtree.update(l-1,r-1);
			}
			else {
				cout<<segtree.query(l-1,r-1)<<endl;
			}
		}
	}
}