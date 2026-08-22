// Submission Timestamp: 2025-07-03 10:42:19

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	int n, m;cin>>n>>m;
	vector<vector<pair<int,int>>> arr(n);
	vector<int> cap(m * 2);
	vector<int> bas(m * 2);
	vector<int> from(n);
	vector<int> layer(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;cin>>u>>v>>w;
		cap[i*2]=w;
		arr[u-1].push_back({v-1,i*2});
		arr[v-1].push_back({u-1,i*2+1});
		bas[i*2] = u-1;
		bas[i*2+1] = v-1;
	}
	auto send = [&](void)->int{
		queue<array<int,3>> q;
		fill(from.begin(), from.end(), -1);
		fill(layer.begin(), layer.end(), -1);
		q.push({0,1<<30,-1});
		layer[0] = 0;
		while (q.size()){
			int node = q.front()[0];
			int flow = q.front()[1];
			int ed = q.front()[2];
			q.pop();
			if (from[node] != -1) continue;
			from[node] = ed;
			if (node == n-1) return flow;
			for (auto it : arr[node]){
				if (!cap[it.second]) continue;
				if (layer[it.first] == -1) layer[it.first]=layer[node]+1;
				if (layer[it.first] == layer[node]+1){
					q.push({it.first,min(flow,cap[it.second]),it.second});
				}
			}
		}
		return 0;
	};
	int ans = 0;
	int new_flow;
	while (new_flow = send()){
		if (new_flow == 0) break;
		ans += new_flow;
		int tt = n-1;
		while (tt){
			cap[from[tt]]-=new_flow;
			cap[from[tt]^1]+=new_flow;
			tt=bas[from[tt]];
		}
	}
	cout<<ans<<'\n';
}