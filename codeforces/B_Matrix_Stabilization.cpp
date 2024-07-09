#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin >> v[i][j];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int mx = -1; bool red=1;
      if(i-1>=0 && v[i-1][j]>=v[i][j])continue;
      else if(i-1>=0)mx=max(v[i-1][j], mx);

      if(i+1<n && v[i+1][j]>=v[i][j])continue;
      else if(i+1<n)mx=max(v[i+1][j], mx);

      if(j-1>=0 && v[i][j-1]>=v[i][j])continue;
      else if(j-1>=0)mx=max(v[i][j-1], mx);

      if(j+1<m && v[i][j+1]>=v[i][j])continue;
      else if(j+1<m)mx=max(v[i][j+1], mx);

      if(mx!=-1)v[i][j]=mx;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cout << v[i][j] << " ";
    cout << endl;
  }

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}