// Submission Timestamp: 2022-10-05 15:51:58

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
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0);
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
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]+=val;
		while (node>0){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
};
struct Query{
	int type, point, l, r;
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		SegTree segtree(2000005);
		vector<Query> arr;
		for (int i = 0; i < n; i++){
			deci(x1);deci(y1);
			deci(x2);deci(y2);
			x1+=1e6;
			x2+=1e6;
			y1+=1e6;
			y2+=1e6;
			Query query;
			if (x1==x2){
				arr.push_back({1,y1,x1,-1});
				arr.push_back({2,y2,x1,-1});
			}
			else {
				arr.push_back({0,y1,x1,x2});
			}
		}
		sort(arr.begin(),arr.end(),[](Query a, Query b){
			if (a.point==b.point) return a.type<b.type;
			return a.point<b.point;
		});
		int ans = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i].type==0){
				ans+=segtree.query(arr[i].l,arr[i].r);
			}
			else if (arr[i].type==1){
				segtree.update(arr[i].l,1);
			}
			else {
				segtree.update(arr[i].l,-1);
			}
		}
		cout<<ans<<endl;
	}
}