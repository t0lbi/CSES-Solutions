// Submission Timestamp: 2024-10-15 21:51:47

#include <bits/stdc++.h>
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
template<typename T> void shuffle(vector<T> &a){
	for (int i = a.size()-1; i > 0; i--){
		swap(a[i],a[ayahya()%(i+1)]);
	}
}
int main(){
	string s;cin>>s;
	int n = s.length();
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	shuffle(a);
	vector<int> z(2*n);
	s+=s+s;
	function<void(int)> z_table = [&](int l){
		z[0]=0;
		int j = 0;
		for (int i = 1; i < 2*n; i++){
			z[i]=0;
			if (j+z[j]-1>=i){
				z[i]=min(z[i-j],j+z[j]-i);
			}
			while (i+z[i]<2*n && s[z[i]+l]==s[i+z[i]+l]) z[i]++;
			if (i+z[i]>j+z[j]) j=i;
		}
	};
	z_table(a[0]);
	int best = a[0];
	for (int i = 1; i < n; i++){
		int c = a[i];
		int pos = c-best;
		if (pos<0) pos+=n;
		if (s[best+pos+z[pos]]<s[best+z[pos]]){
			best=c;
			z_table(best);
		}
	}
	cout<<s.substr(best,n)<<endl;
}