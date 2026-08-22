// Submission Timestamp: 2023-06-12 12:09:22

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
using namespace std;
template<typename X, typename Y> istream& operator>>(istream& in, pair<X,Y> &pr) {return in>>pr.first>>pr.second;}
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> arr) {for(auto &it : arr) os<<it<<" "; return os;}
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
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vint(arr(n));
		cinarr(arr);
		vector<int> act(n);
		for (int i = 0; i < n; ++i)
		{
			arr[i]--;
			act[arr[i]]=i;
		}
		vector<bool> al(n,false);
		vector<vector<pair<int,int>>> ansarr(1,vector<pair<int,int>>(0));
		for (int i = 0; i < n; ++i)
		{
			if (arr[i]==i) {
				al[i]=true;
			}
			if (al[i]) continue;
			int a = i;
			int b = act[i];
			while (true){
				if (a==b) break;
				if (al[a]||al[b]) break;
				swap(act[arr[a]],act[arr[b]]);
				swap(arr[a],arr[b]);
				al[a]=al[b]=true;
				ansarr.back().push_back({a+1,b+1});
				a=arr[b];
				b=act[b];
			}
		}
		fill(al.begin(), al.end(), false);
		ansarr.push_back(vector<pair<int,int>>(0));
		for (int i = 0; i < n; ++i)
		{
			if (arr[i]==i) {
				al[i]=true;
			}
			if (al[i]) continue;
			int a = i;
			int b = act[i];
			while (true){
				if (a==b) break;
				if (al[a]||al[b]) break;
				swap(act[arr[a]],act[arr[b]]);
				swap(arr[a],arr[b]);
				al[a]=al[b]=true;
				ansarr.back().push_back({a+1,b+1});
				a=arr[b];
				b=act[b];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			assert(arr[i]==i);
		}
		while (ansarr.size() && ansarr.back().size()==0) ansarr.pop_back();
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].size()<<endl;
			for (int j = 0; j < ansarr[i].size(); j++){
				cout<<ansarr[i][j]<<endl;
			}
		}
	}
}