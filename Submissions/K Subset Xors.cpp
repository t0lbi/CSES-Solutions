// Submission Timestamp: 2025-06-25 15:16:27

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int LOG = 30;
int basis[LOG];
vector<int> say;
int cnt;
void f(int x, int bit){
	if (!cnt) return;
	if (bit == -1){
		cnt--;
		say.push_back(x);
		return;
	}
	f(min(x,x^basis[bit]), bit-1);
	if (basis[bit]) f(max(x, x^basis[bit]), bit-1);
}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin>>n>>k;
	int r = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		for (int i = LOG-1; i >= 0; i--){
			if ((x>>i) & 1){
				if (basis[i]) x ^= basis[i];
				else {
					basis[i] = x;
					goto mahmut;
				}
			}
		}
		r++;
		mahmut:;
	}
	if (r > 30) r = 30;
	int blok = (1ll<<r);
	cnt = (k+blok-1)/blok;
	f(0, LOG-1);
	for (int i = 0; i < k; i++){
		cout<<say[i/blok]<<" ";
	}
	cout<<'\n';
}