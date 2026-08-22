// Submission Timestamp: 2022-09-29 22:36:56

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
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		if (segtree[node]>val) return;
		segtree[node]=val;
		while (node>0){
			node=(node-1)/2;
			segtree[node]=max(segtree[node*2+1],segtree[node*2+2]);
		}
	}
	int query(int tarl, int tarr, int l=-1, int r=-1, int node=0){
		if (l==-1) l=0,r=segtree.size()/2;
		if (l>tarr || r<tarl) return 0ll;
		if (l>=tarl && r<=tarr) return segtree[node];
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode,rnode);
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
		cinarr(arr);
		SegTree segtree(n);
		map<int,int> mp;
		vector<int> barr=arr;
		sortarr(barr);
		int ind = 1;
		for (int i = 0; i < n; ++i)
		{
			if (mp[barr[i]]) continue;
			mp[barr[i]]=ind++;
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i]=mp[arr[i]]-1;
		}
		int ans = 0ll;
		for (int i = 0; i < n; ++i)
		{
			int val = segtree.query(0,arr[i]-1)+1ll;
			ans = max(ans,val);
			segtree.update(arr[i],val);
		}
		cout<<ans<<endl;
	}
}