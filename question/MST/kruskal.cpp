#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
#include <queue>
using namespace std;

struct DSU
{
    int n;
    vector<int>leader,size;

    DSU(int n){
        n = this->n;
       leader.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
           leader[i] = i;
            size[i] = 1;
        }
    }

    int getLeader(int u){
        // if u is the leader own ourself return u
        // else return u = getLeader(leader(u));
        if(leader[u] == u) return u;
        return leader[u] = getLeader(leader[u]); // update the leader of u 
    }

    void  connect(int x, int y){
        int leader_x = getLeader(x);
        int leader_y = getLeader(y);

        if(leader_x == leader_y) return ;

        if(size[leader_x] > size[leader_y]) swap(leader_x, leader_y);

        leader[leader_y] = leader_x;
        size[leader_x] += leader[leader_y];
    }
};


void kruskal(vector<vector<int>>&edges, int n){ // O(nlogn + (n + logn));
    sort(edges.begin(),edges.end()); // O(nlogn);
    DSU dsu(n); // O(n);
    vector<vector<int>>mst;
    for(auto edge : edges){
        int u = edge[0] , v = edge[1] , wt = edge[2];
        if(dsu.getLeader(u) != dsu.getLeader(v)){ //O(log n);
            dsu.connect(u,v);
            mst.push_back(edge);
            cout<<u<<" "<<v<<" "<<wt<<endl;
        }
    }
}


vector<vector<int>> prims(vector<vector<pair<int,int>>>&adj, int n){
    const int INF = 1e9;
    vector<int>dist(n,INF);
    int total_cost = 0;
    vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[0] = 0;
    pq.push({0,0});
    vector<vector<int>>mst;
    vector<int>parent(n,-1);
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        total_cost += dist[node];
        mst.push_back({parent[node],node,dist[node]});
        for(auto over : adj[node]){
            int child = over.first;
            int wt = over.second;
            if(!vis[child] && dist[child] > wt){
                dist[child]  = wt;
                parent[child] = node;
                pq.push({dist[child],child});
            }
        }
    }
    return mst;
}

int main(){
    int n , m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i = 0; i < m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].emplace_back(v,wt);
        adj[v].emplace_back(u,wt);
    }
    vector<vector<int>>mst = prims(adj,n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < adj[i].size(); j++){
            cout<<mst[i][j]<<" "<<endl;
        } 
    }
}
