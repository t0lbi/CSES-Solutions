// Submission Timestamp: 2023-04-19 17:48:10

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
int n;
vector<int> pref;
vector<int> pp;
vector<int> pp2;
vector<int> oldm;
vector<int> newm;
int left(int l, int r){
	int hh = 0;
	if (l) hh=pp[l-1];
	int ans = pp[r]-hh;
	hh=0;
	if (l) hh = pref[l-1];
	return ans-(l+1)*(pref[r]-hh);
}
int right(int l, int r){
	int hh = 0;
	if (l) hh = pp2[l-1];
	int ans = pp2[r]-hh;
	hh=0;
	if (l) hh = pref[l-1];
	return ans-(n-r)*(pref[r]-hh);
}
int C(int l, int r){
	if (l==r) return 0ll;
	int mid = l+(r-l)/2;
	return left(l,mid)+right(mid+1,r);
}
void calc(int l, int r, int optl, int optr){
	if (l>r) return;
	int mid = l+(r-l)/2;
	int opt = -1;
	newm[mid]=1e16;
	for (int i = max(0ll,optl); i <= min(optr,mid-1); i++){
		if (oldm[i]+C(i,mid)<newm[mid]){
			newm[mid]=oldm[i]+C(i,mid);
			opt=i;
		}
	}
	calc(l, mid-1, optl, opt);
	calc(mid+1, r, opt, optr);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		cin>>n;deci(k);
		pref.resize(n);
		pp.resize(n);
		pp2.resize(n);
		cinarr(pref);
		oldm.resize(n);
		newm.resize(n);
		for (int i = 0; i < n; i++){
			pp[i]=(i+1)*pref[i];
			pp2[i]=(n-i)*pref[i];
			if (i) {
				pp[i]+=pp[i-1];
				pp2[i]+=pp2[i-1];
				pref[i]+=pref[i-1];
			}
		}
		for (int i = 0; i < n; i++){
			oldm[i]=right(0,i);
		}
		for (int i = 2; i <= k; i++){
			calc(0,n-1,0,n-1);
			swap(oldm,newm);
		}
		int ans = INF;
		for (int i = k-1; i < n; i++){
			ans=min(ans,oldm[i]+left(i,n-1));
		}
		cout<<ans<<endl;
	}
}