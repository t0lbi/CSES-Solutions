// Submission Timestamp: 2022-11-25 15:37:41

#pragma optimize("Bismillahirrahmanirrahim")
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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		vector<int> pi(str.length(),0);
		for (int i = 1; i < str.length(); i++){
			int j = pi[i-1];
			while (j>0 && str[i]!=str[j]) j=pi[j-1];
			if (str[i]==str[j]) j++;
			pi[i]=j;
		}
		vector<int> ansarr;
		int i = pi[str.length()-1];
		while (i>0){
			ansarr.push_back(i);
			i=pi[i-1];
		}
		rev(ansarr);
		coutarr(ansarr);
	}
}