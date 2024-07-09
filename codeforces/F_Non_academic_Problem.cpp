#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;

int timer;

void dfs(int node, int par, vector<vector<int>> &v,vector<int> &time, vector<int> &low, vector<array<int,2>> &bridges, vector<int> &sz){
  time[node] = timer;
  low[node] = timer;
  sz[node]=1;
  timer++;//cout << node << "node ";

  for(auto nbr: v[node]){
    if(nbr==par)continue;

    if(time[nbr]==-1){
      dfs(nbr, node, v, time, low, bridges, sz);
      low[node] = min(low[node], low[nbr]);
      sz[node]+=sz[nbr];
      if(low[nbr]>time[node]){
        //cout << "inf" << node << " " << nbr << " " << low[node] << " " << low[nbr] << " ";
        bridges.pb({node, nbr});
      }
      
      continue;
    }
    low[node] = min(low[node], low[nbr]);
  }
}

 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(0));
    for(int i=0;i<m;i++){
      int u,vv; cin >> u >> vv;
      v[u].pb(vv);
      v[vv].pb(u);
    }
    vector<int> time(n+1, -1), low(n+1,INF), sz(n+1, 0);
    vector<array<int,2>> bridges;bridges.clear();
    timer=1;

    dfs(1, -1, v, time, low, bridges, sz);
    int ans,mxans;ans=mxans=(n*(n-1))/2;
    for(auto [x,y]: bridges){
      //cout << x << " "  << sz[x] << y << sz[y] << "h ";
      int cnt = min(sz[x], sz[y]);
      ans = min(ans, mxans-(cnt*(n-cnt)));
    }

    cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}