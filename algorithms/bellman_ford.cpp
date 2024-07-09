//Find shortest path from node 1 to every other node in the graph(undirected)
//Input: n(the number of edges) followed by n lines of three integers x,y,z where there exists an edge between nodes x and y of weight z
//Output: paths from node 1 to every node in the graph
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m=0;
    cin >> n;
    vector<tuple<int,int,int>> v;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({x,y,z});
        v.push_back({y,x,z});
        m=max(max(x,y),m);
    }
    vector<int> dist(m+1,1000000);
    dist[1] = 0;
    vector<int> path[m+1];
    for(auto u: v){
            int a,b,c;
            tie(a,b,c) = u;
            if(a==1)path[b] = {1,b};
    }
        path[1] = {1};

    for(int i=1;i<n;i++){
        for(auto u: v){
            int a,b,c;
            tie(a,b,c) = u;
            if(dist[a] + c<dist[b]){
                path[b] = path[a];
                path[b].push_back(b);
                dist[b] = dist[a]+c;
            }
        }
    }

    for(auto u: path){
        for(auto b: u){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}

/*for(int i=1;i<n;i++){
        for(auto u: v){
            int a,b,c;
            tie(a,b,c) = u;
            dist[b] = min(dist[a]+c, dist[b]);
        }
    }
    for(auto u: dist){
        cout << u << " ";
    }*/
