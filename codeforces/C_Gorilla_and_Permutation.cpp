#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,m,k; cin >> n >> m >> k;
  for(int i=n;i>=k;i--)cout << i << " ";
  for(int i=k-1;i>m;i--)cout << i << " ";
  for(int i=1;i<=m;i++)cout << i << " ";
  cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}