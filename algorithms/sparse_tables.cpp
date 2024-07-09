#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, q; cin >> n >> q;
  vector<int> blog(n+1);
  blog[1] = 0;

  for(int i=2;i<=n;i++){
    blog[i] = blog[i/2]+1;
  }

  vector<int> v(n);
  for(int i=0;i<n;i++)cin >> v[i];

  vector<vector<int>> mn(n, vector<int>(blog[n]));
  for(int i=0;i<n;i++)mn[i][0] = v[i];

  for(int j=1;j<=blog[n];j++){
    for(int i=0;i+(1<<j)-1<n;i++){
      mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
    }
  }
  
  while(q--){
    int a,b; cin >> a >> b;
    int length = b-a+1;
    int ind = blog[length];
    cout << min(mn[a-1][ind], mn[b-(1<<ind)][ind]) << endl;
  }

}
 
int32_t main(){
  int t=1;//cin>>t;
  while(t--)solve();
  return 0;
}