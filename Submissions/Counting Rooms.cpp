// Submission Timestamp: 2022-10-11 10:27:36

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
vector<int> par;
int find_par(int node){
	if (par[node]==-1) return -1;
	if (par[node]==node) return node;
	return par[node]=find_par(par[node]);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		vector<string> arr(n);
		par.resize(n*m,0);
		cinarr(arr);
		for (int i = 0; i < n*m; ++i)
		{
			par[i]=i;
			if (arr[i/m][i%m]=='#') par[i]=-1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr[i][j]=='#') continue;
				if (i && arr[i-1][j]=='.') 		par[find_par(i*m+j)]=find_par(i*m+j-m); 
				if (i<n-1 && arr[i+1][j]=='.') 	par[find_par(i*m+j)]=find_par(i*m+j+m); 
				if (j && arr[i][j-1]=='.') 		par[find_par(i*m+j)]=find_par(i*m+j-1); 
				if (j<m-1 && arr[i][j+1]=='.') 	par[find_par(i*m+j)]=find_par(i*m+j+1); 
			}
		}
		map<int,bool> mp;
		for (int i = 0; i < n*m; ++i)
		{
			mp[find_par(i)]=true;
		}
		mp.erase(-1);
		cout<<mp.size()<<endl;
	}
}