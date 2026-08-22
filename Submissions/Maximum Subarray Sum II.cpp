// Submission Timestamp: 2022-10-04 18:11:46

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
struct SegTree{
	vector<int> segtree;
	SegTree(vector<int> arr){
		segtree.clear();
		segtree.resize(tol(ceil(log2(arr.size())+1))-1,-1000000000000000ll);
		for (int i = 0; i < arr.size(); ++i)
		{
			segtree[segtree.size()/2+i]=arr[i];
		}
		for (int i = segtree.size()/2-1; i>=0; i--){
			segtree[i]=max(segtree[i*2+1],segtree[i*2+2]);
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (tarl>tarr) return -1000000000000000ll;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return -1000000000000000ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode, rnode);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		deci(a);deci(b);
		vint(arr(n));
		cinarr(arr);
		int ans = -1000000000000000ll;
		for (int i = 1; i < n; ++i)
		{
			arr[i]+=arr[i-1];
		}
		SegTree segtree(arr);
		for (int i = 0; i < n; ++i)
		{
			int crr = 0;
			if (i) crr = -arr[i-1];
			crr+=segtree.query(i+a-1,min(i+b-1,n-1));
			ans=max(ans,crr);
		}
		cout<<ans<<endl;
	}
}