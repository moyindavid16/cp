#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,k; cin >> n >> k;
  // cout << n << k << " ";
  cout << (n-1 + k-2)/(k-1) << "\n";
}
 
int32_t main(){
  int t=1;cin>>t;
  while(t--)solve();
  return 0;
}