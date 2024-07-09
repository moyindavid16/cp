#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int x,y;cin >> x >> y;
    for(int i=0;i<64;i++){
      if(((x>>i)&1)!=((y>>i)&1)){
        cout << (1<<i) << endl;
        return;
      }
    }
    cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}