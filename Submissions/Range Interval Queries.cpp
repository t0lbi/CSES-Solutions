// Submission Timestamp: 2025-06-28 22:23:09

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5;
int seg[maxn * 2];
void update(int x, int p){
	for (seg[x+=maxn]+=p;x;x>>=1) seg[x>>1]=seg[x]+seg[x^1];
}
int query(int l, int r){
	int ret = 0;
	for (l+=maxn,r+=maxn+1;l<r;l>>=1,r>>=1){
		if (l&1) ret += seg[l++];
		if (r&1) ret += seg[--r];
	}
	return ret;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q;cin>>n>>q;
	vector<int> arr(n);
	vector<int> cmp(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		cmp[i] = arr[i];
	}
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
	vector<int> ans(q);
	vector<array<int,5>> qu(q * 2);
	for (int i = 0; i < q; i++){
		int l1, r1, l2, r2;cin>>l1>>r1>>l2>>r2;
		l1--,r1--;
		l2 = lower_bound(cmp.begin(),cmp.end(),l2)-cmp.begin();
		r2 = lower_bound(cmp.begin(),cmp.end(),r2+1)-cmp.begin()-1;
		qu[i * 2] = {l1-1, l2, r2, i, -1};
		qu[i * 2 + 1] = {r1, l2, r2, i, 1};
	}


	int ind = 0;
	sort(qu.begin(), qu.end());
	for (auto [x, l, r, i, c] : qu){
		while (ind <= x){
			arr[ind] = lower_bound(cmp.begin(), cmp.end(), arr[ind])-cmp.begin();
			update(arr[ind], 1);
			ind++;
		}
		ans[i] += c * query(l, r);
	}
	for (auto it : ans) cout<<it<<'\n';
}