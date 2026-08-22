// Submission Timestamp: 2022-11-22 10:14:46

#pragma optimize("Bismillahirrahmanirrahim")
#pragma GCC optimize("Ofast")
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
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<int> sz(n);
		vector<vector<int>> arr(n);
		vector<vector<int>> hueh(n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			sz[u-1]++;
			arr[u-1].push_back(v-1);
			hueh[v-1].push_back(u-1);
		}
		queue<int> qu;
		for (int i = 0; i < n; i++){
			if (!sz[i]) qu.push(i);
		}
		vector<int> topo;
		while (qu.size()){
			int node = qu.front();
			qu.pop();
			topo.push_back(node);
			for (int i = 0; i < hueh[node].size(); i++){
				sz[hueh[node][i]]--;
				if (!sz[hueh[node][i]]) qu.push(hueh[node][i]);
			}
		}
		vector<bitset<50000>> ansarr(n);
		for (int i = 0; i < n; i++){
			ansarr[topo[i]].set(topo[i],true);
		}
		for (int j = 0; j < n; ++j)
		{
			int node = topo[j];
			for (int i = 0; i < arr[node].size(); i++){
				ansarr[node]|=ansarr[arr[node][i]];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<ansarr[i].count()<<" ";
		}
		cout<<endl;
	}
}