// Submission Timestamp: 2022-10-26 22:46:44

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
vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> rval = {{0,0},{0,0}};
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++){
				rval[i][j]+=a[i][k]*b[k][j];
				rval[i][j]%=MOD;
			}
		}
	}
	return rval;
}
vector<vector<int>> matpow(vector<vector<int>> base, int pow){
	vector<vector<int>> rval={{1,0},{0,1}};
	if (pow==0) return rval;
	if (pow&1) rval=mult(base,rval);
	return mult(matpow(mult(base,base),pow/2),rval);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		vector<vector<int>> arr={{1,1},{1,0}};
		deci(n);
		if (n) cout<<matpow(arr,n-1)[0][0]<<endl;
		else cout<<0<<endl;
	}
}