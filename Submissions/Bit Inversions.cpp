// Submission Timestamp: 2023-04-30 19:00:46

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
using namespace std;
template<typename X, typename Y> istream& operator>>(istream& in, pair<X,Y> &pr) {return in>>pr.first>>pr.second;}
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> &pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X, typename Y> pair<X,Y> operator+(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first+b.first,c.second=a.second+b.second;return c;}
template<typename X, typename Y> pair<X,Y> operator-(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first-b.first,c.second=a.second-b.second;return c;}
template<typename X, typename Y> void operator+=(pair<X,Y> &a, pair<X,Y> &b){a.first+=b.first,a.second+=b.second;}
template<typename X, typename Y> void operator-=(pair<X,Y> &a, pair<X,Y> &b){a.first-=b.first,a.second-=b.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
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
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
struct SegTree{
	struct Node{
		int sum, left, right, ic, sz;
		Node():sum(0),left(0),right(0),ic(0),sz(0){}
	};
	vector<Node> segtree;
	SegTree(int n){
		segtree.resize(tol(ceil(log2(n)+1))-1);
	}
	void update(int node, int val){
		node+=segtree.size()/2;
		segtree[node].sum=segtree[node].left=segtree[node].right=segtree[node].ic=val;
		segtree[node].sz=1ll;
		int lsz = 2ll;
		while (node){
			node=(node-1)/2;
			segtree[node].sz=lsz;
			if (segtree[node*2+1].sum==segtree[node*2+1].sz){
				segtree[node].left=segtree[node*2+1].sz+segtree[node*2+2].left;
			}
			else segtree[node].left=segtree[node*2+1].left;
			if (segtree[node*2+2].sum==segtree[node*2+2].sz){
				segtree[node].right=segtree[node*2+2].sz+segtree[node*2+1].right;
			}
			else segtree[node].right=segtree[node*2+2].right;
			segtree[node].sum=segtree[node*2+1].sum+segtree[node*2+2].sum;
			segtree[node].ic=max(segtree[node*2+1].ic,max(segtree[node*2+2].ic,max(segtree[node].left,segtree[node].right)));
			segtree[node].ic=max(segtree[node].ic,segtree[node*2+1].right+segtree[node*2+2].left);
			lsz<<=1;
		}
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		int n = str.length();
		deci(q);
		SegTree segtree1(n), segtree2(n);
		for (int i = 0; i < str.length(); i++){
			segtree1.update(i,(str[i]=='0'));
			segtree2.update(i,(str[i]!='0'));
		}
		while (q--){
			deci(x);x--;
			if (str[x]=='1') str[x]='0';
			else str[x]='1';
			segtree1.update(x,(str[x]=='0'));
			segtree2.update(x,(str[x]!='0'));
			cout<<max(segtree1.segtree[0].ic,segtree2.segtree[0].ic)<<" ";
		}
		cout<<endl;
	}
}