// Submission Timestamp: 2023-05-01 21:52:08

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
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> &pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X, typename Y> pair<X,Y> operator+(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first+b.first,c.second=a.second+b.second;return c;}
template<typename X, typename Y> pair<X,Y> operator-(pair<X,Y> &a, pair<X,Y> &b) {pair<X,Y> c; c.first=a.first-b.first,c.second=a.second-b.second;return c;}
template<typename X, typename Y> void operator+=(pair<X,Y> &a, pair<X,Y> &b){a.first+=b.first,a.second+=b.second;}
template<typename X, typename Y> void operator-=(pair<X,Y> &a, pair<X,Y> &b){a.first-=b.first,a.second-=b.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> &arr) {for(auto &it : arr) os<<it<<" "; return os;}
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
		n<<=1;
		decstr(str);
		vector<string> ansarr;
		if (n>6){
			for (int i = 0; i < n/2-1; i++){
				if (str[i]=='A') continue;
				if (str[i]=='B'){
					if (str[i+1]=='.'){
						swap(str[i+1],str[i+3]);
						swap(str[i+2],str[i+4]);
						ansarr.push_back(str);
					}
					for (int j = 0; j < n; j++){
						if (str[j]=='.'){
							swap(str[i],str[j]);
							swap(str[i+1],str[j+1]);
							ansarr.push_back(str);
							break;
						}
					}
				}
				bool boolean = false;
				for (int j = i; j < n-1; j++){
					if (str[j]=='A'){
						boolean=true;
						swap(str[i],str[j]);
						swap(str[i+1],str[j+1]);
						ansarr.push_back(str);
						break;
					}
				}
				if (!boolean){
					swap(str[i],str[n-2]);
					swap(str[i+1],str[n-1]);
					ansarr.push_back(str);
					swap(str[i+1],str[n-2]);
					swap(str[i+2],str[n-1]);
					ansarr.push_back(str);
					swap(str[i+1],str[n-3]);
					swap(str[i+2],str[n-2]);
					ansarr.push_back(str);
					swap(str[n-3],str[i]);
					swap(str[n-2],str[i+1]);
					ansarr.push_back(str);
					swap(str[i],str[i+2]);
					swap(str[i+1],str[i+3]);
					ansarr.push_back(str);
				}
			}
		}
		else if (n==6){
			if (str[0]!='.'){
				if (str[1]=='.'){
					swap(str[1],str[3]);
					swap(str[2],str[4]);
					ansarr.push_back(str);
				}
				for (int j = 0; j < 6; j++){
					if (str[j]=='.'){
						swap(str[0],str[j]);
						swap(str[1],str[j+1]);
						ansarr.push_back(str);
						break;
					}
				}
			}
			for (int j = 0; j < 6; j++){
				if (str[j]=='A'){
					swap(str[0],str[j]);
					swap(str[1],str[j+1]);
					ansarr.push_back(str);
					break;
				}
			}
			if (str[2]=='.'){
				swap(str[2],str[4]);
				swap(str[3],str[5]);
				ansarr.push_back(str);
			}
			for (int i = 0; i < 6; i++){
				if (str[i]=='.'){
					swap(str[1],str[i]);
					swap(str[2],str[i+1]);
					ansarr.push_back(str);
					break;
				}
			}
			if (str=="A..BAB"){
				ansarr.push_back("AABB..");
			}
			else if (str=="A..BBA"){
				cout<<-1<<endl;
				continue;
			}
		}
		else if (n==4){
			int posa = -1;
			int posb = -1;
			for (int i = 0; i < 4; i++){
				if (str[i]=='B') posb=i;
				else if (str[i]=='A') posa=i;
			}
			if (posa>posb){
				cout<<-1<<endl;
				continue;
			}
		}
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); i++){
			cout<<ansarr[i]<<endl;
		}
	}
}