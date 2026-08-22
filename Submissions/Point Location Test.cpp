// Submission Timestamp: 2024-07-03 02:06:27

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
	int x, y;
	friend istream& operator>>(istream& is, Point &pt){
		return is>>pt.x>>pt.y;
	}
	void operator-=(Point &pt){
		x-=pt.x,y-=pt.y;
	}
};
int main(){
	int t;cin>>t;
	while (t--){
		Point a,b,c;cin>>a>>b>>c;
		b-=a,c-=a;
		ll prod = (ll)b.x*c.y-(ll)c.x*b.y;
		if (prod>0) cout<<"LEFT"<<endl;
		else if (prod<0) cout<<"RIGHT"<<endl;
		else cout<<"TOUCH"<<endl;
	}
}