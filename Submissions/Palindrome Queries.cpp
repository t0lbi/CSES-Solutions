// Submission Timestamp: 2023-03-07 09:36:10

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
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 232323233;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int fpow(int base, int pow){
	int rval = 1ll;
	while (pow){
		if (pow&1){
			rval*=base;
			rval%=MOD;
		}
		base*=base;
		base%=MOD;
		pow>>=1;
	}
	return rval;
};
struct SegTree{
	vector<int> segtree;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]=val%MOD;
		while (node){
			node=(node-1)/2;
			segtree[node]=(segtree[node*2+1]+segtree[node*2+2])%MOD;
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return (lnode+rnode)%MOD;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		decstr(str);
		const int hsz = 2;
		array<int,hsz> base;
		for (int i = 0; i < hsz; i++) base[i]=ayahya()%232323;
		vector<SegTree> seg(hsz,SegTree(n));
		vector<SegTree> rev(hsz,SegTree(n));
		auto update = [&](int pos, char val)->void{
			for (int i = 0; i < hsz; i++){
				seg[i].update(pos,val*fpow(base[i], pos));
				rev[i].update(pos,val*fpow(base[i], n-pos-1));
			}
		};
		auto ispalindrome = [&](int l, int r)->bool{
			for (int i = 0; i < hsz; ++i)
			{
				int ha1 = seg[i].query(l,r);
				int ha2 = rev[i].query(l,r);
				ha1*=fpow(fpow(base[i],l),MOD-2);
				ha2*=fpow(fpow(base[i],n-r-1),MOD-2);
				ha1%=MOD;
				ha2%=MOD;
				if (ha1!=ha2) return false;
			}
			return true;
		};
		for (int i = 0; i < n; ++i)
		{
			update(i,str[i]);
		}
		while (q--){
			deci(ty);
			if (ty==1){
				deci(pos);char ch;cin>>ch;
				update(pos-1,ch);
			}
			else {
				deci(l);deci(r);
				if (ispalindrome(l-1,r-1)){
					cout<<"YES"<<endl;
				}
				else cout<<"NO"<<endl;
			}
		}
	}
}