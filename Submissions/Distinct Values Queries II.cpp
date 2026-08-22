// Submission Timestamp: 2025-06-28 23:41:21

#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 4e5;
set<int> st[maxn<<2];
int seg[maxn<<2];
void update(int x, int v){
	for (seg[x+=maxn]=v;x;x>>=1)seg[x>>1]=min(seg[x],seg[x^1]);
}
int query(int l, int r){
	int ret = maxn;
	for (l+=maxn,r+=maxn;l<r;l>>=1,r>>=1){
		if (l&1) ret=min(ret,seg[l++]);
		if (r&1) ret=min(ret,seg[--r]);
	}
	return ret;
}
int32_t main(){
	fill(seg,seg+(maxn<<2),maxn);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;cin>>n>>q;
	vector<int> arr(n);
	vector<array<int,3>> qu(q);
	vector<int> cmp;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		cmp.push_back(arr[i]);
	}
	for (int i = 0; i < q; ++i)
	{
		cin>>qu[i][0]>>qu[i][1]>>qu[i][2];
		if (qu[i][0] == 1) cmp.push_back(qu[i][2]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()),cmp.end());
	for (int i = 0; i < n; ++i)
	{
		arr[i] = lower_bound(cmp.begin(), cmp.end(), arr[i])-cmp.begin();
		if (st[arr[i]].size()) {
			int j = *st[arr[i]].rbegin();
			update(j,i);
		}
		st[arr[i]].insert(i);
	}
	for (int i = 0; i < q; i++){
		if (qu[i][0] == 1){
			qu[i][2] = lower_bound(cmp.begin(), cmp.end(), qu[i][2])-cmp.begin();

			st[arr[qu[i][1]-1]].erase(qu[i][1]-1);
			auto it = st[arr[qu[i][1]-1]].lower_bound(qu[i][1]);
			int nx = maxn;
			if (it != st[arr[qu[i][1]-1]].end()) nx = *it;
			if (it != st[arr[qu[i][1]-1]].begin()){
				int j = *prev(it);
				update(j, nx);
			}

			it = st[qu[i][2]].lower_bound(qu[i][1]);
			nx = maxn;
			if (it != st[qu[i][2]].end()) nx = *it;
			update(qu[i][1]-1, nx);
			if (it != st[qu[i][2]].begin()){
				int j = *prev(it);
				update(j, qu[i][1]-1);
			}
			st[qu[i][2]].insert(qu[i][1]-1);
			arr[qu[i][1]-1]=qu[i][2];
		}
		else {
			cout<<"YES\0NO"+4*(query(qu[i][1]-1,qu[i][2]) <= qu[i][2]-1)<<'\n';
		}
	}
}