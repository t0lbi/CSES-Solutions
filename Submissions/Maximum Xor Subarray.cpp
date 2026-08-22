// Submission Timestamp: 2023-04-23 22:44:12

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
const int LOG = 32;
struct Trie{
	struct Node{
		array<int,2> child;
		Node(){
			child[0]=child[1]=-1;
		}
	};
	vector<Node> trie;
	Trie(){
		trie.push_back(Node());
	}
	void insert(int x){
		int node = 0;
		for (int bit = LOG-1; bit >= 0; bit--){
			if (trie[node].child[!!(tol(bit)&x)]==-1){
				trie[node].child[!!(tol(bit)&x)]=trie.size();
				trie.push_back(Node());
			}
			node=trie[node].child[!!(tol(bit)&x)];
		}
	}
	int query(int x){
		int node = 0;
		int ans = 0;
		for (int bit = LOG-1; bit >= 0; bit--){
			if (trie[node].child[!(tol(bit)&x)]==-1){
				node=trie[node].child[!!(tol(bit)&x)];
			}
			else {
				node=trie[node].child[!(tol(bit)&x)];
				ans|=tol(bit);
			}
		}
		return ans;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vint(arr(n));
		cinarr(arr);
		Trie tri;
		tri.insert(0);
		int xo = 0;
		int ans = 0;
		for (int i = 0; i < n; i++){
			xo^=arr[i];
			ans=max(ans,tri.query(xo));
			tri.insert(xo);
		}
		cout<<ans<<endl;
	}
}