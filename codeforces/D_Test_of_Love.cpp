#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,m,k; cin >> n >> m >> k;
  string s; cin >> s;s = "L"+s;
  vector<int> dp(n+2, INF);
  dp[n+1] = 0;
  for(int i=n;i>=0;i--){
    if(s[i]=='W'){
      if(i<n-1 && s[i+1]=='C')continue;
      dp[i] = 1 + dp[i+1];
    }
    else if(s[i]=='L'){
      for(int j=1;j<=m && j+i<=n+1;j++){
        dp[i] = min(dp[i], dp[i+j]);
      }
    }
  }
  //for(auto u: dp)cout << u << " ";

  if(dp[0]<=k)cout << "YES";
  else cout << "NO";
  cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}