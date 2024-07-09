//Find shortest path from node 1 to every other node in the graph(undirected)
//Input: n(the number of edges) followed by n lines of three integers x,y,z where there exists an edge between nodes x and y of weight z
//Output: paths from node 1 to every node in the graph
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m=0;
    cin >> n;
    vector<pair<int,int>> v[1000];
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        m = max(max(x,y),m);
    }

    priority_queue<pair<int,int>> q;
    vector<int> dist(m+1,1000000);
    vector<bool> vis(m+1,0);
    vector<int> path[m+1];
    dist[1]=0;
    q.push({0,1});
    path[1] = {1};

    while(!q.empty()){
        int curr = q.top().second;
        q.pop();
        if(vis[curr])continue;
        vis[curr] = 1;
        for(auto u: v[curr]){
            int b = u.first, w = u.second;
            if(dist[curr] + w < dist[b]){
                dist[b] = dist[curr] + w;
                path[b] = path[curr];
                path[b].push_back(b);
                q.push({-dist[b], b});
            }
        }
    }

    for(auto u: path){
        for(auto p: u){
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}