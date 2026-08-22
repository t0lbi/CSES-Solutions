// Submission Timestamp: 2022-10-18 14:04:52

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
int inv(int node){
	if (node%2) node--;
	else node++;
	return node;
}
vector<vector<int>> arr;
vector<int> stak;
vector<bool> vis;
vector<vector<int>> revarr;
void dfs(int node){
	vis[node]=true;
	for (int i = 0; i < arr[node].size(); i++){
		if (vis[arr[node][i]]) continue;
		dfs(arr[node][i]);
	}
	stak.push_back(node);
}
int crr;
vector<int> component;
void dfs2(int node){
	vis[node]=true;
	component[node]=crr;
	for (int i = 0; i < revarr[node].size(); i++){
		if (vis[revarr[node][i]]) continue;
		dfs2(revarr[node][i]);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(m*2);
		revarr.resize(m*2);
		component.resize(m*2,-1);
		for (int i = 0; i < n; ++i)
		{
			char c;int x;
			cin>>c>>x;
			int u=x*2+(c=='+')-2;
			cin>>c>>x;
			int v=x*2+(c=='+')-2;
			arr[inv(u)].push_back(v);
			revarr[v].push_back(inv(u));
			arr[inv(v)].push_back(u);
			revarr[u].push_back(inv(v));
		}
		vis.clear();
		vis.resize(m*2,false);
		for (int i = 0; i < m*2; i++){
			if (vis[i]) continue;
			dfs(i);
		}
		vis.clear();
		vis.resize(m*2,false);
		crr=0;
		while (stak.size()){
			int node = stak[stak.size()-1];
			stak.pop_back();
			if (vis[node]) continue;
			dfs2(node);
			crr++;
		}
		bool boolean = true;
		for (int i = 0; i < m; ++i)
		{
			if (component[i*2]==component[i*2+1]){
				boolean=false;
				break;
			}
		}
		if (!boolean){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		vector<vector<int>> rarr(crr);
		vector<int> gir(crr,0);
		for (int i = 0; i < arr.size(); i++){
			for (int j = 0; j < arr[i].size(); j++){
				if (component[i]==component[arr[i][j]]) continue;
				rarr[component[i]].push_back(component[arr[i][j]]);
				gir[component[arr[i][j]]]++;
			}
		}
		queue<int> q;
		for (int i = 0; i < crr; i++){
			if (!gir[i]) q.push(i);
		}
		vector<int> topo;
		while (q.size()){
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (int i = 0; i < rarr[node].size(); i++){
				gir[rarr[node][i]]--;
				if (!gir[rarr[node][i]]) q.push(rarr[node][i]);
			}
		}
		vector<int> hueh(crr);
		for (int i = 0; i < crr; i++){
			hueh[topo[i]]=i;
		}
		for (int i = 0; i < m; i++){
			int u = component[i*2];
			int v = component[i*2+1];
			if (hueh[u]<hueh[v]){
				cout<<"+ ";
			}
			else cout<<"- ";
		}
		cout<<endl;
	}
}