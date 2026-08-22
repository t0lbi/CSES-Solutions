// Submission Timestamp: 2023-04-23 17:29:47

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
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());\
int pp[10];
int swp(int val, int a, int b){
	int av = (val/pp[a])%10;
	int bv = (val/pp[b])%10;
	val-=av*pp[a];
	val-=bv*pp[b];
	val+=bv*pp[a];
	val+=av*pp[b];
	return val;
}
int32_t main(){
	pp[0]=1;
	for (int i = 1; i < 10; i++){
		pp[i]=pp[i-1]*10;
	}
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		vector<int> v(9);
		cinarr(v);
		int bak = 0;
		int kk = 100000000;
		for (int i = 0; i < v.size(); i++){
			bak+=v[i]*kk;
			kk/=10;
		}
		queue<pair<int,int>> q;
		unordered_set<int> mp;
		q.push({0,123456789});
		mp.insert(123456789);
		int ans = -1;
		while (q.size()){
			int w = q.front().first;
			int node = q.front().second;
			q.pop();
			if (node==bak){
				ans=w;
				break;
			}
			for (int i = 0; i < 3; i++){
				if (!mp.count(swp(node,i*3,i*3+1))) q.push({w+1,swp(node,i*3,i*3+1)}),mp.insert(swp(node,i*3,i*3+1));
				if (!mp.count(swp(node,i*3+2,i*3+1))) q.push({w+1,swp(node,i*3+2,i*3+1)}),mp.insert(swp(node,i*3+2,i*3+1));
				if (!mp.count(swp(node,i,i+3))) q.push({w+1,swp(node,i,i+3)}),mp.insert(swp(node,i,i+3));
				if (!mp.count(swp(node,i+3,i+6))) q.push({w+1,swp(node,i+3,i+6)}),mp.insert(swp(node,i+3,i+6));
			}
		}
		cout<<ans<<endl;
	}
}