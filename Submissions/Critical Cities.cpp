// Submission Timestamp: 2023-04-29 03:30:15

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
vector<int> label;
vector<int> dsu;
vector<int> par;
vector<int> dom;
vector<int> sdom;
vector<int> enc;
vector<int> decy;
vector<vector<int>> cont;
vector<vector<int>> arr;
vector<vector<int>> revarr;
int find(int node, bool bl = false){
	if (dsu[node]==node) return bl?-1:node;
	int v = find(dsu[node],true);
	if (v<0) return node;
	if (sdom[label[dsu[node]]]<sdom[label[node]]){
		label[node]=label[dsu[node]];
	}
	dsu[node]=v;
	return bl?v:label[node];
}
int tim;
void dfs(int node, int lnode = -1){
	enc[node]=tim;
	decy[tim]=node;
	if (lnode!=-1) par[tim]=enc[lnode];
	else par[tim]=-1;
	tim++;
	for (int i = 0; i < arr[node].size(); i++){
		if (enc[arr[node][i]]!=-1) continue;
		dfs(arr[node][i],node);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		label.resize(n);
		dsu.resize(n);
		par.resize(n);
		enc.resize(n,-1);
		decy.resize(n,-1);
		sdom.resize(n);
		dom.resize(n);
		arr.resize(n);
		cont.resize(n);
		revarr.resize(n);
		iota(label.begin(), label.end(), 0ll);
		iota(dsu.begin(), dsu.end(), 0ll);
		iota(sdom.begin(), sdom.end(), 0ll);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			revarr[v-1].push_back(u-1);
		}
		int st = 0;
		int en = n-1;
		dfs(st);
		for (int i = n-1; i >= 0; i--){
			if (decy[i]==-1) continue;
			for (int z = 0; z < revarr[decy[i]].size(); z++){
				int v = enc[revarr[decy[i]][z]];
				if (v==-1) continue;
				sdom[i]=min(sdom[i],sdom[find(v)]);
			}
			if (i) cont[sdom[i]].push_back(i);
			for (int j = 0; j < cont[i].size(); j++){
				int w = cont[i][j];
				int v = find(w);
				if (sdom[w]==sdom[v]) dom[w]=sdom[w];
				else dom[w]=v;
			}
			if (i) dsu[i]=par[i];
		}
		for (int ali = 0; ali < n; ali++){
			if (dom[ali]!=sdom[ali]) dom[ali]=dom[dom[ali]];
		}
		vector<int> ansarr;
		int node = n-1;
		while (node){
			ansarr.push_back(node+1);
			node=decy[dom[enc[node]]];
		}
		ansarr.push_back(1);
		sortarr(ansarr);
		cout<<ansarr.size()<<endl;
		coutarr(ansarr);
		cout<<flush;
	}
}