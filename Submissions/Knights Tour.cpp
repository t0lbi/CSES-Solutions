// Submission Timestamp: 2022-10-19 22:24:01

#pragma optimize("Bismillahirrahmanirrahim")
//ahmet23 orz...
//Allahuekber
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
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
vector<vector<int>> arr;
vector<int> ansarr;
vector<int> val;
vector<bool> vis;
int crr;
void dfs(int node){
	ansarr[node]=crr;
	vis[node]=true;
	crr++;
	for (int i = 0; i < arr[node].size(); ++i)
	{
		if (vis[arr[node][i]]) continue;
		val[arr[node][i]]--;
	}
	int miva = -1;
	for (int i = 0; i < arr[node].size(); i++){
		if (vis[arr[node][i]]) continue;
		if (miva==-1) miva = i;
		if (val[arr[node][i]]<=val[arr[node][miva]]){
			miva = i;
		}
	}
	if (arr[node].size()==0) return;
	if (vis[arr[node][miva]]) return;
	dfs(arr[node][miva]);
}
bool valid(int i, int j){
	if (i<0) return false;
	if (j<0) return false;
	if (j>7) return false;
	if (i>7) return false;
	return true;
}
int tu(int i, int j){
	return i*8+j;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		crr=1;
		arr.resize(65);
		val.resize(65,0);
		ansarr.resize(65,-1);
		vis.resize(65,false);
		deci(x);deci(y);
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				int node = i*8+j;
				if (valid(i-1,j-2)) arr[node].push_back(tu(i-1,j-2));
				if (valid(i+1,j-2)) arr[node].push_back(tu(i+1,j-2));
				if (valid(i+1,j+2)) arr[node].push_back(tu(i+1,j+2));
				if (valid(i-1,j+2)) arr[node].push_back(tu(i-1,j+2));
				if (valid(i+2,j-1)) arr[node].push_back(tu(i+2,j-1));
				if (valid(i-2,j+1)) arr[node].push_back(tu(i-2,j+1));
				if (valid(i-2,j-1)) arr[node].push_back(tu(i-2,j-1));
				if (valid(i+2,j+1)) arr[node].push_back(tu(i+2,j+1));
			}
		}
		for (int i = 0; i < 64; ++i)
		{
			val[i]=arr[i].size();
		}
		dfs((y-1)*8+x-1);
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cout<<ansarr[i*8+j]<<" ";
			}
			cout<<endl;
		}
	}
}