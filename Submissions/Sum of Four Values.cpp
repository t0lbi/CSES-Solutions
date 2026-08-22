// Submission Timestamp: 2022-09-26 10:40:54

#define author tolbi
#pragma optimize("Bismillahirrahmanirrahim")//atilla sattı ab :(
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
		deci(n);deci(x);
		vint(arr(n));
		cinarr(arr);
		map<int,pair<int,int>> mp;
		bool boolean = false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j){
				int ara = x-arr[i]-arr[j];
				if (mp[ara].second == 0){
					mp.erase(ara);
				}
				else {
					boolean = true;
					cout<<mp[ara].first+1<<" "<<mp[ara].second+1<<" "<<i+1<<" "<<j+1<<endl;
				}
				if (boolean) break;
			}
			if (boolean) break;
			for (int j = 0; j < i; j++){
				mp[arr[i]+arr[j]]={j,i};
			}
		}
		if (!boolean) cout<<"IMPOSSIBLE"<<endl;
	}
}