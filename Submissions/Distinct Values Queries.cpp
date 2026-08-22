// Submission Timestamp: 2022-10-17 15:22:42

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
int bl;
struct Query{
	int l,r,i;
};
bool comp(Query a, Query b){
	if (a.l/bl==b.l/bl) return a.r<b.r;
	return a.l<b.l;
}
vector<int> compress(vector<int> arr){
	int ind = 1;
	map<int,int> mp;
	for (int i = 0; i < arr.size(); i++){
		if (mp[arr[i]]) {
			arr[i]=mp[arr[i]]-1;
			continue;
		}
		mp[arr[i]]=ind;
		arr[i]=ind-1;
		ind++;
	}
	return arr;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(q);
		vint(arr(n));
		cinarr(arr);
		arr=compress(arr);
		vector<Query> qu(q);
		for (int i = 0; i < q; ++i)
		{
			cin>>qu[i].l>>qu[i].r;
			qu[i].l--;
			qu[i].r--;
			qu[i].i=i;
		}
		vector<int> ansarr(q);
		bl=sqrt(n);
		sort(qu.begin(),qu.end(),comp);
		int l = 0, r = 0;
		vector<int> mp(n+4,0);
		mp[arr[0]]++;
		int ans = 1;
		for (int i = 0; i < q; ++i)
		{
			while (l<qu[i].l){
				mp[arr[l]]--;
				if (!mp[arr[l]]) ans--;
				l++;
			}
			while (l>qu[i].l){
				l--;
				if (!mp[arr[l]]) ans++;
				mp[arr[l]]++;
			}
			while (r>qu[i].r){
				mp[arr[r]]--;
				if (!mp[arr[r]]) ans--;
				r--;
			}
			while (r<qu[i].r){
				r++;
				if (!mp[arr[r]]) ans++;
				mp[arr[r]]++;
			}
			ansarr[qu[i].i]=ans;
		}
		for (int i = 0; i < q; ++i)
		{
			cout<<ansarr[i]<<endl;
		}
	}
}