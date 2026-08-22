// Submission Timestamp: 2022-11-29 12:16:24

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
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
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
vector<int> z_function(string str){
	vector<int> rval;
	rval.resize((int)str.length(),0);
	int l = 0, r = 0;
	for (int i = 1; i < (int)str.length(); i++){
		if (i<=r){
			rval[i]=min(rval[i-l],r-i+1);
		}
		for (int j = rval[i]; i+j < (int)str.length(); j++){
			if (str[j]==str[i+j]) rval[i]++;
			else break;
		}
		if (rval[i]+i-1>r){
			l=i;
			r=rval[i]+i-1;
		}
	}
	return rval;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		vector<int> z=z_function(str);
		for (int i = 0; i < (int)str.length(); i++){
			if (z[i]+i==(int)str.length()){
				cout<<i<<" ";
			}
		}
		cout<<(int)str.length()<<endl;
	}
}