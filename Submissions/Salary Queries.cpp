// Submission Timestamp: 2025-06-28 14:07:10

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4e5;
int seg[maxn<<1];
void update(int x, int v){
	for (seg[x+=maxn]+=v;x;x>>=1)seg[x>>1]=seg[x]+seg[x^1];
}
int query(int l, int r){
	int ret = 0;
	for (l+=maxn,r+=maxn;l<r;l>>=1,r>>=1){
		if (l&1) ret += seg[l++];
		if (r&1) ret += seg[--r];
	}
	return ret;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;cin>>n>>q;
	vector<int> p(n);
	vector<int> cmp(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
		cmp[i] = p[i];
	}
	vector<array<int,3>> qu(q);
	for (int i = 0; i < q; ++i)
	{
		char ch;cin>>ch;
		cin>>qu[i][1]>>qu[i][2];
		if (ch == '?') qu[i][0] = 0;
		else qu[i][0] = 1, qu[i][1]--,cmp.push_back(qu[i][2]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
	for (int i = 0; i < n; i++){
		p[i] = lower_bound(cmp.begin(), cmp.end(), p[i])-cmp.begin();
		update(p[i], 1);
	}
	for (int i = 0; i < q; i++){
		if (qu[i][0] == 0){
			int l = lower_bound(cmp.begin(), cmp.end(), qu[i][1])-cmp.begin();
			int r = lower_bound(cmp.begin(), cmp.end(), qu[i][2]+1)-cmp.begin()-1;
			cout<<query(l,r+1)<<'\n';
		}
		else {
			int x = qu[i][1];
			int v = lower_bound(cmp.begin(), cmp.end(), qu[i][2])-cmp.begin();
			update(p[x],-1);
			update(v,1);
			p[x] = v;
		}
	}
}