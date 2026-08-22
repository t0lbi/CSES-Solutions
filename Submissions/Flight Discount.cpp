// Submission Timestamp: 2022-10-13 14:25:29

#include <bits/stdc++.h>
#define l LONG_LONG_MAX
#define o long long
using namespace std;main(){o n,m;cin>>n>>m;vector<vector<pair<o,o>>>r(n);for(o i=0;i<m;++i){o u,v,c;cin>>u>>v>>c;r[u-1].push_back({v-1,c});}priority_queue<pair<o,pair<o,o>>>q;vector<vector<o>>p(n,vector<o>(2,l));q.push({0,{0,0}});while(q.size()){o y=q.top().second.second;o flag=q.top().first;o w=-q.top().second.first;q.pop();if(p[y][flag]<=w)continue;p[y][flag]=w;if (flag){for(o i=0;i<r[y].size();i++){if(p[r[y][i].first][flag]<=w+r[y][i].second)continue;q.push({flag,{-(w+r[y][i].second),r[y][i].first}});}}else{for(o i=0;i<r[y].size();i++){if(p[r[y][i].first][flag]<=w+r[y][i].second)continue;q.push({flag,{-(w+r[y][i].second),r[y][i].first}});}flag^=1;for(o i=0;i<r[y].size();i++){if(p[r[y][i].first][flag]<=w+r[y][i].second/2)continue;q.push({flag,{-(w+r[y][i].second/2),r[y][i].first}});}}}cout<<p[n-1][1];}