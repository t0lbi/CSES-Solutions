// Submission Timestamp: 2025-06-25 15:37:13

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while (t--){
		int n, a, b;cin>>n>>a>>b;
		if (a + b == 0){
			cout<<"YES"<<'\n';
			for (int i = 0; i < n; ++i)
			{
				cout<<i+1<<" ";
			}
			cout<<'\n';
			for (int i = 0; i < n; ++i)
			{
				cout<<i+1<<" ";
			}
			cout<<'\n';
		}
		else if (a + b > n) cout<<"NO"<<'\n';
		else {
			int rev = min(a, b) - 1;
			int draw = n - (a + b);
			if (rev < 0){
				cout<<"NO"<<'\n';
			}
			else {
				cout<<"YES"<<'\n';
				for (int i = n; i >= 1; --i)
				{
					cout<<i<<" ";
				}
				cout<<'\n';
				int k = n;
				for (int i = 0; i < draw; i++){
					cout<<k<<" ";
					k--;
				}
				for (int i = 0; i < rev; i++){
					cout<<k-1<<" "<<k<<" ";
					k-=2;
				}
				if (a > b){
					for (int i = k-1; i >= 1; i--){
						cout<<i<<" ";
					}
					cout<<k<<" ";
				}
				else {
					cout<<1<<" ";
					for (int i = k; i >= 2; i--){
						cout<<i<<" ";
					}
				}
				cout<<'\n';
			}
		}
	}
}