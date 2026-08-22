// Submission Timestamp: 2023-03-07 07:56:35

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
inline int fpow(int base, int pow){
	int rval = 1ll;
	while (pow){
		if (pow&1){
			rval*=base;
			rval%=MOD;
		}
		base*=base;
		base%=MOD;
		pow>>=1;
	}
	return rval;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		decstr(str);
		int m = str.length();
		vector<int> pi(m,0);
		for (int i = 1; i < m; i++){
			int j = pi[i-1];
			while (j>0 && str[i]!=str[j]) j=pi[j-1]; 
			if (str[i]==str[j]) j++;
			pi[i]=j;
		}
		vector<vector<int>> dp(n,vector<int>(m,-1));
		auto f = [&](int node, int flag, auto f)->int{
			if (flag==m) return fpow(26,n-node);
			if (node==n) return 0ll;
			if (dp[node][flag]!=-1) return dp[node][flag];
			dp[node][flag]=0ll;
			for (char chr = 'A'; chr <= 'Z'; chr++){
				int cur = flag;
				while (cur>0 && str[cur]!=chr){
					cur=pi[cur-1];
				}
				if (str[cur]==chr) cur++;
				dp[node][flag]+=f(node+1,cur,f);
				dp[node][flag]%=MOD;
			}
			return dp[node][flag];
		};
		cout<<f(0,0,f)<<endl;
	}
}