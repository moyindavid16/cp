#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
const int MAX_N = 300000;
int a[MAX_N];
 
using namespace std;

void build(int curr, vector<array<int, 2>>& dp, vector<bool>& vis, vector<vector<int>>& v){
  vis[curr]=1;
  dp[curr][0] = 0, dp[curr][1] = a[curr];
  for(auto u: v[curr]){
    if(vis[u])continue;
    build(u, dp, vis, v);
    dp[curr][0] += max(dp[u][0], dp[u][1]);
    dp[curr][1] += dp[u][0];
  }
}

bool update(int curr, int pick, vector<array<int, 2>>& dp, vector<bool>& vis, vector<vector<int>>& v){
  vis[curr]=1;
  bool child_pick=0;

  if(pick==1){
    for(auto u: v[curr]){
      if(!vis[u])update(u, 0, dp, vis, v);
    }
  }
  else{
    for(auto u: v[curr]){
      if(vis[u])continue;
      //pick child
      if(dp[u][1]>dp[u][0]){update(u,1,dp,vis,v); child_pick=1;}
      else if(dp[u][1]<dp[u][0])update(u,0,dp, vis, v);
      else child_pick = (child_pick | update(u,2,dp, vis, v));
    }
  }
  if(!child_pick)a[curr]=0;
  return (!child_pick);
}
 
void solve(){
  int n; cin >> n;
  vector<vector<int>> v(n+1, vector<int>());
  for(int i=0;i<n;i++)cin >> a[i+1];

  for(int i=0;i<n-1;i++){
    int x,y; cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }

  int ans=0, curr_sum=0;
  for(int i=1;i<=n;i++)ans+=a[i];
  curr_sum=ans;
  vector<array<int, 2>> dp(n+1);
  vector<bool> vis(n+1);
  while(curr_sum>0){
    vis.assign(n+1, 0);
    build(1,dp,vis,v);
    vis.assign(n+1,0);
    if(dp[1][1]>dp[1][0])update(1,1,dp,vis,v);
    else update(1,0,dp,vis,v);
    curr_sum=0;
    for(int i=1;i<=n;i++)curr_sum+=a[i];
    ans+=curr_sum;
  }
  
  cout << ans << endl;
}
 
int32_t main(){
  int t=1;cin>>t;
  while(t--)solve();
  return 0;
}