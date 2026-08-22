// Submission Timestamp: 2022-11-25 10:45:51

#pragma optimize("Bismillahirrahmanirrahim")
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
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct Node{
	int val;
	int pres;
	int vals;
	int lnode, rnode, h, sz, ls;
	bool rev;
	Node():lnode(-1),rnode(-1),sz(1),ls(1),rev(false){}
};
struct Treap{
	vector<Node> tree;
	void update(int node){
		tree[node].vals=tree[node].val;
		tree[node].pres=tree[node].val;
		if (tree[node].lnode!=-1) tree[node].vals+=tree[tree[node].lnode].vals;
		if (tree[node].rnode!=-1) tree[node].vals+=tree[tree[node].rnode].vals;
		if (tree[node].lnode!=-1) tree[node].pres+=tree[tree[node].lnode].vals;
		tree[node].sz=1ll;
		if (tree[node].lnode!=-1) tree[node].sz+=tree[tree[node].lnode].sz;
		if (tree[node].rnode!=-1) tree[node].sz+=tree[tree[node].rnode].sz;
		tree[node].ls=1ll;
		if (tree[node].lnode!=-1) tree[node].ls+=tree[tree[node].lnode].sz;
	}
	void insert(int h, int ind, int val, int node = 0){
		if (tree.size()==0){
			tree.push_back(Node());
			tree[0].h=h;
			tree[0].val=val;
			tree[0].ls=ind;
		}
		else {
			if (tree[node].ls>=ind){
				if (tree[node].lnode==-1){
					tree[node].lnode=tree.size();
					tree.push_back(Node());
					tree[tree[node].lnode].h=h;
					tree[tree[node].lnode].val=val;
					tree[tree[node].lnode].ls=ind;
				}
				else {
					insert(h, ind, val, tree[node].lnode);
				}
			}
			else {
				if (tree[node].rnode==-1){
					tree[node].rnode=tree.size();
					tree.push_back(Node());
					tree[tree[node].rnode].h=h;
					tree[tree[node].rnode].val=val;
					tree[tree[node].rnode].ls=ind;
				}
				else {
					insert(h, ind, val, tree[node].rnode);
				}
			}
		}
	}
	void calc(){
		for (int i = tree.size()-1; i >= 0; i--){
			update(i);
		}
	}
	void dallan(int node){
		if (tree[node].rev){
			swap(tree[node].lnode, tree[node].rnode);
			if (tree[node].lnode!=-1) tree[tree[node].lnode].rev^=1;
			if (tree[node].rnode!=-1) tree[tree[node].rnode].rev^=1;
		}
		update(node);
		tree[node].rev=false;
	}
	pair<int,int> split(int node, int ind){
		if (node==-1) return {-1,-1};
		dallan(node);
		if (tree[node].ls>=ind){
			auto spl = split(tree[node].lnode, ind);
			tree[node].lnode=spl.second;
			update(node);
			return {spl.first,node};
		}
		else {
			auto spl = split(tree[node].rnode, ind-tree[node].ls);
			tree[node].rnode=spl.first;
			update(node);
			return {node,spl.second};
		}
	}
	int merge(int a, int b){
		if (a==-1) return b;
		if (b==-1) return a;
		if (tree[a].h>tree[b].h){
			dallan(a);
			tree[a].rnode=merge(tree[a].rnode,b);
			update(a);
			return a;
		}
		else {
			dallan(b);
			tree[b].lnode=merge(a,tree[b].lnode);
			update(b);
			return b;
		}
	}
	void reverse(int l, int r){
		auto [a,x] = split(0,l);
		auto [b,c] = split(x,r-l+2);
		tree[b].rev^=true;
		dallan(b);
		x = merge(a,b);
		merge(x,c); 
	}
	int get(int ind, int node = 0){
		if (node==-1) return 0ll;
		dallan(node);
		if (tree[node].ls==ind){
			return tree[node].pres;
		}
		else if (tree[node].ls>ind){
			return get(ind,tree[node].lnode);
		}
		else {
			return tree[node].pres+get(ind-tree[node].ls,tree[node].rnode);
		}
	}
	int query(int l, int r){
		if (l==1){
			return get(r);
		}
		return get(r)-get(l-1);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		vint(str(n));
		cinarr(str);
		vector<int> arr(n);
		for (int i = 0; i < n; i++){
			arr[i]=i;
		}
		for (int i = n-1; i >= 0; i--){
			swap(arr[i],arr[ayahya()%(i+1)]);
		}
		Treap treap;
		for (int i = 0; i < n; i++){
			treap.insert(n-i,arr[i]+1,str[arr[i]]);
		}
		treap.calc();
		while (q--){
			deci(x);deci(l);deci(r);
			if (x==1){
				treap.reverse(l,r);
			}
			else {
				cout<<treap.query(l,r)<<endl;
			}
		}
	}
}