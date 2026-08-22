// Submission Timestamp: 2022-10-04 14:11:10

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
vector<int> arr;
int n;
int k;
bool query(int x){
	int crr = x;
	int huh = 1;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>x) return false;
		if (arr[i]>crr) crr=x-arr[i],huh++;
		else crr-=arr[i];
	}
	return (huh<=k);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n>>k;
		arr.resize(n);
		cinarr(arr);
		int l = 0, r = LONG_LONG_MAX;
		while (l<r){
			int mid = l+(r-l)/2;
			if (query(mid)) r=mid;
			else l = mid+1;
		}
		cout<<l<<endl;
	}
}