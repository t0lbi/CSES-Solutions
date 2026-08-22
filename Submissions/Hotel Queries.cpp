// Submission Timestamp: 2022-10-04 08:40:37

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
	SegTree(vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,0ll);
		for (int i = 0; i < arr.size(); i++){
			segtree[i+segtree.size()/2]=arr[i];
		}
		for (int i = segtree.size()/2-1; i >= 0; i--){
			segtree[i]=max(segtree[i*2+1],segtree[i*2+2]);
		}
	}
	int find(int val){
		if (segtree[0]<val) return -1;
		int node = 0;
		while (node*2+2<segtree.size()){
			if (segtree[node*2+1]>=val){
				node=node*2+1;
			}
			else node=node*2+2;
		}
		node-=segtree.size()/2;
		return node;
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]-=val;
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
		deci(n);deci(q);
		vint(arr(n));
		cinarr(arr);
		SegTree segtree(arr);
		while (q--){
			deci(x);
			int pos = segtree.find(x);
			if (pos+1) segtree.update(pos,x);
			cout<<pos+1<<" ";
		}
		cout<<endl;
	}
}