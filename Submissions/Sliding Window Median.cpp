// Submission Timestamp: 2022-10-04 14:33:10

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
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
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
		while (node>0){
			node=(node-1)/2;
			segtree[node]=segtree[node*2+1]+segtree[node*2+2];
		}
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
		map<int,int> rel;
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
			cout<<rel[segtree.find((k+1)/2)]<<" ";
			if (i==n-k) break;
			segtree.update(arr[i],-1);
			segtree.update(arr[i+k],1);
		}
		cout<<endl;
	}
}