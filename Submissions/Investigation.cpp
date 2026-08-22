// Submission Timestamp: 2022-10-14 11:22:43

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
//#define endl '\n'
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
struct route{
	int w=INF, cnt=0, minc=0, maxc=0;
};
vector<route> dp;
class comp{
public:
	bool operator()(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
		return p1.first+dp[p1.second.first].w>p2.first+dp[p2.second.first].w;
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<vector<pair<int,int>>> arr(n);
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);deci(c);
			arr[u-1].push_back({v-1,c});
		}
		route defrout;
		dp.resize(n,defrout);
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
		dp[0].w=0;
		dp[0].cnt=1;
		pq.push({0,{-1,0}});
		while (pq.size()){
			int w = pq.top().first;
			int node = pq.top().second.second;
			if (pq.top().second.first+1){
				route rot = dp[pq.top().second.first];
				rot.w+=w;
				pq.pop();
				if (dp[node].w<rot.w) {
					continue;
				}
				else if (dp[node].w==rot.w){
					dp[node].cnt+=rot.cnt;
					dp[node].cnt%=MOD;
					dp[node].cnt+=MOD;
					dp[node].cnt%=MOD;
					dp[node].maxc=max(dp[node].maxc,rot.maxc+1);
					dp[node].minc=min(dp[node].minc,rot.minc+1);
					continue;
				}
				dp[node]=rot;
				dp[node].maxc++;
				dp[node].minc++;
			}
			else pq.pop();
			for (int i = 0; i < arr[node].size(); i++){
				int next = arr[node][i].first;
				if (dp[next].w<dp[node].w+arr[node][i].second) continue;
				pq.push({arr[node][i].second,{node,next}});
			}
		}
		cout<<dp[n-1].w<<" "<<dp[n-1].cnt<<" "<<dp[n-1].minc<<" "<<dp[n-1].maxc<<endl;
	}
}