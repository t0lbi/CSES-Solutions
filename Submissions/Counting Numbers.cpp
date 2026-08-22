// Submission Timestamp: 2022-10-11 14:13:45

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
int toint(string num){
	int res = 0;
	int carp = 1;
	while (num.size()) {
		res+=carp*(num[num.size()-1]-'0');
		carp*=10;
		num.pop_back();
	}
	return res;
}
bool valid(string str){
	for (int i = 1; i < str.length(); i++){
		if (str[i]==str[i-1]) return false;
	}
	return true;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(a);decstr(b);
		if (b.length()<=6){
			int ai = toint(a);
			int j = toint(b);
			int ans = 0;
			for (int i = ai; i <= j; ++i)
			{
				if (valid(to_string(i))) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		vector<vector<vector<vector<int>>>> dp(b.length()+1,vector<vector<vector<int>>>(11,vector<vector<int>>(a.length()+1,vector<int>(b.length()+1,1))));
		for (int el = b.length()-1; el >= 0; el--){
			for (int inda = a.length(); inda>=0; inda--){
				for (int indb=b.length(); indb>=0;indb--){
					for (int last = 0; last <= 10; last++){
						dp[el][last][inda][indb]=0;
						for (int cha = 0; cha < 10; cha++){
							if(cha==last) continue;
							int cra = inda;
							int crb = indb;
							if (cra<a.length()){
								if(a[cra]-'0'==cha) cra++;
								else if (a[cra]-'0'>cha) continue;
								else cra=a.length();
							}
							if (crb<b.length()){
								if (b[crb]-'0'==cha) crb++;
								else if (b[crb]-'0'<cha) continue;
								else crb = b.length();
							}
							dp[el][last][inda][indb]+=dp[el+1][cha][cra][crb];
						}
					}
				}
			}
		}
		int ans = dp[0][0][0][0];
		if (a=="0") ans++;
		for (int i = 1; i <= b.length()-a.length();i++){
			ans+=dp[i][0][0][b.length()];
		}
		cout<<ans<<endl;
	}
}