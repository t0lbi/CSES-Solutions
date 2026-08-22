// Submission Timestamp: 2022-10-27 13:53:07

#pragma optimize("Bismillahirrahmanirrahim")
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define ayahya() chrono::steady_clock().now().time_since_epoch().count()
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
vector<vector<int>> capa;
vector<int> par;
vector<vector<int>> arr;
int bfs(int s, int t){
	fill(par.begin(),par.end(),-1);
	par[0]=/*ahmet*/23;
	priority_queue<pair<int,int>> pq;
	pq.push({INF,s});
	while (pq.size()){
		int node = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (node==t){
			return w;
		}
		for (int next : arr[node]){
			if (par[next]!=-1) continue;
			if (!capa[node][next]) continue;
			pq.push({min(capa[node][next],w),next});
			par[next]=node;
		}
	}
	return 0;
}
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(n);deci(m);
		par.resize(n,-1);
		capa.resize(n,vector<int>(n,0));
		vector<vector<bool>> valid(n,vector<bool>(n,false));
		arr.resize(n);
		for (int i = 0; i < m; i++){
			deci(u);deci(v);
			capa[u-1][v-1]++;
			arr[u-1].push_back(v-1);
			arr[v-1].push_back(u-1);
			valid[u-1][v-1]=true;
		}
		vector<vector<int>> ansarr;
		while (true){
			int val = bfs(0,n-1);
			if (!val) break;
			ansarr.push_back(vector<int>());
			int node = n-1;
			while (node){
				ansarr.back().push_back(node+1);
				capa[node][par[node]]+=val;
				capa[par[node]][node]-=val;
				node=par[node];
			}
			ansarr.back().push_back(node+1);
			rev(ansarr.back());
		}
		vector<vector<vector<pair<int,int>>>> pos(n,vector<vector<pair<int,int>>>(n));
		for (int i = 0; i < ansarr.size(); ++i)
		{
			for (int j = 0; j < ansarr[i].size()-1; ++j){
				pos[ansarr[i][j]-1][ansarr[i][j+1]-1].push_back({i,j});
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j){
				if (valid[j][i]) continue;
				if (!pos[j][i].size()) continue;
				while (pos[j][i].size()){
					int ar;
					int swar;
					int ind;
					int swind;
					while (pos[j][i].size()){
						ar = pos[j][i].back().first;
						ind = pos[j][i].back().second;
						pos[j][i].pop_back();
						if (ind>=ansarr[ar].size()-1 || ansarr[ar][ind]!=j+1 || ansarr[ar][ind+1]!=i+1) continue;
						else break;
					}
					while (pos[i][j].size()){
						swar = pos[i][j].back().first;
						swind = pos[i][j].back().second;
						pos[i][j].pop_back();
						if (swind>=ansarr[swar].size()-1 || ansarr[swar][swind]!=i+1 || ansarr[swar][swind+1]!=j+1) continue;
						else break;
					}
					if (swind>=ansarr[swar].size()-1 || ansarr[swar][swind]!=i+1 || ansarr[swar][swind+1]!=j+1) continue;
					if (ind>=ansarr[ar].size()-1 || ansarr[ar][ind]!=j+1 || ansarr[ar][ind+1]!=i+1) continue;
					vector<int> nw;
					vector<int> nw2;
					for (int x = ind+1; x < ansarr[ar].size(); x++){
						nw.push_back(ansarr[ar][x]);
					}
					for (int x = swind+1; x < ansarr[swar].size(); x++){
						nw2.push_back(ansarr[swar][x]);
					}
					while (ansarr[swar].size()>swind)ansarr[swar].pop_back();
					while (ansarr[ar].size()>ind)ansarr[ar].pop_back();
					for (int x = 0; x < nw.size(); ++x)
					{
						ansarr[swar].push_back(nw[x]);
						if (ansarr[swar].size()>1) pos[ansarr[swar][ansarr[swar].size()-2]-1][ansarr[swar][ansarr[swar].size()-1]-1].push_back({swar,ansarr[swar].size()-2});
					}					
					for (int x = 0; x < nw2.size(); ++x)
					{
						ansarr[ar].push_back(nw2[x]);
						if (ansarr[ar].size()>1) pos[ansarr[ar][ansarr[ar].size()-2]-1][ansarr[ar][ansarr[ar].size()-1]-1].push_back({ar,ansarr[ar].size()-2});
					}
				}
			}
		}
		for (int i = 0; i < ansarr.size(); ++i)
		{
			for (int j = 0; j < ansarr[i].size(); ++j){
				if (ansarr[i][j]==n){
					while (ansarr[i].size()>j+1) ansarr[i].pop_back();
					break;
				}
			}		
		}
		cout<<ansarr.size()<<endl;
		for (int i = 0; i < ansarr.size(); ++i)
		{
			cout<<ansarr[i].size()<<endl;
			coutarr(ansarr[i]);
		}
	}
}