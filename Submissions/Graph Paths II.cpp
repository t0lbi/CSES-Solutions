// Submission Timestamp: 2022-10-27 00:12:23

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
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
void debug(vector<vector<int>> arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		coutarr(arr[i]);
	}
}
vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> rval(a.size(),vector<int>(a.size(),INF));
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a.size(); j++){
			for (int k = 0; k < a.size(); k++){
				if (a[i][k]<INF && b[k][j]<INF){
					rval[i][j]=min(rval[i][j],a[i][k]+b[k][j]);
				}
			}
		}
	}
	return rval;
}
vector<vector<int>> matpow(vector<vector<int>> arr, int pow){
	if (pow==0){
		vector<vector<int>> basec(arr.size(),vector<int>(arr.size(),INF));
		for (int i = 0; i < arr.size(); ++i)
		{
			basec[i][i]=0;
		}
		return basec;
	}
	if (pow&1){
		return mult(arr,matpow(mult(arr,arr),pow/2));
	}
	return matpow(mult(arr,arr),pow/2);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);deci(k);
		vector<vector<int>> arr(n,vector<int>(n,INF));
		for (int i = 0; i < m; ++i)
		{
			deci(u);deci(v);deci(c);
			arr[u-1][v-1]=min(arr[u-1][v-1],c);
		}
		arr=matpow(arr,k);
		if (arr[0][n-1]==INF) cout<<-1<<endl;
		else cout<<arr[0][n-1]<<endl;
	}
}