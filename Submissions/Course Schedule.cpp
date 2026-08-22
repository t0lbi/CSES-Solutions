// Submission Timestamp: 2022-10-14 00:06:58

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
		vector<int> gir(n,0);
		vector<vector<int>> arr(n);
		vector<int> ansarr;
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);
			arr[u-1].push_back(v-1);
			gir[v-1]++;
		}
		queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			if (gir[i]==0) q.push(i);
		}
		while (q.size()){
			int node = q.front();
			q.pop();
			ansarr.push_back(node+1);
			for (int i = 0; i < arr[node].size(); ++i)
			{
				gir[arr[node][i]]--;
				if (!gir[arr[node][i]]){
					q.push(arr[node][i]);
				}
			}
		}
		if (ansarr.size()!=n){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else coutarr(ansarr);
	}
}