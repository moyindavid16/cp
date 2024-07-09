#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int a,b,c; cin >> a >> b >> c;
  int ans = INF;
  for(int i=0;i<11;i++){
    ans = min(ans, abs(a-i) + abs(b-i) + abs(c-i));
  }
  cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}