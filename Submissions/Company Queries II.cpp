// Submission Timestamp: 2022-10-06 16:54:18

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
#define endl '\n'
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
int LOG;
vector<vector<int>> st;
vector<int> sir;
vector<vector<int>> arr;
vector<int> dep;
void dfs(int node, int lnode, int dept){
	sir.push_back(node);
	dep[node]=dept;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs(arr[node][i],node,dept+1);
	}
}
int kthanc(int node, int k){
	for (int bit = LOG-1; bit >= 0; bit--){
		if (tol(bit)&k){
			node = st[node][bit];
		}
	}
	return node;
}
int lca(int a, int b){
	if (dep[a]>dep[b]){
		a = kthanc(a,dep[a]-dep[b]);
	}
	else {
		b = kthanc(b,dep[b]-dep[a]);
	}
	if (a==b) return a;
	for (int bit = LOG-1; bit>=0; bit--){
		if (st[a][bit]==st[b][bit]) continue;
		a=st[a][bit];
		b=st[b][bit];
	}
	return st[a][0];
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		LOG = ceil(log2(n))+5;
		st.resize(n,vector<int>(LOG,-1));
		arr.clear();
		arr.resize(n);
		dep.clear();
		dep.resize(n);
		for (int i = 1; i < n; i++){
			cin>>st[i][0];
			st[i][0]--;
			arr[i].push_back(st[i][0]);
			arr[st[i][0]].push_back(i);
		}
		sir.clear();
		dfs(0,-1,0);
		for (int bit = 1; bit < LOG; bit++){
			for (int i = 0; i < n; i++){
				int node = sir[i];
				st[node][bit]=-1;
				if (st[node][bit-1]==-1) continue;
				st[node][bit]=st[st[node][bit-1]][bit-1];
			}
		}
		while (q--){
			deci(a);deci(b);
			cout<<lca(a-1,b-1)+1<<endl;
		}
	}
}