#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, m; cin >> n >> m;
	string a,b;cin >> a >> b;
	
  int i,j; i=j=0;
  for(;i<n;){
    while(j<m && b[j]!=a[i]){
      j++;
    }
    if(j==m)break;
    i++;
    j++;
  }
  cout << i << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}