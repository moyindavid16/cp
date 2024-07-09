#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b=a;
    map<int, array<int,2>> pa;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin >> a[i][j];pa[a[i][j]]={i,j};}
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> b[i][j];

    for(int i=0;i<n;i++){
      for(int j=1;j<m;j++){
        if(pa[b[i][j]][0]!=pa[b[i][j-1]][0]){
          cout << "NO" << endl;
          return;
        }
      }
    }

    for(int j=0;j<m;j++){
      for(int i=1;i<n;i++){
        if(pa[b[i][j]][1]!=pa[b[i-1][j]][1]){
          cout << "NO" << endl;
          return;
        }
      }
    }
    cout << "YES" << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}