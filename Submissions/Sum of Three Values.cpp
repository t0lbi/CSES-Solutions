// Submission Timestamp: 2022-09-26 10:24:03

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
		vector<pair<int,int>> arr(n);
		bool boolean = false;
		for (int i = 0; i < n; ++i)
		{
			deci(x);
			arr[i]={x,i+1};
		}
		sortarr(arr);
		for (int i = 0; i < n; ++i)
		{
			int ara = x-arr[i].first;
			int l = 0, r = n-1;
			while (l<r){
				if (l==i) {l++;continue;}
				if (r==i) {r--;continue;}
				if (arr[l].first+arr[r].first==ara){
					cout<<arr[l].second<<" "<<arr[i].second<<" "<<arr[r].second<<endl;
					boolean = true;
					break;
				}
				else if (arr[l].first+arr[r].first<ara){
					l++;
				}
				else r--;
			}
			if (boolean) break;
		}
		if(!boolean) cout<<"IMPOSSIBLE"<<endl;
	}
}