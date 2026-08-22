// Submission Timestamp: 2022-12-01 16:13:03

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
//#include "geodeb.h"
#define int long long
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
struct Point{
	int x, y;
	friend inline istream& operator>>(istream& is, Point& p){
		return is>>p.x>>p.y;
	}
	friend inline ostream& operator<<(ostream& is, Point& p){
		return is<<"{ "<<p.x<<" , "<<p.y<<" }";
	}
	friend inline bool operator<(Point a, Point b){
		if (a.y==b.y) return a.x<b.x;
		return a.y<b.y;
	}
};
int dist(Point a, Point b){
	int xp = a.x-b.x;
	int yp = a.y-b.y;
	return xp*xp+yp*yp;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		//GD_INIT("out.html");
		deci(n);
		vector<Point> arr(n);
		cinarr(arr);
		set<Point> st;
		deque<Point> dq;
		sort(arr.begin(), arr.end(), [&](Point a, Point b){
			return a.x<b.x;
		});
		//coutarr(arr);
		for (int i = 0; i < n; ++i)
		{
			//GD_POINT(arr[i].x, arr[i].y);
		}
		dq.push_back(arr[0]);
		st.insert(arr[0]);
		//cout<<"LKHASDKJH"<<endl;
		int ans = dist(arr[0],arr[1]);
		//GD_PAUSE();
		//GD_POINT(arr[0].x,arr[0].y,"green");
		for (int i = 1; i < n; ++i)
		{
			//GD_PAUSE();
			//GD_RECTANGLE(arr[i].x-(int)ceil(sqrt(ans)+2),arr[i].y-(int)ceil(sqrt(ans)+2),arr[i].x,arr[i].y+(int)ceil(sqrt(ans)+2));
			//GD_PAUSE();
			while (dq.size() && dq.front().x<arr[i].x-ceil(sqrt(ans)+2)){
				//GD_PAUSE();
				//GD_POINT(dq.front().x,dq.front().y,"red");
				st.erase(dq.front());
				dq.pop_front();
			}
			for (auto it = st.lower_bound({0,arr[i].y-(int)ceil(sqrt(ans)+2)}); it != st.upper_bound({0,arr[i].y+(int)ceil(sqrt(ans))+2}); it++){
				Point p;
				p.x=it->x;
				p.y=it->y;
				//cout<<p<<" "<<i<<" "<<st.size()<<endl;
				ans=min(ans,dist(arr[i],*it));
			}
			dq.push_back(arr[i]);
			st.insert(arr[i]);
			//GD_PAUSE();
			//GD_POINT(arr[i].x,arr[i].y,"green");
		}
		cout<<ans<<endl;
		//GD_SHOW();
	}
}