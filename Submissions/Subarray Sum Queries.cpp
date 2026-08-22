// Submission Timestamp: 2022-10-05 13:38:14

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
struct ty{
	int somma,massimo,rmasimo,lmasimo;
};
struct SegTree{
	vector<ty> segtree;
	SegTree (vector<int> arr){
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,{0,0,0,0});
		for (int i = 0; i < arr.size(); i++){
			segtree[segtree.size()/2+i].somma=arr[i];
			segtree[segtree.size()/2+i].massimo=max(0ll,arr[i]);
			segtree[segtree.size()/2+i].lmasimo=max(0ll,arr[i]);
			segtree[segtree.size()/2+i].rmasimo=max(0ll,arr[i]);
		}
		for (int node = segtree.size()/2-1; node >= 0; node--){
			segtree[node].somma=segtree[node*2+1].somma+segtree[node*2+2].somma;
			segtree[node].lmasimo=max(segtree[node*2+1].lmasimo,segtree[node*2+1].somma+segtree[node*2+2].lmasimo);
			segtree[node].rmasimo=max(segtree[node*2+2].rmasimo,segtree[node*2+1].rmasimo+segtree[node*2+2].somma);
			segtree[node].massimo=max(segtree[node*2+1].massimo,max(segtree[node*2+2].massimo,segtree[node*2+1].rmasimo+segtree[node*2+2].lmasimo));
		}
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node].somma=val;
		segtree[node].massimo=max(0ll,val);
		segtree[node].lmasimo=max(0ll,val);
		segtree[node].rmasimo=max(0ll,val);
		while (node>0){
			node=(node-1)/2;
			segtree[node].somma=segtree[node*2+1].somma+segtree[node*2+2].somma;
			segtree[node].lmasimo=max(segtree[node*2+1].lmasimo,segtree[node*2+1].somma+segtree[node*2+2].lmasimo);
			segtree[node].rmasimo=max(segtree[node*2+2].rmasimo,segtree[node*2+1].rmasimo+segtree[node*2+2].somma);
			segtree[node].massimo=max(segtree[node*2+1].massimo,max(segtree[node*2+2].massimo,segtree[node*2+1].rmasimo+segtree[node*2+2].lmasimo));
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
			deci(pos);deci(val);
			segtree.update(pos-1,val);
			cout<<segtree.segtree[0].massimo<<endl;
		}
	}
}