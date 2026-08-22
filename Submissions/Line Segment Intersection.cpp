// Submission Timestamp: 2022-10-23 20:48:09

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
struct Point{
	int x,y;
	friend inline istream& operator>>(istream &ss, Point &a){
		return ss>>a.x>>a.y;
	}
	friend inline bool operator==(Point a, Point b){
		return (a.x==b.x && a.y==b.y);
	}
	friend inline ostream& operator<<(ostream &ss, Point &a){
		return ss<<"X = "<<a.x<<"Y = "<<a.y;
	}
	friend inline bool operator<(Point a, Point b){
		if (a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	}
};
float angle(Point a, Point b){
	return atan2((float)b.y-a.y,b.x-(float)a.x)/M_PI*180;
}
bool eq(float a, float b){
	if (a<b) swap(a,b);
	return (a-b<=1e-7);
}
int typo(float a, float b){
	int rval;
	if (eq(a,b)){
		rval=1ll;
	}
	else if (a>=0){
		if (b<=a && b>=0) rval=2ll;
		else if (a-180<=b && b<=0) rval=2ll;
		else rval=0ll;
	}
	else {
		if (b>=a && b<=0) rval=0ll;
		else if (b<=a+180 && b>=0) rval=0ll;
		else rval=2ll;
	}
	return rval;
}
pair<bool,string> liner(vector<Point> barr){
	vector<Point> arr=barr;
	sortarr(arr);
	float ang = angle(arr[0],arr[1]);
	for (int i = 1; i < 4; ++i)
	{
		if (!eq(angle(arr[0],arr[i]),ang)){
			return {false,"NONE"};
		}
	}
	vector<pair<Point,int>> huh(4);
	for (int i = 0; i < 4; ++i)
	{
		huh[i].second=i;
		huh[i].first=barr[i];
	}
	sortarr(huh);
	if (huh[0].second/2==huh[1].second/2) return {true,"NO"};
	return {true,"YES"};
}
int32_t main(){
	ios;
	int t=0;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		vector<Point> arr(4);
		cinarr(arr);
		bool boo = false;
		swap(arr[1],arr[2]);
		for (int i = 0; i < 4; ++i)
		{
			if (arr[i]==arr[(i+1)%4]){
				boo=true;
				break;
			}
		}
		if (boo){
			cout<<"YES"<<endl;
			continue;
		}
		swap(arr[1],arr[2]);
		if (liner(arr).first){
			cout<<liner(arr).second<<endl;
			continue;
		}
		swap(arr[1],arr[2]);
		bool boolean = true;
		vector<int> hehe;
		for (int i = 0; i < 4; i++){
			hehe.push_back(typo(angle(arr[i],arr[(i+1)%4]),angle(arr[(i+1)%4],arr[(i+2)%4])));
		}
		sortarr(hehe);
		if (hehe[0]==0 && hehe[3]==2) boolean=false;
		if (boolean){
			cout<<"YES"<<endl;
			continue;
		}
		swap(arr[1],arr[3]);
		hehe.clear();
		boolean = true;
		for (int i = 0; i < 4; i++){
			hehe.push_back(typo(angle(arr[i],arr[(i+1)%4]),angle(arr[(i+1)%4],arr[(i+2)%4])));
		}
		sortarr(hehe);
		if (hehe[0]==0 && hehe[3]==2) boolean=false;
		if (boolean){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
}