// Submission Timestamp: 2022-10-13 12:03:28

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
		deci(n);deci(m);deci(q);
		vector<vector<int>> arr(n,vector<int>(n,-1));
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);deci(c);
			if (arr[u-1][v-1]==-1)arr[u-1][v-1]=c;
			arr[u-1][v-1]=min(arr[u-1][v-1],c);
			arr[v-1][u-1]=arr[u-1][v-1];
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i][i]=0;
		}
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (arr[i][k]==-1 || arr[k][j]==-1) continue;
					if (arr[i][j]==-1) arr[i][j]=LONG_LONG_MAX;
					arr[j][i]=arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
				}
			}
		}
		while (q--){
			deci(a);deci(b);
			cout<<arr[a-1][b-1]<<endl;
		}
	}
}