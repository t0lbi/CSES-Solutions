// Submission Timestamp: 2022-10-31 14:08:56

//#pragma optimize("Bismillahirrahmanirrahim")
//Allahuekber
//ahmet23 orz...
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
	int sz;
	SegTree(int n){
		sz=n;
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
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
		segtree[node]=val;
		while (node){
			node = (node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
	void debug(){
		for (int i = 0; i < sz; i++){
			cout<<query(i,i)<<" ";
		}
		cout<<endl;
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
		arr.push_back(MOD);
		n++;
		SegTree pre(n);
		for (int i = 0; i < n; ++i)
		{
			pre.update(i,arr[i]);
		}
		vector<int> ansarr(q);
		vector<pair<pair<int,int>,int>> qarr(q);
		for (int i = 0; i < q; i++){
			cin>>qarr[i].first.first>>qarr[i].first.second;
			qarr[i].first.first--;
			qarr[i].first.second--;
			qarr[i].second=i;
		}
		sortrarr(qarr);
		int ind = 0;
		deque<int> stak;
		stak.push_front(n-1);
		SegTree valus(n);
		for (int i = n-2; i >= 0; i--){
			while (stak.size() && arr[stak.front()]<arr[i]){
				valus.update(stak.front(),0);
				stak.pop_front();
			}
			int nenod = stak.front();
			valus.update(i,arr[i]*(nenod-i)-pre.query(i,nenod-1));
			stak.push_front(i);
			while (ind<(int) qarr.size() && qarr[ind].first.first==i){
				int pos = upper_bound(stak.begin(),stak.end(),qarr[ind].first.second)-stak.begin()-1;
				int ans = 0;
				if (pos){
					ans+=valus.query(i,stak[pos-1]);
				}
				ans+=(qarr[ind].first.second-stak[pos]+1)*arr[stak[pos]]-pre.query(stak[pos],qarr[ind].first.second);
				ansarr[qarr[ind].second]=ans;
				ind++;
			}
		}
		for (int i = 0; i < q; ++i)
		{
			cout<<ansarr[i]<<endl;
		}
	}
}