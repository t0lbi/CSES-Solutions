// Submission Timestamp: 2023-03-09 09:35:16

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
	int LOG = log2(n)+2;
	vector<int> p(n);
	vector<int> c(n);
	vector<int> pn(n);
	vector<int> cnt(max(30ll,n));
	vector<int> newc(n);
	vector<pair<char,int>> _cn(n);
	for (int i = 0; i < n; i++){
		_cn[i]={str[i],i};
	}
	sortarr(_cn);
	for (int i = 0; i < n; i++){
		p[i]=_cn[i].second;
	}
	int cls = 0;
	c[p[0]]=0;
	for (int i = 1; i < n; i++){
		if (str[p[i]]==str[p[i-1]]) c[p[i]]=c[p[i-1]];
		else c[p[i]]=++cls;
	}
	for (int k = 1; k < LOG; k++){
		fill(cnt.begin(), cnt.end(), 0ll);
		for (int i = 0; i < n; i++){
			pn[i]=(((p[i]-tol(k-1))%n)+n)%n;
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i < cnt.size(); i++){
			cnt[i]+=cnt[i-1];
		}
		for (int i = n-1; i >= 0; i--){
			p[--cnt[c[pn[i]]]]=pn[i];
		}
		pair<int,int> old;
		cls = 0;
		newc[p[0]]=0;
		old={c[p[0]],c[(p[0]+tol(k-1))%n]};
		for (int i = 1; i < n; i++){
			pair<int,int> crv = {c[p[i]],c[(p[i]+tol(k-1))%n]};
			if (crv==old){
				newc[p[i]]=newc[p[i-1]];
			}
			else newc[p[i]]=++cls;
			swap(crv,old);
		}
		swap(newc,c);
	}
	rev(p);
	p.pop_back();
	rev(p);
	return p;
}
vector<int> LCP(string &str, vector<int> &p){
	int n = str.length();
	vector<int> rank(n);
	for (int i = 0; i < n; i++){
		rank[p[i]]=i;
	}
	int k = 0;
	vector<int> lcp(n,0);
	for (int i = 0; i < n; i++){
		if (rank[i]==0){
			k=0;
			continue;
		}
		int j = p[rank[i]-1];
		while (i+k<n && j+k<n && str[i+k]==str[j+k]){
			k++;
		}
		lcp[rank[i]]=k;
		if (k) k--;
	}
	return lcp;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		decstr(str);
		int n = str.length();
		vector<int> suff = Suffix_Array(str);
		vector<int> lcparr = LCP(str, suff);
		int ans = n*(n+1)/2;
		for (int i = 0; i < lcparr.size(); i++){
			ans-=lcparr[i];
		}
		cout<<ans<<endl;
	}
}