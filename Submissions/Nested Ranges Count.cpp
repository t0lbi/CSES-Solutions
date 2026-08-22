// Submission Timestamp: 2022-10-04 18:41:22

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
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
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r=segtree.size()/2;
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
		while (node){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
	}
	void clear(){
		segtree.clear();
	}
	void resize(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
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
		vector<int> hueh;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].first.first>>arr[i].first.second;
			arr[i].second=i;
			hueh.push_back(arr[i].first.first);
			hueh.push_back(arr[i].first.second);
		}
		map<int,int> mp;
		int ind = 1;
		sortarr(hueh);
		for (int i = 0; i < hueh.size(); ++i)
		{
			if (mp[hueh[i]]) continue;
			mp[hueh[i]]=ind++;
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i].first.first=mp[arr[i].first.first];
			arr[i].first.second=mp[arr[i].first.second];
		}
		sort(arr.begin(),arr.end(),[](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
			if (a.first.first==b.first.first) return a.first.second<b.first.second;
			return a.first.first>b.first.first;
		});
		SegTree segtree(ind+5);
		vector<int> ansarr(n);
		for (int i = 0; i < n; ++i)
		{
			ansarr[arr[i].second]=segtree.query(0,arr[i].first.second);
			segtree.update(arr[i].first.second,1);
		}
		coutarr(ansarr);
		sort(arr.begin(),arr.end(),[](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
			if (a.first.first==b.first.first) return a.first.second>b.first.second;
			return a.first.first<b.first.first;
		});
		segtree.clear();
		segtree.resize(ind+5);
		ansarr.clear();
		ansarr.resize(n);
		for (int i = 0; i < n; ++i)
		{
			ansarr[arr[i].second]=segtree.query(arr[i].first.second,ind+3);
			segtree.update(arr[i].first.second,1);
		}
		coutarr(ansarr);
	}
}