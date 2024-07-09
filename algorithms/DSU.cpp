// Leetcode link -> https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
#include <bits/stdc++.h>

using namespace std;

class UF{
public:
    vector<int> par, rank;
    int components;
    UF(int n){
        components=n;
        par.clear();
        for(int i=0;i<=n;i++)par.push_back(i);
        rank.resize(n+1, 1);
    }

    int find(int a){
        if(a==par[a])return a;
        return par[a] = find(par[a]);
    }

    int unite(int a, int b){
        a=find(a),b=find(b);
        if(a==b)return 0;

        if(rank[a]<rank[b])swap(a,b);
        par[b] = a;
        rank[a]+=rank[b];
        components--;
        return 1;
    }

    bool isConnected(){
        return components==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UF alice = UF(n), bob = UF(n);
        int cnt = 0;
        for(auto edge: edges){
            if(edge[0]!=3)continue;
            cnt+=(alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2]));
        }

        for(auto edge: edges){
            if(edge[0]==1){
                cnt+=alice.unite(edge[1], edge[2]);
            }
            else if(edge[0]==2){
                cnt+=bob.unite(edge[1], edge[2]);
            }
        }
        if(!alice.isConnected() || !bob.isConnected())return -1;

        return edges.size()-cnt;
    }
};