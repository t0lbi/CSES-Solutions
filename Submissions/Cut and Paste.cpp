// Submission Timestamp: 2022-11-25 09:23:37

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
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct Node{
	char val;
	int lnode, rnode, h, sz, ls;
	Node():lnode(-1),rnode(-1),sz(1),ls(1){}
};
struct Treap{
	vector<Node> tree;
	void update(int node){
		tree[node].sz=1ll;
		if (tree[node].lnode!=-1) tree[node].sz+=tree[tree[node].lnode].sz;
		if (tree[node].rnode!=-1) tree[node].sz+=tree[tree[node].rnode].sz;
		tree[node].ls=1ll;
		if (tree[node].lnode!=-1) tree[node].ls+=tree[tree[node].lnode].sz;
	}
	void insert(int h, int ind, char val, int node = 0){
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
	string get(int node=0){
		string str = "";
		if (tree[node].lnode!=-1) str+=get(tree[node].lnode);
		str+=tree[node].val;
		if (tree[node].rnode!=-1) str+=get(tree[node].rnode);
		return str;
	}
	pair<int,int> split(int node, int ind){
		if (node==-1) return {-1,-1};
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
			tree[a].rnode=merge(tree[a].rnode,b);
			update(a);
			return a;
		}
		else {
			tree[b].lnode=merge(a,tree[b].lnode);
			update(b);
			return b;
		}
	}
	void cutpasta(int l, int r){
		auto sp = split(0,l);
		int a = sp.first;
		int b = sp.second;
		sp = split(b,r-l+2);
		b = sp.first;
		int c = sp.second;
		a = merge(a,c);
		merge(a,b);
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
			deci(l);deci(r);
			treap.cutpasta(l,r);
		}
		cout<<treap.get()<<endl;
	}
}