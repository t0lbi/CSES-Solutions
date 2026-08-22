// Submission Timestamp: 2022-11-22 07:44:29

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
int indi = -1;
struct Node{
	int nenod[26];
	bool end;
	Node(){
		end=false;
		memset(nenod,-1,sizeof(nenod));
	}
};
vector<Node> trie;
void insert(string str){
	int crr = 0;
	for (int i = 0; i < str.length(); i++){
		if (trie[crr].nenod[str[i]-'a']==-1){
			trie[crr].nenod[str[i]-'a']=trie.size();
			trie.push_back(Node());
		}
		crr=trie[crr].nenod[str[i]-'a'];
		if (i==str.length()-1){
			trie[crr].end=true;
		}
	}
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		deci(n);
		trie.push_back(Node());
		for (int i = 0; i < n; ++i)
		{
			decstr(h);
			insert(h);
		}
		vector<int> dp(str.length()+1,0);
		dp[str.length()]=1ll;
		for (int i = str.length()-1; i >= 0; i--){
			int crr = 0;
			for (int j = i; j<str.length(); j++){
				if (trie[crr].nenod[str[j]-'a']==-1){
					break;
				}
				crr=trie[crr].nenod[str[j]-'a'];
				if (trie[crr].end){
					dp[i]+=dp[j+1];
					dp[i]%=MOD;
				}
			}
		}
		cout<<dp[0]<<endl;
	}
}