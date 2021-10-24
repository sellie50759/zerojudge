#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
#define MAX 10005
// 找src到dst的最短路徑，注意pair<int,int>的first是權重，second是點的編號
int dijkstra(int src,int dst,vector<vector<pair<int,int> > > &graph){  //first是權重，second是點的編號
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int n=graph.size();
    bool visited[n];
    int shortpath[n];
    for(int i=0;i<n;i++){
        shortpath[i]=2147483646;
        visited[i]=false;
    }
    shortpath[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u]=true;
        for(int i=0;i<graph[u].size();i++){
            int val=graph[u][i].first,v=graph[u][i].second;
            if(shortpath[u]+val<shortpath[v]){
                shortpath[v]=shortpath[u]+graph[u][i].first;
                if(v==dst)
                    return shortpath[v];
                pq.push(make_pair(shortpath[v],v));
            }
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,d,a,b,w;
    while(cin>>n>>m>>d){
        vector<vector<pair<int,int> > > graph(n);
        while(m--){
            cin>>a>>b>>w;
            graph[a].push_back({w,b});
            graph[b].push_back({w,a});
        }
        cout<<dijkstra(0,d,graph)<<"\n";
    }
}
/*
使用dijkstra演算法尋找最短路徑，詳細資料參考 https://zh.wikipedia.org/wiki/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95
注意這題的memory要動態分配，如果直接用10^5的array的話會segmentation fault
*/




