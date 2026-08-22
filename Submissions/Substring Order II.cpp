// Submission Timestamp: 2023-03-13 13:13:30

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
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
vector<int> Suffix_Array(string &str){
	str+="$";
	int n = str.length();
	vector<int> p(n);
	vector<int> pn(n);
	vector<int> c(n);
	vector<int> cnt(max(30ll,n));
	vector<int> newc(n);
	vector<pair<char,int>> __nc(n);
	for (int i = 0; i < n; ++i)
	{
		__nc[i]={str[i],i};
	}
	sortarr(__nc);
	for (int i = 0; i < n; ++i)
	{
		p[i]=__nc[i].second;
	}
	int cls = 0;
	c[p[0]]=0;
	for (int i = 1; i < n; ++i)
	{
		if (str[p[i]]==str[p[i-1]]) c[p[i]]=c[p[i-1]];
		else c[p[i]]=++cls;
	}
	int LOG = log2(n)+1;
	for (int k = 0; k < LOG; k++){
		fill(cnt.begin(), cnt.end(), 0ll);
		for (int i = 0; i < n; ++i)
		{
			pn[i]=(((p[i]-tol(k))%n)+n)%n;
			cnt[c[i]]++;
		}
		for (int i = 1; i < cnt.size(); i++){
			cnt[i]+=cnt[i-1];
		}
		for (int i = n-1; i >= 0; i--)
		{
			p[--cnt[c[pn[i]]]]=pn[i];
		}
		cls=0;
		newc[p[0]]=0;
		pair<int,int> old={c[p[0]],c[(p[0]+tol(k))%n]};
		for (int i = 1; i < n; i++){
			pair<int,int> crr = {c[p[i]],c[(p[i]+tol(k))%n]};
			if (old==crr) newc[p[i]]=newc[p[i-1]];
			else newc[p[i]]=++cls;
			swap(old,crr);
		}
		swap(newc,c);
	}
	str.pop_back();
	rev(p);
	p.pop_back();
	rev(p);
	return p;
}//Suffix Array
vector<int> LCP(string &str, vector<int> &suff){
	int n = str.length();
	vector<int> lcp(n,0);
	vector<int> rank(n);
	for (int i = 0; i < n; ++i)
	{
		rank[suff[i]]=i;
	}
	int k = 0;
	for (int i = 0; i < n; i++){
		if (rank[i]==n-1){
			k=0;
			continue;
		}
		int j = suff[rank[i]+1];
		while (i+k<n && j+k<n && str[i+k]==str[j+k]) k++;
		lcp[rank[i]]=k;
		if (k) k--;
	}
	return lcp;
}//LCP
struct SegTree{
	vector<int> segtree;
	vector<int> lazy;
	vector<int> val;
	vector<bool> isvalid;
	vector<int> sz;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0);
		lazy.resize(segtree.size(),0);
		val.resize(segtree.size(),0);
		sz.resize(segtree.size(),0);
		isvalid.resize(segtree.size(),false);
		for (int i = 0; i < n; i++){
			sz[i+sz.size()/2]=1ll;
		}
		for (int i = segtree.size()/2-1; i >= 0; i--){
			sz[i]=sz[i*2+1]+sz[i*2+2];
		}
	}
	void dallan(int node){
		if (isvalid[node]){
			if (node*2+1<segtree.size()){
				lazy[node*2+1]=lazy[node*2+2]=lazy[node];
				val[node*2+1]=val[node*2+2]=val[node];
				isvalid[node*2+1]=isvalid[node*2+2]=true;
			}
			segtree[node]=(val[node]+lazy[node])*sz[node];
		}
		else {
			segtree[node]+=lazy[node]*sz[node];
			if (node*2+1<segtree.size()){
				lazy[node*2+1]+=lazy[node];
				lazy[node*2+2]+=lazy[node];
			}
		}
		lazy[node]=0;
		val[node]=0;
		isvalid[node]=false;
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>tarr || r<tarl) return 0ll;
		dallan(node);
		if (l>=tarl && r<=tarr) return segtree[node];
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return lnode+rnode;
	}
	void update(int tarl, int tarr, int x, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr){
			lazy[node]+=x;
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		dallan(node);
		update(tarl, tarr, x, l, mid, node*2+1);
		update(tarl, tarr, x, mid+1, r, node*2+2);
		dallan(node*2+1);
		dallan(node*2+2);
		segtree[node]=segtree[node*2+1]+segtree[node*2+2];
	}
	void set(int tarl, int tarr, int x, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr){
			val[node]=x;
			lazy[node]=0;
			isvalid[node]=true;
			return;
		}
		if (l>tarr || r<tarl) return;
		int mid = l+(r-l)/2;
		dallan(node);
		set(tarl, tarr, x, l, mid, node*2+1);
		set(tarl, tarr, x, mid+1, r, node*2+2);
		dallan(node*2+1);
		dallan(node*2+2);
		segtree[node]=segtree[node*2+1]+segtree[node*2+2];
	}
};//Segment Tree
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		deci(k);
		vector<int> suff = Suffix_Array(str);
		int n = str.length();
		vector<int> lcp = LCP(str,suff);
		SegTree segtree(n+1);
		k=n*(n+1)/2-k+1;
		for (int i = n-1; i >= 0; i--){
			segtree.set(lcp[i]+1,n,0);
			segtree.update(1,n-suff[i],1);
			int bi = 0;
			if (i) bi = lcp[i-1];
			int cur = segtree.query(bi+1,n);
			if (k<=cur){
				int ind = 0;
				for (int j = n; j >= 1; j--){
					int cc = segtree.query(j,j);
					if (k<=cc){
						ind=j;
						break;
					}
					k-=cc;
				}
				cout<<str.substr(suff[i],ind)<<endl;
				break;
			}
			else k-=cur;
		}
	}
}