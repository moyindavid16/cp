#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, k, x; cin >> n >> k >> x;
  int needed=(n+x-1)/x;
  needed *= needed;
  if(needed>k){
    cout << "NO";
  }
  else cout << "YES";
  cout << endl;

}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}