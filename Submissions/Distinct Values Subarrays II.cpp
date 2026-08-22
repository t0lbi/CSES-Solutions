// Submission Timestamp: 2022-10-04 13:24:38

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
		deci(n);deci(k);
		vint(arr(n));
		cinarr(arr);
		int node = 0;
		map<int,int> mp;
		mp[arr[0]]++;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			while (node<n-1){
				if (mp.size()==k){
					if (mp[arr[node+1]]) {
						mp[arr[node+1]]++;
						node++;
					}
					else {
						mp.erase(arr[node+1]);
						break;
					}
				}
				else {
					node++;
					mp[arr[node]]++;
				}
			}
			ans+=node-i+1;
			mp[arr[i]]--;
			if (mp[arr[i]]==0) mp.erase(arr[i]);
		}
		cout<<ans<<endl;
	}
}