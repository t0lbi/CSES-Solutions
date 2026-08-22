// Submission Timestamp: 2022-10-30 22:44:22

//#pragma optimize("Bismillahirrahmanirrahim")
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
vector<int> heavy;
vector<vector<int>> arr;
vector<int> valus;
vector<int> par;
vector<int> dep;
int dfs(int node, int lnode = -1){
	par[node]=lnode;
	if (lnode!=-1) dep[node]=dep[lnode]+1;
	else dep[node]=0ll;
	int sz = 1ll;
	int mv = -1, crn = 0;
	for (int i = 0; i < (int)arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		int crr = dfs(arr[node][i],node);
		sz+=crr;
		if (crr>mv){
			mv=crr;
			crn=arr[node][i];
		}
	}
	if (mv!=-1){
		heavy[crn]=true;
	}
	return sz;
}
vector<int> head;
vector<int> ind;
vector<int> seg;
int indi;
void dfs2(int node){
	if (!heavy[node]) head[node]=node;
	for(int i = 0; i < (int)arr[node].size(); i++){
		if (arr[node][i]==par[node]) continue;
		if (head[node]==-1) head[node]=node;
		if (heavy[arr[node][i]]){
			if (heavy[node]){
				head[arr[node][i]]=head[node];
				seg[arr[node][i]]=seg[node];
				ind[arr[node][i]]=ind[node]+1ll;
			}
			else {
				head[arr[node][i]]=arr[node][i];
				seg[arr[node][i]]=indi++;
				ind[arr[node][i]]=0ll;
			}
		}
		else {
			head[arr[node][i]]=arr[node][i];
		}
		dfs2(arr[node][i]);
	}
}
struct SegTree{
	vector<int> segtree;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1,0ll);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node]=val;
		while (node){
			node=(node-1)/2;
			segtree[node]=max(segtree[node*2+1],segtree[node*2+2]);
		}
	}
	int query(int tarl, int tarr, int l = 0, int r = -1, int node = 0){
		if (r==-1) r = segtree.size()/2;
		if (l>=tarl && r<=tarr) return segtree[node];
		if (l>tarr || r<tarl) return 0ll;
		int mid = l+(r-l)/2;
		int lnode = query(tarl, tarr, l, mid, node*2+1);
		int rnode = query(tarl, tarr, mid+1, r, node*2+2);
		return max(lnode, rnode);
	}
};
vector<SegTree> segtree;
bool deb = false;
int query(int a, int b){
	int rval = 0ll;
	while (head[a]!=head[b]){
		int deba = -1;
		if (par[head[a]]!=-1) deba = dep[par[head[a]]];
		int debb = -1;
		if (par[head[b]]!=-1) debb = dep[par[head[b]]];
		if (deba<debb) swap(a,b);
		if (deb) cout<<a<<" "<<b<<endl;
		rval=max(rval,valus[a]);
		if (heavy[a]){
			rval=max(rval,segtree[seg[a]].query(0,ind[a]));
		}
		a=par[head[a]];
	}
	if (dep[a]<dep[b]) swap(a,b);
	if (deb) cout<<a<<" "<<b<<endl;
	if (a!=b){
		rval=max(rval,segtree[seg[a]].query(ind[b],ind[a]));
	}
	rval=max(rval,valus[b]);
	return rval;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		int start=clock();
		deci(n);deci(q);
		arr.resize(n);
		par.resize(n,-1);
		valus.resize(n);
		heavy.resize(n,false);
		head.resize(n,-1);
		ind.resize(n,-1);
		seg.resize(n,-1);
		dep.resize(n,0);
		cinarr(valus);
		for (int i = 0; i < n-1; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		dfs(0);
		dfs2(0);
		if (deb) {cout<<"DEP ";coutarr(dep);}
		if (deb) {cout<<"PAR ";coutarr(par);}
		if (deb) {cout<<"HED ";coutarr(head);}
		if (deb) {cout<<"HEV ";coutarr(heavy);}
		vector<int> inds(indi);
		for (int i = 0; i < n; i++){
			if (!heavy[i]) continue;
			inds[seg[i]]=max(inds[seg[i]],ind[i]+1);
		}
		for (int i = 0; i < indi; i++){
			segtree.push_back(inds[i]);
		}
		for (int i = 0; i < n; i++){
			if (!heavy[i]) continue;
			segtree[seg[i]].update(ind[i],valus[i]);
		}
		vector<int> anses;
		while (q--){
			deci(ty);deci(a);deci(b);
			if (ty==1){
				valus[a-1]=b;
				if (heavy[a-1]){
					segtree[seg[a-1]].update(ind[a-1],b);
				}
			}
			else {
				anses.push_back(query(a-1,b-1));
			}
		}
		//cout<< (int)((( (double)(((int)clock()) - (int)start )) / (double)CLOCKS_PER_SEC)*1000) << endl;
		coutarr(anses);
	}
}