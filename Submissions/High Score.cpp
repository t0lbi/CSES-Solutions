// Submission Timestamp: 2022-10-13 13:43:56

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
struct edge{
	int u, v, c;
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<edge> arr(m);
		vector<int> dp(n,-INF);
		dp[0]=0;
		for (int i = 0; i < m; ++i)
		{
			cin>>arr[i].u>>arr[i].v>>arr[i].c;
			arr[i].u--;
			arr[i].v--;
		}
		bool hueh=false;
		for (int j = 0; j < 2*n; ++j)
		{
			for (int i = 0; i < m; ++i)
			{
				if (dp[arr[i].u]>-INF){
					if (dp[arr[i].v]<dp[arr[i].u]+arr[i].c && j>n-2) {
						dp[arr[i].u]=INF;
					}
					if (dp[arr[i].u]==INF){
						dp[arr[i].v]=INF;
						continue;
					}
					dp[arr[i].v]=max(dp[arr[i].u]+arr[i].c,dp[arr[i].v]);
				}
			}
		}
		if (dp[n-1]==INF){
			cout<<-1<<endl;
		}
		else cout<<dp[n-1]<<endl;
	}
}