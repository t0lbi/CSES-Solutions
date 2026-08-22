// Submission Timestamp: 2022-10-04 15:08:40

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
vector<int> rel;
struct SegTree{
	vector<int> segtree;
	vector<int> toptree;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
		toptree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	int find(int x){
		int node = 0;
		while (node*2+1<segtree.size()){
			if (segtree[node*2+1]>=x){
				node=node*2+1;
			}
			else{
				x-=segtree[node*2+1];
				node=node*2+2;
			}
		}
		return node-segtree.size()/2;
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]+=val;
		toptree[node]+=val*rel[(node-segtree.size()/2)];
		while (node>0){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
			toptree[node]=toptree[node*2+1]+toptree[node*2+2];
		}
	}
	int query(int tarl, int tarr, int l=0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	int tquery(int tarl, int tarr, int l=0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return toptree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = tquery(tarl, tarr, l, mid, node*2+1);
		int rnode = tquery(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	int cost(int node){
		int topq=tquery(0,node-1);
		int topq2=tquery(node+1,segtree.size()/2);
		int qu=query(0,node-1);
		int qu2=query(node+1,segtree.size()/2);
		int valul = rel[node]*qu-topq;
		int valur = topq2-rel[node]*qu2;
		return valul+valur;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(k);
		vint(arr(n));
		cinarr(arr);
		rel.resize(3e5,0);
		map<int,int> val;
		int ind = 1;
		vint(barr)=arr;
		sortarr(barr);
		for (int i = 0; i < n; ++i)
		{
			if (val[barr[i]]) continue;
			val[barr[i]]=ind;
			rel[ind]=barr[i];
			ind++;
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i]=val[arr[i]];
		}
		SegTree segtree(ind+5);
		for (int i = 0; i < k; ++i)
		{
			segtree.update(arr[i],1);
		}
		for (int i = 0; i < n-k+1; i++){
			cout<<segtree.cost(segtree.find((k+1)/2))<<" ";
			if (i==n-k) break;
			segtree.update(arr[i],-1);
			segtree.update(arr[i+k],1);
		}
		cout<<endl;
	}
}