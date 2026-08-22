// Submission Timestamp: 2024-01-31 20:32:22

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
namespace Geo{
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
};
namespace ConvexHull{
	vector<Geo::Point> arr;
	void prepare(vector<pair<int,int>> pr){
		arr.clear();
		int n = pr.size();
		vector<Geo::Point> barr(pr.size());
		for (int i = 0; i < pr.size(); ++i)
		{
			barr[i]=Geo::Point(pr[i].first,pr[i].second);
		}
		for (int i = n-1; i >= 0; i--){
			if (barr[i].x<barr.back().x){
				swap(barr[i],barr.back());
			}
		}
		arr.push_back(barr.back());
		barr.pop_back();
		sort(barr.begin(), barr.end(), [&](Geo::Point a, Geo::Point b){
			int cross = Geo::cross(a-arr[0],b-arr[0]);
			if (cross==0) return Geo::dist(a,arr[0])<Geo::dist(b,arr[0]);
			return cross<0;
		});
		int l = barr.size()-1;
		while (l>0){
			if (Geo::cross(barr[l-1]-arr[0],barr.back()-arr[0])==0){
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
	}
	bool query(int x, int y){
		Geo::Point pt(x,y);
		int l = 1, r = arr.size();
		while (r-l+1>2){
			int mid = l+(r-l)/2;
			if (Geo::cross(arr[mid]-arr[0],pt-arr[0])>=0){
				r=mid;
			}
			else {
				l=mid;
			}
		}
		int cr1 = Geo::cross(arr[0]-arr[l],pt-arr[l]);
		int cr2 = Geo::cross(arr[l]-arr[r],pt-arr[r]);
		int cr3 = Geo::cross(arr[r]-arr[0],pt-arr[0]);
		if (cr1<=0 && cr2<=0 && cr3<=0) return true;
		if (cr1>=0 && cr2>=0 && cr3>=0) return true;
		return false;
	}
};
int32_t main(){
	deci(n);
	vector<pair<int,int>> arr(n);
	cinarr(arr);
	ConvexHull::prepare(arr);
	cout<<ConvexHull::arr.size()<<endl;
	for (auto it : ConvexHull::arr){
		cout<<it<<endl;
	}
}
