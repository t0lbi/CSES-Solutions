// Submission Timestamp: 2023-05-14 18:29:34

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
//#define endl '\n'
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
struct Node{
	int val, l, r, lnode, rnode, par, time;
	Node(): val(0),l(-1),r(-1),lnode(-1),rnode(-1), par(-1){}
} segtree[8000000];
int indi;
int times[200005];
void cret(int node){
	segtree[indi]=segtree[segtree[node].lnode];
	segtree[indi].time=segtree[node].time;
	segtree[indi].par=node;
	segtree[node].lnode=indi;
	indi++;
	segtree[indi]=segtree[segtree[node].rnode];
	segtree[indi].time=segtree[node].time;
	segtree[indi].par=node;
	segtree[node].rnode=indi;
	indi++;
}
void update(int time, int node, int val){
	int nod = times[time];
	while (segtree[nod].l!=node || segtree[nod].r!=node){
		int mid = segtree[nod].l+(segtree[nod].r-segtree[nod].l)/2;
		cret(nod);
		if (node<=mid){
			nod=segtree[nod].lnode;
		}
		else {
			nod=segtree[nod].rnode;
		}
	}
	segtree[nod].val=val;
	while (segtree[nod].par!=-1){
		nod=segtree[nod].par;
		segtree[nod].val=segtree[segtree[nod].lnode].val+segtree[segtree[nod].rnode].val;
	}
}
int query(int l, int r, int node){
	if (segtree[node].l>=l && segtree[node].r<=r) return segtree[node].val;
	if (segtree[node].l>r || segtree[node].r<l) return 0ll;
	return query(l,r,segtree[node].lnode)+query(l,r,segtree[node].rnode);
}
int millis=1;
void netre(int time){
	segtree[indi]=segtree[times[time]];
	segtree[indi].time=millis;
	times[millis]=indi;
	indi++,millis++;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		indi=tol(ceil(log2(n))+1)-1;
		for (int i = 0; i < tol(ceil(log2(n))); i++){
			segtree[indi/2+i].val=0;
			segtree[indi/2+i].l=i;
			segtree[indi/2+i].r=i;
			segtree[indi/2+i].par=((indi/2+i)-1)/2;
			segtree[indi/2+i].time=0;
		}
		for (int i = 0; i < n; i++){
			cin>>segtree[indi/2+i].val;
		}
		for (int i = indi/2-1; i >= 0; i--){
			segtree[i].lnode=i*2+1;
			segtree[i].rnode=i*2+2;
			segtree[i].l=segtree[segtree[i].lnode].l;
			segtree[i].r=segtree[segtree[i].rnode].r;
			segtree[i].val=segtree[segtree[i].lnode].val+segtree[segtree[i].rnode].val;
			if (i) segtree[i].par=(i-1)/2;
			segtree[i].time=0;
		}
		times[0]=0;
		while (q--){
			deci(ty);
			if (ty==1){
				deci(tim);deci(nod);deci(valu);
				update(tim-1,nod-1,valu);
			}
			else if (ty==2){
				deci(tim);deci(l);deci(r);
				cout<<query(l-1,r-1,times[tim-1])<<endl;
			}
			else {
				deci(tim);
				netre(tim-1);
			}
		}
	}
}