#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,m; cin >> n >> m;
  vector<string> v(n,"");
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  
  if(v[0][0]==v[n-1][m-1] || v[0][m-1]==v[n-1][0]){
    cout << "YES" << endl; return;
  }

  if(v[0][0]==v[0][m-1]){
    for(int i=1;i<m-1;i++){
      if(v[n-1][i]==v[0][0] || v[0][i]==v[n-1][0]){
        cout << "YES" << endl;return;
      }
    }
  }
  if(v[0][0]==v[n-1][0]){
    for(int i=1;i<n-1;i++){
      if(v[i][m-1]==v[0][0] || v[i][0]==v[0][m-1]){
        cout << "YES" << endl;return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}