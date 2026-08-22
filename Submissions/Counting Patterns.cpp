// Submission Timestamp: 2023-03-08 14:26:01

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
	vector<int> cnt(max(30ll,n));
	vector<int> pn(n);
	vector<int> newc(n);
	int LOG = log2(n)+2;
	vector<pair<char,int>> _cr(n);
	for (int i = 0; i < n; i++){
		_cr[i]={str[i],i};
	}
	sortarr(_cr);
	p[0]=_cr[0].second;
	c[p[0]]=0;
	int cl = 0;
	for (int i = 1; i < n; ++i)
	{
		p[i]=_cr[i].second;
		if (str[p[i]]==str[p[i-1]]) c[p[i]]=c[p[i-1]];
		else c[p[i]]=++cl;
	}
	for (int k = 1; k < LOG; ++k){
		fill(cnt.begin(), cnt.end(), 0ll);
		for (int i = 0; i < n; i++){
			pn[i]=(((p[i]-tol(k-1))%n)+n)%n;
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i < cnt.size(); i++){
			cnt[i]+=cnt[i-1];
		}
		for (int i = n-1; i >= 0; i--){
			p[--cnt[c[pn[i]]]] = pn[i];
		}
		cl = 0;
		newc[p[0]]=0;
		pair<int,int> onc={c[p[0]],c[(p[0]+tol(k-1))%n]};
		for (int i = 1; i < n; i++){
			pair<int,int> crr = {c[p[i]],c[(p[i]+tol(k-1))%n]};
			if (crr==onc){
				newc[p[i]]=newc[p[i-1]];
			}
			else {
				newc[p[i]]=++cl;
			}
			onc=crr;
		}
		swap(c,newc);
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
		int n = str.length();
		int len;
		vector<int> suff = Suffix_Array(str);
		auto get = [&](int num)->string{
			return str.substr(suff[num],len);
		};
		deci(q);
		while (q--){
			decstr(crr);
			len=crr.length();
			int l = 0, r = n-1;
			while (l<r){
				int mid = l+(r-l+1)/2;
				if (get(mid)<=crr){
					l=mid;
				}
				else r = mid-1;
			}
			if (get(l)!=crr){
				cout<<0<<endl;
				continue;
			}
			int sag = l;
			l = 0, r = n-1;
			while (l<r){
				int mid = l+(r-l)/2;
				if (get(mid)>=crr){
					r=mid;
				}
				else l = mid+1;
			}
			int sol = r;
			cout<<sag-sol+1<<endl;
		}
	}
}