// Submission Timestamp: 2022-10-02 11:43:03

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
	}
	int query(int tarl, int tarr, int l=-1, int r=-1, int node = 0){
		if (l==-1) l=0,r=segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode,rnode);
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
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vector<pair<pair<int,int>,int>> arr(n);
		vector<int> comps;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
			comps.push_back(arr[i].first.first);
			comps.push_back(arr[i].first.second);
		}
		sortarr(comps);
		map<int,int> mp;
		int iter = 1;
		for (int i = 0; i < comps.size(); ++i)
		{
			if (mp[comps[i]]) continue;
			mp[comps[i]]=iter++;
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i].first.first=mp[arr[i].first.first]-1;
			arr[i].first.second=mp[arr[i].first.second]-1;
		}
		SegTree segtree(iter+10);
		mp.clear();
		comps.clear();
		sortarr(arr);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int val = segtree.query(0,arr[i].first.first)+arr[i].second;
			segtree.update(arr[i].first.second+1,val);
			ans=max(ans,val);
		}
		cout<<ans<<endl;
	}
}
