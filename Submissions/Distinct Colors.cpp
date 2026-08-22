// Submission Timestamp: 2022-10-06 10:27:50

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
vector<int> par;
vector<vector<int>> arr;
void dfs(int node, int lnode){
	par[node]=lnode;
	for (int i = 0; i < arr[node].size(); i++){
		if (arr[node][i]==lnode) continue;
		dfs(arr[node][i],node);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		if (n==1){
			cout<<1<<endl;
			continue;
		}
		vint(col(n));
		cinarr(col);
		par.clear();
		par.resize(n);
		arr.clear();
		arr.resize(n);
		for (int i = 0; i < n-1; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		dfs(0,-1);
		queue<int> q;
		vector<int> child(n,arr[0].size());
		for (int i = 1; i < n; ++i)
		{
			child[i]=arr[i].size()-1;
			if (child[i]==0){
				q.push(i);
			}
		}
		vector<set<int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			v[i].insert(col[i]);
		}
		vector<int> ansarr(n);
		while (q.size()){
			int node = q.front();
			q.pop();
			ansarr[node]=v[node].size();
			if (par[node]==-1) continue;
			child[par[node]]--;
			if (child[par[node]]==0) q.push(par[node]);
			if (v[par[node]].size()>v[node].size()){
				for (int it : v[node]){
					v[par[node]].insert(it);
				}
			}
			else {
				for (int it : v[par[node]]){
					v[node].insert(it);
				}
				swap(v[node],v[par[node]]);
			}
		}
		coutarr(ansarr);
	}
}