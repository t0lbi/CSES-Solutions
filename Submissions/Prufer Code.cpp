// Submission Timestamp: 2022-12-20 10:40:50

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
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vint(arr(n-2));
		cinarr(arr);
		priority_queue<int,vector<int>,greater<int>> pq;
		map<int,bool> mp;
		for (int i = 0; i < n-2; ++i)
		{
			mp[arr[i]]=true;
		}
		for (int i = 0; i < n; ++i)
		{
			if (mp[i+1]==false) pq.push(i+1);
		}
		vector<pair<int,int>> ansarr;
		vector<int> lel(n+1);
		for (int i = 0; i < n-2; ++i)
		{
			lel[arr[i]]=i;
		}
		for (int i = 0; i < arr.size(); ++i)
		{
			int ele = pq.top();
			pq.pop();
			ansarr.push_back({arr[i],ele});
			if (lel[arr[i]]==i){
				pq.push(arr[i]);
			}
		}
		ansarr.push_back({pq.top(),0});
		pq.pop();
		ansarr.back().second=pq.top();
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].first<<" "<<ansarr[i].second<<endl;
		}
	}
}