// Submission Timestamp: 2022-10-11 22:25:52

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
vector<int> dp;
vector<int> ans;
void dfs(int node){
	ans.push_back(node+1);
	if (node == 0) return;
	int next = arr[node][0];
	for (int i = 0; i < arr[node].size(); ++i)
	{
		if (dp[next]>dp[arr[node][i]]) next = arr[node][i];
	}
	dfs(next);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
		}
		int a = 1, b = n;
		priority_queue<pair<int,int>> pq;
		pq.push({0,a-1});
		dp.resize(n,MOD);
		while (pq.size()){
			int node = pq.top().second;
			int w = -pq.top().first;
			pq.pop();
			if (dp[node]<=w) continue;
			dp[node]=w;
			for (int i = 0; i < arr[node].size(); i++){
				if (dp[arr[node][i]]<=w+1) continue;
				pq.push({-(w+1),arr[node][i]});
			}
		}
		if (dp[b-1]==MOD){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else {
			cout<<dp[b-1]+1<<endl;
			dfs(n-1);
			rev(ans);
			coutarr(ans);
		}
	}
}