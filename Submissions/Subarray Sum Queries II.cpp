// Submission Timestamp: 2025-06-28 22:33:28

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5;
struct P{
	int pref, suff, ans, sum;
	P(int x){
		pref = suff = ans = max(0ll, x);
		sum = x;
	}
	P():pref(0),suff(0),ans(0),sum(0){}
};
P seg[maxn<<1];
P comb(P left, P right){
	P ret;
	ret.pref = max(left.pref, left.sum + right.pref);
	ret.suff = max(right.suff, right.sum + left.suff);
	ret.sum = left.sum + right.sum;
	ret.ans = max({left.ans,right.ans,left.suff+right.pref});
	return ret;
}
void build(vector<int> &a){
	for (int i = 0; i < (int) a.size(); i++) seg[i+maxn]=P(a[i]);
	for (int i = maxn-1; i > 0; i--) seg[i]=comb(seg[i<<1],seg[i<<1|1]);
}
int query(int l, int r){
	P le, ri;
	for (l+=maxn,r+=maxn;l<r;l>>=1,r>>=1){
		if (l&1) le = comb(le,seg[l++]);
		if (r&1) ri = comb(seg[--r],ri);
	}
	return comb(le,ri).ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;cin>>n>>q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	build(a);
	while (q--){
		int l, r;cin>>l>>r;
		cout<<query(l-1,r)<<'\n';
	}
}