// Submission Timestamp: 2022-10-05 14:44:02

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
struct piz{
	int l, r, sz;
};
struct SegTree{
	vector<piz> segtree;
	SegTree(vector<int> arr){
		segtree.resize(tol(1ll+ceil(log2(arr.size())))-1,{MOD,MOD});
		for (int i = segtree.size()/2; i<segtree.size();i++){
			segtree[i].sz=1;
		}
		for (int i = 0; i < arr.size(); i++){
			segtree[segtree.size()/2+i].l=arr[i];
			segtree[segtree.size()/2+i].r=arr[i];
		}
		for (int i = segtree.size()/2-1; i>=0; i--){
			segtree[i].sz=segtree[i*2+1].sz*2;
			segtree[i].l=min(segtree[i*2+1].l,segtree[i*2+2].l+segtree[i*2+1].sz);
			segtree[i].r=min(segtree[i*2+2].r,segtree[i*2+1].r+segtree[i*2+2].sz);
		}
	}
	piz query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return {MOD,MOD,0};
		int mid = l+(r-l)/2;
		piz lnode = query(tarl, tarr, l, mid, node*2+1);
		piz rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return {min(lnode.l,rnode.l+lnode.sz),min(rnode.r,lnode.r+rnode.sz),lnode.sz+rnode.sz};
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node].l=segtree[node].r=val;
		while (node){
			node=(node-1)/2;
			segtree[node].l=min(segtree[node*2+1].l,segtree[node*2+2].l+segtree[node*2+1].sz);
			segtree[node].r=min(segtree[node*2+2].r,segtree[node*2+1].r+segtree[node*2+2].sz);
		}
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
			if (type-1){
				deci(x);
				piz q1=segtree.query(0,x-1);
				piz q2=segtree.query(x-1,n-1);
				cout<<min(q1.r,q2.l)<<endl;
			}
			else {
				deci(pos);deci(x);
				segtree.update(pos-1,x);
			}
		}
	}
}