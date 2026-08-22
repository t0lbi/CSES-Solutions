// Submission Timestamp: 2022-10-19 11:25:22

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
vector<vector<int>> arr;
vector<int> ansarr;
void dfs(int node){
	while (arr[node].size()){
		int next = arr[node].back();
		arr[node].pop_back();
		dfs(next);
		ansarr.push_back(next+1);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		vector<int> indeg(n);
		vector<int> outdeg(n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			indeg[v-1]++;
			outdeg[u-1]++;
		}
		bool boolean = true;
		for (int i = 1; i < n-1; i++){
			if (indeg[i]!=outdeg[i]){
				boolean=false;
				break;
			}
		}
		if (!boolean or outdeg[0]!=indeg[0]+1 or indeg[n-1]!=outdeg[n-1]+1){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		ansarr.clear();
		arr[n-1].push_back(0);
		dfs(n-1);
		if (ansarr.size()!=m+1){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		rev(ansarr);
		coutarr(ansarr);
	}
}