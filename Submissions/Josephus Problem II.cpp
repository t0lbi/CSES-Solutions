// Submission Timestamp: 2022-09-29 13:34:57

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
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0);
		for (int i = 0; i < n; ++i)
		{
			segtree[i+segtree.size()/2]=1ll;
		}
		for (int i = segtree.size()/2-1; i>=0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
		}
	}
	int query(int tarl, int tarr, int l = -1, int r = -1, int node = 0){
		if (l==-1) {
			l=0;
			r=segtree.size()/2;
		}
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void erase(int node){
		node+=segtree.size()/2;
		segtree[node] = 0ll;
		while (node>0){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
	int find(int k){
		int node = 0;
		while (node*2+2<segtree.size()){
			if (segtree[node*2+1]>=k){
				node = node*2+1;
			}
			else {
				k-=segtree[node*2+1];
				node=node*2+2;
			}
		}
		return node-segtree.size()/2;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(k);
		SegTree segtree(n);
		int pos = 0;
		int kal = n;
		while (kal > 0){
			int huh = !segtree.query(pos,pos);
			int crk = k;
			crk+=segtree.query(0,pos)+huh;
			crk%=kal;
			if (crk==0) crk=kal;
			int node = segtree.find(crk);
			cout<<node+1<<" ";
			segtree.erase(node);
			pos=node;
			kal--;
		}
		cout<<endl;
	}
}