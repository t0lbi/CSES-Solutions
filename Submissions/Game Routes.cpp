// Submission Timestamp: 2022-10-14 00:42:04

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<vector<int>> arr(n);
		vector<int> gir(n);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			gir[v-1]++;
		}
		queue<int> q;
		vector<int> topo;
		for (int i = 0; i < n; ++i)
		{
			if (!gir[i]) q.push(i);
		}
		while (q.size()){
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (int i = 0; i < arr[node].size(); ++i)
			{
				gir[arr[node][i]]--;
				if (!gir[arr[node][i]]) q.push(arr[node][i]);
			}
		}
		vector<int> dp(n,0);
		dp[0]=1;
		for (int no = 0; no < n; ++no)
		{
			int node = topo[no];
			for (int i = 0; i < arr[node].size(); i++){
				dp[arr[node][i]]+=dp[node];
				dp[arr[node][i]]%=MOD;
			}
		}
		cout<<dp[n-1]<<endl;
	}
}