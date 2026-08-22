// Submission Timestamp: 2022-12-29 18:46:15

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
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
template<typename X, typename Y> struct Point{
X x;
Y y;
friend inline istream& operator>>(istream& ss, Point& a){
	return ss>>a.x>>a.y;
}
friend inline ostream& operator<<(ostream& ss, Point& a){
	return ss<<a.x<<" "<<a.y;
}
inline void operator+=(const Point& a){
	x+=a.x;
	y+=a.y;
}
inline void operator-=(const Point& a){
	x-=a.x;
	y-=a.y;
}
inline void operator*=(const int v){
	x*=v;
	y*=v;
}
inline void operator/=(const int v){
	x/=v;
	y/=v;
}
friend inline Point<X,Y> operator+(Point<X,Y> a, Point<X,Y> b){
	a.x+=b.x;
	a.y+=b.y;
	return a;
}
friend inline Point<X,Y> operator-(Point<X,Y> a, Point<X,Y> b){
	a.x-=b.x;
	a.y-=b.y;
	return a;
}
friend inline Point<X,Y> operator*(Point<X,Y> a, Point<X,Y> b){
	a.x*=b.x;
	a.y*=b.y;
	return a;
}
friend inline Point<X,Y> operator/(Point<X,Y> a, Point<X,Y> b){
	a.x/=b.x;
	a.y/=b.y;
	return a;
}
friend inline bool operator==(Point<X,Y> a, Point<X,Y> b){
	if (a.x!=b.x) return false;
	if (a.y!=b.y) return false;
	return true;
}
friend inline bool operator!=(Point<X,Y> a, Point<X,Y> b){
	if (a.x!=b.x) return true;
	if (a.y!=b.y) return true;
	return false;
}
X armori(Point<X,Y> a, Point<X,Y> b){
	X ang = x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y);
	if (ang<0) return 1; //RIGHT
	if (ang>0) return -1; //LEFT
	return 0; //TOUCH
}
X angori(Point<X,Y> a, Point<X,Y> b){
	X ang = (a.x-x)*(b.y-y)-(a.y-y)*(b.x-x);
	if (ang<0) return 1; //RIGHT
	if (ang>0) return -1; //LEFT
	return 0; //TOUCH
}
X dist(Point<X,Y> a){
	return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
}
float angle(Point<X,Y> a){
	return atan2(y-a.y, a.x-x)/M_PI*180;
}
};
template<typename X,typename Y> X PolygonArea(vector<Point<X,Y>> arr){
	X ans = 0ll;
	arr.push_back(arr[0]);
	for (int i = 0; i < arr.size()-1; i++){
		ans+=(arr[i].x*arr[i+1].y)-(arr[i+1].x*arr[i].y);
	}
	return abs(ans);
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);
		vector<Point<int,int>> arr(n);
		cinarr(arr);
		int S = PolygonArea(arr);
		int B = -n;
		for (int i = 0; i < n; i++){
			Point<int,int> p1 = arr[i];
			Point<int,int> p2 = arr[(i+1)%arr.size()];
			p1-=p2;
			p1.x=abs(p1.x);
			p1.y=abs(p1.y);
			B+=__gcd(p1.x,p1.y)+1;
		}
		int I = (S-B)/2+1;
		cout<<I<<" "<<B<<endl;
	}
}