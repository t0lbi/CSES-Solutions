// Submission Timestamp: 2022-10-03 21:48:59

#define author tolbi
#pragma optimize("Bismillahirrahmanirrahim")
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
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
struct SegTree{
	vector<int> segtree;
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0);
		for (int i = 0; i < arr.size(); i++){
			segtree[segtree.size()/2+i]=arr[i];
		}
		for (int i = segtree.size()/2-1; i>=0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
		}
	}
	int query(int tarl, int tarr, int l=0, int r=-1, int node = 0){
		if (r==-1) r=segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void update(int node, int pos){
		node+=segtree.size()/2;
		segtree[node]=pos;
		while (node>0){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
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
			deci(ty);
			if (ty==1){
				deci(pos);deci(val);
				segtree.update(pos-1,val);
			}
			else {
				deci(l);deci(r);
				cout<<segtree.query(l-1,r-1)<<endl;
			}
		}
	}
}