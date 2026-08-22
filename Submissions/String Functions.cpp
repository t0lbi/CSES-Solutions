// Submission Timestamp: 2023-03-09 10:27:33

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
vector<int> Z(string str){
	int n = str.length();
	vector<int> rval(n);
	rval[0]=0;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i<=r) rval[i]=min(r-i+1,rval[i-l]);
		while (i+rval[i]<n && str[rval[i]]==str[i+rval[i]]) rval[i]++;
		if (i+rval[i]-1>r){
			r=i+rval[i]-1;
			l=i;
		}
	}
	return rval;
}
vector<int> Pi(string str){
	int n = str.length();
	vector<int> rval(n);
	rval[0]=0;
	for (int i = 1; i < n; i++){
		int j = rval[i-1];
		while (j>0 && str[i]!=str[j]){
			j=rval[j-1];
		}
		if (str[i]==str[j]) j++;
		rval[i]=j;
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
		vector<int> z = Z(str);
		vector<int> pi = Pi(str);
		coutarr(z);
		coutarr(pi);
	}
}