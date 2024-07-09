#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
#define str to_string
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;

using namespace std;

const int MAX_N = 10000;
const int LOG = 14;
int depth[MAX_N];
int up[MAX_N][LOG];
vector<int> children[MAX_N];

void dfs(int a){
  for(auto u: children[a]){
    depth[u] = depth[a]+1;
    up[u][0] = a;
    for(int j=1; j<LOG;j++)up[u][j] = up[up[u][j-1]][j-1];
    dfs(u);
  }
}

int findLCA(int a, int b){
  if(depth[a]>depth[b])swap(a,b);
  int k = depth[b]-depth[a];
  int j=0;
  while(k>0){
    if(k&1){
      b = up[b][j];
    }
    j+=1;
    k=k>>1;
  }
  if(a==b)return a;

  for(int j=LOG-1;j>=0;j--){
    if(up[a][j]!=up[b][j]){
      a=up[a][j];
      b=up[b][j];
    }
  }

  return up[a][0];

}
 
void solve(){
  int n; cin >> n;
  
  for(int i=0;i<n;i++){
    int m; cin >> m;
    for(int j=0;j<m;j++){
      int temp; cin >> temp;
      children[i].pb(temp);
    }
  }
  depth[0] = 0;
  dfs(0);

  int q; cin >> q;
  while(q--){
    int a,b; cin >> a >> b;
    cout << findLCA(a,b)  << "\n";
  }

}
 
int32_t main(){
  int t=1;//cin>>t;
  while(t--)solve();
  return 0;
}