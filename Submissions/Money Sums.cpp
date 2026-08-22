// Submission Timestamp: 2022-09-29 16:48:55

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
int n;
vint(arr);
vector<vector<bool>> dp;
map<int,bool> mp;
void f(int node, int val){
	if (node==n) return;
	if (dp[node][val]) return;
	dp[node][val]=true;
	f(node+1,val);
	f(node+1,val+arr[node]);
	if (val+arr[node]) mp[val+arr[node]]=true;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;
		arr.resize(n);
		cinarr(arr);
		dp.resize(n,vector<bool>(100000,false));
		f(0,0);
		cout<<mp.size()<<endl;
		for (auto it : mp) cout<<it.first<<" ";cout<<endl;
	}
}