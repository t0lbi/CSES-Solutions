// Submission Timestamp: 2022-10-21 18:12:44

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
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
struct SparceTable{
	int LOG;
	vector<vector<int>> st;
	SparceTable(vector<int> arr){
		LOG=ceil(log2(arr.size()))+5;
		st.resize(arr.size(),vector<int>(LOG,MOD));
		for (int i = 0; i < arr.size(); ++i)
		{
			st[i][0]=arr[i];
		}
		for (int bit = 1; bit < LOG; bit++){
			for (int i = 0; i < arr.size(); i++){
				if (i+tol(bit-1)<arr.size()) st[i][bit]=min(st[i][bit-1],st[i+tol(bit-1)][bit-1]);
				else st[i][bit]=MOD;
			}
		}
	}
	int query(int l, int r){
		int huh = log2(r-l+1);
		return min(st[l][huh],st[r-tol(huh)+1][huh]);
	}
};
int LOG;
vector<int> finitos;
vector<int> starts;
vector<vector<int>> arr;
vector<int> hueh;
vector<int> dep;
vector<int> sis;
vector<int> ner;
vector<int> haa;
int ind;
void dfs4(int node, int lnode=-1){
	sis.push_back(node);
	if (ner[node]==-1) {
		ner[node]=haa.size();
	}
	haa.push_back(ner[node]);
	ind++;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs4(arr[node][i], node);
		sis.push_back(node);
		haa.push_back(ner[node]);
		ind++;
	}
	haa.push_back(ner[node]);
	sis.push_back(node);
	ind++;
}
void dfs(int node, int lnode=-1){
	if (lnode==-1) dep[node]=0;
	else dep[node]=dep[lnode]+1;
	hueh[ind++]=(node);
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs(arr[node][i],node);
	}
}
void dfs2(int node, int lnode=-1){
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs2(arr[node][i],node);
		finitos[node]+=finitos[arr[node][i]];
		starts[node]+=starts[arr[node][i]];
	}
}
int32_t main(){
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		int n,m;
		cin>>n>>m;
		LOG = ceil(log2(n));
		arr.resize(n);
		dep.resize(n);
		for (int i = 0; i < n-1; i++){
			int u;cin>>u;
			int v;cin>>v;
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		ner.resize(n,-1);
		dfs4(0);
		ind=0;
		hueh.resize(n);
		dfs(0);
		finitos.resize(n,0);
		starts.resize(n,0);
		vector<int> ansarr(n,0);
		SparceTable st(haa);
		while (m--){
			int a,b;
			cin>>a>>b;
			if (ner[a-1]>ner[b-1]) swap(a,b);
			int lc = sis[st.query(ner[a-1],ner[b-1])];
			ansarr[lc]--;
			finitos[lc]+=2;
			starts[a-1]++;
			starts[b-1]++;
		}
		vector<int> huh=finitos;
		dfs2(0);
		for (int i = 0; i < n; i++){
			ansarr[i]+=starts[i]-finitos[i]+huh[i];
		}
		coutarr(ansarr);
	}
}