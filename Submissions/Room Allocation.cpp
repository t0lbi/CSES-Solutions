// Submission Timestamp: 2022-09-26 09:16:40

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
		deci(n);
		vector<pair<int,pair<int,int>>> arr;
		for (int i = 0; i < n; ++i)
		{
			deci(a);deci(b);
			arr.push_back({a,{1,i}});
			arr.push_back({b+1,{-1,i}});
		}
		sortarr(arr);
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			sum+=arr[i].second.first;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
		vector<int> ava;
		for (int i = 0; i < ans; ++i)
		{
			ava.push_back(i+1);
		}
		vector<int> al(n);
		vector<int> ansarr(n);
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i].second.first==1){
				al[arr[i].second.second]=ava[ava.size()-1];
				ansarr[arr[i].second.second]=ava[ava.size()-1];
				ava.pop_back();
			}
			else {
				ava.push_back(al[arr[i].second.second]);
			}
		}
		coutarr(ansarr);
	}
}