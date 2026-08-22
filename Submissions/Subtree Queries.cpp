// Submission Timestamp: 2022-10-21 13:49:23

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
vector<vector<int>> arr;
vector<int> sz;
vector<int> eul;
void dfs(int node, int lnode=-1){
	eul.emplace_back(node);
	sz[node]=1ll;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs(arr[node][i],node);
		sz[node]+=sz[arr[node][i]];
	}
}
struct SegTree{
	vector<int> segtree;
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0);
		for (int i = 0; i < arr.size(); i++){
			segtree[i+segtree.size()/2]=arr[i];
		}
		for (int i = segtree.size()/2-1; i >= 0; i--){
			segtree[i]=segtree[i*2+1]+segtree[i*2+2];
		}
	}
	void update(int node, int x){
		node+=segtree.size()/2;
		segtree[node]=x;
		while (node){
			node = (node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		vint(val(n));
		cinarr(val);
		sz.resize(n,0);
		arr.resize(n);
		for (int i = 0; i < n-1; i++){
			deci(u);deci(v);
			arr[u-1].emplace_back(v-1);
			arr[v-1].emplace_back(u-1);
		}
		dfs(0);
		vector<int> narr(n);
		vector<int> pos(n);
		for (int i = 0; i < n; ++i)
		{
			pos[eul[i]]=i;
		}
		for (int i = 0; i < n; ++i)
		{
			narr[pos[i]]=val[i];
		}
		SegTree segtree(narr);
		while (q--){
			deci(type);
			if (type==1){
				deci(node);deci(x);
				node = pos[node-1];
				segtree.update(node,x);
			}
			else {
				deci(node);
				cout<<segtree.query(pos[node-1],pos[node-1]+sz[node-1]-1)<<endl;
			}
		}
	}
}