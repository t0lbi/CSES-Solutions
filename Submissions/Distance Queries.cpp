// Submission Timestamp: 2025-02-17 15:01:46

#include <bits/stdc++.h>
using namespace std;
struct LCA{
	vector<int> tin;
	vector<int> tout;
	vector<vector<int>> eul;
	vector<int> dept;
	vector<int> inv;
	int n;
	LCA(vector<vector<int>> arr){
		n = arr.size();
		tin.resize(n);
		tout.resize(n);
		dept.resize(n);
		eul.resize(n*2,vector<int>(__lg(n) + 2, -1));
		inv.resize(n*2);
		int ind = 0;
		function<void(int,int)> f = [&](int node, int lnode)->void{
			eul[ind][0]=ind;
			inv[ind]=node;
			tin[node]=ind++;
			for (auto it : arr[node]){
				if (it == lnode) continue;
				dept[it]=dept[node]+1;
				f(it, node);
				eul[ind][0]=tin[node];
				ind++;
			}
			tout[node]=ind-1;
		};
		dept[0]=0;
		f(0, -1);
		for (int i = 1; i < eul[0].size(); i++){
			for (int node = 0; node < eul.size(); node++){
				if (eul[node][i-1] == -1) continue;
				eul[node][i] = min(eul[node][i-1], eul[node+(1<<(i-1))][i-1]);
			}
		}
	}
	int lca(int a, int b){
		if (tin[a] > tin[b]) swap(a, b);
		int sz = tin[b]-tin[a]+1;
		int lg = __lg(sz);
		return inv[min(eul[tin[a]][lg],eul[tin[b]-(1<<lg)+1][lg])];
	}
	int dist(int a, int b){
		return dept[a]+dept[b]-dept[lca(a,b)]*2;
	}
	bool isparent(int parent, int child){
		return tin[child]>=tin[parent] && tin[child]<=tout[parent];
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;cin>>n>>q;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n-1; ++i)
	{
		int u,v;cin>>u>>v;
		arr[u-1].push_back(v-1);
		arr[v-1].push_back(u-1);
	}
	LCA tree(arr);
	while (q--){
		int a, b;cin>>a>>b;a--,b--;
		cout<<tree.dist(a, b)<<endl;
	}
}