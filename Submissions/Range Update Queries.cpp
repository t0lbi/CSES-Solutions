// Submission Timestamp: 2022-09-29 12:14:16

#define author tolbi
#pragma optimize("Bismillahirrahmanirrahim")//atilla sattı ab :(
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
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0);
		for (int i = 0; i < arr.size(); ++i)
		{
			segtree[segtree.size()/2+i]=arr[i];
		}
		for (int i = segtree.size()/2-1; i >=0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
		}
		lazy.resize(segtree.size(),0);
	}
	int query(int tarl, int tarr, int l=-1, int r=-1, int node = 0){
		if (l==-1){
			l=0;
			r=segtree.size()/2;
		}
		segtree[node]+=lazy[node]*(r-l+1);
		if (node*2+2<segtree.size()){
			lazy[node*2+1]+=lazy[node];
			lazy[node*2+2]+=lazy[node];
		}
		lazy[node]=0ll;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void update(int tarl, int tarr, int val, int l = -1, int r = -1, int node = 0){
		if (l==-1){
			l=0;
			r=segtree.size()/2;
		}
		if (l>=tarl && r<=tarr){
			lazy[node]+=val;
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		update(tarl, tarr, val, l, mid, node*2+1);
		update(tarl, tarr, val, mid+1, r, node*2+2);
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
			if (ty-1){
				deci(x);
				cout<<segtree.query(x-1,x-1)<<endl;
			}
			else {
				deci(l);deci(r);deci(w);
				segtree.update(l-1,r-1,w);
			}
		}
	}
}