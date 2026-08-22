// Submission Timestamp: 2024-02-24 00:01:15

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
namespace Geometry{
	struct Point{
		int x, y;
		Point(int a, int b):x(a),y(b){}
		Point():x(0),y(0){}
		Point operator-(Point &a){
			return Point(x-a.x,y-a.y);
		}
		Point operator+(Point &a){
			return Point(x+a.x,y+a.y);
		}
		int operator*(Point &a){
			return x*a.y-y*a.x;
		}
		bool operator < (const Point &a) const{
			if (x==a.x) return y<a.y;
			return x<a.x;
		}
		void operator=(const Point& a){
			x=a.x;
			y=a.y;
		}
		void operator+=(const Point& a){
			x+=a.x;
			y+=a.y;
		}
		void operator-=(const Point& a){
			x-=a.x;
			y-=a.y;
		}
		friend ostream& operator<<(ostream& os, const Point &pt){
			return os<<pt.x<<" "<<pt.y;
		}
	};
	int cross(Point a, Point b){
		return a.x*b.y-a.y*b.x;
	}
	int dist(Point a, Point b){
		return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	}
	struct Polygon{
		vector<Point> vertices;
		Polygon(){}
		Polygon(vector<Point> pts):vertices(pts){};
		void push_back(Point pt){
			vertices.push_back(pt);
		}
		void pop_back(){
			assert(vertices.size()>0);
			vertices.pop_back();
		}
		void clear(){
			vertices.clear();
		}
		int size(){
			return vertices.size();
		}
		Point& operator[](int indice){
			return vertices[indice];
		}
		bool inside(int x, int y){
			Point pt(x,y);
			int l = 1, r = vertices.size()-1;
			while (r-l+1>2){
				int mid = l+(r-l)/2;
				if (cross(vertices[mid]-vertices[0],pt-vertices[0])>=0){
					r=mid;
				}
				else {
					l=mid;
				}
			}
			int cr1 = cross(vertices[0]-vertices[l],pt-vertices[l]);
			int cr2 = cross(vertices[l]-vertices[r],pt-vertices[r]);
			int cr3 = cross(vertices[r]-vertices[0],pt-vertices[0]);
			if (cr1==0 && cr2==0 & cr3==0){
				if (pt.x>vertices[0].x && pt.x>vertices[l].x && pt.x>vertices[r].x) return false;
				if (pt.x<vertices[0].x && pt.x<vertices[l].x && pt.x<vertices[r].x) return false;
				if (pt.y>vertices[0].y && pt.y>vertices[l].y && pt.y>vertices[r].y) return false;
				if (pt.y<vertices[0].y && pt.y<vertices[l].y && pt.y<vertices[r].y) return false;
				return true;
			}
			if (cr1<=0 && cr2<=0 && cr3<=0) return true;
			if (cr1>=0 && cr2>=0 && cr3>=0) return true;
			return false;
		}
		bool inside(Point pt){
			return inside(pt.x,pt.y);
		}
		int area(){
			int ret = 0;
			for (int i = 0; i < vertices.size(); i++){
				ret+=cross(vertices[i],vertices[(i+1)%vertices.size()]);
			}
			if (ret<0) ret=-ret;
			return ret;
		}
	};
	Polygon ConvexHull(vector<Point> &pr){
		Polygon arr;
		int n = pr.size();
		vector<Point> barr(pr.size());
		for (int i = 0; i < pr.size(); ++i)
		{
			barr[i]=Point(pr[i].x,pr[i].y);
		}
		for (int i = n-1; i >= 0; i--){
			if (barr[i].x<barr.back().x){
				swap(barr[i],barr.back());
			}
		}
		arr.push_back(barr.back());
		barr.pop_back();
		sort(barr.begin(), barr.end(), [&](Point a, Point b){
			int cros = cross(a-arr[0],b-arr[0]);
			if (cros==0) return dist(a,arr[0])<dist(b,arr[0]);
			return cros<0;
		});
		int l = barr.size()-1;
		while (l>0){
			if (cross(barr[l-1]-arr[0],barr.back()-arr[0])==0){
				l--;
			}
			else break;
		}
		reverse(barr.begin()+l,barr.end());
		arr.push_back(barr[0]);
		for (int i = 1; i < barr.size(); i++){
			while (arr.size()>=2 && cross(arr[arr.size()-1]-arr[arr.size()-2],barr[i]-arr[arr.size()-1])>0){
				arr.pop_back();
			}
			arr.push_back(barr[i]);
		}
		while (arr.size()>=2 && cross(arr[arr.size()-1]-arr[arr.size()-2],arr[0]-arr[arr.size()-1])>0){
			arr.pop_back();
		}
		return arr;
	}
	Polygon ConvexHull(vector<pair<int,int>> &pr){
		vector<Point> pr2(pr.size());
		for (int i = 0; i < pr.size(); ++i)
		{
			pr2[i].x=pr[i].first;
			pr2[i].y=pr[i].second;
		}
		return ConvexHull(pr2);
	}
};
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		int n;cin>>n;
		Geometry::Polygon a;
		for (int i = 0; i < n; ++i)
		{
			deci(x);deci(y);
			a.push_back({x,y});
		}
		cout<<a.area()<<endl;
	}
}