// Submission Timestamp: 2022-12-30 08:57:29

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#ifdef LOCAL
	#include "23.h"
#endif
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct LiChaoTree{
	vector<pair<int,int>> segtree;
	LiChaoTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,{0,INF});
	}
	void insert(pair<int,int> f, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		int mid = l+(r-l)/2;
		int oldm = segtree[node].first*mid+segtree[node].second;
		int newm = f.first*mid+f.second;
		int oldl = segtree[node].first*l+segtree[node].second;
		int newl = f.first*l+f.second;
		if (newm<oldm){
			swap(f,segtree[node]);
		}
		if (l==r) return;
		if ((newm<oldm)!=(newl<oldl)){
			insert(f, l, mid, node*2+1);
		}
		else insert(f, mid+1, r, node*2+2);
	}
	int query(int x, int l=0, int r=-1, int node=0){
		if (r==-1) r = segtree.size()/2;
		int val = segtree[node].first*x+segtree[node].second;
		if (l==r) return val;
		int mid = l+(r-l)/2;
		if (mid>=x){
			return min(val, query(x, l, mid, node*2+1));
		}
		return min(val, query(x,mid+1,r,node*2+2));
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(x);
		vint(arr(n));
		cinarr(arr);
		vint(barr(n));
		cinarr(barr);
		LiChaoTree lct(*max_element(arr.begin(), arr.end()));
		int ans;
		lct.insert({x,0});
		for (int i = 0; i < n; i++){
			ans=lct.query(arr[i]);
			lct.insert({barr[i],ans});
		}
		cout<<ans<<endl;
	}
}