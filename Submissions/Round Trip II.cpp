// Submission Timestamp: 2022-10-14 00:01:45

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
vector<int> vis;
vector<vector<int>> arr;
vector<int> ansarr;
vector<int> crarr;
void dfs(int node){
	if (ansarr.size()) return;
	vis[node]=1;
	crarr.push_back(node+1);
	for (int i = 0; i < arr[node].size(); ++i)
	{
		if (ansarr.size()) break;
		if (vis[arr[node][i]]==2) continue;
		if (vis[arr[node][i]]==1){
			crarr.push_back(arr[node][i]+1);
			ansarr=crarr;
			break;
		}
		dfs(arr[node][i]);
		vis[arr[node][i]]=2;
	}
	crarr.pop_back();
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		arr.resize(n);
		vis.resize(n,0);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
		}
		for (int i = 0; i < n; i++){
			if (vis[i]==0) {
				crarr.clear();
				dfs(i);
				vis[i]=2;
			}
			if (ansarr.size()){
				rev(ansarr);
				while (ansarr[ansarr.size()-1]!=ansarr[0]) ansarr.pop_back();
				rev(ansarr);
				break;
			}
		}
		if (ansarr.size()){
			cout<<ansarr.size()<<endl;
			coutarr(ansarr);
		}
		else cout<<"IMPOSSIBLE"<<endl;
	}
}