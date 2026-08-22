// Submission Timestamp: 2022-10-03 21:18:47

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
	vector<vector<int>> segtree;
	SegTree(int n, int m){
		segtree.resize(tol(ceil(log2(n)+1))-1,vector<int>(tol(ceil(log2(m)+1))-1,0LL));
	}
	int querya(int tarl, int tarr, int dim, int l=-1, int r=-1, int node = 0){
		if (l==-1) l=0,r=segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[dim][node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = querya(tarl, tarr, dim, l, mid, node*2+1);
		int rnode = querya(tarl, tarr, dim, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	int query(int xl, int xr, int yl, int yr, int l=-1, int r=-1, int node = 0){
		if (l==-1) l=0,r=segtree.size()/2;
		if (l>=xl && r<=xr) return querya(yl, yr, node);
		if (l>xr || r<xl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(xl, xr, yl, yr, l, mid, node*2+1);
		int rnode = query(xl, xr, yl, yr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void update(int xnode, int ynode, int val){
		xnode+=segtree.size()/2;
		ynode+=segtree[0].size()/2;
		segtree[xnode][ynode]=val;
		int huh = ynode;
		while (huh>0){
			huh=(huh-1)/2;
			segtree[xnode][huh]=segtree[xnode][huh*2+1]+segtree[xnode][huh*2+2];
		}
		while (xnode>0){
			xnode=(xnode-1)/2;
			int crnode=ynode;
			segtree[xnode][crnode]=segtree[xnode*2+1][crnode]+segtree[xnode*2+2][crnode];
			while (crnode>0){
				crnode=(crnode-1)/2;
				segtree[xnode][crnode]=segtree[xnode][crnode*2+1]+segtree[xnode][crnode*2+2];
			}
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
		SegTree segtree(n,n);
		for (int i = 0; i < n; ++i)
		{
			decstr(str);
			for (int j = 0; j < n; j++){
				if (str[j]=='.') continue;
				segtree.update(i,j,1ll);
			}
		}
		while (q--){
			deci(x1);deci(y1);deci(x2);deci(y2);
			cout<<segtree.query(x1-1,x2-1,y1-1,y2-1)<<endl;
		}
	}
}