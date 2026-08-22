// Submission Timestamp: 2023-10-26 10:14:11

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
vector<int> Suffix_Array(string str){
	str+="$";
	int n = str.length();
	vector<int> p(n);
	vector<int> c(n);
	int LOG = log2(n)+3;
	vector<pair<pair<int,int>,int>> pn(n);
	for (int i = 0; i < n; i++){
		pn[i]={{str[i],str[i]},i};
	}
	sortarr(pn);
	for (int i = 0; i < n; ++i)
	{
		p[i]=pn[i].second;
	}
	int cls = 0;
	c[p[0]]=0;
	for (int i = 1; i < n; i++){
		if (pn[i].first==pn[i-1].first) c[p[i]]=c[p[i-1]];
		else c[p[i]]=++cls;
	}
	for (int k = 1; k < LOG; k++){
		for (int i = 0; i < n; i++){
			pn[i]={{c[i],c[(i+tol(k-1))%n]},i};
		}
		sortarr(pn);
		for (int i = 0; i < n; i++){
			p[i]=pn[i].second;
		}
		int cls = 0;
		c[p[0]]=0;
		for (int i = 1; i < n; i++){
			if (pn[i].first==pn[i-1].first) c[p[i]]=c[p[i-1]];
			else c[p[i]]=++cls;
		}
	}
	rev(p);
	p.pop_back();
	rev(p);
	return p;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		vector<int> suff = Suffix_Array(str);
		deci(q);
		while (q--){
			decstr(crr);
			int l = 0, r = str.length()-1;
			while (l<r){
				int mid = l+(r-l+1)/2;
				if (str.substr(suff[mid],crr.length())<=crr){
					l=mid;
				}
				else r=mid-1;
			}
			if (str.substr(suff[l],crr.length())==crr){
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
}