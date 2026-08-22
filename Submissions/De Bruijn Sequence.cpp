// Submission Timestamp: 2022-10-19 00:38:48

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
vector<vector<pair<int,char>>> arr;
string ans;
int n;
void dfs(int node){
	while (arr[node].size()){
		pair<int,char> next = arr[node][arr[node].size()-1];
		arr[node].pop_back();
		ans+=next.second;
		dfs(next.first);
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;
		if (n==1){
			cout<<"10"<<endl;
			continue;
		}
		arr.resize(tol(n-1));
		for (int i = 0; i < arr.size(); i++){
			int num = i;
			if (num&tol(n-2)) num^=tol(n-2);
			num*=2;
			arr[i].push_back({num,'0'});
			arr[i].push_back({num+1,'1'});
		}
		for (int i = 0; i < n-1; i++){
			cout<<0;
		}
		dfs(0);
		cout<<ans<<endl;
	}
}